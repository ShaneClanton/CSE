function getGrades() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "https://amhep.pythonanywhere.com/grades");
    xhttp.onload = function() {
  
      var data = JSON.parse(this.response);
      var table = document.getElementById("table");
      table.innerHTML;
      for(i in Object.keys(data)){
  
        var row = table.insertRow();
        var cell0 = row.insertCell(0);
        var cell1 = row.insertCell(1);
  
        cell0.innerHTML = Object.keys(data)[i];
        cell1.innerHTML = data[Object.keys(data)[i]];
      }
    };
    xhttp.send();
}

function getStudentGrade(){
    var xhttp = new XMLHttpRequest();
    var student = document.getElementById("E1");
    xhttp.open("GET", "https://amhep.pythonanywhere.com/grades/"+student.value);
    xhttp.onload = function() {
    document.getElementById("E1_response").innerHTML = this.responseText;
    };
    xhttp.send();
}

function createStudent() {
  var name = document.getElementById("name").value;
  var grade = document.getElementById("E3").value;
  var xhttp = new XMLHttpRequest();
  xhttp.open("POST", "https://amhep.pythonanywhere.com/grades");
  xhttp.setRequestHeader("Content-Type", "application/json");
  xhttp.onload = function() {
    location.reload();
  };
  const body = {"name": name, "grade": grade};
  xhttp.send(JSON.stringify(body));
}


function editGrades() {
  var name = document.getElementById("E4").value;
  var xhttp = new XMLHttpRequest();
  xhttp.open("PUT", "https://amhep.pythonanywhere.com/grades/" + encodeURIComponent(name));
  xhttp.setRequestHeader("Content-Type", "application/json");
  xhttp.onload = function() {
    location.reload();
  };
  const body = {"grade": document.getElementById("grade").value};
  xhttp.send(JSON.stringify(body));
}


function deleteStudent() {
  var xhttp = new XMLHttpRequest();
  var studentName = prompt("Enter the name of the student you want to delete:");
  xhttp.open("DELETE", "https://amhep.pythonanywhere.com/grades/" + studentName);
  xhttp.onload = function() {
    location.reload();
  };
  xhttp.send();
}