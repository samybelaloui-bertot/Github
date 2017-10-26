/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <AltSoftSerial.h>
#include <std_msgs/Float64.h>
const int sharpPin = 2;
const int ledPin =  13;      // the number of the LED pin
int sharpState = 0;
ros::NodeHandle  nh;
AltSoftSerial altSerial;
std_msgs::Float64 str_msg;
std_msgs::Float64 str_msg2;
String var;

void messageCb( const std_msgs::String& msg){
  var = msg.data;
  altSerial.println(var);  
}
ros::Subscriber<std_msgs::String> s("scanInfo", &messageCb);
ros::Publisher stop_left("/left_controller/command", &str_msg);
ros::Publisher stop_right("/right_controller/command", &str_msg2);

//ros::
void setup()
{
  nh.initNode();
  nh.subscribe(s);
  nh.advertise(stop_left);
  nh.advertise(stop_right);
  //Serial.begin(9600);
  altSerial.begin(57600);
  pinMode(ledPin,OUTPUT);
  pinMode(sharpPin,INPUT);
}

void loop()
{
  sharpState  = digitalRead(sharpPin);
  nh.spinOnce();


  if (sharpState == LOW) {
   str_msg.data = -512.0;
   str_msg2.data = 512.0;
   stop_left.publish(&str_msg);
   stop_right.publish(&str_msg2);
   altSerial.println("obstacle detecte");
   delay(250);
   str_msg.data = 0.0;
   str_msg2.data = 0.0;
   stop_left.publish(&str_msg);
   stop_right.publish(&str_msg2);
  } 
  else {
  }
  delay(100);
   
}
/*void loop() {
  String c;

  if (Serial.available()) {
    c = Serial.read();
    altSerial.print(c);
  }
  if (altSerial.available()) {
    c = altSerial.read();
    Serial.print(c);
  }
}*/
