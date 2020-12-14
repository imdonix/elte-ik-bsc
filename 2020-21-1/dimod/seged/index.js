$(function(){
   $(document).on("blur", ".number", function(){
      if(!$.isNumeric($(this).html())){
        $(this).addClass("invalid");
      }
      else{
        $(this).removeClass("invalid");
      }
   });
});

var $TABLE = $('#table');
var $BTN = $('#export-btn');
var $EXPORT = $('#export');
var $CALC = $('#calculate-btn');
var $INTERPOLATE = $('#interpolate-btn');


$('.table-add').click(function () {
  var $clone = $TABLE.find('tr.hide').clone(true).removeClass('hide table-line d-none');
  $TABLE.find('table').append($clone);
});

$('.table-remove').click(function () {
  $(this).parents('tr').detach();
});

$('.table-up').click(function () {
  var $row = $(this).parents('tr');
  if ($row.index() === 1) return; // Don't go above the header
  $row.prev().before($row.get(0));
});

$('.table-down').click(function () {
  var $row = $(this).parents('tr');
  $row.next().after($row.get(0));
});

// A few jQuery helpers for exporting only
jQuery.fn.pop = [].pop;
jQuery.fn.shift = [].shift;

$BTN.click(function () {
  var $rows = $TABLE.find('tr:not(:hidden)');
  var headers = [];
  var data = [];

  // Get the headers (add special header logic here)
  $($rows.shift()).find('th:not(:empty)').each(function () {
    headers.push($(this).text().toLowerCase());
  });

  // Turn all existing rows into a loopable array
  $rows.each(function () {
    var $td = $(this).find('td');
    var h = {};

    // Use the headers from earlier to name our hash keys
    headers.forEach(function (header, i) {
      h[header] = $td.eq(i).text();
    });

    data.push(h);
  });

  // Output the result
  $EXPORT.text(JSON.stringify(data));
});

function renderTexExpressions(la){
   baseLparagraphId = "equationL";

	 for (var index = 0; index < la.pointCount(); index++) {
	 	 $("#divEquationL").append(`<p id="${baseLparagraphId + index}">`);
	 }

	 for (var index = 0; index < la.pointCount(); index++) {
		 katex.render(la.generateTexLexpression(index), document.getElementById(baseLparagraphId + index), {
			 throwOnError: false
			});
	 }

	 katex.render(la.generateTexPexpression(), equationP, {
		 throwOnError: false
		});
}

$('#clear-btn').click(clear);

function clear(){
  $TABLE.find("tr:not(:hidden)").detach();
  clearOutput();
}

function clearOutput(){
    $("#divEquationL").empty();
    $("#equationP").empty();
    $("#divEval").hide();
    $('#resultAlert').hide();
    $("#value").val(0);
}

var chart = null;

function fillChart(xValues, dataPoints){
  if(chart != null){
    chart.destroy();
  }
  var ctx = document.getElementById("chart");

  chart = new Chart(ctx, {
      type: 'line',
      data: {
        labels: xValues,
          datasets: [{
              label: 'Interpolation',
              data: dataPoints,
              //borderWidth: 1,
              fill: false,
              lineTension: 0,
              //backgroundColor: 'rgba(0, 0, 0, 0)',
              borderColor: 'rgb(255, 99, 132)',
              cubicInterpolationMode: 'monotone',
              pointRadius: 3,
              pointHoverRadius: 5
          }]
      },
      options: {
          responsive: true,
      }
  });
}

$CALC.click(function () {
  clearOutput();
  var $rows = $TABLE.find('tr:not(:hidden)');
  var xs = [];
  var ys = [];

  // Turn all existing rows into a loopable array
  $rows.each(function () {
    var $td = $(this).find('td');

    $td.each(function(index){
      var v = parseFloat($(this).text());
      if(index == 0){
        xs.push(v);
      }
      else if(index == 1){
        ys.push(v);
      }
    });

  });

  lagrange = new Lagrange(xs[0], ys[0], xs[1], ys[1]);

  for (var i = 2; i < xs.length; i++) {
    lagrange.addPoint(xs[i], ys[i]);
  }

  renderTexExpressions(lagrange);

  $("#divEval").show();
});

$INTERPOLATE.click(function(){
  let value = parseFloat($("#value").val());
  $('#resultValue').text(lagrange.evaluateExpression(value));
  $('#resultAlert').fadeIn();

  const xValues = lagrange.estimatePlotXvalues();

  const dataPoints = xValues.map(function (x) {
             return {'x': x, 'y':lagrange.evaluateExpression(x)}
           });

  fillChart(xValues, dataPoints);
})
