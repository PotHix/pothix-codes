var numbers = 47831 + 47528 + 47454 + 47468 + 47458 + 44528;

var TableConstructor = function(){
	var headers = ["n","Saldo devedor", "Juro", "Amortização", "Pagamento"];
	var total = headers.length;

	/**
	 * Table constructor
	 * Creates the main table and its headers
	 */
	this.createTable = function(){
		var table = document.createElement("table");
		var line = document.createElement("tr");

		for(var i = 0; i < total; i++){
			var header = document.createElement("th");
			header.innerHTML = headers[i];
			line.appendChild(header);
		}

		table.appendChild(line);
		return table;
	}

	/**
	 * Rows and columns generator
	 * Creates all the rows and columns to receive the calculations
	 *
	 * @mainArray: All values to populate table
	 */
	this.createRowsCols = function(mainArray){
		table = this.createTable();

		for(var n = 0; n < mainArray.length; n++){
			var line = document.createElement("tr");

			for(var i = 0; i < total; i++){
				var column = document.createElement("td");
				column.innerHTML = mainArray[n][i] < 0.0001 ? 0 : mainArray[n][i];
				line.appendChild(column);
			}

			table.appendChild(line);
		}

		return table;
	}

	/**
	 * Append a h1 element to identify the table
	 *
	 * @table: The table to be insert after the header
	 * @text: The text of the header
	 */
	this.appendTableWithHeader = function(table, text){
		h1 = document.createElement("h1");
		h1.innerHTML = text;

		exercisesDiv = document.getElementById("exercises");
		exercisesDiv.appendChild(h1);
		exercisesDiv.appendChild(table);
	}
}

var DefaultCalculation = function(){
	var mainArray = []

	var defaultI = 0.01;
	var defaultN = 60;

	/**
	 * Allocate a new array with defaultN positions
	 */
	this.arrayAloc = function(){
		for(var i=0; i<=defaultN+1; i++){
			mainArray[i] = new Array(null, null, null, null, null);
		}
	}

	/**
	 * Insert values on the last line of the array tith totals for the current exercise
	 *
	 * @total_tax: A calculated total number of taxes
	 * @total_payment: A calculated total number of payment
	 * @total_amortization: A calculated total number of amortization
	 */
	this.createLastLine = function(total_tax, total_payment, total_amortization){
		mainArray[defaultN+1][0] = "Total";
		mainArray[defaultN+1][1] = "-x-";
		mainArray[defaultN+1][2] = total_tax.toFixed(6);
		mainArray[defaultN+1][3] = total_amortization.toFixed(6);
		mainArray[defaultN+1][4] = total_payment.toFixed(6);
	}

	/**
	 * The main method to calculate values
	 *
	 * @method: A function that responds to functions: createFirstLine, payment, tax, amortization, balanceDue, calculateInOrder
	 */
	this.calculate = function(method){
		this.arrayAloc();
		method.createFirstLine(mainArray, numbers);

		total_tax = 0;
		total_payment = 0;
		total_amortization = 0;

		for(var n=1; n <= defaultN; n++){
			method.calculateInOrder(mainArray, n, defaultI, defaultN);

			total_tax = parseFloat(total_tax) + parseFloat(mainArray[n][2]);
			total_payment = parseFloat(total_payment) + parseFloat(mainArray[n][4]);
			total_amortization = parseFloat(total_amortization) + parseFloat(mainArray[n][3]);
		}

		this.createLastLine(total_tax, total_payment, total_amortization);
		return mainArray;
	}
}

var Price = function(){
	this.payment = function(c,i,n){
		return ((c*i)/(1-Math.pow(1+i,-n))).toFixed(6);
	}

	this.tax = function(c,i){
		return (c*i).toFixed(6);
	}

	this.amortization = function(r,j){
		return (parseFloat(r)-parseFloat(j)).toFixed(6);
	}

	this.balanceDue = function(c,a){
		return (parseFloat(c)-parseFloat(a)).toFixed(6);
	}

	/**
	 * Calculate the problem using the correct calculations order
	 *
	 * @mainArray: Main array with "table" values
	 * @n: The number of the array line
	 * @defaultI: The default tax for all exercises
	 * @defaultN: The default number of lines for all exercises
	 */
	this.calculateInOrder = function(mainArray, n, defaultI, defaultN){
		mainArray[n][0] = n;
		mainArray[n][4] = this.payment(mainArray[0][1], defaultI, defaultN);
		mainArray[n][2] = this.tax(mainArray[n-1][1], defaultI);
		mainArray[n][3] = this.amortization(mainArray[n][4], mainArray[n][2]);
		mainArray[n][1] = this.balanceDue(mainArray[n-1][1], mainArray[n][3]);
	}

	this.createFirstLine = function(mainArray, numbers){
		mainArray[0][0] = 0;
		mainArray[0][1] = numbers.toFixed(6);
		mainArray[0][2] = "-x-";
		mainArray[0][3] = "-x-";
		mainArray[0][4] = "-x-";
	}
}

