
values = []

for i in range(10):
    x = int(input("Please enter an integer"))
    values.append(x)
    mod = x % 2
    if mod > 0:
        print ("Odd")
    else:
        print ("Even")
    
