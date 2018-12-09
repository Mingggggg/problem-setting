import sys
from random import randint

n = 100
m = 100
k = 10

with open("test.in", "w") as out:
    out.write("%d %d %d\n" % (n, m, 1000))
    i = 0
    for x in range(0, n):
        for y in range(0, m):
            if x is 0 and y is 0:
                out.write("0 ")
            else:
                if y == m-1:
                    out.write("%d" % (randint(1, k)))
                else:
                    out.write("%d " % (randint(1, k)))
        out.write("\n")
    for x in range(0, n):
        for y in range(0, m):
            if x is 0 and y is 0:
                out.write("0 ")
            else:
                if y == m-1:
                    out.write("%d" % (randint(1, k)))
                else:
                    out.write("%d " % (randint(1, k)))
        out.write("\n")
