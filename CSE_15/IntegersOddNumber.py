#Collect the 10 values entered by the user

values = []


for i in range(10): 
    x = int(input("Enter value"))
    values.append(x)
    mod = x % 2
    if mod > 0:
        print ("This is an odd number.")
    else:
        print ("This is an even number.")
