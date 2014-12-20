#include <MeggyJrSimple.h>
// global variables go here
int xcoord = 0;
int ycoord = 0;

int C3x = 4;
int C3y = 5;
int B3x = 6;
int B3y = 2;
int A3x = 2;
int A3y = 3;
int D3x = 0;
int D3y = 4;

struct Point
{
  /*int x;
  int y;*/
  int C3x;
  int C3y;
  int B3x;
  int B3y;
  int A3x;
  int A3y;
  int D3x;
  int D3y;
  
  
  //boolean visited;
};

Point p1={C3x,C3y};
Point p2={B3x,B3y};
Point p3={A3x,A3y};
Point p4={D3x,D3y};

Point dotArray[64]={p1,p2,p3,p4};

int marker=4;

void setup()
{
  MeggyJrSimpleSetup();
  Serial.begin(9600); // code to show the points of variables
}




void loop() // loop code that goes through loop
{
  shift();
  DrawPx(p1.C3x,p1.C3y,Violet);
  DrawPx(xcoord,ycoord,Blue); // draw dot
  dotsound(); // make sounds from dots

  /*
  drawlevel
  updatelevel
  */
  DisplaySlate();
  delay(150);
  ClearSlate();
  
  /*
  (make 2 arrays: level array, level completion array,
  compare level completion array to level array see if player completed
    neccesary steps to complete level
  if player meets requirements, update level array
  
  psudo code:
  * game starts with first level of dots from level array and player coursor
  on screen,
  * player moves coursor and can press A when on a dot to play a sound (will
  need to make a sound method for having certain dots make a certain sound),
  * use didIwin method (boolean) to compaire the completion and level arrays,
  * if true allow level array to update to make the next leve and completion
   array to update for the next level,
  * 
  
  
  */
}


void shift() // taken from Maze_Game of Brennan Brown
{
  CheckButtonsDown();
  if (Button_Right)
    {
      if (xcoord < 7)
      xcoord = xcoord + 1; // indented because belongs to inner if statement;
                           //  could also say xcoord++
      if (xcoord == 7)
        Tone_Start (ToneC3,100);
    }
    
  if (Button_Left)
    {
      if (xcoord > 0)
      xcoord = xcoord - 1;
      if (xcoord == 0)
      Tone_Start (ToneC3,100);
    }
    
  if (Button_Up)
    {
      if (ycoord < 7)
      ycoord = ycoord + 1;
      if (ycoord == 7)
      Tone_Start (ToneC3,100); // play error sound when go off screen
    }
    
   if (Button_Down)
    {
      if (ycoord > 0)
      ycoord = ycoord - 1;
      if (ycoord == 0)
      Tone_Start (ToneC3,100); // play error sound when go off screen
    }
}

void dotsound() // simple code to make dots create sound
{
 CheckButtonsDown();
 if (Button_A)
 {
  if (ReadPx(xcoord == dotArray[0].C3x,ycoord == dotArray[0].C3y) == Violet)
   {
     Tone_Start (ToneC3,300);
   }
   DrawPx(0,0,15);
 }
}

