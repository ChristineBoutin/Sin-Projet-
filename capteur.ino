#include <rgb_lcd.h>
#include <Wire.h>
// broche SDA est Analog4 
// pin SCL est Analog5 
// DS1621 a A2, A1 et A0 broches connecté à GND 
rgb_lcd lcd;  //Constructeur rgb_lcd pour l'objet lcd



#define DEV_ID 0x90 >> 1 // adresse requis par wire.h 


void setup () 
{ 
 Serial.begin (9600);  // initiallisation Serie
 Wire.begin (); // initiallisation I2C
 Wire.beginTransmission (DEV_ID); // Connecter à DS1621 (# 0) 
 Wire.write (0xAC); // Accès Configuration registre
 Wire.write (0x02); // Fixée pour la conversion continue 
 Wire.beginTransmission (DEV_ID); // Redémarrer 
 Wire.write (0xEE); // Démarrage de la conversions 
 Wire.endTransmission (); // fin de transmmision 
 lcd.begin(16, 2); //Initialisation du lcd de 16 colonnes et 2 lignes
    
} 


void loop () 
{ 
 int tempC = 0; // variable qui contient la température
 delay(1000); // Donner du temps pour la mesure 
 Wire.beginTransmission (DEV_ID); 
 Wire.write (0xAA); // Température lue 
 Wire.endTransmission (); // fin de transmmision
 Wire.requestFrom (DEV_ID, 1); // Demande un octet de DS1621 
  tempC = Wire.read (); // Obtenir des degrés entiers de lecture
 Serial.println(tempC); //afficher la température en degrés

   if ( tempC < 26 )  // si la temperature est inférieur à 26°C
   {
    lcd.setCursor(0,0); // colone 0 ligne 0
    lcd.print("Temp ="); // afficher "temp =" sur l'afficheur
    lcd.setCursor(8,0); // colone 8 ligne 0
    lcd.print(tempC); // afficher le contenu de la variable
    lcd.setCursor(0,1); // colone 0 ligne 1
    lcd.print("correct"); // afficher "correct" sur l'afficheur
    lcd.setRGB(0,255,0); // changer la couleur de l'afficheur en vert
    delay(1000);// pause de 1 seconde
    lcd.clear(); // nettoyer l'afficheur
   }
  
   else  // sinon faire 
   {
    lcd.setCursor(0,0); // colone 0 ligne 0
    lcd.print("Temp ="); // afficher "temp =" sur l'afficheur
    lcd.setCursor(8,0); // colone 8 ligne 0
    lcd.print(tempC); // afficher le contenu de la variable
    lcd.setCursor(0,1); // colone 0 ligne 1
    lcd.print("attention !"); // afficher "attention !" sur l'afficheur lcd
    lcd.setRGB(255,0,0); // changer la couleur en rouge
    delay(1000);// pause de 1 seconde
    lcd.clear(); // nettoyer l'afficheur
   }
}
