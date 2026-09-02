This project uses an esp32 dev board with dht11 relative temp and humidity sensors with an ldr sensor to add more data for the demonstration. 
Edit the esp32 code to change wifi credentials to be able to connect to the sever running under the same network

the esp32 sends information from the sensors every 30 seconds to the server that saves it to an sqllite database
For this demonstration I used graphana to show the data I gathered from keeping the esp32 on for 2 hours
