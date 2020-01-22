# Created by "Alpha" on 21-01-2020

# Works on Official CCC Grader.

# Algorithm Highlight - Recursive Dynamic Programming
"""
Basically we wan't to try out all the substitution rules
to see if we can generate the final string using the desired steps
given in the input.

We have 2 base conditions:
    1) If we have reached the desired number of steps AND the final seq
        - return steps recorded until then
    2) Else if we have reached the desired number of steps but have not matched
       the final seq
        - return False

Recursive Code:
(a, b) is our substitution rule:
We can find a in our seq using .find() to get the index and generate
new string with substitution rule and call recursive function.

"""

from sys import stdin

INPUT = stdin.readline

# Inputting 3 rules
a1, b1 = INPUT().split()
a2, b2 = INPUT().split()
a3, b3 = INPUT().split()

# Num. of steps, initial seq, and final seq
steps, initial, final = INPUT().split()
steps = int(steps)

# Memoization set for speeding up recursion
memoize = set()


def rec(it, seq, moves):
    # If we used the RIGHT number of steps, and reached the goal seq...
    if it == steps and seq == final:
        return moves

    # If we have reached number of steps, but seq doesn't match goal seq...
    if it == steps:
        return False

    # If we visit the same number of steps + seq...
    setup = (it, seq)
    if setup in memoize:
        return False
    memoize.add(setup)

    # Get rule # + (a,b) setup in form of a1 start seq, a2 end seq
    for rule, (a, b) in enumerate([(a1, b1), (a2, b2), (a3, b3)]):
        # Find all pos of (a) seq in bigger sequence starting from `0 index
        # and call recursive func on it.
        pos = -1
        while True:
            # use seq.find() to find pos of a in seq.
            pos = seq.find(a, pos + 1)

            # If we are not able to find a valid sequence.
            if pos == -1:
                break

            # ns (new seq) = previous string + substitution + string after
            ns = seq[:pos] + b + seq[pos + len(a):]
            # Call bool function (b/c it can be false) on:
            """
            it+1 --> This adds one step
            ns --> The new sequence
            moves arr (our answer) in format of --> rule#, position, and ns 
            """
            # rule is being added to 1, because enumerate starts with 0.
            # pos is added to 1, because J5 Problem is not asking for literal index (ex.):
            """
            ABCD - (A starts with index 1.) (B starts with index 2, goes on...) 
            """
            output = rec(it + 1, ns, moves + [[rule + 1, pos + 1, ns]])
            # If output == valid moves arr, then we must return it.
            if output:
                return output

    return False


# Run recursive function to try out
# all the rules and return 1 that works...


value = rec(0, initial, [])

if not value:
    print "IMPOSSIBLE"
else:
    # (Value is stored with rule #, index, resulting seq...)
    for a, b, c in value:
        print a, b, c
