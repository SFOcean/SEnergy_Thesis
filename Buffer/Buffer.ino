
int analogBuffer[400];

void setup() {
 
  Serial.begin(9600);
}


void loop() {
  for (int i=0; i<400; i++)
  {
    analogBuffer[i]=analogRead(A0);
    }
    for (int i=0; i<400; i++)
  {
    Serial.println(analogBuffer[i]);
  }
}
