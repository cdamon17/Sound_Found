#include <MeggyJrSimple.h>
// global variables go here
int xcoord = 0;
int ycoord = 7;

void setup()
{
  MeggyJrSimpleSetup();
}
void loop()
{
  shift();
  DrawPx(xcoord,ycoord,Blue); // draw dot
  DisplaySlate();
  delay(150);
  ClearSlate();
}
void shift() // taken from Maze_Game
{
  CheckButtonsDown();
  if (Button_Right)
    {
      if (xcoord < 7)
      xcoord = xcoord + 1; // indented because belongs to inner if statement; could also say xcoord++
      if (ReadPx(xcoord, ycoord) == Green)
      xcoord = xcoord -1; // as soon as user lands on green pixel, go +1 pixels to original position
      if (xcoord == 7)
      Tone_Start (ToneC3,100);
    }
    
  if (Button_Left)
    {
      if (xcoord > 0)
      xcoord = xcoord - 1;
      if (ReadPx(xcoord, ycoord) == Green)
      xcoord = xcoord +1;
      if (xcoord == 0)
      Tone_Start (ToneC3,100);
    }
    
  if (Button_Up)
    {
      if (ycoord < 7)
      ycoord = ycoord + 1;
      if (ReadPx(xcoord, ycoord) == Green)
      ycoord = ycoord -1; // as soon as user lands on green pixel, go -1 pixels to original position
      if (ycoord == 7)
      Tone_Start (ToneC3,100); // play error sound when go off screen
    }
    
   if (Button_Down)
    {
      if (ycoord > 0)
      ycoord = ycoord - 1;
      if (ReadPx(xcoord, ycoord) == Green)
      ycoord = ycoord +1;
      if (ycoord == 0)
      Tone_Start (ToneC3,100); // play error sound when go off screen
    }
}

