#include <Adafruit_Protomatter.h>

#include <Wire.h>

//Set up pins correctly
uint8_t rgbPins[]  = {2, 3, 4, 5, 6, 7};
uint8_t addrPins[] = {A0, A1, A2, A3};
uint8_t clockPin   = 8;
uint8_t latchPin   = 10;
uint8_t oePin      = 9;

uint8_t R = 0;
uint8_t G = 0;
uint8_t B = 0;

uint8_t anim_del_len = 0;


Adafruit_Protomatter matrix(
  64,          // Width of matrix (or matrix chain) in pixels
  4,           // Bit depth, 1-6
  1, rgbPins,  // # of matrix chains, array of 6 RGB pins for each
  3, addrPins, // # of address pins (height is inferred), array of pins
  clockPin, latchPin, oePin, // Other matrix control pins
  true);      // No double-buffering here (see "doublebuffer" example)

//Display State/Type Things
double animType = 0;
double fancyAnim = 0;

double dispType = 7; //which display type to start on/display when cycling
double dispTypePrev = 0;

String messageTypeString = String();
double messageType = 0;

boolean firstLoopDone = false;

double currentTime = 0;

int cargoType = 0;
int cargoOrientation = 0;

int clearType = 0;
int draw_type = 0;

int randSelect = 0;
//----------------------------\\

//Data/Values
String alliancePartners = String();

//Both used to display Alliance Partners, one String per board
String ap1d = String();
String ap2d = String();

//Inactive right now, but there is a function that would send the current battery voltage over Serial
double voltDouble = 0;
String voltString = String();

char display[4] = "";

String scrolltext = String();
double stlength = 0;

int numberStartX;

int sliderSelect = 0;

int reps = 0;

int sliderRand = 0;

int runs = 0;

int declareRuns = 0;
//----------------------------\\

//Serial/I2C Stuff
int ap1 = 0;
int ap2 = 0;

char allianceArray[] = "0,0";
int str_len = 0;

char *strings[6]; // an array of pointers to the pieces of the above array after strtok()
char *ptr = NULL;

String cargoTypeString = String();
String cargoOrientationString = String();

String I2Cstring = String();

int length = 0;
//----------------------------\\

//How long each phase lasts
double dlength = 4000;
//double dlength = 100;




int colorSelect = 0;
int prideSelect = 0;
//----------------------------\\

//Scrolltext stuff
char scrollArray[] = "0,0";

String ST1 = String();
String ST2 = String();
String ST3 = String();
String ST4 = String();

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

//Delay, but checking for new info while waiting.
//Now, it also 
void fun2(int del_len){

  currentTime = millis();
  
  while((millis()-currentTime) < del_len){

//start of i2c stuff
    if(Wire.available()){
      char c = Wire.read();
      Serial.print(c);
    }

    int x = Wire.read();

    itoa(x, allianceArray, 10);

    Serial.println("Gottem");

      Serial.println("mt: " + messageTypeString);

      if(messageType == 1){
        dispType = 1;
        cargoDisp(1, 1);
      }else if(messageType == 2){
        dispType = 2;
        cargoDisp(2, 1);
      }
   


  }
}

