#include "main.h"
#include "pros/gps.hpp"

void detectSide(){
    if (gps.get_position_x() < 0){
        blueSide = true;
    }
    else {
        blueSide = false;
    }
}

void fourRingDeterminer(){
    if (!blueSide){
        SoloWP();
    }
    else {
        blueSoloWP();
    }
}


//auton select
//read side of field
//change bool value based on side
//run auton
