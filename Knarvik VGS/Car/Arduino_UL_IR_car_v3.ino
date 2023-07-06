#include <Servo.h>
Servo leftm;
Servo rightm;
Servo sensor;


// Her definerer vi Pins
  const int trigPin =  A1;
  const int echoPin = A0;
  const int ir =      A2; 



// Her definerer vi variabler
  long distance_ir; //long er en type variabel som kan  variere litt mer og være litt større enn int
  long duration;   // her er tiden Ultralyd singalet bruker til å på å gå frem og tilbake
  long  distance; // med litt matte kan vi bruke det til å regne ut en ca distanse

void setup() {
    leftm.attach(7);
    rightm.attach(6);
    sensor.attach(5);
    
  pinMode(trigPin, OUTPUT); // Her setter vi trigpin som output
  pinMode(echoPin, INPUT); // Setter Echopin som input
  pinMode(ir, INPUT); // Setter ir som input
  Serial.begin(9600); // Starter serial output (trykk ctrl+shift+m for å se verdiene)

}


void loop() {
  // Først resetter vi trigpin sånn at den er clean
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Så setter vi den på 10 microsek
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Her leser vi av echopin, og får ut kor lang tid bølgen tokk i microsek 
  duration = pulseIn(echoPin, HIGH);
  // Kalkulerer avstanden
  distance= duration*0.034/2;
  
  //her leser vi av avstanden til IR sensoren. Den leses analogt av IR pin som er på A0.
  distance_ir = analogRead(ir); // husk å kommenter ut denn linjen eller sett A2 til ground om den ikke er i bruk
  // Her printer vi alle veridene inn i serial, sånn at vi kan se på de med serial monitor
  Serial.print("Distance ultra: ");
  Serial.print(distance);
  Serial.print(" Distance IR: ");
  Serial.println(distance_ir);



  
  // om den ikke leser på ultra så står den stille
  if(Serial.available() < 0){  //her sjekker vi om vi får signal, om ikke signal så står den i ro
    
  
   //her nede har vi noen If/else greier med ultra
        if (distance < 25 ) {  //om den er nærmere enn 25cm så vill den rygge her
        leftm.write(0);
        rightm.write(180);
        delay(100);}
        
        else {
        leftm.write(90);  // om den ikke er nærmere enn 25cm så vill den stå i ro
        rightm.write(90);
        delay(100);}
         }
        
  else {
      leftm.write(90);  // om den måler mindre enn 130 så stor den i ro
      rightm.write(90);
      delay(100);}
  
  
  
  //her nede har vi noen If/else greier med IR
    if (distance_ir > 130 ){  //om den måler større en 130 på ir så gå den bakover
    leftm.write(0);
    rightm.write(180);
    delay(100);
    }
    
    else {
    leftm.write(90);  // om den måler mindre enn 130 så stor den i ro
    rightm.write(90);
    delay(100);}
}




