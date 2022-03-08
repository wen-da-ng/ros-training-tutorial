/*To install rosserial library, go to "Tools --> Manage Libraries --> type in 'rosserial' "*/

#include <ros.h>                //ROS library can be found in Documents/Arduino/libraries/Rosserial_Arduino_Library/src/ros.h
#include <std_msgs/Int8.h>

ros::NodeHandle  nh;

void led( const std_msgs::Int8& LED_msg){
  if(LED_msg.data == 2){
    digitalWrite(8, HIGH); 
    delay(100);                  
    digitalWrite(8, LOW);    
    delay(100); 
  }else if(LED_msg.data == 0){
    digitalWrite(9, HIGH); 
    delay(100);                  
    digitalWrite(9, LOW);    
    delay(100); 
  }else if(LED_msg.data == 1){
    digitalWrite(10, HIGH); 
    delay(100);                  
    digitalWrite(10, LOW);    
    delay(100); 
  }else{
    digitalWrite(8, LOW);   
    digitalWrite(9, LOW);   
    digitalWrite(10, LOW);   
  }
  
}

ros::Subscriber<std_msgs::Int8> sub("obj_location", &led );

void setup()
{ 
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