void drawFRC(int x_off, int y_off){
  R = 255;
  G = 0;
  B = 0;
  matrix.drawLine(4+x_off,1+y_off,4+x_off,8+y_off, matrix.color565(R, G, B)); //triangle start
  matrix.drawLine(3+x_off,4+y_off,3+x_off,12+y_off, matrix.color565(R, G, B));
  matrix.drawLine(2+x_off,9+y_off,2+x_off,12+y_off, matrix.color565(R, G, B));
  matrix.drawLine(4+x_off,11+y_off,7+x_off,11+y_off, matrix.color565(R, G, B));
  matrix.drawLine(4+x_off,12+y_off,6+x_off,12+y_off, matrix.color565(R, G, B));
  matrix.drawLine(7+x_off,10+y_off,8+x_off,10+y_off, matrix.color565(R, G, B));
  matrix.drawLine(10+x_off,9+y_off,11+x_off,9+y_off, matrix.color565(R, G, B));
  matrix.drawLine(11+x_off,6+y_off,11+x_off,8+y_off, matrix.color565(R, G, B));
  matrix.drawLine(10+x_off,5+y_off,10+x_off,6+y_off, matrix.color565(R, G, B));
  matrix.drawLine(9+x_off,4+y_off,9+x_off,5+y_off, matrix.color565(R, G, B));
  matrix.drawLine(8+x_off,3+y_off,8+x_off,4+y_off, matrix.color565(R, G, B));
  matrix.drawLine(5+x_off,1+y_off,5+x_off,3+y_off, matrix.color565(R, G, B));
  matrix.drawLine(7+x_off,2+y_off,7+x_off,3+y_off, matrix.color565(R, G, B));
  matrix.drawLine(6+x_off,2+y_off,6+x_off,3+y_off, matrix.color565(R, G, B)); //triangle end
  matrix.drawPixel(4+x_off,0+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(5+x_off,0+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(6+x_off,1+y_off, matrix.color565(R,G,B));
  R = 255;                                           // R doesn't need to be set here but it looks nicer
  G = 255;
  B = 255;
  matrix.drawLine(10+x_off,3+y_off,14+x_off,3+y_off, matrix.color565(R,G,B)); //Circle start
  matrix.drawPixel(10+x_off,4+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(8+x_off,5+y_off, matrix.color565(R,G,B));
  matrix.drawLine(7+x_off,6+y_off,7+x_off,8+y_off, matrix.color565(R,G,B));
  matrix.drawLine(8+x_off,6+y_off,8+x_off,9+y_off, matrix.color565(R,G,B));
  matrix.drawLine(9+x_off,9+y_off,9+x_off,10+y_off, matrix.color565(R,G,B));
  matrix.drawLine(10+x_off,10+y_off,10+x_off,11+y_off, matrix.color565(R,G,B));
  matrix.drawLine(11+x_off,11+y_off,14+x_off,11+y_off, matrix.color565(R,G,B));
  matrix.drawLine(14+x_off,10+y_off,15+x_off,10+y_off, matrix.color565(R,G,B));
  matrix.drawLine(15+x_off,10+y_off,16+x_off,9+y_off, matrix.color565(R,G,B));
  matrix.drawLine(16+x_off,5+y_off,16+x_off,8+y_off, matrix.color565(R,G,B));
  matrix.drawLine(17+x_off,6+y_off,17+x_off,8+y_off, matrix.color565(R,G,B)); //circle end
  R = 0;
  G = 0;
  B = 255;                                            // B doesn't need to be set here but it looks nicer
  matrix.drawLine(19+x_off,1+y_off,17+x_off,1+y_off, matrix.color565(R,G,B)); //Dimond Start
  matrix.drawLine(17+x_off,2+y_off,16+x_off,2+y_off, matrix.color565(R,G,B));
  matrix.drawLine(17+x_off,2+y_off,16+x_off,2+y_off, matrix.color565(R,G,B));
  matrix.drawLine(16+x_off,3+y_off,15+x_off,3+y_off, matrix.color565(R,G,B));
  matrix.drawLine(15+x_off,4+y_off,14+x_off,4+y_off, matrix.color565(R,G,B));
  matrix.drawLine(14+x_off,5+y_off,13+x_off,5+y_off, matrix.color565(R,G,B));
  matrix.drawLine(13+x_off,6+y_off,12+x_off,6+y_off, matrix.color565(R,G,B));
  matrix.drawLine(12+x_off,7+y_off,12+x_off,8+y_off, matrix.color565(R,G,B));
  matrix.drawLine(13+x_off,8+y_off,13+x_off,9+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(14+x_off,9+y_off, matrix.color565(R,G,B));
  matrix.drawLine(15+x_off,11+y_off,17+x_off,13+y_off, matrix.color565(R,G,B));
  matrix.drawLine(16+x_off,11+y_off,17+x_off,12+y_off, matrix.color565(R,G,B));
  matrix.drawLine(18+x_off,13+y_off,24+x_off,7+y_off, matrix.color565(R,G,B));
  matrix.drawLine(19+x_off,13+y_off,24+x_off,8+y_off, matrix.color565(R,G,B));
  matrix.drawLine(23+x_off,6+y_off,19+x_off,2+y_off, matrix.color565(R,G,B));
  matrix.drawLine(24+x_off,6+y_off,20+x_off,2+y_off, matrix.color565(R,G,B));//dimond end
  matrix.drawPixel(18+x_off,0+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(25+x_off,7+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(18+x_off,14+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(11+x_off,7+y_off, matrix.color565(R,G,B));
  matrix.show();
  R = 100;                                          
  G = 100;
  B = 100;
  matrix.drawLine(27+x_off,0+y_off,29+x_off,0+y_off, matrix.color565(R,G,B)); //F start
  matrix.drawLine(27+x_off,1+y_off,27+x_off,4+y_off, matrix.color565(R,G,B));
  matrix.drawLine(28+x_off,2+y_off,29+x_off,2+y_off, matrix.color565(R,G,B));// F end
  matrix.drawLine(27+x_off,10+y_off,27+x_off,6+y_off, matrix.color565(R,G,B)); // R start
  matrix.drawLine(28+x_off,6+y_off,27+x_off,6+y_off, matrix.color565(R,G,B));
  matrix.drawLine(29+x_off,7+y_off,28+x_off,8+y_off, matrix.color565(R,G,B));
  matrix.drawLine(29+x_off,9+y_off,29+x_off,10+y_off, matrix.color565(R,G,B)); // R end
  matrix.drawLine(27+x_off,12+y_off,29+x_off,12+y_off, matrix.color565(R,G,B)); // C start
  matrix.drawLine(27+x_off,13+y_off,27+x_off,15+y_off, matrix.color565(R,G,B));
  matrix.drawLine(28+x_off,15+y_off,29+x_off,15+y_off, matrix.color565(R,G,B)); // C end
  R = 30;
  G = 30;
  B = 30;
  matrix.drawLine(3+x_off,1+y_off,3+x_off,3+y_off, matrix.color565(R,G,B)); //triangle shading
  matrix.drawLine(2+x_off,4+y_off,2+x_off,8+y_off, matrix.color565(R,G,B));
  matrix.drawLine(1+x_off,9+y_off,1+x_off,12+y_off, matrix.color565(R,G,B));
  matrix.drawLine(4+x_off,10+y_off,6+x_off,10+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(7+x_off,9+y_off, matrix.color565(R,G,B));
  matrix.drawLine(10+x_off,8+y_off,10+x_off,7+y_off, matrix.color565(R,G,B));
  matrix.drawLine(7+x_off,4+y_off,6+x_off,3+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(9+x_off,6+y_off, matrix.color565(R,G,B)); //triangle shading end
  matrix.drawPixel(7+x_off,12+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(8+x_off,11+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(3+x_off,0+y_off, matrix.color565(R,G,B));
  matrix.drawLine(9+x_off,11+y_off,10+x_off,12+y_off, matrix.color565(R,G,B)); //diamond shading
  matrix.drawLine(11+x_off,12+y_off,15+x_off,12+y_off, matrix.color565(R,G,B));
  matrix.drawLine(16+x_off,10+y_off,7+x_off,8+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(17+x_off,9+y_off, matrix.color565(R,G,B));
  matrix.drawLine(13+x_off,4+y_off,11+x_off,4+y_off, matrix.color565(R,G,B)); //circle shading end
  matrix.drawLine(12+x_off,9+y_off,13+x_off,10+y_off, matrix.color565(R,G,B)); // diamond shading
  matrix.drawLine(16+x_off,13+y_off,17+x_off,14+y_off, matrix.color565(R,G,B));
  matrix.drawLine(18+x_off,2+y_off,23+x_off,7+y_off, matrix.color565(R,G,B));
  matrix.drawLine(18+x_off,14+y_off,19+x_off,14+y_off, matrix.color565(R,G,B));
  matrix.drawLine(20+x_off,13+y_off,24+x_off,9+y_off, matrix.color565(R,G,B));
  matrix.drawLine(17+x_off,3+y_off,13+x_off,7+y_off, matrix.color565(R,G,B)); // diamond shading end
  matrix.drawPixel(25+x_off,8+y_off, matrix.color565(R,G,B));
  matrix.drawPixel(18+x_off,15+y_off, matrix.color565(R,G,B));
}

void cargoDisp(int CT, int CO){
  matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));

  //Displays solid purple when requested cargo type is a cube, or CT = 1.
  //Displays yellow with space in the center of boards for an orientation arrow for Cones, or CT = 2.
  if(CT == 1){ //Cargo Type ~ "Cubes"
    for(uint8_t x=0; x<8; x++){
      //matrix.fillRect(0, 0, 64, 16, matrix.color565(100, 0, 255));
      draw_cube(0, 0);
      draw_cube(32, 0);
      matrix.show();
      fun2(250);
      matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
      matrix.show();
      fun2(250);
    }
    //matrix.fillRect(0, 0, 64, 16, matrix.color565(100, 0, 255));
    draw_cube(0, 0);
    draw_cube(32, 0);
    matrix.show();
  }else if(CT == 2){ //Cargo Type ~ Cones
    matrix.fillRect(0, 0, 5, 16, matrix.color565(255, 255, 0));
    matrix.fillRect(6, 0, 26, 16, matrix.color565(0, 0, 0));
    matrix.fillRect(27, 0, 31, 16, matrix.color565(255, 255, 0));
    matrix.fillRect(0+31, 0, 5+31, 16, matrix.color565(255, 255, 0));
    matrix.fillRect(6+31, 0, 27+31, 16, matrix.color565(0, 0, 0));
    matrix.fillRect(28+31, 0, 32+31, 16, matrix.color565(255, 255, 0));
  }
  
  //Damn bro, that's crazy
  if(CT == 3){
    matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
    matrix.setCursor(1, 1);
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.color565(255,255,255));
    matrix.print("DAMN");
    matrix.setCursor(1, 9);
    matrix.print("BRO");

    matrix.setCursor(33, 1);
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.color565(255,255,255));
    matrix.print("THATS");
    matrix.setCursor(33, 9);
    matrix.print("CRAZY");
  }

  if(CT == 4){
    matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
    matrix.setCursor(2, 1);
    matrix.setTextSize(1);
    matrix.setTextColor(matrix.color565(255,255,255));
    matrix.print("----NO----");
    matrix.setCursor(2, 8);
    matrix.setTextSize(1);
    matrix.print("-BITCHES?-");
  }

  //Since orientation for Cubes doesn't matter, this only triggers when Cones are requested. If Cargo Orientation is 1, or upright, a vertical line will display. 
  //A horizontal line will display for CO = 2.
  if(CT == 2){
    if(CO == 1){
      for(uint8_t x=0; x<8; x++){
        matrix.fillRect(0, 0, 5, 16, matrix.color565(255, 255, 0));
        matrix.fillRect(6, 0, 26, 16, matrix.color565(0, 0, 0));
        matrix.fillRect(27, 0, 31, 16, matrix.color565(255, 255, 0));
        matrix.fillRect(0+31, 0, 5+31, 16, matrix.color565(255, 255, 0));
        matrix.fillRect(6+31, 0, 27+31, 16, matrix.color565(0, 0, 0));
        matrix.fillRect(28+31, 0, 32+31, 16, matrix.color565(255, 255, 0));
        //matrix.fillRect(0, 0, 64, 16, matrix.color565(100, 0, 255));
        draw_vertical_cone(0, 0);
        draw_vertical_cone(32, 0);
        matrix.show();
        fun2(250);
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
        matrix.show();
        fun2(250);
      }
      matrix.fillRect(0, 0, 5, 16, matrix.color565(255, 255, 0));
      matrix.fillRect(6, 0, 26, 16, matrix.color565(0, 0, 0));
      matrix.fillRect(27, 0, 31, 16, matrix.color565(255, 255, 0));
      matrix.fillRect(0+31, 0, 5+31, 16, matrix.color565(255, 255, 0));
      matrix.fillRect(6+31, 0, 27+31, 16, matrix.color565(0, 0, 0));
      matrix.fillRect(28+31, 0, 32+31, 16, matrix.color565(255, 255, 0));
      draw_vertical_cone(0, 0);
      draw_vertical_cone(32, 0);
    }else if (CO == 2){
      for(uint8_t x=0; x<8; x++){
        matrix.fillRect(0, 0, 5, 16, matrix.color565(255, 255, 0));
        matrix.fillRect(6, 0, 26, 16, matrix.color565(0, 0, 0));
        matrix.fillRect(27, 0, 31, 16, matrix.color565(255, 255, 0));
        matrix.fillRect(0+31, 0, 5+31, 16, matrix.color565(255, 255, 0));
        matrix.fillRect(6+31, 0, 27+31, 16, matrix.color565(0, 0, 0));
        matrix.fillRect(28+31, 0, 32+31, 16, matrix.color565(255, 255, 0));
        //matrix.fillRect(0, 0, 64, 16, matrix.color565(100, 0, 255));
        draw_horizontal_cone(0, 0);
        draw_horizontal_cone(32, 0);
        matrix.show();
        fun2(250);
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
        matrix.show();
        fun2(250);
      }
      matrix.fillRect(0, 0, 5, 16, matrix.color565(255, 255, 0));
      matrix.fillRect(6, 0, 26, 16, matrix.color565(0, 0, 0));
      matrix.fillRect(27, 0, 31, 16, matrix.color565(255, 255, 0));
      matrix.fillRect(0+31, 0, 5+31, 16, matrix.color565(255, 255, 0));
      matrix.fillRect(6+31, 0, 27+31, 16, matrix.color565(0, 0, 0));
      matrix.fillRect(28+31, 0, 32+31, 16, matrix.color565(255, 255, 0));
      draw_horizontal_cone(0, 0);
      draw_horizontal_cone(32, 0);
    }
  }
  

  matrix.show();

  fun2(10000);
}

void drawAmogus (int x_off, int y_off){
  R = 255;
G = 0;
B = 0;
matrix.drawLine(4 + x_off, 2 + y_off, 8 + x_off, 2 + y_off, matrix.color565(R, G, B)); //bright red body of among us start
matrix.drawLine(3 + x_off, 3 + y_off, 9 + x_off, 3 + y_off, matrix.color565(R, G, B));
matrix.drawLine(6 + x_off, 4 + y_off, 9 + x_off, 4 + y_off, matrix.color565(R, G, B));
matrix.drawLine(7 + x_off, 5 + y_off, 9 + x_off, 5 + y_off, matrix.color565(R, G, B));
matrix.drawLine(7 + x_off, 6 + y_off, 9 + x_off, 6 + y_off, matrix.color565(R, G, B));
matrix.drawLine(6 + x_off, 7 + y_off, 9 + x_off, 7 + y_off, matrix.color565(R, G, B));
matrix.drawLine(5 + x_off, 8 + y_off, 7 + x_off, 8 + y_off, matrix.color565(R, G, B));
matrix.drawLine(11 + x_off, 5 + y_off, 11 + x_off, 7 + y_off, matrix.color565(R, G, B));
matrix.drawLine(12 + x_off, 5 + y_off, 12 + x_off, 7 + y_off, matrix.color565(R, G, B));
matrix.drawLine(3 + x_off, 8 + y_off, 3 + x_off, 14 + y_off, matrix.color565(R, G, B)); //originally a darker red, but didn't work so merged it with bright red
matrix.drawLine(4 + x_off, 8 + y_off, 4 + x_off, 14 + y_off, matrix.color565(R, G, B));
matrix.drawLine(5 + x_off, 9 + y_off, 5 + x_off, 12 + y_off, matrix.color565(R, G, B));
matrix.drawLine(6 + x_off, 9 + y_off, 6 + x_off, 11 + y_off, matrix.color565(R, G, B));
matrix.drawLine(7 + x_off, 9 + y_off, 7 + x_off, 12 + y_off, matrix.color565(R, G, B));
matrix.drawLine(8 + x_off, 8 + y_off, 8 + x_off, 14 + y_off, matrix.color565(R, G, B));
matrix.drawLine(9 + x_off, 8 + y_off, 9 + x_off, 14 + y_off, matrix.color565(R, G, B));
matrix.drawLine(11 + x_off, 8 + y_off, 11 + x_off, 13 + y_off, matrix.color565(R, G, B));
matrix.drawLine(12 + x_off, 8 + y_off, 12 + x_off, 12 + y_off, matrix.color565(R, G, B));
R = 0;
G = 0;
B = 255;
matrix.drawLine(2 + x_off, 6 + y_off, 5 + x_off, 6 + y_off, matrix.color565(R, G, B)); //dark blue visor
matrix.drawPixel(5 + x_off,5 + y_off, matrix.color565(R,G,B));
R = 137;
G = 207;
B = 240;
matrix.drawLine(2 + x_off, 5 + y_off, 4 + x_off, 5 + y_off, matrix.color565(R, G, B)); //light blue visor
R = 255;
G = 255;
B = 255;
matrix.drawLine(4 + x_off, 1 + y_off, 8 + x_off, 1 + y_off, matrix.color565(R, G, B)); //white outline of amogus
matrix.drawLine(9 + x_off, 2 + y_off, 10 + x_off, 3 + y_off, matrix.color565(R, G, B));
matrix.drawLine(10 + x_off, 4 + y_off, 10 + x_off, 14 + y_off, matrix.color565(R, G, B));
matrix.drawLine(11 + x_off, 13 + y_off, 12 + x_off, 13 + y_off, matrix.color565(R, G, B));
matrix.drawLine(13 + x_off, 12 + y_off, 13 + x_off, 5 + y_off, matrix.color565(R, G, B));
matrix.drawLine(11 + x_off, 4 + y_off, 12 + x_off, 4 + y_off, matrix.color565(R, G, B));
matrix.drawLine(8 + x_off, 15 + y_off, 9 + x_off, 15 + y_off, matrix.color565(R, G, B));
matrix.drawLine(7 + x_off, 14 + y_off, 7 + x_off, 13 + y_off, matrix.color565(R, G, B));
matrix.drawPixel(6 + x_off, 12 + y_off, matrix.color565(R,G,B));
matrix.drawLine(5 + x_off, 13 + y_off, 5 + x_off, 14 + y_off, matrix.color565(R, G, B));
matrix.drawLine(3 + x_off, 15 + y_off, 4 + x_off, 15 + y_off, matrix.color565(R, G, B));
matrix.drawLine(2 + x_off, 14 + y_off, 2 + x_off, 7 + y_off, matrix.color565(R, G, B));
matrix.drawLine(3 + x_off, 7 + y_off, 5 + x_off, 7 + y_off, matrix.color565(R, G, B));
matrix.drawLine(6 + x_off, 6 + y_off, 6 + x_off, 5 + y_off, matrix.color565(R, G, B));
matrix.drawLine(5 + x_off, 4 + y_off, 2 + x_off, 4 + y_off, matrix.color565(R, G, B));
matrix.drawLine(1 + x_off, 5 + y_off, 1 + x_off, 6 + y_off, matrix.color565(R, G, B));
matrix.drawLine(2 + x_off, 3 + y_off, 3 + x_off, 2 + y_off, matrix.color565(R, G, B));
matrix.show();

}

void drawHeart(int x_off, int y_off){
  R = 255;
  G = 0;
  B = 0;
  matrix.drawLine(1 + x_off, 2 + y_off, 1 + x_off, 4 + y_off, matrix.color565(R,G,B));
  matrix.drawPixel(2 + x_off, 1 + y_off, matrix.color565(R,G,B));
  matrix.drawPixel(2 + x_off, 5 + y_off, matrix.color565(R,G,B));
  matrix.drawPixel(3 + x_off, 3 + y_off, matrix.color565(255, 255, 255));
  matrix.drawPixel(3 + x_off, 2 + y_off, matrix.color565(255, 255, 255));
  matrix.drawPixel(3 + x_off, 6 + y_off, matrix.color565(R,G,B));
  matrix.drawPixel(4 + x_off, 2 + y_off, matrix.color565(255, 255, 255));
  matrix.drawPixel(4 + x_off, 3 + y_off, matrix.color565(255, 255, 255));
  matrix.drawPixel(4 + x_off, 7 + y_off, matrix.color565(R,G,B));
  matrix.drawLine(4 + x_off, 0 + y_off, 3 + x_off, 0 + y_off, matrix.color565(R,G,B));
  matrix.drawPixel(5 + x_off, 1 + y_off, matrix.color565(R,G,B));
  matrix.drawPixel(5 + x_off, 8 + y_off, matrix.color565(R,G,B)); 
  matrix.drawPixel(6 + x_off, 7 + y_off, matrix.color565(R,G,B));
  matrix.drawLine(7 + x_off, 0 + y_off, 6 + x_off, 0 + y_off, matrix.color565(R,G,B));
  matrix.drawPixel(7 + x_off, 6 + y_off, matrix.color565(R,G,B));
  matrix.drawPixel(8 + x_off, 1 + y_off, matrix.color565(R,G,B));
  matrix.drawPixel(8 + x_off, 5 + y_off, matrix.color565(R,G,B));
  matrix.drawLine(9 + x_off, 2 + y_off, 9 + x_off, 4 + y_off, matrix.color565(R,G,B));
}

void draw_we_love_animated(void){
  
  matrix.setTextSize(1);
  
  for(uint8_t x=0; x<66; x++){
    matrix.setTextColor(matrix.color565(255,255,0));
    matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
    
    matrix.setCursor(-64 + x, 1); //Draw 2 "WE" texts, slide in from left
    matrix.print("WE");
    matrix.setCursor(-32 + x, 1);
    matrix.print("WE");
    
    drawHeart(86-x, 0); //Draw 2 Minecraft hearts, slide in from right
    if(x > 54){
      drawHeart(64-(x-54), 0);
    }

    matrix.setTextColor(matrix.color565(255,255,255));

    
    length = ap1d.length();
    
    if(length == 4) {
      numberStartX = 5;
    }else if(length == 3) {
      numberStartX = 7;
    }else if(length == 2) {
      numberStartX = 10;
    }else{
      numberStartX = 5;
    }
      
    if(x < 16){
      matrix.setCursor(numberStartX, x-7);
      matrix.print(ap1d.charAt(0));
    }else if(x < 32){
      matrix.setCursor(numberStartX, 9);
      matrix.print(ap1d.charAt(0));
      matrix.setCursor(numberStartX+6, x-23);
      matrix.print(ap1d.charAt(1));
    }else if(x < 48){
      matrix.setCursor(numberStartX, 9);
      matrix.print(ap1d.charAt(0));
      matrix.setCursor(numberStartX+6, 9);
      matrix.print(ap1d.charAt(1));
      matrix.setCursor(numberStartX+12, x-39);
      matrix.print(ap1d.charAt(2));
    }else if(x < 64){
      matrix.setCursor(numberStartX, 9);
      matrix.print(ap1d.charAt(0));
      matrix.setCursor(numberStartX+6, 9);
      matrix.print(ap1d.charAt(1));
      matrix.setCursor(numberStartX+12, 9);
      matrix.print(ap1d.charAt(2));
      if(length > 3){
        matrix.setCursor(numberStartX+18, x-55);
        matrix.print(ap1d.charAt(3));
      }
    }else if(x < 70){
      matrix.setCursor(numberStartX, 9);
      matrix.print(ap1d.charAt(0));
      matrix.setCursor(numberStartX+6, 9);
      matrix.print(ap1d.charAt(1));
      matrix.setCursor(numberStartX+12, 9);
      matrix.print(ap1d.charAt(2));
      matrix.setCursor(numberStartX+18, 9);
      matrix.print(ap1d.charAt(3));
    }

    length = ap2d.length();
    
    if(length == 4) {
      numberStartX = 5;
    }else if(length == 3) {
      numberStartX = 7;
    }else if(length == 2) {
      numberStartX = 10;
    }else{
      numberStartX = 5;
    }
      
    if(x < 16){
      matrix.setCursor(numberStartX+32, x-7);
      matrix.print(ap2d.charAt(0));
    }else if(x < 32){
      matrix.setCursor(numberStartX+32, 9);
      matrix.print(ap2d.charAt(0));
      matrix.setCursor(numberStartX+6+32, x-23);
      matrix.print(ap2d.charAt(1));
    }else if(x < 48){
      matrix.setCursor(numberStartX+32, 9);
      matrix.print(ap2d.charAt(0));
      matrix.setCursor(numberStartX+6+32, 9);
      matrix.print(ap2d.charAt(1));
      matrix.setCursor(numberStartX+12+32, x-39);
      matrix.print(ap2d.charAt(2));
    }else if(x < 64){
      matrix.setCursor(numberStartX+32, 9);
      matrix.print(ap2d.charAt(0));
      matrix.setCursor(numberStartX+6+32, 9);
      matrix.print(ap2d.charAt(1));
      matrix.setCursor(numberStartX+12+32, 9);
      matrix.print(ap2d.charAt(2));
      if(length > 3){
        matrix.setCursor(numberStartX+18+32, x-55);
        matrix.print(ap2d.charAt(3));
      }
    }else if(x < 70){
      matrix.setCursor(numberStartX+32, 9);
      matrix.print(ap2d.charAt(0));
      matrix.setCursor(numberStartX+6+32, 9);
      matrix.print(ap2d.charAt(1));
      matrix.setCursor(numberStartX+12+32, 9);
      matrix.print(ap2d.charAt(2));
      matrix.setCursor(numberStartX+18+32, 9);
      matrix.print(ap2d.charAt(3));
    }
    
    matrix.show();
    fun2(10);
  }


  
}

void draw_swarm_animated(void){
  for(uint8_t x=0; x<66; x++){
    matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
    if(x < 16){
      matrix.setTextColor(matrix.color565(255,255,0)); //set text color to yellow
      matrix.setCursor(1, 16-x);
      matrix.print("S");
      matrix.show();
      fun2(100);
    }else if(x < 32){
      matrix.setTextColor(matrix.color565(255,255,0)); //set text color to yellow
      matrix.setCursor(1, 0);
      matrix.print("S");
      matrix.setCursor(7, 32-x);
      matrix.print("W");
      matrix.show();
      fun2(100);
      
    }else{
      matrix.setTextColor(matrix.color565(255,255,0)); //set text color to yellow
      
      //Write "SWARM" in yellow text
      matrix.setCursor(1, 0);
      matrix.print("SWARM");
      matrix.setCursor(33, 0);
      matrix.print("SWARM");
      
      matrix.setTextColor(matrix.color565(255,255,255));
      
      //Write "957" in white text, centered
      matrix.setCursor(7, 9);
      matrix.print("957");
      matrix.setCursor(39, 9);
      matrix.print("957");
    }
    
  }
  matrix.show();
  fun2(dlength);
  
}

void draw_we_love_static(int x_off, int y_off){
  matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
  //Write "WE"
  matrix.setCursor(1 + x_off, 1 + y_off);
        matrix.setTextSize(1);
      
        matrix.setTextColor(matrix.color565(255,255,0));
        matrix.print("WE");
        matrix.setCursor(33 + x_off, 1 + y_off);
        matrix.print("WE");
      
        R = 255;
        G = 0;
        B = 0;
      
        //Draw the heart

        
        matrix.drawLine(25 + x_off, 0 + y_off, 24 + x_off, 0 + y_off, matrix.color565(R,G,B));
        matrix.drawLine(28 + x_off, 0 + y_off, 27 + x_off, 0 + y_off, matrix.color565(R,G,B));
      
        matrix.drawLine(57 + x_off, 0 + y_off, 56 + x_off, 0 + y_off, matrix.color565(R,G,B));
        matrix.drawLine(60 + x_off, 0 + y_off, 59 + x_off, 0 + y_off, matrix.color565(R,G,B));
      
        matrix.drawPixel(29 + x_off, 1 + y_off, matrix.color565(R,G,B));
        matrix.drawPixel(26 + x_off, 1 + y_off, matrix.color565(R,G,B)); 
        matrix.drawPixel(23 + x_off, 1 + y_off, matrix.color565(R,G,B));
      
        matrix.drawPixel(61 + x_off, 1 + y_off, matrix.color565(R,G,B));
        matrix.drawPixel(58 + x_off, 1 + y_off, matrix.color565(R,G,B)); 
        matrix.drawPixel(55 + x_off, 1 + y_off, matrix.color565(R,G,B));
    
        matrix.drawLine(30 + x_off, 2 + y_off, 30 + x_off, 4 + y_off, matrix.color565(R,G,B));
        matrix.drawLine(22 + x_off, 2 + y_off, 22 + x_off, 4 + y_off, matrix.color565(R,G,B));
        matrix.drawLine(62 + x_off, 2 + y_off, 62 + x_off, 4 + y_off, matrix.color565(R,G,B));
        matrix.drawLine(54 + x_off, 2 + y_off, 54 + x_off, 4 + y_off, matrix.color565(R,G,B));
  
        matrix.drawPixel(24 + x_off, 2 + y_off, matrix.color565(255, 255, 255));
        matrix.drawPixel(25 + x_off, 2 + y_off, matrix.color565(255, 255, 255));
        matrix.drawPixel(24 + x_off, 3 + y_off, matrix.color565(255, 255, 255));
        matrix.drawPixel(25 + x_off, 3 + y_off, matrix.color565(255, 255, 255));
  
        matrix.drawPixel(56 + x_off, 2 + y_off, matrix.color565(255, 255, 255));
        matrix.drawPixel(57 + x_off, 2 + y_off, matrix.color565(255, 255, 255));
        matrix.drawPixel(56 + x_off, 3 + y_off, matrix.color565(255, 255, 255));
        matrix.drawPixel(57 + x_off, 3 + y_off, matrix.color565(255, 255, 255));
      
        matrix.drawPixel(29 + x_off, 5 + y_off, matrix.color565(R,G,B));
        matrix.drawPixel(23 + x_off, 5 + y_off, matrix.color565(R,G,B));
      
        matrix.drawPixel(61 + x_off, 5 + y_off, matrix.color565(R,G,B));
        matrix.drawPixel(55 + x_off, 5 + y_off, matrix.color565(R,G,B));
      
        matrix.drawPixel(28 + x_off, 6 + y_off, matrix.color565(R,G,B));
        matrix.drawPixel(24 + x_off, 6 + y_off, matrix.color565(R,G,B));
      
        matrix.drawPixel(60 + x_off, 6 + y_off, matrix.color565(R,G,B));
        matrix.drawPixel(56 + x_off, 6 + y_off, matrix.color565(R,G,B));
      
        matrix.drawPixel(27 + x_off, 7 + y_off, matrix.color565(R,G,B));
        matrix.drawPixel(25 + x_off, 7 + y_off, matrix.color565(R,G,B));
      
        matrix.drawPixel(59 + x_off, 7 + y_off, matrix.color565(R,G,B));
        matrix.drawPixel(57 + x_off, 7 + y_off, matrix.color565(R,G,B));
      
        matrix.drawPixel(26 + x_off, 8 + y_off, matrix.color565(R,G,B));
        matrix.drawPixel(58 + x_off, 8 + y_off, matrix.color565(R,G,B));
      
      
        //Center text cursor based on length of alliance team #s
        length = ap1d.length();
      
        if(length == 4) {
          matrix.setCursor(5 + x_off, 9 + y_off);
        }else if(length == 3) {
          matrix.setCursor(7 + x_off, 9 + y_off);
        }else if(length == 2) {
          matrix.setCursor(10 + x_off, 9 + y_off);
        }else{
          matrix.setCursor(1 + x_off, 9 + y_off);
        }
        
        matrix.setTextColor(matrix.color565(255,255,255));
        matrix.print(ap1d);
        
      
        length = ap2d.length();
      
        if(length == 4) {
          matrix.setCursor(37 + x_off, 9 + y_off);
        }else if(length == 3) {
          matrix.setCursor(39 + x_off, 9 + y_off);
        }else if(length == 2) {
          matrix.setCursor(42 + x_off, 9 + y_off);
        }else{
          matrix.setCursor(33 + x_off, 9 + y_off);
        }
      
        matrix.setTextColor(matrix.color565(255,255,255));
        matrix.print(ap2d);
}

void draw_swarm(int x_off, int y_off){
  matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
  matrix.setTextColor(matrix.color565(255,255,0));
  
    //Write "SWARM" in yellow text
    matrix.setCursor(1 + x_off, 0 + y_off);
    matrix.print("SWARM");
    matrix.setCursor(33 + x_off, 0 + y_off);
    matrix.print("SWARM");
    
    matrix.setTextColor(matrix.color565(255,255,255));
    
    //Write "957" in white text, centered
    matrix.setCursor(7 + x_off, 9 + y_off);
    matrix.print("957");
    matrix.setCursor(39 + x_off, 9 + y_off);
    matrix.print("957");
}

void draw_vertical_cone(int x_off, int y_off){
  R = 255;
  G = 255;
  B = 0;
  matrix.drawLine(9 + x_off, 13 + y_off, 9 + x_off, 14 + y_off, matrix.color565(R, G, B)); //vertical cone start
  matrix.drawLine(10 + x_off, 11 + y_off, 10 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(11 + x_off, 9 + y_off, 11 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(12 + x_off, 7 + y_off, 12 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(13 + x_off, 5 + y_off, 13 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(14 + x_off, 3 + y_off, 14 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(15 + x_off, 1 + y_off, 15 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(16 + x_off, 1 + y_off, 16 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(17 + x_off, 3 + y_off, 17 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(18 + x_off, 5 + y_off, 18 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(19 + x_off, 7 + y_off, 19 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(20 + x_off, 9 + y_off, 20 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(21 + x_off, 11 + y_off, 21 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(22 + x_off, 13 + y_off, 22 + x_off, 14 + y_off, matrix.color565(R, G, B)); //vertical cone end
  matrix.show();
}

void draw_horizontal_cone(int x_off, int y_off){
  R = 255;
  G = 255;
  B = 0;
  matrix.drawLine(9 + x_off, 1 + y_off, 9 + x_off, 14 + y_off, matrix.color565(R, G, B)); //horizontal cone start
  matrix.drawLine(10 + x_off, 1 + y_off, 10 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(11 + x_off, 2 + y_off, 11 + x_off, 13 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(12 + x_off, 2 + y_off, 12 + x_off, 13 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(13 + x_off, 3 + y_off, 13 + x_off, 12 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(14 + x_off, 3 + y_off, 14 + x_off, 12 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(15 + x_off, 4 + y_off, 15 + x_off, 11 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(16 + x_off, 4 + y_off, 16 + x_off, 11 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(17 + x_off, 5 + y_off, 17 + x_off, 10 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(18 + x_off, 5 + y_off, 18 + x_off, 10 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(19 + x_off, 6 + y_off, 19 + x_off, 9 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(20 + x_off, 6 + y_off, 20 + x_off, 9 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(21 + x_off, 7 + y_off, 21 + x_off, 8 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(22 + x_off, 7 + y_off, 22 + x_off, 8 + y_off, matrix.color565(R, G, B)); //horizontal cone end
  matrix.show();
}

void draw_cube(int x_off, int y_off){
  R = 100;
  G = 25;
  B = 255;
  matrix.drawLine(8 + x_off, 1 + y_off,8 + x_off, 14 + y_off, matrix.color565(R, G, B)); //”cube” start
  matrix.drawLine(9 + x_off, 1 + y_off,22 + x_off, 1 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(22 + x_off, 2 + y_off,22 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(9 + x_off, 14 + y_off,21 + x_off, 14 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(9 + x_off, 6 + y_off,9 + x_off, 9 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(10 + x_off, 4 + y_off,10 + x_off, 11 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(11 + x_off, 3 + y_off,11 + x_off, 12 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(12 + x_off, 3 + y_off,12 + x_off, 12 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(13 + x_off, 2 + y_off,13 + x_off, 13 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(14 + x_off, 2 + y_off,14 + x_off, 13 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(15 + x_off, 2 + y_off,15 + x_off, 13 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(16 + x_off, 2 + y_off,16 + x_off, 13 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(17 + x_off, 2 + y_off,17 + x_off, 13 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(18 + x_off, 3 + y_off,18 + x_off, 12 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(19 + x_off, 3 + y_off,19 + x_off, 12 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(20 + x_off, 4 + y_off,20 + x_off, 11 + y_off, matrix.color565(R, G, B));
  matrix.drawLine(21 + x_off, 6 + y_off,21 + x_off, 9 + y_off, matrix.color565(R, G, B)); //”cube” end
  matrix.show();
}

void clear_screen(uint8_t R, uint8_t G, uint8_t B, uint8_t anim_del_len, int message){
  clearType = random(1, 3);
  //clearType = 2;
  //firstLoopDone = true;
  if(clearType == 1){
      //Clear screen (but *a*n*i*m*a*t*e*d*)
      animType = random(1, 15);
      //animType = 15;
  
      if(animType == 1){ //Left to Right straight line clear
        for(uint8_t x=0; x<33; x++) { //simple bar from side
           matrix.drawLine(x, 0, x, 16, matrix.color565(R, G, B));
           matrix.drawLine(x+32, 0, x+32, 16, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
      }else if(animType == 2){ //Circle from center of each board
        for(uint8_t x=0; x<33; x++) { //2 circles from center of each board
           matrix.fillCircle(16, 8, x, matrix.color565(R, G, B));
           matrix.fillCircle(48, 8, x, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
      }else if(animType == 3){ //Rectangle from bottom right corner
        for(uint8_t x=0; x<33; x++) {
           matrix.fillRect(16-x, 8-x, 16+x, 8+x, matrix.color565(R, G, B));
           matrix.fillRect(48-x, 8-x, 48+x, 8+x, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }    
      }else if(animType == 4){ 
        for(uint8_t x=0; x<33; x++) { //lines from corners
           matrix.drawLine(0, 0, x, 16, matrix.color565(R, G, B));
           matrix.drawLine(32, 16, 32-x, 0, matrix.color565(R, G, B));
           matrix.drawLine(32, 0, 32+x, 16, matrix.color565(R, G, B));
           matrix.drawLine(64, 16, 64-x, 0, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }  
      }else if(animType == 5){
        for(uint8_t x=0; x<33; x++) { //lines from corners 2
           matrix.drawLine(0, 16, x, 0, matrix.color565(R, G, B));
           matrix.drawLine(32, 0, 32-x, 16, matrix.color565(R, G, B));
           matrix.drawLine(32, 16, 32+x, 0, matrix.color565(R, G, B));
           matrix.drawLine(64, 0, 64-x, 16, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }  
      }else if(animType == 6){ //4 large rectangles, each covering half a board
        for(uint8_t y=0; y<17; y++) {
           matrix.fillRect(0, 0, 16, y, matrix.color565(R, G, B));
           matrix.fillRect(48, 0, 64, y, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
        for(uint8_t y=0; y<17; y++) {
           matrix.fillRect(16, 0, 32, y, matrix.color565(R, G, B));
           matrix.fillRect(32, 0, 48, y, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        } 
      }else if(animType == 7){ //3 circles, from the edges of each board
        for(uint8_t x=0; x<33; x++) {
           matrix.fillCircle(0, 8, x, matrix.color565(R, G, B));
           matrix.fillCircle(32, 8, x, matrix.color565(R, G, B));
           matrix.fillCircle(64, 8, x, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
      }else if(animType == 8){ //Lines from all 4 corners
        for(uint8_t x=0; x<33; x++) {
           matrix.drawLine(0, 16, x, 0, matrix.color565(R, G, B));
           matrix.drawLine(32, 0, 32-x, 16, matrix.color565(R, G, B));
           matrix.drawLine(32, 16, 32+x, 0, matrix.color565(R, G, B));
           matrix.drawLine(64, 0, 64-x, 16, matrix.color565(R, G, B));
           matrix.drawLine(0, 0, x, 16, matrix.color565(R, G, B));
           matrix.drawLine(32, 16, 32-x, 0, matrix.color565(R, G, B));
           matrix.drawLine(32, 0, 32+x, 16, matrix.color565(R, G, B));
           matrix.drawLine(64, 16, 64-x, 0, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        } 
      }else if(animType == 9){ //Windshield wipers
        for(uint8_t y=0; y<17; y++) {
           matrix.drawLine(16, 0, 0, y, matrix.color565(R, G, B));
           matrix.drawLine(17, 0, 32, y, matrix.color565(R, G, B));
           matrix.drawLine(48, 0, 32, y, matrix.color565(R, G, B));
           matrix.drawLine(49, 0, 64, y, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
        for(uint8_t x=0; x<17; x++) {
           matrix.drawLine(16, 0, x, 16, matrix.color565(R, G, B));
           matrix.drawLine(17, 0, 32-x, 16, matrix.color565(R, G, B));
           matrix.drawLine(48, 0, 32+x, 16, matrix.color565(R, G, B));
           matrix.drawLine(49, 0, 64-x, 16, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
      }else if(animType == 10){ //Vertical staggered lines
        for(uint8_t y=0; y<17; y++) {
           matrix.drawLine(0, 0, 0, y, matrix.color565(R, G, B));
           matrix.drawLine(2, 0, 2, y, matrix.color565(R, G, B));
           matrix.drawLine(4, 0, 4, y, matrix.color565(R, G, B));
           matrix.drawLine(6, 0, 6, y, matrix.color565(R, G, B));
           matrix.drawLine(8, 0, 8, y, matrix.color565(R, G, B));
           matrix.drawLine(10, 0, 10, y, matrix.color565(R, G, B));
           matrix.drawLine(12, 0, 12, y, matrix.color565(R, G, B));
           matrix.drawLine(14, 0, 14, y, matrix.color565(R, G, B));
           matrix.drawLine(16, 0, 16, y, matrix.color565(R, G, B));
           matrix.drawLine(18, 0, 18, y, matrix.color565(R, G, B));
           matrix.drawLine(20, 0, 20, y, matrix.color565(R, G, B));
           matrix.drawLine(22, 0, 22, y, matrix.color565(R, G, B));
           matrix.drawLine(24, 0, 24, y, matrix.color565(R, G, B));
           matrix.drawLine(26, 0, 26, y, matrix.color565(R, G, B));
           matrix.drawLine(28, 0, 28, y, matrix.color565(R, G, B));
           matrix.drawLine(30, 0, 30, y, matrix.color565(R, G, B));
           matrix.drawLine(32, 0, 32, y, matrix.color565(R, G, B));
           matrix.drawLine(34, 0, 34, y, matrix.color565(R, G, B));
           matrix.drawLine(36, 0, 36, y, matrix.color565(R, G, B));
           matrix.drawLine(38, 0, 38, y, matrix.color565(R, G, B));
           matrix.drawLine(40, 0, 40, y, matrix.color565(R, G, B));
           matrix.drawLine(42, 0, 42, y, matrix.color565(R, G, B));
           matrix.drawLine(44, 0, 44, y, matrix.color565(R, G, B));
           matrix.drawLine(46, 0, 46, y, matrix.color565(R, G, B));
           matrix.drawLine(48, 0, 48, y, matrix.color565(R, G, B));
           matrix.drawLine(50, 0, 50, y, matrix.color565(R, G, B));
           matrix.drawLine(52, 0, 52, y, matrix.color565(R, G, B));
           matrix.drawLine(54, 0, 54, y, matrix.color565(R, G, B));
           matrix.drawLine(56, 0, 56, y, matrix.color565(R, G, B));
           matrix.drawLine(58, 0, 58, y, matrix.color565(R, G, B));
           matrix.drawLine(60, 0, 60, y, matrix.color565(R, G, B));
           matrix.drawLine(62, 0, 62, y, matrix.color565(R, G, B));
           matrix.drawLine(64, 0, 64, y, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
        for(uint8_t y=0; y<17; y++) {
           matrix.drawLine(1, 0, 1, y, matrix.color565(R, G, B));
           matrix.drawLine(3, 0, 3, y, matrix.color565(R, G, B));
           matrix.drawLine(5, 0, 5, y, matrix.color565(R, G, B));
           matrix.drawLine(7, 0, 7, y, matrix.color565(R, G, B));
           matrix.drawLine(9, 0, 9, y, matrix.color565(R, G, B));
           matrix.drawLine(11, 0, 11, y, matrix.color565(R, G, B));
           matrix.drawLine(13, 0, 13, y, matrix.color565(R, G, B));
           matrix.drawLine(15, 0, 15, y, matrix.color565(R, G, B));
           matrix.drawLine(17, 0, 17, y, matrix.color565(R, G, B));
           matrix.drawLine(19, 0, 19, y, matrix.color565(R, G, B));
           matrix.drawLine(21, 0, 21, y, matrix.color565(R, G, B));
           matrix.drawLine(23, 0, 23, y, matrix.color565(R, G, B));
           matrix.drawLine(25, 0, 25, y, matrix.color565(R, G, B));
           matrix.drawLine(27, 0, 27, y, matrix.color565(R, G, B));
           matrix.drawLine(29, 0, 29, y, matrix.color565(R, G, B));
           matrix.drawLine(31, 0, 31, y, matrix.color565(R, G, B));
           matrix.drawLine(33, 0, 33, y, matrix.color565(R, G, B));
           matrix.drawLine(35, 0, 35, y, matrix.color565(R, G, B));
           matrix.drawLine(37, 0, 37, y, matrix.color565(R, G, B));
           matrix.drawLine(39, 0, 39, y, matrix.color565(R, G, B));
           matrix.drawLine(41, 0, 41, y, matrix.color565(R, G, B));
           matrix.drawLine(43, 0, 43, y, matrix.color565(R, G, B));
           matrix.drawLine(45, 0, 45, y, matrix.color565(R, G, B));
           matrix.drawLine(47, 0, 47, y, matrix.color565(R, G, B));
           matrix.drawLine(49, 0, 49, y, matrix.color565(R, G, B));
           matrix.drawLine(51, 0, 51, y, matrix.color565(R, G, B));
           matrix.drawLine(53, 0, 53, y, matrix.color565(R, G, B));
           matrix.drawLine(55, 0, 55, y, matrix.color565(R, G, B));
           matrix.drawLine(57, 0, 57, y, matrix.color565(R, G, B));
           matrix.drawLine(59, 0, 59, y, matrix.color565(R, G, B));
           matrix.drawLine(61, 0, 61, y, matrix.color565(R, G, B));
           matrix.drawLine(63, 0, 63, y, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
      }else if(animType == 11){ //Slant angled towards top left
        for(uint8_t x=0; x<50; x++) {
           matrix.drawLine(x-16, 0, x, 16, matrix.color565(R, G, B));
           matrix.drawLine(80-x, 0, 64-x, 16, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
      }else if(animType == 12){ //Slant angled towards top right
        for(uint8_t x=0; x<50; x++) {
           matrix.drawLine(x, 0, x-16, 16, matrix.color565(R, G, B));
           matrix.drawLine(64-x, 0, 80-x, 16, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
      }else if(animType == 13){ //Horizontal staggered lines
        for(uint8_t x=0; x<33; x++) {
           matrix.drawLine(0, 0, x, 0, matrix.color565(R, G, B));
           matrix.drawLine(0, 2, x, 2, matrix.color565(R, G, B));
           matrix.drawLine(0, 4, x, 4, matrix.color565(R, G, B));
           matrix.drawLine(0, 6, x, 6, matrix.color565(R, G, B));
           matrix.drawLine(0, 8, x, 8, matrix.color565(R, G, B));
           matrix.drawLine(0, 10, x, 10, matrix.color565(R, G, B));
           matrix.drawLine(0, 12, x, 12, matrix.color565(R, G, B));
           matrix.drawLine(0, 14, x, 14, matrix.color565(R, G, B));
           matrix.drawLine(0, 16, x, 16, matrix.color565(R, G, B));
           matrix.drawLine(0, 18, x, 18, matrix.color565(R, G, B));
           matrix.drawLine(0, 20, x, 20, matrix.color565(R, G, B));
           matrix.drawLine(0, 22, x, 22, matrix.color565(R, G, B));
           matrix.drawLine(0, 24, x, 24, matrix.color565(R, G, B));
           matrix.drawLine(0, 26, x, 26, matrix.color565(R, G, B));
           matrix.drawLine(0, 28, x, 28, matrix.color565(R, G, B));
           matrix.drawLine(0, 30, x, 30, matrix.color565(R, G, B));
           matrix.drawLine(0, 32, x, 32, matrix.color565(R, G, B));

           matrix.drawLine(32, 0, 32+x, 0, matrix.color565(R, G, B));
           matrix.drawLine(32, 2, 32+x, 2, matrix.color565(R, G, B));
           matrix.drawLine(32, 4, 32+x, 4, matrix.color565(R, G, B));
           matrix.drawLine(32, 6, 32+x, 6, matrix.color565(R, G, B));
           matrix.drawLine(32, 8, 32+x, 8, matrix.color565(R, G, B));
           matrix.drawLine(32, 10, 32+x, 10, matrix.color565(R, G, B));
           matrix.drawLine(32, 12, 32+x, 12, matrix.color565(R, G, B));
           matrix.drawLine(32, 14, 32+x, 14, matrix.color565(R, G, B));
           matrix.drawLine(32, 16, 32+x, 16, matrix.color565(R, G, B));
           matrix.drawLine(32, 18, 32+x, 18, matrix.color565(R, G, B));
           matrix.drawLine(32, 20, 32+x, 20, matrix.color565(R, G, B));
           matrix.drawLine(32, 22, 32+x, 22, matrix.color565(R, G, B));
           matrix.drawLine(32, 24, 32+x, 24, matrix.color565(R, G, B));
           matrix.drawLine(32, 26, 32+x, 26, matrix.color565(R, G, B));
           matrix.drawLine(32, 28, 32+x, 28, matrix.color565(R, G, B));
           matrix.drawLine(32, 30, 32+x, 30, matrix.color565(R, G, B));
           matrix.drawLine(32, 32, 32+x, 32, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
        for(uint8_t x=0; x<33; x++) {
           matrix.drawLine(0, 1, x, 1, matrix.color565(R, G, B));
           matrix.drawLine(0, 3, x, 3, matrix.color565(R, G, B));
           matrix.drawLine(0, 5, x, 5, matrix.color565(R, G, B));
           matrix.drawLine(0, 7, x, 7, matrix.color565(R, G, B));
           matrix.drawLine(0, 9, x, 9, matrix.color565(R, G, B));
           matrix.drawLine(0, 11, x, 11, matrix.color565(R, G, B));
           matrix.drawLine(0, 13, x, 13, matrix.color565(R, G, B));
           matrix.drawLine(0, 15, x, 15, matrix.color565(R, G, B));
           matrix.drawLine(0, 17, x, 17, matrix.color565(R, G, B));
           matrix.drawLine(0, 19, x, 19, matrix.color565(R, G, B));
           matrix.drawLine(0, 21, x, 21, matrix.color565(R, G, B));
           matrix.drawLine(0, 23, x, 23, matrix.color565(R, G, B));
           matrix.drawLine(0, 25, x, 25, matrix.color565(R, G, B));
           matrix.drawLine(0, 27, x, 27, matrix.color565(R, G, B));
           matrix.drawLine(0, 29, x, 29, matrix.color565(R, G, B));
           matrix.drawLine(0, 31, x, 31, matrix.color565(R, G, B));

           matrix.drawLine(32, 1, 32+x, 1, matrix.color565(R, G, B));
           matrix.drawLine(32, 3, 32+x, 3, matrix.color565(R, G, B));
           matrix.drawLine(32, 5, 32+x, 5, matrix.color565(R, G, B));
           matrix.drawLine(32, 7, 32+x, 7, matrix.color565(R, G, B));
           matrix.drawLine(32, 9, 32+x, 9, matrix.color565(R, G, B));
           matrix.drawLine(32, 11, 32+x, 11, matrix.color565(R, G, B));
           matrix.drawLine(32, 13, 32+x, 13, matrix.color565(R, G, B));
           matrix.drawLine(32, 15, 32+x, 15, matrix.color565(R, G, B));
           matrix.drawLine(32, 17, 32+x, 17, matrix.color565(R, G, B));
           matrix.drawLine(32, 19, 32+x, 19, matrix.color565(R, G, B));
           matrix.drawLine(32, 21, 32+x, 21, matrix.color565(R, G, B));
           matrix.drawLine(32, 23, 32+x, 23, matrix.color565(R, G, B));
           matrix.drawLine(32, 25, 32+x, 25, matrix.color565(R, G, B));
           matrix.drawLine(32, 27, 32+x, 27, matrix.color565(R, G, B));
           matrix.drawLine(32, 29, 32+x, 29, matrix.color565(R, G, B));
           matrix.drawLine(32, 31, 32+x, 31, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
      }else if(animType == 14){ //gradient trans
        R = 0;
        for(uint8_t x=0; x<32; x++) {
           R = R+5;
           G = 50;
           B = 50;
           matrix.drawLine(x, 0, x, 16, matrix.color565(R, G, B));
           matrix.drawLine(x+32, 0, x+32, 16, matrix.color565(R, G, B));
           matrix.show();
           fun2(anim_del_len);
        }
        fun2(1000);
        for(uint8_t x=0; x<32; x++) {
           matrix.drawLine(x, 0, x, 16, matrix.color565(0, 0, 0));
           matrix.drawLine(x+32, 0, x+32, 16, matrix.color565(0, 0, 0));
           matrix.show();
           fun2(anim_del_len);
        }
      }else if(animType == 15){ //random pride flag
        for(uint8_t y=0; y<17; y++){
          matrix.fillRect(0, 0, 64, y, matrix.color565(0, 0, 0));
          matrix.show();
          fun2(5);
        }
        for(uint8_t y=0; y<17; y++){
          //select_pride();
          matrix.fillRect(0, 0, 64, 16-y, matrix.color565(0, 0, 0));
          matrix.show();
          fun2(5);
        }
        fun2(1000);
        for(uint8_t x=0; x<32; x++) {
           matrix.drawLine(x, 0, x, 16, matrix.color565(0, 0, 0));
           matrix.drawLine(x+32, 0, x+32, 16, matrix.color565(0, 0, 0));
           matrix.show();
           fun2(anim_del_len);
        }
      }
  }
  if(clearType == 2){
    //animType = random(1, 4);
    if(animType == 1){
      for(uint8_t x=0; x<65; x++){
        select_disp(message, 0-x, 0);
        matrix.show();
        fun2(10);
      }
    }else if(animType == 2){
      for(uint8_t y=0; y<17; y++){
        select_disp(message, 0, y);
        matrix.show();
        fun2(10);
      }
    }else if(animType == 3){
      for(uint8_t y=0; y<17; y++){
        select_disp(message, 0, 0-y);
        matrix.show();
        fun2(10);
      }
    }
  }
}

void select_disp(int message, int x_off, int y_off){
  //Self-explanatory: selects whether or not to display the We Love or SWARM message
  if(message == 2){
    draw_we_love_static(x_off, y_off);
  }else if(message == 3){
    draw_swarm(x_off, y_off);
  }
}

void drawScreen(int drawType, int message){
  if(drawType == 0){
    drawType = random(1, 3);
    Serial.println("DT");
    Serial.println(drawType);
  }
  if(drawType == 1){ //Draw logo, partially obscure before updating boards
    matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
    animType = random(1, 4);
    Serial.println("AT");
    Serial.println(animType);
    //animType = 5;

    if(animType == 1){ //Draw from bottom up
      for(uint8_t y=0; y<17; y++){
        select_disp(message, 0, 0);
        matrix.fillRect(0, 0, 64, 16-y, matrix.color565(0, 0, 0));
        matrix.show();
        fun2(5);
      }
    }else if(animType == 2){ //Draw from center of both boards
      for(uint8_t x=0; x<65; x++){
        select_disp(message, 0, 0);
        matrix.fillCircle(32, 8, 32-x, matrix.color565(0, 0, 0));
        matrix.show();
        fun2(5);
      }
    }else if(animType == 3){ //Draw from right side of both boards
      for(uint8_t x=0; x<65; x++){
        select_disp(message, 0, 0);
        matrix.fillRect(0, 0, (64-x), 16, matrix.color565(0, 0, 0));
        matrix.show();
        fun2(2);
      }
    }else if(animType == 4){
      for(uint8_t x=0; x<33; x++){
        select_disp(message, 0, 0);
        matrix.fillRect(x, 0, 64, 16, matrix.color565(0, 0, 0));
        matrix.show();
        fun2(2);
      }
    }
  }else if(drawType == 2){ //slide into view
    animType = random(1, 4);
      if(animType == 1){
        for(uint8_t x=0; x<65; x++){
        select_disp(message, x-64, 0);
        matrix.show();
        fun2(10);
      }
    }else if(animType == 2){
      for(uint8_t y=0; y<17; y++){
        select_disp(message, 0, 16-y);
        matrix.show();
        fun2(10);
      }
    }else if(animType == 3){
      for(uint8_t y=0; y<17; y++){
        select_disp(message, 0, y-16);
        matrix.show();
        fun2(10);
      }
    }
    
  }
}

void drawDeclarationFull (void){
  
  scrolltext = "      In Congress, July 4, 1776 The unanimous Declaration of the thirteen united States of America, When in the Course of human events, it becomes necessary for one people to dissolve the political bands which have connected them with another, and to assume among the powers of the earth, the separate and equal station to which the Laws of Nature and of Nature's God entitle them, a decent respect to the opinions of mankind requires that they should declare the causes which impel them to the separation. We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness.--That to secure these rights, Governments are instituted among Men, deriving their just powers from the consent of the governed, --That whenever any Form of Government becomes destructive of these ends, it is the Right of the People to alter or to abolish it, and to institute new Government, laying its foundation on such principles and organizing its powers in such form, as to them shall seem most likely to effect their Safety and Happiness. Prudence, indeed, will dictate that Governments long established should not be changed for light and transient causes; and accordingly all experience hath shewn, that mankind are more disposed to suffer, while evils are sufferable, than to right themselves by abolishing the forms to which they are accustomed. But when a long train of abuses and usurpations, pursuing invariably the same Object evinces a design to reduce them under absolute Despotism, it is their right, it is their duty, to throw off such Government, and to provide new Guards for their future security.--Such has been the patient sufferance of these Colonies; and such is now the necessity which constrains them to alter their former Systems of Government. The history of the present King of Great Britain is a history of repeated injuries and usurpations, all having in direct object the establishment of an absolute Tyranny over these States. To prove this, let Facts be submitted to a candid world. ";
  drawDeclaration(2150);
  fun2(100);
  scrolltext = "      He has refused his Assent to Laws, the most wholesome and necessary for the public good. He has forbidden his Governors to pass Laws of immediate and pressing importance, unless suspended in their operation till his Assent should be obtained; and when so suspended, he has utterly neglected to attend to them. He has refused to pass other Laws for the accommodation of large districts of people, unless those people would relinquish the right of Representation in the Legislature, a right inestimable to them and formidable to tyrants only. He has called together legislative bodies at places unusual, uncomfortable, and distant from the depository of their public Records, for the sole purpose of fatiguing them into compliance with his measures. He has dissolved Representative Houses repeatedly, for opposing with manly firmness his invasions on the rights of the people. He has refused for a long time, after such dissolutions, to cause others to be elected; whereby the Legislative powers, incapable of Annihilation, have returned to the People at large for their exercise; the State remaining in the mean time exposed to all the dangers of invasion from without, and convulsions within. He has endeavoured to prevent the population of these States; for that purpose obstructing the Laws for Naturalization of Foreigners; refusing to pass others to encourage their migrations hither, and raising the conditions of new Appropriations of Lands. He has obstructed the Administration of Justice, by refusing his Assent to Laws for establishing Judiciary powers. He has made Judges dependent on his Will alone, for the tenure of their offices, and the amount and payment of their salaries. He has erected a multitude of New Offices, and sent hither swarms of Officers to harrass our people, and eat out their substance. He has kept among us, in times of peace, Standing Armies without the Consent of our legislatures. He has affected to render the Military independent of and superior to the Civil power. ";
  drawDeclaration(2010);
  fun2(100);
  scrolltext = "      He has combined with others to subject us to a jurisdiction foreign to our constitution, and unacknowledged by our laws; giving his Assent to their Acts of pretended Legislation: For Quartering large bodies of armed troops among us: For protecting them, by a mock Trial, from punishment for any Murders which they should commit on the Inhabitants of these States: For cutting off our Trade with all parts of the world: For imposing Taxes on us without our Consent: For depriving us in many cases, of the benefits of Trial by Jury: For transporting us beyond Seas to be tried for pretended offences For abolishing the free System of English Laws in a neighbouring Province, establishing therein an Arbitrary government, and enlarging its Boundaries so as to render it at once an example and fit instrument for introducing the same absolute rule into these Colonies: For taking away our Charters, abolishing our most valuable Laws, and altering fundamentally the Forms of our Governments: For suspending our own Legislatures, and declaring themselves invested with power to legislate for us in all cases whatsoever. He has abdicated Government here, by declaring us out of his Protection and waging War against us. He has plundered our seas, ravaged our Coasts, burnt our towns, and destroyed the lives of our people. He is at this time transporting large Armies of foreign Mercenaries to compleat the works of death, desolation and tyranny, already begun with circumstances of Cruelty & perfidy scarcely paralleled in the most barbarous ages, and totally unworthy the Head of a civilized nation. He has constrained our fellow Citizens taken Captive on the high Seas to bear Arms against their Country, to become the executioners of their friends and Brethren, or to fall themselves by their Hands. He has excited domestic insurrections amongst us, and has endeavoured to bring on the inhabitants of our frontiers, the merciless Indian Savages, whose known rule of warfare, is an undistinguished destruction of all ages, sexes and conditions. ";
  drawDeclaration(2050);
  fun2(100);
  scrolltext = "      In every stage of these Oppressions We have Petitioned for Redress in the most humble terms: Our repeated Petitions have been answered only by repeated injury. A Prince whose character is thus marked by every act which may define a Tyrant, is unfit to be the ruler of a free people. Nor have We been wanting in attentions to our Brittish brethren. We have warned them from time to time of attempts by their legislature to extend an unwarrantable jurisdiction over us. We have reminded them of the circumstances of our emigration and settlement here. We have appealed to their native justice and magnanimity, and we have conjured them by the ties of our common kindred to disavow these usurpations, which, would inevitably interrupt our connections and correspondence. They too have been deaf to the voice of justice and of consanguinity. We must, therefore, acquiesce in the necessity, which denounces our Separation, and hold them, as we hold the rest of mankind, Enemies in War, in Peace Friends. We, therefore, the Representatives of the united States of America, in General Congress, Assembled, appealing to the Supreme Judge of the world for the rectitude of our intentions, do, in the Name, and by Authority of the good People of these Colonies, solemnly publish and declare, That these United Colonies are, and of Right ought to be Free and Independent States; that they are Absolved from all Allegiance to the British Crown, and that all political connection between them and the State of Great Britain, is and ought to be totally dissolved; and that as Free and Independent States, they have full Power to levy War, conclude Peace, contract Alliances, establish Commerce, and to do all other Acts and Things which Independent States may of right do. And for the support of this Declaration, with a firm reliance on the protection of divine Providence, we mutually pledge to each other our Lives, our Fortunes and our sacred Honor. ";
  drawDeclaration(1950);
  fun2(100);
  scrolltext = "      Georgia Button Gwinnett Lyman Hall George Walton North Carolina William Hooper Joseph Hewes John Penn South Carolina Edward Rutledge Thomas Heyward, Jr. Thomas Lynch, Jr. Arthur Middleton Massachusetts John Hancock Maryland Samuel Chase William Paca Thomas Stone Charles Carroll of Carrollton Virginia George Wythe Richard Henry Lee Thomas Jefferson Benjamin Harrison Thomas Nelson, Jr. Francis Lightfoot Lee Carter Braxton Pennsylvania Robert Morris Benjamin Rush Benjamin Franklin John Morton George Clymer James Smith George Taylor James Wilson George Ross Delaware Caesar Rodney George Read Thomas McKean New York William Floyd Philip Livingston Francis Lewis Lewis Morris New Jersey Richard Stockton John Witherspoon Francis Hopkinson John Hart Abraham Clark New Hampshire Josiah Bartlett William Whipple Massachusetts Samuel Adams John Adams Robert Treat Paine Elbridge Gerry Rhode Island Stephen Hopkins William Ellery Connecticut Roger Sherman Samuel Huntington William Williams Oliver Wolcott New Hampshire Matthew Thornton";
  drawDeclaration(1040);
  fun2(100);
}

void drawDeclaration (int times){
  //scrolltext = "      In Congress, July 4, 1776 The unanimous Declaration of the thirteen united States of America, When in the Course of human events, it becomes necessary for one people to dissolve the political bands which have connected them with another, and to assume among the powers of the earth, the separate and equal station to which the Laws of Nature and of Nature's God entitle them, a decent respect to the opinions of mankind requires that they should declare the causes which impel them to the separation. We hold these truths to be self-evident, that all men are created equal, that they are endowed by their Creator with certain unalienable Rights, that among these are Life, Liberty and the pursuit of Happiness.--That to secure these rights, Governments are instituted among Men, deriving their just powers from the consent of the governed, --That whenever any Form of Government becomes destructive of these ends, it is the Right of the People to alter or to abolish it, and to institute new Government, laying its foundation on such principles and organizing its powers in such form, as to them shall seem most likely to effect their Safety and Happiness. Prudence, indeed, will dictate that Governments long established should not be changed for light and transient causes; and accordingly all experience hath shewn, that mankind are more disposed to suffer, while evils are sufferable, than to right themselves by abolishing the forms to which they are accustomed. But when a long train of abuses and usurpations, pursuing invariably the same Object evinces a design to reduce them under absolute Despotism, it is their right, it is their duty, to throw off such Government, and to provide new Guards for their future security.--Such has been the patient sufferance of these Colonies; and such is now the necessity which constrains them to alter their former Systems of Government. The history of the present King of Great Britain is a history of repeated injuries and usurpations, all having in direct object the establishment of an absolute Tyranny over these States. To prove this, let Facts be submitted to a candid world. ";
  stlength = scrolltext.length();
  runs = 0;
  stRuns = 0;
  for(uint8_t x=0; x<(times); x++){
      for(uint8_t x=0; x<6; x++){
        
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));

        matrix.setTextSize(1);

        matrix.setCursor(2, 0);
        //matrix.print("~SPONSORS~");
        
        matrix.setCursor(0-x, 4);
        matrix.print(scrolltext.charAt(stRuns));
        matrix.setCursor(6-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 1));
        matrix.setCursor(12-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 2));
        matrix.setCursor(18-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 3));
        matrix.setCursor(24-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 4));
        matrix.setCursor(30-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 5));
        matrix.setCursor(36-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 6));
        matrix.setCursor(42-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 7));
        matrix.setCursor(48-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 8));
        matrix.setCursor(54-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 9));
        matrix.setCursor(60-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 10));
        matrix.setCursor(66-x, 4);
        matrix.print(scrolltext.charAt(stRuns + 11));

        matrix.fillRect(0, 12, 64, 16, matrix.color565(0, 0, 0));
        
        matrix.show();
        fun2(5);
        
      }
      stRuns++;
      runs++;
      if(runs > times){
        break;
      }
    }
}

void drawSponsors (void){
  scrolltext = "          West Albany High School/South Albany High School/Albany Public Schools Foundation/Redhawk Flight Club/Knife River/HP Inc./No Dinx/Argosy Foundation/LAM Research/Autodesk/Tektronix/Linn County Fair, Albany, OR/Benton County Fair Corvallis, OR/Albany Parks & Recreation/Altrusa International Foundation/Harbor Freight/CADD Connection, BIM Connection/Concept Systems/First Force/FIRST/Intel/Oregon Robotics Tournament & Outreach Program/Nuscale/Selmet Inc/Party Perfection/Linn Veterinary Hospital P.C./Bottle Drop/KFIR 720 AM/Marie Lamfrom Foundation/Ram Steelco/Central Welding Supply/Burcham's Metals/Batteries + Bulbs/Albany American Legion Post 10/Chase Bank/Optimist Club/Nathan Guthrie/Eric Shilling/Sean & JulieBeth Wilson/Melanie Cunningham/Doug & Roberta Cogswell/Eric Chamberlain/Janice & David Brown/Ivan & Nadine/Flossie & Family/Toney Cunningham Williams/Jason Yutzie/ AND THE REST!";
  stlength = scrolltext.length();
  runs = 0;
  stRuns = 0;
  for(uint8_t x=0; x<(900); x++){
      for(uint8_t x=0; x<6; x++){
        
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));

        matrix.setTextSize(1);

        matrix.setCursor(2, 0);
        matrix.print("~SPONSORS~");
        
        matrix.setCursor(0-x, 8);
        matrix.print(scrolltext.charAt(stRuns));
        matrix.setCursor(6-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 1));
        matrix.setCursor(12-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 2));
        matrix.setCursor(18-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 3));
        matrix.setCursor(24-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 4));
        matrix.setCursor(30-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 5));
        matrix.setCursor(36-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 6));
        matrix.setCursor(42-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 7));
        matrix.setCursor(48-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 8));
        matrix.setCursor(54-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 9));
        matrix.setCursor(60-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 10));
        matrix.setCursor(66-x, 8);
        matrix.print(scrolltext.charAt(stRuns + 11));
        
        matrix.show();
        fun2(5);
        
      }
      stRuns++;
      runs++;
      if(runs > 915){
        break;
      }
    }
}

void drawScrolltext(String scrolltextString){
  
  //scrolltext = "      Huzzah! how long can we make this?";
  //scrolltext = "      Lakemonsters love SWARM! ~ SAFETY THIRD!";
  //scrolltext = "      YE - 4662 ~~~ Hi Mom! Hi Dad! - ORF";
  //scrolltext = "      OBAMA - 2915 ~~~ GO HEDGEHOGS! - 2898";
  //scrolltext = "      HI MOM! IM ON TV!";
  //Q31
  //scrolltext = "      things could be going better...";
  //scrolltext = "      things ARE going slightly better"; //unused
  //scrolltext = "      AMONGUS & GLHF - 2374 ~~~  GO BB! - 5975";
  //scrolltext = "      NOTHING IN PARTICULAR - 1425 ~~~ I THINK WE'RE GOOD - 6465";
  //scrolltext = "      SPOON - 4488 ~~~ PESTO - 1540";
  //scrolltext = "      6343 SOCCER BOT ~~~ I DON'T KNOW GO RED ALLIANCE THERE YOU GO - 2471";
  //scrolltext = "      THE RIZZLER - 2635 ~~~ IT'S NEVER AS FUNNY THE 2ND TIME AROUND - 4127";
  //scrolltext = "      PESTO IS THE BESTO - 1540 ~~~ I BELIEVE THAT WE WILL WIN! - 2374";

  //scrolltext = "      Hi Mom!";
  //scrolltext = "      No swerve? - 997";
  //scrolltext = "     Stay stealthy folks! - 4089 ~~~ o7 o7 o7 o7 o7 o7 - 2898";
  //scrolltext = "     I don't know, I'm gonna be honest - 2990";

  //scrolltext = "      Alright I don't have anything - 1425";
  //scrolltext = "      Go Sam! - 7034 ~~~ Obama prism - 847";
  //scrolltext = "      Blue Thunder - 2811 ~~~ Tank Drive Forever! - 2733";
  //scrolltext = "      BLUE ALLIANCE! - 2521 ~~~ LET'S HOPE THE AUTO WORKS! - 2471";
  //scrolltext = "      PESTO IS THE BESTO - 1540 ~~~ NO RP????? - 3636";
  //scrolltext = "      We love 5468! ~~~ We're doing okay! - 6465";
  //scrolltext = "      RIZZBOT - 2635 ~~~ CLIP IT! - 3673";
  //scrolltext = "      FIMSH <3 - 5975 ~~~ AARG! - 1359";
  //scrolltext = "      It's been real.";
  //scrolltext = "      The 'S' in SWARM stands for South!";
  scrolltext = "      The 'S' in SWARM stands for South!";

  matrix.setTextSize(2);

  //Split serial input into parts by each comma in the string
  str_len = scrolltext.length();

  stlength = (str_len*12)+128;

  stRuns = 0;

  for(uint8_t x=0; x<(str_len + 1); x++){
    for(uint8_t x=0; x<12; x++){
      matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
      matrix.setCursor(0-x, 0);
      matrix.print(scrolltext.charAt(stRuns));
      matrix.setCursor(12-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 1));
      matrix.setCursor(24-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 2));
      matrix.setCursor(36-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 3));
      matrix.setCursor(48-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 4));
      matrix.setCursor(60-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 5));
      matrix.setCursor(72-x, 0);
      matrix.print(scrolltext.charAt(stRuns + 6));
      matrix.show();
      fun2(8);
    }
    stRuns++;
  }
}

void drawSlider(int sliderType, int x_off, int y_off){
  if(sliderType == 1){
    drawFRC(x_off, y_off);
  }else if(sliderType == 2){
    drawAmogus(x_off, y_off);
  }
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
    fun2(500);
    for(uint8_t x=0; x<65; x++){
      matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
      
      drawSlider(sliderSelect, -32+x, 0);
      matrix.show();
      fun2(5);
    }
    fun2(500);
    reps = random(0, 5);
    for(uint8_t x=0; x<reps; x++){
      for(uint8_t x=0; x<33; x++){
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
        
        drawSlider(sliderSelect, 32-x, 0);
        matrix.show();
        fun2(5);
      }
      fun2(500);
      for(uint8_t x=0; x<33; x++){
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));
        
        drawSlider(sliderSelect, x, 0);
        matrix.show();
        fun2(5);
      }
      fun2(500);
    }
    for(uint8_t x=0; x<95; x++){
        matrix.fillRect(0, 0, 64, 16, matrix.color565(0, 0, 0));

        drawSlider(sliderSelect, 32-x, 0);
        matrix.show();
        fun2(5);
    }
  }
  
  //Animation type (leave 0 for random), message type (2 for "WE LOVE", 3 for "SWARM"
  if(dispType == 2){
    randSelect = random(1, 3);
    if(randSelect == 1){
      draw_we_love_animated();
      fun2(dlength);
    }else{
      drawScreen(0, 2); 
      fun2(dlength);
    }
  }
  if(dispType == 3){
    randSelect = random(1, 3);
    if(randSelect == 1){
      drawScreen(0, 3); 
      //draw_swarm_animated();
      fun2(dlength);
    }else{
      drawScreen(0, 3); 
      fun2(dlength);
    }
  }

  if(dispType == 4){
    draw_we_love_animated();
    fun2(dlength);
  }

  if(dispType == 5){
    draw_swarm_animated();
    fun2(dlength);
  }

  if(dispType == 6){
    drawScrolltext("HEY, THERE");
    fun2(1000);
  }

  if(dispType == 7){
    //drawSponsors();
    //drawDeclarationFull();
    fun2(1000);
  }

    if(dispType == 8){
    drawSponsors();
    //drawDeclaration();
    fun2(1000);
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
