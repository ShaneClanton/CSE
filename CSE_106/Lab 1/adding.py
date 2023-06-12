# def add_numbers():
#     try:
#         numbers = input("Enter two or more numbers separated by spaces: ").split()
#         numbers = [int(num) for num in numbers]
#         if len(numbers) < 2:
#             raise ValueError("Please enter at least two numbers.")
#         sum_of_numbers = sum(numbers)
#         print("The sum of the numbers is:", sum_of_numbers)
#     except ValueError as error:
#         print(error)

# add_numbers()

def determine_grade(scores):
    if scores >= 90 and scores <= 100:
        print("your grade is an A")
    elif scores >= 80 and scores <= 89:
        print("your grade is an B")
    elif scores >= 70 and scores <= 79:
        print("your grade is an C")
    elif scores >= 60 and scores <= 69:
        print("your grade is an D")
    elif scores >= 50 and scores <= 59:
        print("your grade is an E")
    else:
        print("your grade is an F")

scores = int(input('Enter a number: '))
determine_grade(scores)
