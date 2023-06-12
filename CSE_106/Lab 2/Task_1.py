import numpy as np

# Part A
matrix = np.arange(2, 10).reshape(4, 2)
print("Part 1A")
print(matrix)

print("\n")

# Part B
checkerboard = np.zeros((8, 8), dtype=int)
checkerboard[::2, 1::2] = 1
checkerboard[1::2, ::2] = 1
print("Part 1B")
print(checkerboard)

print("\n")

# Part C
list = [10, 20, 10, 30, 20, 40, 20, 20, 10, 30, 0, 50, 10]
unique_values = np.unique(list)
print("Part 1C")
print(unique_values)

print("\n")

# Part D
list = [6, 75, 9, 82, 36, 42, 59, 3, 52, 1, 32, 68, 93, 4, 27, 85, 0, -3, 57]
values_greater_than_37 = [val for val in list if val > 37]
print("Part 1D")
print(values_greater_than_37)

print("\n")

# Part E
centigrade = np.array([0, 12, 45.21, 34, 99.91])
fahrenheit = (centigrade * 9 / 5) + 32
print("Part 1E")
print(fahrenheit)
