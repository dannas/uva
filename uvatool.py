"""
TODO: Don't strip leading whitespace when testing
TODO: Find out why HtmlParser chokes on some problem desc, i.e. 11799
"""

from HTMLParser import HTMLParser
from difflib import unified_diff
from subprocess import Popen, PIPE
from urllib2 import urlopen
import os
import re
import subprocess
import sys

USERNAME = 'dannas'
USERID =    178401

URL_PREFIX = 'http://uva.onlinejudge.org/external/'

class HtmlImageDownloader(HTMLParser):
    def __init__(self):
        HTMLParser.__init__(self)
        self.fnames = []

    def handle_starttag(self, tag, attrs):
        if tag == 'img':
            self.fnames += [val for key, val in attrs if key == 'src']

DEFAULT, INPUT_HEADER_SEEN, OUTPUT_HEADER_SEEN = (0, 1, 2)

class HtmlTestcaseCollector(HTMLParser):
    def __init__(self):
        HTMLParser.__init__(self)
        self.input = []
        self.output = []
        self.title = ''
        self.tag = ''
        self.intitle = False
        self.inheader = False
        self.state = DEFAULT

    def handle_starttag(self, tag, attrs):
        self.tag = tag
        if tag == 'h2' or tag == 'h3':
            self.inheader = True
        if tag == 'title':
            self.intitle = True

    def handle_endtag(self, tag):
        if tag == 'h2' or tag == 'h3':
            self.inheader = False
        if tag == 'title':
            self.intitle = False

    def handle_data(self, data):
        data = data.strip()
        if self.intitle:
            self.title = data
            # A precaution - The HtmlParser calls handle_data twice for some
            # problem descriptions while inside the title tag. One example is
            # 10041, where...
            #
            #    <HEAD>
            #    <TITLE>Problem C: Vito's family</TITLE>
            #
            # .. handle_data() is called a second time with data=''
            self.intitle = False
        elif self.inheader and data.lower() == 'sample input':
            self.state = INPUT_HEADER_SEEN
        elif self.inheader and (data.lower() == 'sample output' or
                data.lower() == 'output for sample input'):
            self.state = OUTPUT_HEADER_SEEN
        elif self.tag == 'pre' and self.state == INPUT_HEADER_SEEN:
            self.input = data.split('\n')
            self.state = DEFAULT
        elif self.tag == 'pre' and self.state == OUTPUT_HEADER_SEEN:
            self.output = data.split('\n')
            self.state = DEFAULT

def fname(problemid):
    return '%d/%d.html' % (problemid / 100, problemid)

def dname(problemid):
    return '%d' % (problemid / 100)

def create_dir(path):
    dir = os.path.dirname(path)
    if not os.path.exists(dir):
        os.makedirs(dir)

def download(path, url):
    response = urlopen(url)
    payload = response.read()
    create_dir(path)
    with open(path, 'w+') as f:
        f.write(payload)

def download_problem(path, url):
    join = os.path.join
    download(path, url)
    payload = open(path).read()
    urldir = join(URL_PREFIX, dname(problemid))
    dirpath = os.path.dirname(path)
    d = HtmlImageDownloader()
    d.feed(payload)
    for f in d.fnames:
        download(join(dirpath, f), join(urldir, f))

def view(problemid):
    path =  os.path.join('problem', fname(problemid))
    if not os.path.exists(path):
        url = os.path.join(URL_PREFIX, fname(problemid))
        download_problem(path, url)
    subprocess.call(['firefox', path])

def testcases(infile):
    def tokenizer():
        for line in infile:
            m = re.match(r'// *(<|>) *(.*?)\s*$', line)
            if m:
                yield (m.group(1), m.group(2))

    IN, OUT = 0, 1
    state = IN
    input = []
    output = []

    for type, line in tokenizer():
        if state == IN:
            if type == '<':
                input.append(line)
            else:
                state = OUT
        if state == OUT:
            if type == '<':
                yield (input, output)
                state = IN
            else:
                output.append(line)
    yield (input, output)


def runtest(case, fname):
    input, expected = case
    proc = Popen([fname], stdin=PIPE, stdout=PIPE)

    val, _ = proc.communicate('\n'.join(input))

    diff = unified_diff(val.split('\n'), expected,
                        fromfile='output', tofile='expected',
                        lineterm='')
    print '\n'.join(list(diff))

def test(problemid):
    binary = os.path.abspath(os.path.join('obj', str(problemid)))
    fname = os.path.abspath(os.path.join('src', str(problemid)))
    infile = open(fname + '.cc')
    for case in testcases(infile):
        runtest(case, binary)

TEMPLATE = """
// %d - %s

%s

%s

#include <iostream>

using namespace std;

int main()
{
}
"""

def edit(problemid):
    path = os.path.abspath(str(problemid)) + '.cc'
    if not os.path.exists(path):
        htmlfile = os.path.join('problem', fname(problemid))
        c = HtmlTestcaseCollector()
        with open(htmlfile) as f:
            c.feed(f.read())
        input = '\n'.join(['// < ' + line for line in c.input])
        output = '\n'.join(['// > ' + line for line in c.output])
        content = TEMPLATE % (problemid, c.title, input, output)
        with open(path, 'w+') as f:
            f.write(content)
    subprocess.call(['vi', path])

# TODO(dannas): Use argparse
problemid = int(sys.argv[2])
if sys.argv[1] == "view":
    view(problemid)
elif sys.argv[1] == "test":
    test(problemid)
elif sys.argv[1] == "edit":
    edit(problemid)

