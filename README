My solutions to ACM Uva contest problems.

Includes a helper script, uvatool.py. Usage:

    $ alias u='python uvatool.py'

Show a problem description (downloads and caches to disk).

    $ u view 424 --text

Edit the problem (stores the expected input and output as comments in the
beginning of the file)

    $ u edit 424

Test the program against expected input-output in the source file.

    $ u test 424
    PASS

    $ u test 10920

    10920 FAIL
    --- output
    +++ expected
    @@ -1 +1,5 @@
    -
    +Line = 2, column = 2.
    +Line = 3, column = 1.
    +Line = 3, column = 3.
    +Line = 4, column = 4.
    +Line = 5, column = 4.

If we get stuck, show a hint from Steve Skienas algorithmist.com site.

    $ u hint 424 --text

List the problems we haven't solved yet.

    $ make list-unsolved
    10258 - Contest Scoreboard
    10264 - Problem B: The Most Potent Corner
    10920 - Problem A - Spiral Tap
    11581 - Problem E: Grid Successors
    11988 - Problem B: Broken Keyboard (a.k.a. Beiju Text)

List the problems we have solved

    $ make list
    573 -  The Snail
    575 - Skew Binary
    579 - Clockhands
    591 - Box of Bricks
    673 - Parentheses Balance

Run test suite for all solutions, solved or not.

    $ make check
    424 PASS
    483 PASS
    488 PASS
    494 PASS
    499 PASS
    543 PASS
    573 PASS
    575 PASS