var Sam = function(){
	this.payment = function(c0, cx, i, n){
		return ((0.5*(c0/n))+(0.5*cx*i)+(0.5*((c0*i)/(1-Math.pow(1+i, -n))))).toFixed(6);
	}

	this.tax = function(c, i){
		return (c*i).toFixed(6);
	}

	this.amortization = function(r, j){
		return (parseFloat(r)-parseFloat(j)).toFixed(6);
	}

	this.balanceDue = function(c, a){
		return (parseFloat(c)-parseFloat(a)).toFixed(6);
	}

	/**
	 * Calculate the problem using the correct calculations order
	 *
	 * @mainArray: Main array with "table" values
	 * @n: The number of the array line
	 * @defaultI: The default tax for all exercises
	 * @defaultN: The default number of lines for all exercises
	 */
	this.calculateInOrder = function(mainArray, n, defaultI, defaultN){
		mainArray[n][0] = n;
		mainArray[n][2] = this.tax(mainArray[n-1][1], defaultI);
		mainArray[n][4] = this.payment(mainArray[0][1], mainArray[n-1][1], defaultI, defaultN);
		mainArray[n][3] = this.amortization(mainArray[n][4], mainArray[n][2]);
		mainArray[n][1] = this.balanceDue(mainArray[n-1][1], mainArray[n][3]);
	}

	this.createFirstLine = function(mainArray, numbers){
		mainArray[0][0] = 0;
		mainArray[0][1] = numbers.toFixed(6);
		mainArray[0][2] = "-x-";
		mainArray[0][3] = "-x-";
		mainArray[0][4] = "-x-";
	}
}

var Sac = function(){
	this.payment = function(j, ac){
		return (parseFloat(j)+parseFloat(ac)).toFixed(6);
	}

	this.tax = function(c, i){
		return (c*i).toFixed(6);
	}

	this.amortization = function(c, n){
		return (c/n);
	}

	this.balanceDue = function(c, ac){
		return (parseFloat(c)-parseFloat(ac)).toFixed(6);
	}

	/**
	 * Calculate the problem using the correct calculations order
	 *
	 * @mainArray: Main array with "table" values
	 * @n: The number of the array line
	 * @defaultI: The default tax for all exercises
	 * @defaultN: The default number of lines for all exercises
	 */
	this.calculateInOrder = function(mainArray, n, defaultI, defaultN){
		mainArray[n][0] = n;
		mainArray[n][2] = this.tax(mainArray[n-1][1], defaultI);
		mainArray[n][3] = this.amortization(mainArray[0][1], defaultN);
		mainArray[n][1] = this.balanceDue(mainArray[n-1][1], mainArray[n][3]);
		mainArray[n][4] = this.payment(mainArray[n][2], mainArray[n][3]);
	}

	this.createFirstLine = function(mainArray, numbers){
		mainArray[0][0] = 0;
		mainArray[0][1] = numbers.toFixed(6);
		mainArray[0][2] = "-x-";
		mainArray[0][3] = "-x-";
		mainArray[0][4] = "-x-";
	}
}

var Americano = function(){
	this.payment = function(a, j){
		return (parseFloat(a)+parseFloat(j)).toFixed(6);
	}

	this.tax = function(c, i){
		return (c*i).toFixed(6);
	}

	this.amortization = function(n){
		return n != 60 ? 0 : numbers.toFixed(6);
	}

	this.balanceDue = function(n){
		return n == 60 ? 0 : numbers.toFixed(6);
	}

	/**
	 * Calculate the problem using the correct calculations order
	 *
	 * @mainArray: Main array with "table" values
	 * @n: The number of the array line
	 * @defaultI: The default tax for all exercises
	 * @defaultN: The default number of lines for all exercises
	 */
	this.calculateInOrder = function(mainArray, n, defaultI, defaultN){
		mainArray[n][0] = n;
		mainArray[n][2] = this.tax(mainArray[0][1], defaultI);
		mainArray[n][3] = this.amortization(n);
		mainArray[n][1] = this.balanceDue(n);
		mainArray[n][4] = this.payment(mainArray[n][2], mainArray[n][3]);
	}

	this.createFirstLine = function(mainArray, numbers){
		mainArray[0][0] = 0;
		mainArray[0][1] = numbers.toFixed(6);
		mainArray[0][2] = "-x-";
		mainArray[0][3] = "-x-";
		mainArray[0][4] = "-x-";
	}
}

var calculator = new DefaultCalculation();
var tableConstructor = new TableConstructor();

var price = new Price();
var sam = new Sam();
var sac = new Sac();
var americano = new Americano();

tableConstructor.appendTableWithHeader(tableConstructor.createRowsCols(calculator.calculate(price)), "Price");
tableConstructor.appendTableWithHeader(tableConstructor.createRowsCols(calculator.calculate(sam)), "SAM");
tableConstructor.appendTableWithHeader(tableConstructor.createRowsCols(calculator.calculate(sac)), "SAC");
tableConstructor.appendTableWithHeader(tableConstructor.createRowsCols(calculator.calculate(americano)), "Americano");
