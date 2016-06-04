# ESPHue
Controlling the Philips Hue lighting system using just an ESP8266 Wifi controller.

To start:

- Get your Philips Hue bridge IP address. https://www.meethue.com/api/nupnp can help you with this. 
You need this IP address to create a new username for the ESP. 
You also need this IP address to tell the ESP where to send the commands to by replacing BRIDGE_IP in the code by the IP address of your bridge.
- Connect to the router on to which your Philips Hue Bridge is connected. Browse to http://BRIDGE_IP/debug/clip.html
In the "URL:" field you enter: /api/
In the "Message Body:" field you enter: {"devicetype":"ESPHue"}
Click on the "POST" button.
In the "Command Response:" field you should now see: "link button not pressed"
- Go to your physical Philips Hue bridge and press the link button on the top.
- Now again, click on the "POST" button in your browser.
In the the "Command Response:" field you should now see: "success":{"username":"USERNAME"}
Copy this username and replace USERNAME in the code by the username you obtained.

- Replace SSID by the ssid of the router the Philips Hue bridge is connected to.
- Replace PASSWORD by the password of the router the Philips Hue bridge is connected to.

Upload the sketch to your ESP8266 and it should work.

Until now, it is only to do PUT commands by this library. GET commands are not received yet from the Hue bridge. This means that the get commands in this library will refer to the variable states used by this library.

The commands supported by this library are:

void setDebug( bool _debug );

void setupIP( char* _bridge_ip );

void setupUser( char* _bridge_user );

void setup( char* _bridge_ip, char* _bridge_user );
		
void xy( float _x, float _y );

void xySet( uint8_t _light_id, float _x, float _y );

void on();

void on( bool _on );

void onSet( uint8_t _light_id, bool _on );

void onSet( uint8_t _light_id );

bool onGet();

void off();

void offSet( uint8_t _light_id );

void hue( uint16_t _hue );

void hueSet( uint8_t _light_id, uint16_t _hue );

uint16_t hueGet();

void ct( uint16_t _ct );

void ctSet( uint8_t _light_id, uint16_t _ct );

uint16_t ctGet();

void bri( uint8_t _bri );

void briSet( uint8_t _light_id, uint8_t _bri );

uint8_t briGet();

void sat( uint8_t _sat );

void satSet( uint8_t _light_id, uint8_t _sat );

uint8_t satGet();

void HSB( uint16_t _hue, uint8_t _sat, uint8_t _bri );

void HSBSet( uint8_t _light_id, uint16_t _hue, uint8_t _sat, uint8_t _bri );

void HSBOnSet( uint8_t _light_id, uint16_t _hue, uint8_t _sat, uint8_t _bri, bool _on );

void CB( uint16_t _ct, uint8_t _bri );

void CBSet( uint8_t _light_id, uint16_t _ct, uint8_t _bri );

bool set( uint8_t _light_id );

bool set( uint8_t _light_id, String _command );
