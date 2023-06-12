from logic import TruthTable

p = []
y = 'Y'
while (y == 'Y'):
    p1 = input("Enter a propositon:")
    p.append(p1)
    y = input("Would you like to enter more [Y/N]: ")

myTable = TruthTable(p)
myTable.table

p2 = []
for i in myTable.table:
    p2.append(i[1])

for j in p2:
    if (j[0] == j[1]):
        if (j[0] == 0):
            print("Your description is consistent.")
            break
        else:
             print("Your description is not consistent.")
             break
