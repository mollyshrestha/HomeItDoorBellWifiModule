#include <ESP8266WiFi.h>
#include "SpiffsFunctions.h"
#include "WebServerFunctions.h"
#include "NetworkFunctions.h"
#include "HubFunctions.h"

//needed for library for WifiManager
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "WiFiManager.h"          //https://github.com/tzapu/WiFiManager

#include <Ticker.h>  //Ticker Library

#include "DoubleResetDetector.h"

// Number of seconds after reset during which a 
// subseqent reset will be considered a double reset.
#define DRD_TIMEOUT 10

// RTC Memory Address for the DoubleResetDetector to use
#define DRD_ADDRESS 0

DoubleResetDetector drd(DRD_TIMEOUT, DRD_ADDRESS);

Ticker timer;


int period = 1000;
unsigned long time_now = 0;

int inputPin = 5;
int outputPin = LED_BUILTIN;


void timerforReset()
{
  digitalWrite(outputPin, !(digitalRead(outputPin)));  //Invert Current State of LED  
}

void configModeCallback (WiFiManager *myWiFiManager) 
{
	Serial.println("Entered config mode");
	Serial.println(WiFi.softAPIP());
	//if you used auto generated SSID, print it
	Serial.println(myWiFiManager->getConfigPortalSSID());
}


void setup()
{
	pinMode(inputPin, INPUT);
	pinMode(outputPin, OUTPUT);

	Serial.begin(9600);

	if (drd.detectDoubleReset()) \
	{
    	Serial.println("Double Reset Detected");
  	} 
	else 
	{
    	Serial.println("No Double Reset Detected");
  	}

	//Initialize Ticker every 0.5s
    timer.attach(1, timerforReset); //Use <strong>attach_ms</strong> if you need time in ms

	//WiFi.disconnect();         /*PBS : Enable if you want to reset Wifi data each time its flash */
	//WiFi.softAPdisconnect();   /*PBS :Enable if you want to reset Wifi data each time its flash */

	/* WiFiManager
	Local intialization. Once its business is done, there is no need to keep it around */
	WiFiManager wifiManager;
	//reset settings - for testing
	//wifiManager.resetSettings();

	//set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
	wifiManager.setAPCallback(configModeCallback);

	//fetches ssid and pass and tries to connect
	//if it does not connect it starts an access point with the specified name
	//here  "AutoConnectAP"
	//and goes into a blocking loop awaiting configuration
	if(!wifiManager.autoConnect()) 
	{
    	Serial.println("failed to connect and hit timeout");
    	//reset and try again, or maybe put it to deep sleep
    	ESP.reset();
    	delay(1000);
	} 

	//if you get here you have connected to the WiFi
	Serial.println("You have connected to Wifi Router");

	startSPIFFS();
	startNetwork();   /*PBS : Network connected using WifiManager */
	startWebServer();

	Serial.println("Started Web Server");

	if (NETWORK_AS_STATION == true)
	{
		Serial.println("Staring the Hub");
		startHub();
	}
}

void loop()
{
	if (NETWORK_AS_AP == true)
	{
		WebSocketServer.loop();
	}
	else if (NETWORK_AS_STATION == true)
	{
		int sensorValue = digitalRead(inputPin);
		websocketClientLoop();
		if (millis() > time_now + period && sensorValue > 0)
		{
			time_now = millis();

			Serial.println(sensorValue);
        
			digitalWrite(outputPin, LOW);
        
			ringBell();
		}
		digitalWrite(outputPin, HIGH);
	}
	WebServer.handleClient();

	// Call the double reset detector loop method every so often,
  	// so that it can recognise when the timeout expires.
  	// You can also call drd.stop() when you wish to no longer
  	// consider the next reset as a double reset.
  	drd.loop();
}