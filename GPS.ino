 /*
  * File  : DFRobot_SIM7000_MQTT.ino
  * Power : SIM7000 needs 7-12V DC power supply
  * Brief : This example verify MQTT send verification
  *         With initialization completed, we connect to iot.dfrobot.com.cn
  *         Then send data to a topic
  *         Thus we finished the MQTT send verification
  * Note  : If you use Mega please connect PIN8 PIN10 and set PIN_RX = 10
  *         If you select another IOT, please confirm that the IOT is in the whitelist of your NB card
  *         The maximum length of data transmitted each time is 50
  */

#include <DFRobot_SIM7000.h>

//Login website (http://iot.dfrobot.com.cn) to register an account ,fill the following information based on your account
#define serverIP        "iot.dfrobot.com.cn"
#define IOT_CLIENT      "GPS-BUS"
#define IOT_USERNAME    "PMuJ4T4WR"
#define IOT_KEY         "EGu14oVZgz"
#define IOT_TOPIC       "gC0sVTVWg"

#define PIN_TX          7
#define PIN_RX          8
#define PIN_BT          2
#define PIN_SC          4

SoftwareSerial          mySerial(PIN_RX,PIN_TX);
DFRobot_SIM7000         sim7000;

extern unsigned long    timer0_millis;              // millis()
String                  stPosition;
String                  stPositionHold;

void setup(){

    pinMode(PIN_BT, INPUT_PULLUP);
    pinMode(PIN_SC, INPUT);
    
    Serial.begin(115200);
    while(!Serial);
    
    sim7000.begin(mySerial);

    Serial.print("ON .. ");
    sim7000.turnON();                                            //Turn ON SIM7000

    Serial.print("setRate .. ");
    while(1){
        if(sim7000.setBaudRate(19200)){                          //Set SIM7000 baud rate from 115200 to 19200 reduce the baud rate to avoid distortion
            break;
        }else{
            Serial.println("ERR_1");
            delay(1000);
        }
    }

    Serial.print("SIM .. ");
    if(!sim7000.checkSIMStatus()){                                //Check SIM card
        Serial.println("ERR_2");
        while(1);
    }

    Serial.print("setNet .. ");
    while(1){
        if(sim7000.setNetMode(NB)){                              //Set net mod NB-IOT
            break;
        }else{
            Serial.println("ERR_3");
            delay(1000);
        }
    }

    Serial.print("Attaching .. ");
    while(1){
        if(sim7000.attacthService()){                            //Open the connection
            break;
        }else{
            Serial.println("ERR_4");
            delay(1000);
        }
    }

    Serial.print("initPosition .. ");
    while(1){
        if(sim7000.initPos()){
            break;
        }else{
            Serial.println("ERR_5");
            delay(500);
        }
    }
    Serial.println("setup OK!");  
}

void loop(){
    send_position();   
    delay(20000);
}

String read_position(){
    while(1){
      if(sim7000.getPosition()){
        return (String("") + sim7000.getLongitude() + "," + sim7000.getLatitude());
        break;
      }
    }
}
void send_position(){

    Serial.print("IP:");
    Serial.println(serverIP);
    if(!sim7000.openNetwork(TCP,serverIP,1883)){                  //Connect to server
        Serial.println("ERR_6");
        return;
    }
    delay(200);

    Serial.print(" Connect: ");
    Serial.println(IOT_USERNAME);
    if(!sim7000.mqttConnect(IOT_CLIENT,IOT_USERNAME,IOT_KEY)){    //MQTT connect request
        Serial.println("ERR_7");
        return;
    }
    delay(200);
    
    Serial.print("Send: ");
    if(sim7000.mqttPublish(IOT_TOPIC,String("->001号，坐标:") + read_position())){                 //Send data to topic
        Serial.println(" OK");
    }else{
        Serial.println("ERR_8");
        return;
    }
    delay(200); 

    Serial.println("Close ..");
    if(!sim7000.closeNetwork()){                                  //Close connection
        Serial.println("ERR_9");
        return;
    }
    delay(200);
}
