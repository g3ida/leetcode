#############################################################
# 36. Valid Sudoku
# Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
#
#     Each row must contain the digits 1-9 without repetition.
#     Each column must contain the digits 1-9 without repetition.
#     Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
#
# Note:
#
#     A Sudoku board (partially filled) could be valid but is not necessarily solvable.
#     Only the filled cells need to be validated according to the mentioned rules.
#
#############################################################

from typing import List

class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        for i in range(0, 9):
            line, column, box = set(), set(), set()
            for j in range(0, 9):
                if board[i][j] != '.':
                    if board[i][j] in line:
                        return False
                    else:
                        line.add(board[i][j])
                if board[j][i] != '.':
                    if board[j][i] in column:
                        return False
                    else:
                        column.add(board[j][i])
                ii, jj = (i//3)*3 + j//3, (i%3)*3 + j%3
                if board[ii][jj] != '.':
                    if board[ii][jj] in box:
                        return False
                    else:
                        box.add(board[ii][jj])
        return True

example1 =  [["5","3",".",".","7",".",".",".","."]
            ,["6",".",".","1","9","5",".",".","."]
            ,[".","9","8",".",".",".",".","6","."]
            ,["8",".",".",".","6",".",".",".","3"]
            ,["4",".",".","8",".","3",".",".","1"]
            ,["7",".",".",".","2",".",".",".","6"]
            ,[".","6",".",".",".",".","2","8","."]
            ,[".",".",".","4","1","9",".",".","5"]
            ,[".",".",".",".","8",".",".","7","9"]]

example2 =  [["8","3",".",".","7",".",".",".","."]
            ,["6",".",".","1","9","5",".",".","."]
            ,[".","9","8",".",".",".",".","6","."]
            ,["8",".",".",".","6",".",".",".","3"]
            ,["4",".",".","8",".","3",".",".","1"]
            ,["7",".",".",".","2",".",".",".","6"]
            ,[".","6",".",".",".",".","2","8","."]
            ,[".",".",".","4","1","9",".",".","5"]
            ,[".",".",".",".","8",".",".","7","9"]]

#driver program
s = Solution()
assert(s.isValidSudoku(example1))
assert(not s.isValidSudoku(example2))