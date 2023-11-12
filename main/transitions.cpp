
#include <Adafruit_Protomatter.h>
#include "patterns.h"

extern Adafruit_Protomatter matrix;

extern int clearType;
extern double animType;

extern void fun(int del_len);

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
           fun(anim_del_len);
        }
      }else if(animType == 2){ //Circle from center of each board
        for(uint8_t x=0; x<33; x++) { //2 circles from center of each board
           matrix.fillCircle(16, 8, x, matrix.color565(R, G, B));
           matrix.fillCircle(48, 8, x, matrix.color565(R, G, B));
           matrix.show();
           fun(anim_del_len);
        }
      }else if(animType == 3){ //Rectangle from bottom right corner
        for(uint8_t x=0; x<33; x++) {
           matrix.fillRect(16-x, 8-x, 16+x, 8+x, matrix.color565(R, G, B));
           matrix.fillRect(48-x, 8-x, 48+x, 8+x, matrix.color565(R, G, B));
           matrix.show();
           fun(anim_del_len);
        }    
      }else if(animType == 4){ 
        for(uint8_t x=0; x<33; x++) { //lines from corners
           matrix.drawLine(0, 0, x, 16, matrix.color565(R, G, B));
           matrix.drawLine(32, 16, 32-x, 0, matrix.color565(R, G, B));
           matrix.drawLine(32, 0, 32+x, 16, matrix.color565(R, G, B));
           matrix.drawLine(64, 16, 64-x, 0, matrix.color565(R, G, B));
           matrix.show();
           fun(anim_del_len);
        }  
      }else if(animType == 5){
        for(uint8_t x=0; x<33; x++) { //lines from corners 2
           matrix.drawLine(0, 16, x, 0, matrix.color565(R, G, B));
           matrix.drawLine(32, 0, 32-x, 16, matrix.color565(R, G, B));
           matrix.drawLine(32, 16, 32+x, 0, matrix.color565(R, G, B));
           matrix.drawLine(64, 0, 64-x, 16, matrix.color565(R, G, B));
           matrix.show();
           fun(anim_del_len);
        }  
      }else if(animType == 6){ //4 large rectangles, each covering half a board
        for(uint8_t y=0; y<17; y++) {
           matrix.fillRect(0, 0, 16, y, matrix.color565(R, G, B));
           matrix.fillRect(48, 0, 64, y, matrix.color565(R, G, B));
           matrix.show();
           fun(anim_del_len);
        }
        for(uint8_t y=0; y<17; y++) {
           matrix.fillRect(16, 0, 32, y, matrix.color565(R, G, B));
           matrix.fillRect(32, 0, 48, y, matrix.color565(R, G, B));
           matrix.show();
           fun(anim_del_len);
        } 
      }else if(animType == 7){ //3 circles, from the edges of each board
        for(uint8_t x=0; x<33; x++) {
           matrix.fillCircle(0, 8, x, matrix.color565(R, G, B));
           matrix.fillCircle(32, 8, x, matrix.color565(R, G, B));
           matrix.fillCircle(64, 8, x, matrix.color565(R, G, B));
           matrix.show();
           fun(anim_del_len);
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
           fun(anim_del_len);
        } 
      }else if(animType == 9){ //Windshield wipers
        for(uint8_t y=0; y<17; y++) {
           matrix.drawLine(16, 0, 0, y, matrix.color565(R, G, B));
           matrix.drawLine(17, 0, 32, y, matrix.color565(R, G, B));
           matrix.drawLine(48, 0, 32, y, matrix.color565(R, G, B));
           matrix.drawLine(49, 0, 64, y, matrix.color565(R, G, B));
           matrix.show();
           fun(anim_del_len);
        }
        for(uint8_t x=0; x<17; x++) {
           matrix.drawLine(16, 0, x, 16, matrix.color565(R, G, B));
           matrix.drawLine(17, 0, 32-x, 16, matrix.color565(R, G, B));
           matrix.drawLine(48, 0, 32+x, 16, matrix.color565(R, G, B));
           matrix.drawLine(49, 0, 64-x, 16, matrix.color565(R, G, B));
           matrix.show();
           fun(anim_del_len);
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
           fun(anim_del_len);
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
           fun(anim_del_len);
        }
      }else if(animType == 11){ //Slant angled towards top left
        for(uint8_t x=0; x<50; x++) {
           matrix.drawLine(x-16, 0, x, 16, matrix.color565(R, G, B));
           matrix.drawLine(80-x, 0, 64-x, 16, matrix.color565(R, G, B));
           matrix.show();
           fun(anim_del_len);
        }
      }else if(animType == 12){ //Slant angled towards top right
        for(uint8_t x=0; x<50; x++) {
           matrix.drawLine(x, 0, x-16, 16, matrix.color565(R, G, B));
           matrix.drawLine(64-x, 0, 80-x, 16, matrix.color565(R, G, B));
           matrix.show();
           fun(anim_del_len);
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
           fun(anim_del_len);
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
           fun(anim_del_len);
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
           fun(anim_del_len);
        }
        fun(1000);
        for(uint8_t x=0; x<32; x++) {
           matrix.drawLine(x, 0, x, 16, matrix.color565(0, 0, 0));
           matrix.drawLine(x+32, 0, x+32, 16, matrix.color565(0, 0, 0));
           matrix.show();
           fun(anim_del_len);
        }
      }else if(animType == 15){ //random pride flag
        for(uint8_t y=0; y<17; y++){
          matrix.fillRect(0, 0, 64, y, matrix.color565(0, 0, 0));
          matrix.show();
          fun(5);
        }
        for(uint8_t y=0; y<17; y++){
          //select_pride();
          matrix.fillRect(0, 0, 64, 16-y, matrix.color565(0, 0, 0));
          matrix.show();
          fun(5);
        }
        fun(1000);
        for(uint8_t x=0; x<32; x++) {
           matrix.drawLine(x, 0, x, 16, matrix.color565(0, 0, 0));
           matrix.drawLine(x+32, 0, x+32, 16, matrix.color565(0, 0, 0));
           matrix.show();
           fun(anim_del_len);
        }
      }
  }
  if(clearType == 2){
    //animType = random(1, 4);
    if(animType == 1){
      for(uint8_t x=0; x<65; x++){
        select_disp(message, 0-x, 0);
        matrix.show();
        fun(10);
      }
    }else if(animType == 2){
      for(uint8_t y=0; y<17; y++){
        select_disp(message, 0, y);
        matrix.show();
        fun(10);
      }
    }else if(animType == 3){
      for(uint8_t y=0; y<17; y++){
        select_disp(message, 0, 0-y);
        matrix.show();
        fun(10);
      }
    }
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
        fun(5);
      }
    }else if(animType == 2){ //Draw from center of both boards
      for(uint8_t x=0; x<65; x++){
        select_disp(message, 0, 0);
        matrix.fillCircle(32, 8, 32-x, matrix.color565(0, 0, 0));
        matrix.show();
        fun(5);
      }
    }else if(animType == 3){ //Draw from right side of both boards
      for(uint8_t x=0; x<65; x++){
        select_disp(message, 0, 0);
        matrix.fillRect(0, 0, (64-x), 16, matrix.color565(0, 0, 0));
        matrix.show();
        fun(2);
      }
    }else if(animType == 4){
      for(uint8_t x=0; x<33; x++){
        select_disp(message, 0, 0);
        matrix.fillRect(x, 0, 64, 16, matrix.color565(0, 0, 0));
        matrix.show();
        fun(2);
      }
    }
  }else if(drawType == 2){ //slide into view
    animType = random(1, 4);
      if(animType == 1){
        for(uint8_t x=0; x<65; x++){
        select_disp(message, x-64, 0);
        matrix.show();
        fun(10);
      }
    }else if(animType == 2){
      for(uint8_t y=0; y<17; y++){
        select_disp(message, 0, 16-y);
        matrix.show();
        fun(10);
      }
    }else if(animType == 3){
      for(uint8_t y=0; y<17; y++){
        select_disp(message, 0, y-16);
        matrix.show();
        fun(10);
      }
    }
    
  }
}