#include "patterns.h"
#include "transitions.h"
#include "animations.h"
#include "scroll_text.h"
#include <Wire.h>
//#include <random>
#include <iostream>
#include <Adafruit_Protomatter.h>
#include "LittleFS.h" 
#include <VFS.h>

int randNumber = 0;
// Use FeatherWing pinout
  uint8_t rgbPins[]  = {8, 7, 9, 11, 10, 12};
  uint8_t addrPins[] = {25, 24, 29, 28};
  uint8_t clockPin   = 13;
  uint8_t latchPin   = 1;
  uint8_t oePin      = 0;

// Create a 32-pixel tall, 64 pixel wide matrix with the defined pins
Adafruit_Protomatter matrix(
  64,          // Width of matrix (or matrix chain) in pixels
  4,           // Bit depth, 1-6
  1, rgbPins,  // # of matrix chains, array of 6 RGB pins for each
  3, addrPins, // # of address pins (height is inferred), array of pins
  clockPin, latchPin, oePin, // Other matrix control pins
  true);      // Double-buffering here (see "doublebuffer" example)


//Variables used for the old drawing style and animations
uint8_t R = 0;
uint8_t G = 0;
uint8_t B = 0;

//Display State/Type Things
double animType = 0;
double fancyAnim = 0;
double dispType = 7; //which display type to start on/display when cycling
double dispTypePrev = 0;
String messageTypeString = String();
double messageType = 0;
boolean firstLoopDone = false;
double currentTime = 0;
int clearType = 0;
int draw_type = 0;
int randSelect = 0;
//----------------------------\\

//Both used to display Alliance Partners, one String per board
String ap1d = String();
String ap2d = String();
String scrolltext = String();
double stlength = 0;
int sliderSelect = 0;
int reps = 0;
int sliderRand = 0;
int runs = 0;
int declareRuns = 0;
//----------------------------\\

//Serial/I2C Stuff
int str_len = 0;
int length = 0;
//----------------------------\\

//How long each phase lasts
double dlength = 4000;
int colorSelect = 0;
int prideSelect = 0;
//----------------------------\\

//Scrolltext (st) stuff 
int stRuns = 0;

//----------------------------\\

int randomNumber1 = 3;
int randomNumber2 = 3;
int seed = 0;

int printStep = 0;


void setup() {

  ap1d = "2025";  //These are the "WE <3 [Team number]" drawings. Make ap1d and ap2d equal to the alliance partner numbers.
  ap2d = "FRC"; //Here is a list of generic text in place of team numbers, for use during events like outreach: PIT, FRC, YOU, 957, BEES, etc. Must be 2-4 characters
  
  LittleFS.begin();
  
  //reading random file:
  File file = LittleFS.open("/rand.txt", "r");
  if(!file){
    randomSeed(seed);
  }else{
    while(file.available()){
      String fromFile = file.readString();
      seed = fromFile.toInt();
    }
  }
  randomSeed(seed);  //sets the seed used for randomization to "seed" (the number in the file)
  file.close();
  delay(100);

  //writing random file
  File writeFile = LittleFS.open("/rand.txt", "w");
  writeFile.print(seed + 1); 
  writeFile.close();
  delay(100);
  //LittleFS.end(); 

  // Initialize matrix...
  ProtomatterStatus status = matrix.begin();
  //Serial.print("Protomatter begin() status: ");
  //Serial.println((int)status);
  if(status != PROTOMATTER_OK) {
    // DO NOT CONTINUE if matrix setup encountered an error.
    for(;;);
  }
  Serial.begin(4800);
  
 

  //Wire.begin();
 
 
}

void holdup(int del_len){
  currentTime = millis();
  while((millis()-currentTime) < del_len){} //this runs a While loop with nothing in it, essentially just doing nothing until it reaches the specified time
}

