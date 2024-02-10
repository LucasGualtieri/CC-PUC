window.onload = () => {
	NumberButtonAssignment();
	btn_AC.onclick = DisplayReset;
	btn_DEL.onclick = Backspace;
	document.querySelector("#btn_comma").onclick = Comma;
};

let displayValue = "0";

function NumberButtonAssignment() {
	let buttons = document.querySelectorAll(".keyboard .number");
	let buttonOrder = [7, 8, 9, 4, 5, 6, 1, 2, 3, 0];
	for (let i = 0; i < buttons.length; i++) {
		buttons[i].onclick = () => Digit(buttonOrder[i]);
	}
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

function DisplayReset() {
	displayValue = "0";
	DisplayUpdate();
}

function Digit(n) {
	if (displayValue == "0") displayValue = "";
	displayValue += n;
	DisplayUpdate();
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

function main() {}
