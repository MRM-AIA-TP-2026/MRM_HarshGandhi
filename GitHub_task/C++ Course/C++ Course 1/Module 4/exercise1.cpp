////////// DO NOT EDIT HEADER! //////////
#include <iostream>                    //
#include "CTurtle.hpp"                 //
#include "CImg.h"                      //
using namespace cturtle;               //
using namespace std;                   //
/////////////////////////////////////////

int main(int argc, char** argv) {
  
  TurtleScreen screen(400, 300); //You may edit the dimensions to fit your window
  Turtle tina(screen);
  tina.speed(TS_SLOWEST);
  
  //add code below this line
  for (int i = 0; i < 3; i++) { // Loop 3 times for 3 sides
    tina.forward(100);          // Move forward by 100 pixels
    tina.left(120);             // Turn left by 120 degrees to form an equilateral triangle
  }


  //add code above this line
  
  screen.exitonclick();
  return 0;
  
}
