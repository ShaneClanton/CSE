from logic import TruthTable

proposition1 = input("Enter Proposition 1:\n")

proposition2 = input("Enter Proposition 2:\n")

myTable1 = TruthTable([proposition1])

myTable2 = TruthTable([proposition2])

print (myTable1.table)

print (myTable2.table)

if myTable1.table == myTable2.table:
 print ('The Proposition are equivalent.')

else:
    print ('The Proposition are not equivalent.')
