import math


def CheckIfPrime ():
    prime = int(input("Enter your number: "))
    count = 0
    sqr = int(math.sqrt(prime))
    for i in range(2, sqr+1):
        if prime % i == 0:
            print("your number is not prime")
            count += 1
            break
    if count == 0:
        print("your number is prime")
        
        
CheckIfPrime()

