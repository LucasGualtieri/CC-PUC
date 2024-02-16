window.onload = () => {
	document.querySelector("#btn_theme-toggle").onclick = ThemeToggle;
	operatorButtons = document.querySelectorAll(".keyboard .operators button");
	ButtonAssignment();
	btn_AC.onclick = DisplayResetAC;
	btn_EC.onclick = DisplayResetEC;
	btn_DEL.onclick = () => DisplayInput("backspace");
	btn_equals.onclick = () => {
		OperationExecution();
		boolTeste = false;
	};
};

let displayValue = "0";
let boolTeste = true;
let displayMaxLen = 9;
let operation = { value1: 0, value2: 0, lastValue: 0, operator: "" };

function ButtonAssignment() {

	document.querySelector("#btn_comma").onclick = () => DisplayInput(",");
	let buttons = document.querySelectorAll(".keyboard .number");
	let buttonOrder = [7, 8, 9, 4, 5, 6, 1, 2, 3, 0];

	for (let i = 0; i < buttons.length; i++) {
		buttons[i].onclick = () => DisplayInput(buttonOrder[i]);
	}

	let operatorOrder = ["/", "*", "-", "+"];

	for (let i = 0; i < operatorButtons.length; i++) {
		operatorButtons[i].onclick = () => {
			OperationSetup(operatorButtons[i], operatorOrder[i]);
		};
	}
}

function OperatorsBackgroundReset() {
	operatorButtons.forEach((button) => {
		button.style.backgroundColor = "rgb(72, 234, 255)";
	});
}

function OperationSetup(button, operator) {
	if (boolTeste) OperationExecution();
	boolTeste = true;
	button.style.backgroundColor = "white";
	operation.value1 = parseFloat(displayValue.replace(",", "."));
	operation.operator = operator;
	displayValue = "0";
}

function OperationExecution() {
	
	if (boolTeste) {
		operation.value2 = parseFloat(displayValue.replace(",", "."));
		operation.lastValue = operation.value2;
	} else {
		operation.value2 = operation.lastValue;
	}

	switch (operation.operator) {
		case "/":
			operation.value1 /= operation.value2;
			break;
		case "*":
			operation.value1 *= operation.value2;
			break;
		case "-":
			operation.value1 -= operation.value2;
			break;
		default:
			operation.value1 += operation.value2;
	}
	
	displayValue = operation.value1.toFixed(displayMaxLen);
	displayValue = displayValue.replace(/\.?0+$/, "").replace(".", ",");
	
	operation.value2 = 0;

	DisplayUpdate();
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

	OperatorsBackgroundReset();

	operation.value1 = 0;
	operation.value2 = 0;
	operation.operator = "";

	displayValue = "0";
	display.innerText = displayValue;

	btn_AC.disabled = true;
	boolTeste = true;
}

function DisplayResetEC() {
	
	OperatorsBackgroundReset();
	
	if (operation.value1 != 0) btn_AC.disabled = false;
	else if (operation.value2 == 0) btn_AC.disabled = true;

	btn_AC.style.display = "block";
	btn_EC.style.display = "none";
	displayValue = "0";

	DisplayUpdate();
}

function DisplayInput(key) {

	OperatorsBackgroundReset();

	if (displayValue.length >= displayMaxLen) return;

	else if (key == "," && displayValue.indexOf(",") != -1) return;

	else if (displayValue == "0") displayValue = "";
	
	if (key == "backspace") {
		if (displayValue.length <= 1) displayValue = "0";
		else displayValue = displayValue.substring(0, displayValue.length - 1);
	}

	else displayValue += key;

	if (displayValue != "0") {
		btn_AC.style.display = "none";
		btn_EC.style.display = "block";
	}

	DisplayUpdate();
}

let themeToggle = true;

function ThemeToggle() {
	
	let DOMProps = document.documentElement.style;

	body.style.transition = "background-color 0.25s";
	document.querySelectorAll("button").forEach(button => {
		button.style.transition = "background-color 0.25s";
	});
	
	document.querySelectorAll("button").forEach(button => {
		button.style.transition = "background-color 0.25s, color 0.25s";
	});
	
	sun.style.transition = "color linear 0s";
	moon.style.transition = "color linear 0s ";

	if (!(themeToggle = !themeToggle)) {
		DOMProps.setProperty('--background-color', 'var(--dark-background-color)');
		DOMProps.setProperty('--number-color', 'var(--dark-number-color)');
		DOMProps.setProperty('--text-color', 'var(--dark-text-color)');
		sun.style.display = "block"
		moon.style.display = "none"
	} else {
		moon.style.display = "block"
		sun.style.display = "none"
		DOMProps.setProperty('--background-color', 'var(--light-background-color)');
		DOMProps.setProperty('--number-color', 'var(--light-number-color)');
		DOMProps.setProperty('--text-color', 'var(--light-text-color)');
	}

}