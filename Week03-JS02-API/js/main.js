var city='';
var state="";
//IMPORTANT: REPLACE YOUR API KEY HERE
var APIKey = "YOUR_API_KEY";
//test

var loadWeather = function(response){
	//if the API sends us an error message
	if(response.response.error){
		alert(response.response.error);
		return;
	}

	// console.log("response = " + JSON.stringify(response));
	
	//create our JS variables from the JSON we received
	var thisCity = response.current_observation.display_location.city;
	var temp = response.current_observation.temp_f;
	var weather = response.current_observation.weather;
	var icon = response.current_observation.icon_url;

	console.log(thisCity);
	console.log(temp);
	console.log(weather);
	console.log(icon);

	//push our variables into our html
	$('.temperature').text(temp);
	$('.weather').text(weather);
	$('.currentCity').val(thisCity);
	$('.weatherIcon').html("<img src='"+ icon +"'>");
}

//call function
var getWeather = function(){
	//create URL for our API call
	var thisURL = 'http://api.wunderground.com/api/' + APIKey + '/conditions/q/' + state + '/' + city + '.json';

	//API call
	$.ajax({
		url : thisURL,
		dataType : 'jsonp',
		success : function(response){
			//call loadWether function with the API's response as parameter
			loadWeather(response);
		}
	});
}

//function that will check our city and state input
var setLocation = function(){
	city = $('.currentCity').val();
	if(city == null || city == ""){
		alert('you need to input a city');
	}
	state = $('.currentState').val();
	console.log('we want the weather data for ' + city + ' / ' + state);
	getWeather();
}

//just like before
var init = function(){
	$('#submit').click(function(e){
		e.preventDefault();
		//call function that will check our city and state input
		setLocation();
	})
}

//just like before
$(document).ready(function(){
	init();
});