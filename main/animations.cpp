
#include <Adafruit_Protomatter.h>
#include "patterns.h"
#include "animations.h"

extern Adafruit_Protomatter matrix;

extern uint8_t R;
extern uint8_t G;
extern uint8_t B;

extern String ap1d;
extern String ap2d;
extern int length;

int numberStartX;
extern int dlength;

extern void fun(int del_len);

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
    fun(10);
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
      fun(100);
    }else if(x < 32){
      matrix.setTextColor(matrix.color565(255,255,0)); //set text color to yellow
      matrix.setCursor(1, 0);
      matrix.print("S");
      matrix.setCursor(7, 32-x);
      matrix.print("W");
      matrix.show();
      fun(100);
      
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
  fun(dlength);
  
}