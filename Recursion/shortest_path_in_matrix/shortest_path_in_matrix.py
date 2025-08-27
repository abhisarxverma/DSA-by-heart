from typing import List

# PROBLEM - Given a matrix, find the shortest path sum from the start to the end of the matrix i.e 0:0 to rows-1:cols-1 of the matrix.

# I solved this myself

# RECURSION IS THE WAY TO SOLVE THIS

#Defining a helper recursion function that will do the recursion
def recursion(matrix, path, path_values, sum, start: List[int], end : List[int], rows: int, columns: int, row: int=None, col: int=None):

  if not row: row = start[0]
  if not col: col = start[-1]

  if [row, col] == end :
    return [sum, path_values]

  possible_moves = []
  if row+1 < rows and ([row+1, col] != start) and [row+1, col] not in path: possible_moves.append([row+1, col])
  if row-1 >= 0 and ([row-1, col] != start) and [row-1, col] not in path : possible_moves.append([row-1, col])
  if col+1 < columns and ([row, col+1] != start) and [row, col+1] not in path : possible_moves.append([row, col+1])
  if col-1 >= 0 and ([row, col-1] != start) and [row, col-1] not in path : possible_moves.append([row, col-1])

  shortest_sum = float("inf")
  shortest_path = []

  for move in possible_moves:
    path_result = recursion(matrix, path+[move], path_values+[matrix[move[0]][move[1]]], sum+(matrix[move[0]][move[1]]), start, end, rows, columns, move[0], move[1])
    if path_result[0] < shortest_sum:
      shortest_sum = path_result[0]
      shortest_path = path_result[1]

  return [shortest_sum, shortest_path]

def get_shortest_path(matrix, start=None, end=None) :
  if not matrix: return [0, []]
  rows = len(matrix)
  columns = len(matrix[0])

  if not start : start = [0, 0]
  if not end : end = [rows-1, columns-1]

  path = [start]
  path_values = [matrix[start[0]][start[-1]]]

  ans = recursion(matrix, path, path_values, int(matrix[0][0]), start, end, rows, columns)

  return ans


matrix = [
    [1, 2, 3, 4, 5],
    [6, 7, 8, 9, 1],
    [1, 2, 3, 4, 5],
    [6, 9, 1, 0, 2],
    [7, 5, 6, 1, 8]
]

ans = get_shortest_path(matrix)
print(f"Shortest Path Sum : ", ans[0])
print(f"Shortest Path : ", ans[-1])