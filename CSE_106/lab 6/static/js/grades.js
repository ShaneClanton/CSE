function getGrades() {
  const xhttp = new XMLHttpRequest();
  xhttp.open("GET", "http://127.0.0.1:5000/grades", true);
  xhttp.send();
  xhttp.onload = function () {
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
}

function getStudentGrade() {
  var E1 = document.getElementById("E1").value;
  var student = E1;
  const xhttp = new XMLHttpRequest();
  xhttp.open("GET", "http://127.0.0.1:5000/grades/" + student, true);
  xhttp.send();
  xhttp.onload = function () {
      document.getElementById("E1_response").innerHTML = this.responseText;
  };
}

function createStudent() {
  var studentNew = document.getElementById("studentNew").value;
  var E3 = document.getElementById("E3").value;
  var xhttp = new XMLHttpRequest();
  xhttp.open("POST", "http://127.0.0.1:5000/grades");
  xhttp.setRequestHeader("Content-Type", "application/json");
  const body = { "name": studentNew, "grade": Number(E3) };
  xhttp.send(JSON.stringify(body));
  xhttp.onload = function () {
    location.reload();
  };
}

function editGrades() {
  var E4 = document.getElementById("E4").value;
  var E5 = document.getElementById("E5").value;
  var xhttp = new XMLHttpRequest();
  xhttp.open("PUT", "http://127.0.0.1:5000/grades/" + E4, true);
  xhttp.setRequestHeader("Content-Type", "application/json");
  const body = { "grade": Number(E5) };
  xhttp.send(JSON.stringify(body));
  xhttp.onload = function () {
    location.reload();
  };
}

function deleteStudent() {
  var E6 = document.getElementById("E6").value;
  const xhttp = new XMLHttpRequest();
  xhttp.open("DELETE", "http://127.0.0.1:5000/grades/" + E6, true);
  xhttp.setRequestHeader("Content-Type", "application/json");
  xhttp.send();
  xhttp.onload = function () {
    location.reload();
  };
}