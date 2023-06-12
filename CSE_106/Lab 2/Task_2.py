import numpy as np

matrix_A = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
matrix_B = np.array([[3, 1, 4], [2, 6, 1], [2, 9, 7]])

# Print matrix A and B
print(matrix_A)
print(matrix_B)
print()
# Print the addition of Matrix A and B
matrix_add = np.add(matrix_A,matrix_B)
print("#2A")
print(matrix_add)
print()
# Print the Matrix A x B
matrix_mult = matrix_A.dot(matrix_B)
print("#2B")
print(matrix_mult)
print()
# Print the determinate of Matrix A
print("#2C")
print (np.linalg.det(matrix_A))
print()
# Print the inverse of Matrix B
print("#2D")
print(np.linalg.inv(matrix_B))
print()
# Print the eigenvalues of Matrix A
print("#2E")
print(np.linalg.eigvals(matrix_A))
print()