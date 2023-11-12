
#include <Adafruit_Protomatter.h>

extern Adafruit_Protomatter matrix;

extern uint8_t R;
extern uint8_t G;
extern uint8_t B;

extern String ap1d;
extern String ap2d;
extern int length;

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

void drawAmogus(int x_off, int y_off){
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

void select_disp(int message, int x_off, int y_off){
  //Self-explanatory: selects whether or not to display the We Love or SWARM message
  if(message == 2){
    draw_we_love_static(x_off, y_off);
  }else if(message == 3){
    draw_swarm(x_off, y_off);
  }
}

void drawSlider(int sliderType, int x_off, int y_off){
  if(sliderType == 1){
    drawFRC(x_off, y_off);
  }else if(sliderType == 2){
    drawAmogus(x_off, y_off);
  }
}