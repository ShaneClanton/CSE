print("please enter an number: ")
score = int(input())

if score >= 90 and score <= 100:
    print("you get an a")
elif score >= 80 and score <= 89:
    print("you get a b")
elif score >= 70 and score <= 79:
    print("you get a c")
elif score >= 60 and score <= 69:
    print("you get a d")
elif score < 60:
    print("you get a f")