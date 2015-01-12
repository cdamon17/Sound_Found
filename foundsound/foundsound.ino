/*
the goal of the game is to click on the colored dots with the A button
to make sounds and eventually win
*/


#include <MeggyJrSimple.h>
// global variables go here
int xcoord = 0; // x coord of cursor
int ycoord = 0; // y coord of cursor

int Level = 1; // levels

boolean dot1 = false; // dots to make level change
boolean dot2 = false;
boolean dot3 = false;
boolean dot4 = false;

void setup()
{
  MeggyJrSimpleSetup();
  Serial.begin(9600); // code to show the points of variables
}


void loop() // loop code that goes through loop
{
  ClearSlate();
  
  //levelcheck(); // code ment to check the first level win conditions
  // mod not needed because of changes for specific order
  
  if (Level == 1) // level change desing with help from Mrs. Kiang
  {
    DrawLevel1();
  }
  else if (Level == 2)
  {
    DrawLevel2();
  }
  
  shift(); // to make coursor work
  if (Level == 1)
  {
    DrawPx(xcoord,ycoord,Blue); // draw coursor
  }
  DisplaySlate();
  delay(150);
}
  


void shift() // taken from Maze_Game of Brennan Brown
{
  CheckButtonsDown();
  if (Button_Right)
    {
      if (xcoord == 7) // FIRST check to see i moving right would put the player
                     // out of bounds
        Tone_Start (ToneC3,100);
      
      if (xcoord < 7)// THEN the player is not already in column 7, add to the
                    // of x
        xcoord = xcoord +1; // indented because belongs to inner if statement;
                // could also say xcoord ++
    }
    
  if (Button_Left)
    {
      if (xcoord == 0)
        Tone_Start (ToneC3,100);
      if (xcoord > 0)
        xcoord = xcoord - 1;
    }
    
  if (Button_Up)
    {
      if (ycoord == 7)
        Tone_Start (ToneC3,100); // play error sound when go off screen
      if (ycoord < 7)
        ycoord = ycoord + 1;
    }
    
   if (Button_Down)
    {
      if (ycoord == 0)
        Tone_Start (ToneC3,100); // play error sound when go off screen
      if (ycoord > 0)
        ycoord = ycoord - 1;
    }
}

void DrawLevel1() // help from Mrs, Kiang about how to make levels
{
  DrawPx(1,2,Violet);
  DrawPx(3,5,Green);
  DrawPx(6,3,Red);
  DrawPx(0,7,White);
  CheckButtonsDown();
 if (Button_A)
 {
   if ((xcoord == 1) && (ycoord == 2))  
     {
       Tone_Start (ToneC3,300);
       dot1 = true;
     }
     
  else if ((xcoord == 3) && (ycoord == 5) && (dot1 == true)) // code to make
                                                            // dots true in a
                                                            // certain order
                                                            // with help from
                                                            // Mrs. kiang
       {
         Tone_Start (ToneD3,300);
         dot2 = true;
         
       }
     
   else if ((xcoord == 6) && (ycoord == 3) && (dot2 == true))
       {
         Tone_Start (ToneA3,300);
         dot3 = true;
       }
     
   else if ((xcoord == 0) && (ycoord == 7) && (dot3 == true))
       {
         Tone_Start (ToneB3,300);
         dot4 = true;
         Level = 2;
       }
 } // end of if button A
} // end of DrawLevel1

void DrawLevel2() // the second level, it spells WIN
{
   DrawPx(1,7,Yellow);
   DrawPx(2,6,Yellow);
   DrawPx(3,5,Yellow);
   DrawPx(4,6,Yellow);
   DrawPx(5,5,Yellow);
   DrawPx(6,6,Yellow);
   DrawPx(7,7,Yellow);
   
   DrawPx(1,3,Yellow);
   DrawPx(1,2,Yellow);
   DrawPx(1,1,Yellow);
   DrawPx(4,0,Yellow);
   DrawPx(4,1,Yellow);
   DrawPx(4,2,Yellow);
   DrawPx(4,3,Yellow);
   DrawPx(5,2,Yellow);
   DrawPx(6,1,Yellow);
   DrawPx(7,3,Yellow);
   DrawPx(7,2,Yellow);
   DrawPx(7,1,Yellow);
   DrawPx(7,0,Yellow);
  
}
