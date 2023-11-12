#include "patterns.h"
#include "transitions.h"
#include "animations.h"
#include "scroll_text.h"
#include <Wire.h>
#include <Adafruit_Protomatter.h>

//Set up pins correctly
uint8_t rgbPins[]  = {2, 3, 4, 5, 6, 7};
uint8_t addrPins[] = {A0, A1, A2, A3};
uint8_t clockPin   = 8;
uint8_t latchPin   = 10;
uint8_t oePin      = 9;

Adafruit_Protomatter matrix(
  64,          // Width of matrix (or matrix chain) in pixels
  4,           // Bit depth, 1-6
  1, rgbPins,  // # of matrix chains, array of 6 RGB pins for each
  3, addrPins, // # of address pins (height is inferred), array of pins
  clockPin, latchPin, oePin, // Other matrix control pins
  true);      // No double-buffering here (see "doublebuffer" example)

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

//Scrolltext stuff
int stRuns = 0;

void setup() {

  ap1d = "1359";
  ap2d = "LEB";
  
  Serial.begin(9600);

  // Initialize matrix...
  ProtomatterStatus status = matrix.begin();
  Serial.print("Protomatter begin() status: ");
  Serial.println((int)status);
  if(status != PROTOMATTER_OK) {
    // DO NOT CONTINUE if matrix setup encountered an error.
    for(;;);
  }

  matrix.show();

  //Wire.begin();
 
}

void fun(int del_len){
  currentTime = millis();
  while((millis()-currentTime) < del_len){} //just runs a While loop with nothing in it, essentially just doing nothing until it reaches the specified time
}

void loop() {

  if(dispType == 1){
    //sliderSelect = random(1, 3);
    sliderRand = random(1, 6);
    if(sliderRand == 3){
      sliderSelect = 2;
    }else{
      sliderSelect = 1;
    }
    
    matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
    matrix.show();
    fun(500);
    for(uint8_t x=0; x<65; x++){
      matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
      
      drawSlider(sliderSelect, -32+x, 0);
      matrix.show();
      fun(5);
    }
    fun(500);
    reps = random(0, 5);
    for(uint8_t x=0; x<reps; x++){
      for(uint8_t x=0; x<33; x++){
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
        
        drawSlider(sliderSelect, 32-x, 0);
        matrix.show();
        fun(5);
      }
      fun(500);
      for(uint8_t x=0; x<33; x++){
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
        
        drawSlider(sliderSelect, x, 0);
        matrix.show();
        fun(5);
      }
      fun(500);
    }
    for(uint8_t x=0; x<95; x++){
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));

        drawSlider(sliderSelect, 32-x, 0);
        matrix.show();
        fun(5);
    }
  }
  
  //Animation type (leave 0 for random), message type (2 for "WE LOVE", 3 for "SWARM"
  if(dispType == 2){
    randSelect = random(1, 3);
    if(randSelect == 1){
      draw_we_love_animated();
      fun(dlength);
    }else{
      drawScreen(0, 2); 
      fun(dlength);
    }
  }
  if(dispType == 3){
    randSelect = random(1, 3);
    if(randSelect == 1){
      drawScreen(0, 3); 
      //draw_swarm_animated();
      fun(dlength);
    }else{
      drawScreen(0, 3); 
      fun(dlength);
    }
  }

  if(dispType == 4){
    draw_we_love_animated();
    fun(dlength);
  }

  if(dispType == 5){
    draw_swarm_animated();
    fun(dlength);
  }

  if(dispType == 6){
    drawScrolltext("HEY, THERE");
    fun(1000);
  }

  if(dispType == 7){
    //drawSponsors();
    //drawDeclarationFull();
    fun(1000);
  }

    if(dispType == 8){
    drawSponsors();
    //drawDeclaration();
    fun(1000);
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

  Serial.println("");
  Serial.println("Before");
  Serial.println("dispType");
  Serial.println(dispType);
  Serial.println("dispTypePrev");
  Serial.println(dispTypePrev);
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
    dispType = 1;
  }
    if(dispTypePrev == 7){
    dispType = 8;
  }
  if(dispTypePrev == 8){
    dispType = 1;
  }
  Serial.println("");
  Serial.println("After");
  Serial.println("dispType");
  Serial.println(dispType);
  Serial.println("dispTypePrev");
  Serial.println(dispTypePrev);

}
