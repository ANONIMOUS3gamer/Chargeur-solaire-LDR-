#include <Servo.h> // Bibliothèque pour servomoteur
//#include <LowPower.h>

	
	Servo horizontal; // Servomoteur horizontal
	int servoh = 90;   
	

	int servohLimitHigh = 180;
	int servohLimitLow = 0;
	

	
	Servo vertical;   // Servomoteur vertical
	int servov = 90;    
	

	int servovLimitHigh = 180;
	int servovLimitLow = 70;
	

	

	//Connexions de broches LDR

	int ldrhg = 2; //LDR en haut à gauche 
	int ldrhd = 3; //LDR en haut à droite 
	int ldrbg = 0; //LDR en bas à gauche
	int ldrbd = 1; //LDR en bas à droite 
  
 
  void setup()
	{
	  Serial.begin(9600);
	  horizontal.attach(9);
	  vertical.attach(10);
	  horizontal.write(180);
	  vertical.write(45);
	  delay(3000);
    
	}
	

	void loop() 
	{
    //for(int i = 0; i < 1; i++) {
     // LowPower.powerSave(SLEEP_8S, ADC_OFF, BOD_OFF, TIMER2_OFF);
   // }
    //for(int i = 0; i < 100; i++){
    int hg = analogRead(ldrhg); // en haut à gauche
	  int hd = analogRead(ldrhd); // en haut à droite
	  int bg = analogRead(ldrbg); // en bas à gauche
	  int bd = analogRead(ldrbd); // en bas à droite
	  
    hg = map(hg,440,22,0,20000);//Permet de calculer la différence de luminosité 
    hd = map(hd,400,20,0,20000);
	  bg = map(bg,415,20,0,20000);
	  bd = map(bd,440,18,0,20000);

   if (hg<0)
   {
     hg = 0;
  }
    if (hd<0)
   {
     hd = 0;
   }
    if (bg<0)
   {
     bg = 0;
   }
    if (bd<0)
   {
     bd = 0;
   }

	  
	  
	  int vmh = (hg + hd) / 2; // Valeur moyenne Haut
	  int vmb = (bg + bd) / 2; // Valeur moyenne bas
	  int vmg = (hg + bg) / 2; // Valeur moyenne gauche
	  int vmd = (hd + bd) / 2; // Valeur moyenne droite
	 
	  
	  Serial.print(hg);
	  Serial.print(" ");
	  Serial.print(hd);
	  Serial.print(" ");
	  Serial.print(bg);
	  Serial.print(" ");
	  Serial.print(bd);
	  Serial.println(" ");
    Serial.println(servoh);
    Serial.println(" ");
    Serial.println(servov);
    Serial.println(" ");
	  

     
	 
{
	  if (vmh > vmb)
	  {
      
	    servov = ++servov;
	     if (servov > servovLimitHigh) 
	     { 
	      servov = servovLimitHigh;
	     }
	  }
	  else if (vmh < vmb)
	  {
      
	    servov= --servov;
	    if (servov < servovLimitLow)
	  {
	    servov = servovLimitLow;
	  }
	  }
	  vertical.write(servov);
	  }
	  
	 
	 {
	  if (vmg < vmd)
	  {
     servoh = --servoh;
	    if (servoh < servohLimitLow)
	    {
	    servoh = servohLimitLow;
	    
	  }
    }
	  else if (vmg > vmd)
	  {
       servoh = ++servoh;
	     if (servoh > servohLimitHigh)
	     {
	     servoh = servohLimitHigh;
	     }
      
	    
	  }

	  horizontal.write(servoh);
	  }
	  
    if (hg < 40 && hd < 40 && bg < 40 && bd < 40)
       servoh = 90;
    if (hg < 40 && hd < 40 && bg < 40 && bd < 40)
       servov = 90;
    
    //}
      // delay(1000);
      }
	

	

 



	
