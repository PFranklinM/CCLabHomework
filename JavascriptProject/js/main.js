//post on blog and finish project by Sunday at midnight

//if the parsons server isnt working try a different host. Ask Umi or Charles for help if need be
//AWS webserver


// var APIKey = 'ac6237af-82b6-47ad-9753-f333cd26ec27';

var summonerName = "";
var totalTimePlayed = "";

// var testFunction = function(){

// }


var timePlayed = function(response){

	// if(response.response.error){
	// 	alert(response.response.error);
	// 	return;
	// }

	console.log("response = " + JSON.stringify(response));

	var TT = response.totalSessionsPlayed;

	console.log(TT);
	$('.totalTime').text("You have played League of Legends for a total of "+ TT + " hours");

}

var loadSummoner = function(response){

	// if(response.response.error){
	// 	alert(response.response.error);
	// 	return;
	// }

	console.log(summonerName);

	console.log("response = " + JSON.stringify(response));

	var IGN = response.name;
	var ID = response.id;

	console.log(IGN);
	console.log(ID);

	$('.summoner').val(IGN);
	$('.summonerID').text(ID);



	var thatUrl = 'https://na.api.pvp.net/api/lol/na/v1.4/summoner/by-name/' + summonerName + '?api_key=ac6237af-82b6-47ad-9753-f333cd26ec27.json';


	$.ajax({
			url : thatUrl,
			dataType : 'jsonp',
			success : function(response){
				timePlayed(response);
			}
	});

}


var getSummoner = function(){
	var thisUrl = 'https://na.api.pvp.net/api/lol/na/v1.4/summoner/by-name/' + summonerName + '?api_key=ac6237af-82b6-47ad-9753-f333cd26ec27.json';

	$.ajax({
			url : thisUrl,
			dataType : 'jsonp',
			success : function(response){
				loadSummoner(response);
			}
	});
}

var setSummoner = function(){
	summonerName = $('.summoner').val();

	getSummoner();
}

var init = function(){
	$('#submit').click(function(e){
		e.preventDefault();
		setSummoner();
	})
}

$(document).ready(function(){
	init();
});