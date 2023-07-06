#include <Servo.h> // tar med servo biblioteket
Servo leftm;  // her kaller eg venstre motor for leftm og høyre for rightm
Servo rightm;
char data = 0;  // setter variabelen char til 0 for å klarere den


void setup() {
  leftm.attach(7);  // setter at venstre motor er på pinne 7
  rightm.attach(6); // setter at venstre motor er på pinne 6

Serial.begin(9600); // Starter serial output (trykk ctrl+shift+m for å se verdiene)
}


void loop() {

  {
   if(Serial.available() > 0)  //her sjekker vi om vi får signal, om ikke signal så står den i ro
   {
     data = Serial.read();  //her leser vi av data ifra serial monitor, som er tx og rx pins
     Serial.print(data);   //vi skriver og ned dataen i serial monitor
     Serial.print("\n");
     
         if(data == 'F'){   //om vi mottar en F fra appen så går den fremover
          leftm.write(180);
          rightm.write(0);
      delay(50);}
      
         else if(data == 'B'){  // B er bakover. Viktig å ha en liten delay, om ikke hakker den bare
          leftm.write(0);
          rightm.write(180);
           delay(50);}
      
       else if(data == 'S'){  // S står den stille
          leftm.write(90);
          rightm.write(90);}

       else if(data == 'L'){ //Venstre
          leftm.write(180);
          rightm.write(180);
           delay(50);}

          else if(data == 'R'){  //høyre
          leftm.write(0);
          rightm.write(0);
           delay(50);}
          
   }

   else {  leftm.write(90);
          rightm.write(90);} // her er else til den på toppen, ingen signal og bilen står stille

}
}



