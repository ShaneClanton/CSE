from flask import Flask, render_template, request
from flask_cors import CORS
from flask_sqlalchemy import SQLAlchemy
import os

app = Flask(__name__)

basedir = os.path.abspath(os.path.dirname(__file__))
db_name = "Grades.db"

with app.app_context():
    
    app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + \
        os.path.join(basedir, db_name)
    data = SQLAlchemy(app)
    CORS(app)
    class classroom(data.Model):
        id = data.Column(data.Integer, primary_key = True)
        name = data.Column(data.String, nullable = False, unique = True)
        grade = data.Column(data.Float, nullable = False, unique = False)
        def __init__ (self, name, grade):
            self.name = name
            self.grade = grade
    data.create_all()

def createDatabase(Class):
    database = {}
    for student in Class:
        database.update({student.name:student.grade})
    return database

@app.route('/')
def static_file():
    return render_template('grades.html')

@app.route('/grades', methods = ['GET', 'POST'])
def grade_Handler1():
    
    if request.method == 'GET':
        return createDatabase(classroom.query.all())
    
    elif request.method == 'POST':
        entry = request.get_json()
        name = entry['name']
        grade = entry['grade'] 
        student = classroom(name, grade)
        data.session.add(student)
        data.session.commit()
        return {name:grade}

@app.route('/grades/<id>', methods = ['GET', 'PUT', 'DELETE'])
def grade_Handler2(id):
    
    if request.method == 'PUT':
        entry = request.get_json()
        newGrade = entry['grade']
        student = classroom.query.filter_by(name = id)
        student = student.update(dict(grade = newGrade))
        data.session.commit()
        return createDatabase(classroom.query.all())
    
    elif request.method == 'DELETE':
        data.session.delete(classroom.query.filter_by(name=id).first())
        data.session.commit()
        return createDatabase(classroom.query.all())
    
    elif request.method == 'GET':
        return createDatabase(classroom.query.filter_by(name = id))

if __name__ == '__main__':
    app.run()