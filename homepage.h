// To create literal strings stored in flash memory enclose your HTML code between 
// F(R"=====( HTML code here )=====");
// If you have 1 reading then you probably have 2 literal strings
// If you have 2 readings then you probably have 3 literal strings etc.

String homePagePart1 = F(R"=====(<!DOCTYPE html>
<html lang="en" > <!-- Needed for Screenreaders !-->
<head>
<!-- UTF-8 character set covers most characters in the world -->
  <meta charset="utf-8">
  <!-- Make page respond to screen size !-->
  <meta name="viewport" content="width=device-width, initial-scale=1, viewport-fit=cover">
 
<!--Include a Title. Used by Search Engines -->
<title>Smart home Doorbell</title>
<style>
   
   <!--choose good contrast between background and foreground colours -->
   body {
      }
	.flex-Container{
        display: flex;
        flex-direction: column;
        background-color: beige;
        align-items: center;
        border-radius: 10px;
      }
     body {       
        background-color: #332421;
      } 
    h1{
    font: bold;
    font-size: 40px;
    font-family: Arial;
    color: black;
	text-align: center;
  }
  p{
    font-size: 25px;
    font-family: Arial;
    color: black;
	text-align: center;
   }  
  th, td {
    font-size: 25px;
    padding: 8px;
    text-align: left;
    border-bottom: 1px solid #ddd;
}
</style>
 <script>
    function fetchTemperature() {
      fetch('/temperature') // Call the ESP32 server
        .then(response => response.text()) // Convert response to text
        .then(temp => {
          console.log("Temperature:", temp); // Debugging output in console
          document.getElementById("tempValue").innerText = temp; // Update webpage dynamically
        })
        .catch(error => console.error('Error fetching temperature:', error)); // Handle errors
    }
    function fetchHumidity() {
      fetch('/humidity') // Call the ESP32 server
        .then(response => response.text()) // Convert response to text
        .then(humid => {
          console.log("Humidity:", humid); // Debugging output in console
          document.getElementById("humidValue").innerText = humid; // Update webpage dynamically
        })
        .catch(error => console.error('Error fetching humidity:', error)); // Handle errors
    }
    function doorStatus() {
      fetch('/doorStatus') // Call the ESP32 server
      .then(response => response.text()) // Convert response to text
        .then(doorstatus => {
          console.log(doorstatus); // Debugging output in console
          document.getElementById("doorLock").innerText = doorstatus; // Update webpage dynamically
        })
        .catch(error => console.error('Error fetching Door Status:', error));
    }

   
    // Fetch temperature/humidity every 1 second
    setInterval(fetchTemperature, 1000);
    setInterval(fetchHumidity, 1000);
    setInterval(doorStatus,1000);

    // Fetch immediately on page load
    window.onload = fetchTemperature;
    window.onload = fetchHumidity;
    window.onload = doorStatus;
  </script>
</head>
	<body>
  <p></p>
		<div class="flex-Container">
		<h1>Smart Home Doorbell</h1>
    </div>
  <p></p>
    <div class="flex-Container">
      <p>Live Camera:</p>
      <iframe width="321" height="241" src="http://10.147.123.92:81/stream" frameborder="0" alt="camera video stream"></iframe>
    </div>
  <p></p>
    <div class="flex-Container">
		<p>Door Status:</p>
    <span id="doorLock">Loading...</span>
    </div>
  <p></p>
    <div class="flex-Container">
		<table>
        <tr>
          <th>Sensor</th>
          <th>Value</th>
        </tr>
        <tr>
          <td>Temperature</td>
         <td><span id="tempValue">Loading...</span> °C</td>
        </tr>
       <tr>
          <td>Humidity</td>
         <td><span id="humidValue">Loading...</span> %</td>
        </tr>
      </table>
     </div>
  <p></p>
  </body>
</html>)=====");
