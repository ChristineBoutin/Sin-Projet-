#include <rgb_lcd.h>//Ajout de la bibliothèque du lcd
#include <Wire.h> //Ajout de la bibliothèque i2c pour utiliser le lcd
rgb_lcd lcd;  //Constructeur rgb_lcd pour l'objet lcd

 char valeur ;// Variable servant à récupérer  les données reçues
 
 
void setup() //Initialisations
{
    lcd.begin(16, 2); //Initialisation du lcd de 16 colonnes et 2 lignes
    Serial.begin(9600); // initialisation série
    
 }
 

void loop() //Programme principal
 {  
   lcd.setRGB(0,0,0); // rétro éclairage eteint 
     if (Serial.available()>0);// Si des données sont disponibles
     {
        valeur = Serial.read(); // On les récupère
         if(valeur == 'g') // si variable = g
          {
           Serial.println(valeur); // afficher la variable 
           lcd.setRGB(0,255,0);// 
           delay(1000);
          }  
              
         if( valeur == 'r')
          {
            Serial.println(valeur);
            lcd.setRGB(255,0,0);         
            delay(1000);
          }
           
          if( valeur == 'b')
          {
            Serial.println(valeur);
            lcd.setRGB(0,0,255);
            delay(1000);
          }  
      } 

 } 
 
 
 
 
 
