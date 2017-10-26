/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */

#include <ros.h>
#include <std_msgs/String.h>
#include <AltSoftSerial.h>

ros::NodeHandle  nh;
AltSoftSerial altSerial;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "C'est nous!";

void setup()
{
  nh.initNode();
  nh.advertise(chatter);
  Serial.begin(9600);
  altSerial.begin(57600);
}

/*void loop()
{
  str_msg.data = hello;
  chatter.publish( &str_msg );
  altSerial.print(hello);
  nh.spinOnce();
  delay(1000);
}*/
void loop() {
  char c;

  if (Serial.available()) {
    c = Serial.read();
    altSerial.print(c);
  }
  if (altSerial.available()) {
    c = altSerial.read();
    Serial.print(c);
  }
}
