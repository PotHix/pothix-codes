var TableConstructor = function(){
	/**
	 * Table constructor
	 * Creates the main table and its headers
	 */
	this.createTable = function(){
		var table = document.createElement("table");

		var line = document.createElement("tr");
		for(var i = 0.5; i <= 8; i += 0.5){
			var header = document.createElement("th");
			header.innerHTML = i;
			line.appendChild(header);
		}

		table.appendChild(line);
		return table;
	}

	/**
	 * Rows and columns generator
	 * Creates all the rows and columns to receive the calculations
	 *
	 * @calculation: A callback function to calculate the final value to the column
	 */
	this.createRowsCols = function(calculation){
		table = this.createTable();

		for(var n = 1; n <= 50; n++){
			var line = document.createElement("tr");
			for(var i = 0.5; i <= 8; i += 0.5){
				var column = document.createElement("td");
				result = calculation(i, n);
				column.innerHTML = result.toFixed(6);
				line.appendChild(column);
			}
			table.appendChild(line);
		}

		return table;
	}

	this.appendTableWithHeader = function(table, text){
		h1 = document.createElement("h1");
		h1.innerHTML = text;

		exercisesDiv = document.getElementById("exercises");
		exercisesDiv.appendChild(h1);
		exercisesDiv.appendChild(table);
	}
}

var Calculation = function(){
	this.exercise1 = function(i, n){
		return Math.pow((1 + i/100), n);
	}

	this.exercise2 = function(i, n){
		return Math.pow((1 + i/100), -n);
	}

	this.exercise3 = function(i, n){
		return ((((Math.pow((1 + i/100), n))) - 1) / i);
	}

	this.exercise4 = function(i, n){
		return ((1 - ((Math.pow((1 + i/100), -n)))) / i);
	}

	this.exercise5 = function(i, n){
		return (i / (((Math.pow((1 + i/100), n))) - 1));
	}

	this.exercise6 = function(i, n){
		return (i / (1 - ((Math.pow((1 + i/100), -n)))));
	}
}

var calculation = new Calculation();
var tableConstructor = new TableConstructor();


tableConstructor.appendTableWithHeader(tableConstructor.createRowsCols(calculation.exercise1), "Exercício 1");
tableConstructor.appendTableWithHeader(tableConstructor.createRowsCols(calculation.exercise2), "Exercício 2");
tableConstructor.appendTableWithHeader(tableConstructor.createRowsCols(calculation.exercise3), "Exercício 3");
tableConstructor.appendTableWithHeader(tableConstructor.createRowsCols(calculation.exercise4), "Exercício 4");
tableConstructor.appendTableWithHeader(tableConstructor.createRowsCols(calculation.exercise5), "Exercício 5");
tableConstructor.appendTableWithHeader(tableConstructor.createRowsCols(calculation.exercise6), "Exercício 6");
