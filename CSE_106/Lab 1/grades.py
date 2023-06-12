import json

# Load grades data from file into memory as a dictionary
def load_grades():
    try:
        with open('grades.txt', 'r') as f:
            return json.load(f)
    except FileNotFoundError:
        return {}

# Write grades data from memory to file
def write_grades(grades):
    with open('grades.txt', 'w') as f:
        json.dump(grades, f)

# Create students and grades
def create_student(grades, name, grade):
    grades[name] = grade
    write_grades(grades)
    print(f'Created grade for student {name}: {grade}')

# Get student grades
def get_grade(grades, name):
    try:
        grade = grades[name]
        print(f'Grade for student {name}: {grade}')
    except KeyError:
        print(f'No grade found for student {name}')

# Edit students grades
def edit_grade(grades, name, new_grade):
    try:
        grades[name] = new_grade
        write_grades(grades)
        print(f'Edited grade for student {name}: {new_grade}')
    except KeyError:
        print(f'No grade found for student {name}')

# Delete student grades
def delete_grade(grades, name):
    try:
        del grades[name]
        write_grades(grades)
        print(f'Deleted grade for student {name}')
    except KeyError:
        print(f'No grade found for student {name}')

# Main
if __name__ == '__main__':
    grades = load_grades()
    while True:
        action = input('Enter a command (create, get, edit, delete, quit): ')
        if action == 'create':
            name = input('Enter student name: ')
            grade = input('Enter student grade: ')
            create_student(grades, name, grade)
        elif action == 'get':
            name = input('Enter student name: ')
            get_grade(grades, name)
        elif action == 'edit':
            name = input('Enter student name: ')
            new_grade = input('Enter new grade: ')
            edit_grade(grades, name, new_grade)
        elif action == 'delete':
            name = input('Enter student name: ')
            delete_grade(grades, name)
        elif action == 'quit':
            break
        else:
            print('Invalid command')
