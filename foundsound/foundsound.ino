#include <MeggyJrSimple.h>
// global variables go here
int xcoord = 0; // x coord of cursor
int ycoord = 0; // y coord of cursor

int Level = 1;


void setup()
{
  MeggyJrSimpleSetup();
  Serial.begin(9600); // code to show the points of variables
}




void loop() // loop code that goes through loop
{
  shift(); // to make coursor work
  DrawPx(xcoord,ycoord,Blue); // draw coursor
  if (Level == 1) // level desing with help from Mrs. Kiang
  {
    DrawLevel1();
  }

  /*
  drawlevel
  updatelevel
  */
  DisplaySlate();
  delay(150);
  ClearSlate();
  
  /*
  
  // will need to change the psudo code
  
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
  DrawPx(4,5,Violet);
  DrawPx(6,2,Green);
  DrawPx(2,3,Red);
  DrawPx(0,4,White);
  CheckButtonsDown();
 if (Button_A)
 {
   if (xcoord == 4)
    {
      if (ycoord == 5)
       {
         Tone_Start (ToneC3,300);
       }
     }
   if (xcoord == 6)
     {
       if (ycoord == 2)
         {
           Tone_Start (ToneD3,300);
         }
     }
   if (xcoord == 2)
     {
       if (ycoord == 3)
         {
           Tone_Start (ToneA3,300);
         }
     } 
   if (xcoord == 0)
     {
       if (ycoord == 4)
         {
           Tone_Start (ToneB3,300);
         }
     }
 }
}
