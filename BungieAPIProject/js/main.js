var playerName = "";

// var APIKey = 'c99c60ac9dcd455f858c714d6bf5394b';

var loadPlayer = function(response){

	// if(response.response.error){
	// 	alert(response.response.error);
	// 	return;
	// }

	console.log(playerName);

	console.log("response = " + JSON.stringify(response));

	var IGN = response.displayName;

	console.log(IGN);

	$('.playerName').val(IGN);

}

var getPlayer = function(){
	var thisURL = 'http://www.bungie.net/Platform/Destiny/SearchDestinyPlayer/{membershipType}/{displayName}/.json';

	$.ajax({
			url : thisURL,
			dataType : 'jsonp',
			success : function(response){
				loadPlayer(response);
			}
	});
}

var setPlayer = function(){
	characterName = $('.playerName').val();

	getPlayer();
}

var init = function(){
	$('#submit').click(function(e){
		e.preventDefault();
		setPlayer();
	})
}

$(document).ready(function(){
	init();
});