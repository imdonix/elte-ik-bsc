//Helper section
function gdc(a, b){
	if (b == 0)
			return a
	else
			return gdc(b, a % b)
}

function ldc(a, b){
	Math.abs(a * b) / gdc(a, b);
}

var Lagrange = function(x1, y1, x2, y2) {
	this.xs = [x1, x2];
	this.ys = [y1, y2];
}

Lagrange.prototype.addPoint = function(x, y) {
	this.xs.push(x);
	this.ys.push(y);
	return this.pointCount() - 1;
}

Lagrange.prototype.removePoint = function (index) {
	this.xs.remove(index);
	this.ys.remove(index);
	return this.pointCount();
};

Lagrange.prototype.pointCount = function () {
	return this.xs.length;
};

Lagrange.prototype.clear = function () {
	this.xs = [];
	this.ys = [];
};

Lagrange.prototype.eval = function (x) {
	//TODO
};

Lagrange.prototype.estimatePlotXvalues = function () {
	min = this.xs[0];
	max = this.xs[0];
	step = this.xs[0];
	MAX_STEPS = 50;

	for (var i = 1; i < this.pointCount(); i++) {
		step = Math.abs(gdc(this.xs[i], step));

		if(this.xs[i] < min){
			min = this.xs[i];
		}

		if(this.xs[i] > max){
			max = this.xs[i];
		}
	}

	min -= step * 2;
	max += step * 2;

	if((max - min) / step > MAX_STEPS)
	{
		 step = (max - min) / MAX_STEPS;
	}

	//alert(`MIN:${min}, MAX:${max}, STEP:${step}`);

	return math.range(min, max, step).toArray();
}

//Expression section
Lagrange.prototype.generateLexpression = function (index) {
	var numerator = "", denominator = "";

	for (var j = 0; j < this.pointCount(); j++) {
		 if(index != j){
			 numerator += `(x - ${this.xs[j]}) *`;
			 denominator += `(${this.xs[index]} - ${this.xs[j]}) *`;
		 }
	}

	return `(${numerator.substr(0, numerator.length - 1)})/ (${denominator.substr(0, denominator.length - 1)})`;
};

Lagrange.prototype.generatePexpression = function () {
	var expression = "";
	for (var i = 0; i < this.pointCount(); i++) {
		expression += `(${this.generateLexpression(i)} * ${(this.ys[i])}) +`;
	}
	return expression.substr(0, expression.length - 1);
};

Lagrange.prototype.evaluateExpression = function(x){
	var compiled = math.compile(this.generatePexpression());
	var scope = {x: x};
	return compiled.eval(scope);
}

//Tex Expression section
Lagrange.prototype.generateTexLexpression = function (index) {
	var numerator = `L_${index}(x) = `, denominator = "";

	for (var j = 0; j < this.pointCount(); j++) {
		 if(index != j){
			 numerator += `(x - ${this.xs[j]}) *`;
			 denominator += `(${this.xs[index]} - ${this.xs[j]}) *`;
		 }
	}

	return `${numerator.substr(0, numerator.length - 1)}/ ${denominator.substr(0, denominator.length - 1)}`;
}

Lagrange.prototype.generateTexPexpression = function () {
	var expression = "P(x) = ";

	for (var i = 0; i < this.pointCount(); i++) {
		expression += `[L_${i}(x) * ${(this.ys[i])}] +`;
	}
	return expression.substr(0, expression.length - 1);
}