void loop() {
  Serial.println("Printing!!!!");
  Serial.println(seed);
  Serial.println("printStep:");
  Serial.println(printStep);
  if(dispType == 1){
    //sliderSelect = random(1, 3);
    sliderRand = random(1, 12);
    if(sliderRand == 3){
      sliderSelect = 2;
    }else{
     sliderSelect = 1;
    }
  
    matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0)); //draws a black rectangle, making the screen appear blank
    matrix.show();
    holdup(500);
    for(uint8_t x=0; x<65; x++){
      matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
      
      drawSlider(sliderSelect, -32+x, 0);
      matrix.show();
      holdup(5);
    }
    holdup(500);
    reps = random(0, 5); //shows the slider a random amount of times
    for(uint8_t x=0; x<reps; x++){
      for(uint8_t x=0; x<33; x++){
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
        
        drawSlider(sliderSelect, 32-x, 0);
        matrix.show();
        holdup(5);
      }
      holdup(500);
      for(uint8_t x=0; x<33; x++){
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
        
        drawSlider(sliderSelect, x, 0);
        matrix.show();
        holdup(5);
      }
      holdup(500);
    }
    for(uint8_t x=0; x<95; x++){
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));

        drawSlider(sliderSelect, 32-x, 0);
        matrix.show();
        holdup(5);
    }
  }
  
  //Animation type (leave 0 for random), message type (2 for "WE LOVE", 3 for "SWARM")
  if(dispType == 2){
    randSelect = random(1, 3);
    if(randSelect == 1){
      draw_we_love_animated();
      holdup(dlength);
    }else{
      drawScreen(0, 2); 
      holdup(dlength);
    }
  }
  if(dispType == 3){
    randSelect = random(1, 3);
    if(randSelect == 1){
      drawScreen(0, 3); 
      //draw_swarm_animated();
      holdup(dlength);
    }else{
      drawScreen(0, 3); 
      holdup(dlength);
    }
  }

  if(dispType == 4){
    draw_we_love_animated();
    holdup(dlength);
  }

  if(dispType == 5){
    draw_swarm_animated();
    holdup(dlength);
  }

  if(dispType == 6){
    drawScrolltext("HEY, THERE");
    holdup(1000);
  }

  if(dispType == 7){
    //drawSponsors();
    //drawDeclarationFull(); //best function
    //std::uniform_real_distribution<double> dist(1, 5);   //generates a random number 1-5 according to the uniform real distribution
    //randNumber = dist(mt);
    randomNumber1 = random(1, 7);
    Serial.println(randNumber);
    if (randNumber == 1){
      drawJelly();
    }
    if (randNumber == 2){
      drawBee();
    }
    if (randNumber == 3){
      drawDeepSea();
    }
    if (randNumber == 4){
      draw957();
    }
    if (randNumber == 5){
      draw957Pride();
    }
    if (randNumber == 6){
      drawShallowSea();
    }
    holdup(8000); 
    /*drawFirework();
    holdup(10);
    drawFirework();
    holdup(10);
    drawFirework();
    holdup(10);
    drawFirework();
    holdup(10);
    drawFirework(); */
  }

    if(dispType == 8){
      randNumber = random(1,100);
    if (randNumber == 1){
      drawDeclarationFull(); //This function gives a 1% chance of showing the entire Decleration of Independence in scrolltext. This is the best function in this program.
    }else{
      randNumber = random (1,3);
      if (randNumber == 1){
        drawSponsors(); //This gives a 33% chance of showing our current sponsors in scrolltext. This is done to prevent the entire thing from scrolling every loop. 
      }
    }
    holdup(1000);
  }
  

  if(dispType != 1){
    fancyAnim = random(1, 6);
    if(fancyAnim == 1){
      //clear_screen(255, 255, 255, 3, dispType);
      clear_screen(0, 0, 0, 5, dispType);
    }else{
      clear_screen(0, 0, 0, 5, dispType);
    } 
  }

  //ln("");
  //Serial.println("Before");
  //Serial.println("dispType");
  //Serial.println(dispType);
  //Serial.println("dispTypePrev");
  //Serial.println(dispTypePrev);
  dispTypePrev = dispType;
  
  if(dispTypePrev == 1){
    dispType = 2;
  }
  if(dispTypePrev == 2){
    dispType = 3;
  }
  if(dispTypePrev == 3){
    dispType = 6;
  }
  if(dispTypePrev == 4){
    dispType = 2;
  }
  if(dispTypePrev == 5){
    dispType = 1;
  }
  if(dispTypePrev == 6){
    dispType = 7;
  }
    if(dispTypePrev == 7){
    dispType = 8;
  }
  if(dispTypePrev == 8){
    dispType = 1;
  }
  //Serial.println("");
  //Serial.println("After");
  //Serial.println("dispType");
  //Serial.println(dispType);
  //Serial.println("dispTypePrev");
  //Serial.println(dispTypePrev);

}