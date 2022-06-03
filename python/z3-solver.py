from queue import Queue
from z3 import *

#记录每一行的皇后所在的列
Queen = [Int(f'Queen_{i+1}') for i in range(8)]

#皇后要求在0-7列，不能超出棋盘，每行必须要有一个皇后
val_c = [And(0 <= Queen[i], Queen[i] <= 7) for i in range(8)]

#不能有两个皇后在同一列
col_c = [Distinct(Queen)]

#不能有两个皇后在同一个斜线
diag_c = [ And(Queen[i] - Queen[j] != i - j, Queen[i] - Queen[j] != j - i)
            for i in range(8) for j in range(i)]

#z3求解
solve(val_c + col_c + diag_c)
