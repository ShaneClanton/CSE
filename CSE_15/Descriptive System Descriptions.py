from logic import TruthTable

letter = 'Y'
prop = []
while letter == 'Y':
    a = input("Enter a propositon:")
    prop.append(a)
    letter = input("Would you like to enter more [Y/N]: ")

myTable = TruthTable(prop)

print ('Your Program uses propositonal variables', myTable.vars)

inside = myTable.vars
props =[]

i = 0
while i < len(inside):
    props.append(input("Enter meaning of " + inside[i] + ': '))
    i+= 1

v = []
for i in myTable.table:
    v.append(i[1])
for r in v:
     if (r[2] == 1):
          print ('Your description is consistent when:')
          print ('It is not the case when', props[0])
          print ('It is not the case when', props[1])
          break
     else:
        print ('Your description is inconsistent')
        print ('It is not the case when', props[0])
        print ('It is not the case when', props[1])
        break
