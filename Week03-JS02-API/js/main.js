//define functions before I call them

var city = "";
var state = "";
var APIKey = "50ed8d77a5b5295b";

var loadWeather = function(response){
	if(response.response.error){
		alert(response.response.error);
		return;
	}

	console.log("response = " + JSON.stringify(response));

	var thisCity = response.current_observation.display_location.city;
	var temp = response.current_observation.temp_f;
	var weather = response.current_observation.weather;
	var icon = response.current_observation.icon_url;

	console.log(thisCity);
	console.log(temp);
	console.log(weather);
	console.log(icon);

	$('.temperature').text(temp);
	$('.weather').text(weather);
	$('.currentCity').val(thisCity);
	$('.weatherIcon').html("<img src = '"+ icon +"'>");

}

var getWeather = function(){
	var thisURL = 'http://api.wunderground.com/api/' + APIKey + '/conditions/q/' + state + '/' + city + '.json';

	$.ajax({
		url : thisURL,
		dataType : 'jsonp',
		success : function(response){
			loadWeather(response);
		}
	});
}

var setLocation = function(){
	city = $('.currentCity').val();
	if(city == null || city == ""){
		alert('must input city');
	}
	state = $('.currentState').val();
	console.log('we want the weather data for ' + city + ' /' + state);
	getWeather();
}

var init = function(){
	$('#submit').click(function(e){
		e.preventDefault();
		setLocation();
	})
}

$(document).ready(function(){
	init();
});


