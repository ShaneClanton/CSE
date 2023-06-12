const output = document.querySelector('.output');
const numberButtons = document.querySelectorAll('.number');
const operatorButtons = document.querySelectorAll('.operator');
const decimalButton = document.querySelector('.decimal');
const equalsButton = document.querySelector('.equals');
const clearButton = document.querySelector('.clear');

let firstNumber = '';
let secondNumber = '';
let currentOperator = '';
let temp = '';
let shouldClearOutput = false;
let lastClickedOperator = '';

function appendNumber(number) {
  if (shouldClearOutput) {
    output.textContent = '';
    shouldClearOutput = false;
  }
  output.textContent += number;
}

function appendDecimal() {
  if (shouldClearOutput) {
    output.textContent = '';
    shouldClearOutput = false;
  }
  if (!output.textContent.includes('.')) {
    output.textContent += '.';
  }
}

function performOperator(operator) {
  if (currentOperator) {
    temp = output.textContent;
    performEquals();
    highlightButton(operatorButtons, operator);
  }
  firstNumber = output.textContent;
  currentOperator = operator;
  shouldClearOutput = true;
  highlightButton(operatorButtons, operator);
  lastClickedOperator = operator;
}


function performLastOperation() {
  let result;
  switch (currentOperator) {
    case '+':
      result = Number(firstNumber) + Number(temp);
      break;
    case '-':
      result = Number(firstNumber) - Number(temp);
      break;
    case '*':
      result = Number(firstNumber) * Number(temp);
      break;
    case '/':
      result = Number(firstNumber) / Number(temp);
      break;
    default:
      return;
  }
  resultOutput = result;
  output.textContent = resultOutput;
  firstNumber = result.toString();
}

function performEquals() {
  if (!currentOperator) {
    return;
  }
  if (shouldClearOutput) {
    performLastOperation();
    highlightButton(operatorButtons, operator);
  }
  if (!secondNumber && !temp) {
    secondNumber = output.textContent;
  }
  if (temp != '') {
    secondNumber = temp;
  }
  let result;
  switch (currentOperator) {
    case '+':
      result = Number(firstNumber) + Number(secondNumber);
      break;
    case '-':
      result = Number(firstNumber) - Number(secondNumber);
      break;
    case '*':
      result = Number(firstNumber) * Number(secondNumber);
      break;
    case '/':
      result = Number(firstNumber) / Number(secondNumber);
      break;
    default:
      return;
  }
  resultOutput = result;
  output.textContent = resultOutput;
  firstNumber = result.toString();
  temp = secondNumber;
  secondNumber = '';
  lastClickedOperator = '';
}

function highlightButton(operatorButtons, operator) {
  operatorButtons.forEach(button => {
    button.classList.remove('highlight');
  });
  const operatorButton = document.querySelector(`button[value="${operator}"]`);
  operatorButton.classList.add('highlight');
}

function resetButton(operatorButtons) {
  if (lastClickedOperator) {
    const operatorButton = document.querySelector(`button[value="${lastClickedOperator}"]`);
    operatorButton.classList.remove('highlight');
  } else {
    operatorButtons.forEach(button => {
      button.classList.remove('highlight');
    });
  }
}


function clearOutput() {
  output.textContent = '';
  firstNumber = '';
  secondNumber = '';
  currentOperator = '';
  temp = '';
  shouldClearOutput = false;
  resetButton(operatorButtons);
}

numberButtons.forEach(button => {
  button.addEventListener('click', () => {
    appendNumber(button.value);
  });
});

decimalButton.addEventListener('click', () => {
  appendDecimal();
});

operatorButtons.forEach(button => {
  button.addEventListener('click', () => {
    performOperator(button.value);
  });
});

equalsButton.addEventListener('click', () => {
  if(currentOperator){
    performEquals();
    resetButton(operatorButtons);
  }else if(!shouldClearOutput){
    performLastOperation();
    resetButton(operatorButtons);
  }
});

clearButton.addEventListener('click', () => {
  clearOutput();
});
