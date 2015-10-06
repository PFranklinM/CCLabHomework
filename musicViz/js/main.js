//post on blog and finish project by Monday at midnight

//if the parsons server isnt working try a different host. Ask Umi or Charles for help if need be
//AWS webserver

var apiKey = '14117b9d752d3049bf97a092125becc7';

var counter = 0;

$(document).ready(function () {

  var audioCtx = new (window.AudioContext || window.webkitAudioContext)();
  var audioElement1 = document.getElementById('audioElement1');
  var audioElement2 = document.getElementById('audioElement2');
  var audioElement3 = document.getElementById('audioElement3');
  var audioElement4 = document.getElementById('audioElement4');
  var audioElement5 = document.getElementById('audioElement5');
  var audioElement6 = document.getElementById('audioElement6');


  var audioSrc1 = audioCtx.createMediaElementSource(audioElement1);
  var audioSrc2 = audioCtx.createMediaElementSource(audioElement2);
  var audioSrc3 = audioCtx.createMediaElementSource(audioElement3);
  var audioSrc4 = audioCtx.createMediaElementSource(audioElement4);
  var audioSrc5 = audioCtx.createMediaElementSource(audioElement5);
  var audioSrc6 = audioCtx.createMediaElementSource(audioElement6);

  var analyser = audioCtx.createAnalyser();

  //Bind the analyser to the audio
  audioSrc1.connect(analyser);
  audioSrc1.connect(audioCtx.destination);

  audioSrc2.connect(analyser);
  audioSrc2.connect(audioCtx.destination);

  audioSrc3.connect(analyser);
  audioSrc3.connect(audioCtx.destination);

  audioSrc4.connect(analyser);
  audioSrc4.connect(audioCtx.destination);

  audioSrc5.connect(analyser);
  audioSrc5.connect(audioCtx.destination);

  audioSrc6.connect(analyser);
  audioSrc6.connect(audioCtx.destination);

  
  //The dimensions for the bars
  var songData = new Uint8Array(200);

  var svgHeight = '265';
  var svgWidth = '1230';
  var barPadding = '0.5';

  function createSvg(parent, height, width) {
    return d3.select(parent).append('svg').attr('height', height).attr('width', width);
  }

  var svg = createSvg('body', svgHeight, svgWidth);

  //Create a D3 chart
  svg.selectAll('rect')
     .data(songData)
     .enter()
     .append('rect')
     .attr('x', function (d, i) {
        return i * (svgWidth / songData.length);
     })
     .attr('width', svgWidth / songData.length - barPadding);

  //Loop and update the chart with song data
  function renderChart() {

     requestAnimationFrame(renderChart);

     //Copy song data to the songData array
     analyser.getByteFrequencyData(songData);

     // Update d3 chart with new data.
     svg.selectAll('rect')
        .data(songData)
        .attr('y', function(d) {
           return svgHeight - d;
        })
        .attr('height', function(d) {
           return d;
        })
        .attr('fill', function(d) {
           return 'rgb(0, 0, ' + d + ')';
        });
  }

  // Run the loop
  renderChart();

});

var loadArtist = function(response){

  console.log("response = " + JSON.stringify(response));

for (i = 0; i < response.data.length; i++) {

  var artistNames = response.data[i].name;

  // var names = artistNames[i];

  $('#relatedArtists').append(artistNames + " ~ ");


  console.log(artistNames);

  }

  $('.buttonP').click(function(e){
    e.preventDefault();
    $('#relatedArtists').text("Related Artists: ");
    $('#currentPlay').text("Currently Playing: ");
    counter = 0;
  })

}

var getArtist1 = function(){
  var URL1 = 'http://api.musicgraph.com/api/v2/artist/e211c27d-a6b5-11e0-b446-00251188dd67/similar?api_key=14117b9d752d3049bf97a092125becc7';

  $.ajax({
    url : URL1,
    dataType : 'json',
    success : function(response){
      loadArtist(response);
    }
  });
}

var getArtist2 = function(){
  var URL2 = 'http://api.musicgraph.com/api/v2/artist/e4a49f71-a6b5-11e0-b446-00251188dd67/similar?api_key=14117b9d752d3049bf97a092125becc7';

  $.ajax({
    url : URL2,
    dataType : 'json',
    success : function(response){
      loadArtist(response);
    }
  });
}

var getArtist3 = function(){
  var URL3 = 'http://api.musicgraph.com/api/v2/artist/3d2470dc-5806-d847-b45a-243d4dbb60c9/similar?api_key=14117b9d752d3049bf97a092125becc7';

  $.ajax({
    url : URL3,
    dataType : 'json',
    success : function(response){
      loadArtist(response);
    }
  });
}

var getArtist4 = function(){
  var URL4 = 'http://api.musicgraph.com/api/v2/artist/f2285de4-a6b5-11e0-b446-00251188dd67/similar?api_key=14117b9d752d3049bf97a092125becc7';

  $.ajax({
    url : URL4,
    dataType : 'json',
    success : function(response){
      loadArtist(response);
    }
  });
}

var getArtist5 = function(){
  var URL5 = 'http://api.musicgraph.com/api/v2/artist/374f7900-1c52-043e-8100-dfec506bb218/similar?api_key=14117b9d752d3049bf97a092125becc7';

  $.ajax({
    url : URL5,
    dataType : 'json',
    success : function(response){
      loadArtist(response);
    }
  });
}

var getArtist6 = function(){
  var URL6 = 'http://api.musicgraph.com/api/v2/artist/eb985123-a6b5-11e0-b446-00251188dd67/similar?api_key=14117b9d752d3049bf97a092125becc7';

  $.ajax({
    url : URL6,
    dataType : 'json',
    success : function(response){
      loadArtist(response);
    }
  });
}

var init = function(){
  
  $('#button1').click(function(e){
      e.preventDefault();
      if(counter < 1){
      getArtist1();
      counter++;
    }
      $('#currentPlay').text('Currently Playing: The Who - "The Seeker"');
    })

  $('#button2').click(function(e){
      e.preventDefault();
      if(counter < 1){
      getArtist2();
      counter++;
    }
      $('#currentPlay').text('Currently Playing: Van Halen - "Runnin With The Devil"');
    })

  $('#button3').click(function(e){
      e.preventDefault();
      if(counter < 1){
      getArtist3();
      counter++;
    }
      $('#currentPlay').text('Currently Playing: Childish Gambino - "You See Me"');
    })

  $('#button4').click(function(e){
      e.preventDefault();
      if(counter < 1){
      getArtist4();
      counter++;
    }
      $('#currentPlay').text('Currently Playing: Anamanaguchi - "Meow"');
    })

  $('#button5').click(function(e){
      e.preventDefault();
      if(counter < 1){
      getArtist5();
      counter++;
    }
      $('#currentPlay').text('Currently Playing: Bag Raiders - "Shooting Stars"');
    })

  $('#button6').click(function(e){
      e.preventDefault();
      if(counter < 1){
      getArtist6();
      counter++;
    }
      $('#currentPlay').text('Currently Playing: Little Dragon - "Klapp Klapp"');
    })

}

$(document).ready(function(){
  init();
});



