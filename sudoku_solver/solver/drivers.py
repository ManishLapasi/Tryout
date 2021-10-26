def accept_input():
    inputs = []

    while True:
        try:
            line = input()
        except EOFError:
            break
        inputs.append(list(map(int,line.split())))

    return inputs


def isValidEntry(sudoku, row, column, num):
    for i in range(0,8):
        if sudoku[row][i]==num or sudoku[i][column]==num:
            return False
    
    boxStartRow = row - row%3
    boxStartColumn = column - column%3

    for i in range(boxStartRow,row):
        for j in range(boxStartColumn,column):
            if sudoku[i][j]==num:
                return False
    
    return True


def solve(inputSudoku, row, column):
    if row == 8 and column == 9:
        return (True, inputSudoku)
    if column == 9:
        column = 0
        row = row + 1

    if inputSudoku[row][column]>0:
        return solve(inputSudoku, row, column+1)

    for num in range(1,10):
        if isValidEntry(inputSudoku, row, column, num):
            inputSudoku[row][column] = num
            (boolval, inputSudoku) = solve(inputSudoku, row, column+1)
            if boolval:
                return (boolval, inputSudoku)
        inputSudoku[row][column] = 0

    return (False, inputSudoku)
        

        

