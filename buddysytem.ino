// ------------
// Buddy system, publish and subscribe
// ------------

int dot = 500;
int dash = 1500;

int led1 = D6; // Instead of writing D6 over and over again, we'll write led1
// You'll need to wire an LED to this one to see it blink.

int led2 = D7; // Instead of writing D7 over and over again, we'll write led2
// This one is the little blue LED on your board. On the Photon it is next to D7, and on the Core it is next to the USB jack.


void setup() {

  // It's important you do this here, inside the setup() function rather than outside it or in the loop function.

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  Particle.subscribe("Fake_Wave_Event", waveHandler);

}

// Function for turning light and off for specific lengths.
void light(int on, int off) {

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);


  delay(on);


  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);


  delay(off);
}

// Loop publishes events for us to subscirbe and respond to.
void loop() {
    Particle.publish("Fake_Wave_Event", "wave");
    delay(10000);
    Particle.publish("Fake_Wave_Event", "pat");
    delay(10000);
}

void waveHandler(const char *event, const char *data)
{
    if (strcmp(data, "wave") == 0)
    {
        for (int i = 0; i < 3; i++)
        {
            light(dot, dot);
        }
    }
    
    else if (strcmp(data, "pat") == 0)
    {
        for (int i = 0; i < 2; i++)
        {
            light(dash, dash);
        }
    }
}