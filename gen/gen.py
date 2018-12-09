import sys
from random import randint

n = 10
m = 10

with open("test.in", "w") as out:
    out.write("%d %d %d\n" % (n, m, 1000))
    i = 0
    for x in range(0, n):
        for y in range(0, m):
            out.write("%d " % (randint(1, 10)))
        out.write("\n")
    for x in range(0, n):
        for y in range(0, m):
            out.write("%d " % (randint(1, 10)))
        out.write("\n")
