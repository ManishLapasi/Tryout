import drivers
import sys
sys.setrecursionlimit(10000)
print(sys.getrecursionlimit())

inputSudoku = drivers.accept_input()

print(inputSudoku)

(boolval, solvedSudoku) = drivers.solve(inputSudoku,0,0)

if boolval:
    print("Got a solution!")
    print(solvedSudoku)
else:
    print("Couldn't find a solution")