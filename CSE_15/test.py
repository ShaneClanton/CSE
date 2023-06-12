from logic import TruthTable

myTable=TruthTable(['-a'])
myTable.display()

print("")

myTable=TruthTable(['a and b'])
myTable.display()

print("")

myTable=TruthTable(['a or b'])
myTable.display()

print("")

myTable=TruthTable(['a -> b'])
myTable.display()

print("")

myTable=TruthTable(['a <-> b'])
myTable.display()
