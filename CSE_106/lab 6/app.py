from flask import Flask, render_template, request
from flask_cors import CORS

import json
app = Flask(__name__)
CORS(app)

@app.route('/')
def static_file():
    return render_template('grades.html')

@app.route('/grades', methods = ['GET', 'POST'])
def grade_Handler1():
    if request.method == 'GET':
        grades = json.load(open('grades.json'))
        return grades
    
    elif request.method == 'POST':
        submission = request.get_json()
        grades = json.load(open('grades.json'))
        grades[submission['name']] = submission['grade']
        add_json = open("grades.json", "w")
        json.dump(grades, add_json)
        add_json.close()
        return grades

@app.route('/grades/<id>', methods = ['GET', 'PUT', 'DELETE'])
def grade_Handler2(id):
    
    if request.method == 'PUT':
        grades = json.load(open('grades.json'))
        if id in grades:
            submission = request.get_json()
            grades[id] = submission['grade']
            add_json = open("grades.json", "w")
            json.dump(grades, add_json)
            add_json.close()
            return grades
        
    elif request.method == 'DELETE':
        grades = json.load(open('grades.json'))
        if id in grades:
            del grades[id]
            add_json = open("grades.json", "w")
            json.dump(grades, add_json)
            add_json.close()
            return grades
    
    elif request.method == 'GET':
        grades = json.load(open('grades.json'))
        if id in grades:
            return {id: grades[id]}

if __name__ == '__main__':
    app.run()