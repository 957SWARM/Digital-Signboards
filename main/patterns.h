#ifndef PATTERNS_H
#define PATTERNS_H

typedef struct RGB {
  double r;
  double g;
  double b;
} RGB;

struct RGB colorConverter(int hexValue);
void drawFRC(int x_off, int y_off); //Drawn by Alex Antrim
void drawAmogus(int x_off, int y_off); //Drawn by Alex Antrim
void drawHeart(int x_off, int y_off); //Drawn by Miles Wilson
void draw_we_love_static(int x_off, int y_off); //Drawn by Miles Wilson
void draw_swarm(int x_off, int y_off); //Drawn by Miles Wilson
void select_disp(int message, int x_off, int y_off); //Drawn by Miles Wilson
void drawSlider(int sliderType, int x_off, int y_off); //Framework for all slider animations. Programmed by Miles Wilson.
void drawBeehive(); //Drawn by Alex Antrim
void drawFirework(); //Drawn by Alex Antrim
void drawBee(); //Drawn by Amaryllis Z.
void drawBeeHoney(); //Drawn by Amaryllis Z.
void drawFlyingBee(int x_off, int y_off); //Drawn by Amaryllis Z.
void draw957(); //Drawn by Amaryllis Z.
void draw957Pride(); //Drawn by Arden F.
void drawJellyfishAnim(); //Drawn by Sam Bishop
void drawEvilJellyAnim(); //Drawn by Jacoby Kalita
void drawShallowSea(); //Drawn by Dillon P.
void drawDeepSea(); //Drawn by Dillon P.
void drawJelly(); //Drawn by Braedon Kalita
void drawCrane(); //Drawn by Calvin Buchner
void drawFuel(); //Drawn by Calvin Buchner
void drawFuel957(); //Drawn by Calvin Buchner
void drawDrill(); //Drawn by Calvin Buchner
void drawSteamboat(); //Drawn by Calvin Buchner
void drawCementTruck(); //Drawn by Calvin Buchner
void drawFuelBee(); //Drawn by Calvin Buchner 
void drawAnniversary(); //Drawn by Henry Bishop
void drawAge(); //Drawn by Henry Bishop
void drawUnicornFuel(); //Drawn by Calvin Bucnher + KK R.
void drawMascots(); //Drawn by Jacoby Kalita
#endif