window.onload = () => {
	NumberButtonAssignment();
	OperatorButtonAssignment();
	btn_AC.onclick = DisplayResetAC;
	btn_DEL.onclick = Backspace;
	btn_equals.onclick = () => {
		OperationExecution();
		operation.value1 = 0;
		boolTeste = false;
	}
	document.querySelector("#btn_comma").onclick = Comma;
};

let displayValue = "0";
let boolTeste = true;

function NumberButtonAssignment() {
	let buttons = document.querySelectorAll(".keyboard .number");
	let buttonOrder = [7, 8, 9, 4, 5, 6, 1, 2, 3, 0];
	for (let i = 0; i < buttons.length; i++) {
		buttons[i].onclick = () => NumberInput(buttonOrder[i]);
	}
}

function OperatorButtonAssignment() {
	let buttons = document.querySelectorAll(".keyboard .operators button");
	let buttonOrder = ["/", "*", "-", "+"];

	for (let i = 0; i < buttons.length; i++) {
		buttons[i].onclick = () => {
			ClearBackground();
			buttons[i].style.backgroundColor = "white";
			OperationSetup(buttonOrder[i]);
		};
	}
}

let operation = { value1: 0,
				  value2: 0,
				  operator: "" };

function ClearBackground() {
	let buttons = document.querySelectorAll(".keyboard .operators button");
	buttons.forEach((button) => {
		button.style.backgroundColor = "rgb(72, 234, 255)";
	});
}

function OperationSetup(operator) {
	if (boolTeste) OperationExecution();
	operation.value1 = parseFloat(displayValue.replace(",", "."));
	operation.operator = operator;
	displayValue = "0";
}

function OperationExecution() {
	
	let result;
	if (operation.value1 != 0) {
		result = operation.value1;
		operation.value2 = parseFloat(displayValue.replace(",", "."));
	} else {
		result = parseFloat(displayValue.replace(",", "."));
	}

	switch (operation.operator) {
		case "/":
			result /= operation.value2;
			break;
		case "*":
			result *= operation.value2;
			break;
		case "-":
			result -= operation.value2;
			break;
		default:
			result += operation.value2;
	}

	displayValue = result.toString();
	display.innerText = displayValue;
}

function DisplayUpdate() {
	let [integerPart, fractionalPart] = displayValue.split(",");

	let strAux = "";

	for (let i = integerPart.length - 1, c = 0; i >= 0; i--) {
		if (++c % 4 == 0) {
			strAux = "." + strAux;
			c = 1;
		}
		strAux = integerPart[i] + strAux;
	}

	if (fractionalPart != undefined) strAux += "," + fractionalPart;

	display.innerText = strAux;
}

function DisplayResetAC() {
	operation.value1 = 0;
	operation.value2 = 0;
	operation.operator = "";
	displayValue = "0";
	boolTeste = true;
	ClearBackground();
	display.innerText = displayValue;
}

function NumberInput(n) {
	if (displayValue == "0") displayValue = "";
	ClearBackground();
	displayValue += n;
	DisplayUpdate();
	boolTeste = true;
}

function Comma() {
	if (displayValue.indexOf(",") == -1) {
		displayValue += ",";
		DisplayUpdate();
	}
}

function Backspace() {
	displayValue = displayValue.substring(0, displayValue.length - 1);
	if (displayValue.length == 0) displayValue = "0";
	DisplayUpdate();
}
