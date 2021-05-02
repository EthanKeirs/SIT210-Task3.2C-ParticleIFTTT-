int light_Sensor = D7; //assigns integer light_Sensor as digital pin 7
int count = 0;

void setup() 
{
  pinMode(light_Sensor, INPUT); //sets digital pin 7 as input
  
}

void loop() 
{
    int light_Level = digitalRead(light_Sensor); //assigns collected data as integer light_Level
    if (light_Level > 0 & count >= 7200000)
    {
        
        Particle.publish("Terrarium is in sunlight. light_Level is ", String::format("%d", light_Level), PRIVATE); //publishes sorted data to thingspeak
        for (light_Level > 0; count < 7200;)
        {
            delay(1000); //delay for 1 seconds
            count = count + 1;
        }
    }
    else if (count == 7200000)
    {
        Particle.publish("Terrarium has been in sunlight for 2 hours");
        
    }
    else
    {
        Particle.publish("Terrarium is not in sunlight. light_Level is ", String::format("%d", light_Level), PRIVATE); //publishes sorted data to thingspeak
    }
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    