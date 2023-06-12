class Course:
    def __init__(self, department, number, name, credits, days, start, end, average_grade):
        self.department = department
        self.number = number
        self.name = name
        self.credits = credits
        self.days = days
        self.start = start
        self.end = end
        self.average_grade = average_grade

    def format(self):
        return (f"{self.department}{self.number}: {self.name}\n"
                f"Number of Credits: {self.credits}\n"
                f"Days of Lectures: {self.days}\n"
                f"Lecture Time: {self.start} - {self.end}\n"
                f"Stat: on average, students get {self.average_grade}% in this course\n"
                f"\n")

def main():
    courses = []
    with open("classesInput.txt", "r") as file:
        num_courses = int(file.readline().strip())
        for i in range(num_courses):
            department = file.readline().strip()
            number = file.readline().strip()
            name = file.readline().strip()
            credits = int(file.readline().strip())
            days = file.readline().strip()
            start = file.readline().strip()
            end = file.readline().strip()
            average_grade = int(file.readline().strip())
            courses.append(Course(department, number, name, credits, days, start, end, average_grade))

    with open("classesOutput.txt", "w") as file:
        for i, course in enumerate(courses):
            file.write(f"COURSE {i + 1}: {course.format()}")

if __name__ == "__main__":
    main()
