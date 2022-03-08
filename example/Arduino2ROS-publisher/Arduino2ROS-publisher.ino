//This example uses DHT11 sensor and publish the sensor data from Arduino to ROS 

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 2
#define DHTTYPE    DHT11     // DHT 11
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

#include <ros.h>
#include <std_msgs/Float64.h>

ros::NodeHandle  nh;

std_msgs::Float64 float_msg;
ros::Publisher sensor("sensor", &float_msg);


void setup()
{
  nh.initNode();
  nh.advertise(sensor);
  
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  
}

void loop()
{
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  float_msg.data = event.temperature;
  sensor.publish( &float_msg );
  nh.spinOnce();
  delay(1000);
}
