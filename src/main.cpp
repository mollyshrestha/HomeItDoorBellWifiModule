#include "common.h"
#include "d1mini_pins_arduino.h"
#include <ESP8266WiFi.h>
#include "SpiffsFunctions.h"
#include "WebServerFunctions.h"
#include "NetworkFunctions.h"
#include "HubFunctions.h"

//needed for library for WifiManager
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "WiFiManager.h"          //https://github.com/tzapu/WiFiManager

#define period      (1000)
static L4  time_now = 0;

#define inputPin  D1_MINI_PIN_D1
int outputPin = D1_MINI_PIN_LED_BUILTIN;

void configModeCallback (WiFiManager *myWiFiManager) 
{
	Serial.println("Entered config mode");
	Serial.println(WiFi.softAPIP());
	//if you used auto generated SSID, print it
	Serial.println(myWiFiManager->getConfigPortalSSID());
}


void setup()
{
	pinMode((U1)inputPin, INPUT);
	pinMode(outputPin, OUTPUT);

	Serial.begin(9600);

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
}

/* Clear saved config after double Reset */
void vd_s_ClearConfig(void)
{
	
}