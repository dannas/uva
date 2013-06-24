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
    def __init__(self, dir, urldir):
        HTMLParser.__init__(self)
        self.dir = dir
        self.urldir = urldir

    def handle_starttag(self, tag, attrs):
        if tag == 'img':
            for key,fname in attrs:
                if key == 'src':
                    url = os.path.join(self.urldir, fname)
                    path = os.path.join(self.dir, fname)
                    download(path, url)

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
    download(path, url)
    payload = open(path).read()
    urldir = os.path.join(URL_PREFIX, dname(problemid))
    d = HtmlImageDownloader(os.path.dirname(path), urldir)
    d.feed(payload)

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
    fname = os.path.abspath(str(problemid))
    infile = open(fname + '.cc')
    for case in testcases(infile):
        runtest(case, binary)

# TODO(dannas): Use argparse
problemid = int(sys.argv[2])
if sys.argv[1] == "view":
    view(problemid)
elif sys.argv[1] == "test":
    test(problemid)
