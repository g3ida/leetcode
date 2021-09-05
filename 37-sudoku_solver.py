
#############################################################
# 37. Sudoku Solver
#############################################################
# Write a program to solve a Sudoku puzzle by filling the empty cells.
#
# A sudoku solution must satisfy all of the following rules:
#
#     Each of the digits 1-9 must occur exactly once in each row.
#     Each of the digits 1-9 must occur exactly once in each column.
#     Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
#
# The '.' character indicates empty cells.
#############################################################

from typing import List

class Solution:
    
    lines, columns, boxes = [], [], []

    def initialize(self, board: List[List[str]]) -> None:

        self.lines, self.columns, self.boxes = [], [], []
        nums = {'1', '2', '3', '4', '5', '6', '7', '8', '9'} 
        for i in range(0, 9):
            line, column, box = set(), set(), set()
            for j in range(0, 9):
                if board[i][j] != '.':
                    line.add(board[i][j])
                if board[j][i] != '.':
                    column.add(board[j][i])
                ii, jj = (i//3)*3 + j//3, (i%3)*3 + j%3
                if board[ii][jj] != '.':
                    box.add(board[ii][jj])
            self.columns.append(nums.difference(column))
            self.lines.append(nums.difference(line))
            self.boxes.append(nums.difference(box))

    def solve(self, board: List[List[str]]) -> bool:
        for i in range(0, 9):
            for j in range(0, 9):
                if board[i][j] == '.':
                    bindex = i//3*3 + (j // 3)
                    for el in self.lines[i].intersection(self.columns[j]).intersection(self.boxes[bindex]):
                        board[i][j] = el
                        self.lines[i].remove(el)
                        self.columns[j].remove(el)
                        self.boxes[bindex].remove(el)
                        if self.solve(board):
                            return True
                        board[i][j] = '.' #rollback
                        self.lines[i].add(el)
                        self.columns[j].add(el)
                        self.boxes[bindex].add(el)
                    return False
        return True

    def solveSudoku(self, board: List[List[str]]) -> None:
        self.initialize(board)
        self.solve(board)

input1 =    [["5","3",".",".","7",".",".",".","."]
            ,["6",".",".","1","9","5",".",".","."]
            ,[".","9","8",".",".",".",".","6","."]
            ,["8",".",".",".","6",".",".",".","3"]
            ,["4",".",".","8",".","3",".",".","1"]
            ,["7",".",".",".","2",".",".",".","6"]
            ,[".","6",".",".",".",".","2","8","."]
            ,[".",".",".","4","1","9",".",".","5"]
            ,[".",".",".",".","8",".",".","7","9"]]

output1 =   [["5","3","4","6","7","8","9","1","2"]
            ,["6","7","2","1","9","5","3","4","8"]
            ,["1","9","8","3","4","2","5","6","7"]
            ,["8","5","9","7","6","1","4","2","3"]
            ,["4","2","6","8","5","3","7","9","1"]
            ,["7","1","3","9","2","4","8","5","6"]
            ,["9","6","1","5","3","7","2","8","4"]
            ,["2","8","7","4","1","9","6","3","5"]
            ,["3","4","5","2","8","6","1","7","9"]]

#driver program
s = Solution()
s.solveSudoku(input1)
assert(input1 == output1)