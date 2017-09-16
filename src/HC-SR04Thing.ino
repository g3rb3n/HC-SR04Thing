#include <Thing.h>
#include <BlinkPattern.h>
#include <HCSR04.h>

#define echoPin D7 // Echo Pin
#define trigPin D8 // Trigger Pin
#define ON 0
#define OFF 1

using namespace g3rb3n;

Thing thing;
HCSR04 sensor(D8, D7);

bool motion = false;

void setup()
{
  Serial.begin(230400);
  Serial.println();

  Serial.println("ClientID:" + thing.clientId());

  pinMode(BUILTIN_LED, OUTPUT);

  thing.onStateChange([](const String& msg){
    digitalWrite(BUILTIN_LED, ON);
    Serial.println(msg);
    digitalWrite(BUILTIN_LED, OFF);
  });

  thing.addSensor(String("sensor/distance/") + thing.clientId(), 1000, [](Value& value){
    digitalWrite(BUILTIN_LED, ON);
    value = sensor.meters();
    digitalWrite(BUILTIN_LED, OFF);
  });

  thing.begin();
}

void loop()
{
  thing.handle();
}
