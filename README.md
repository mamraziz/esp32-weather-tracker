<img width="1280" height="720" alt="weather" src="https://github.com/user-attachments/assets/b2c885f7-386d-4aed-8721-aac7f418c1c1" />
<img width="1112" height="524" alt="image" src="https://github.com/user-attachments/assets/17dd40b4-cb30-4474-97b3-dcdb6a152f76" />

This project uses an esp32 dev board with dht11 relative temp and humidity sensors with an ldr sensor to add more data for the demonstration. 
Edit the esp32 code to change wifi credentials to be able to connect to the sever running under the same network

the esp32 sends information from the sensors every 30 seconds to the server that saves it to an sqllite database
For this demonstration I used graphana to show the data I gathered from keeping the esp32 on for 2 hours
