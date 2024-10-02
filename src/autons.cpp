#include "main.h"

void redSoloWP(){
    chassis.setPose(-55,-42,240);
    chassis.moveToPoint(-29.267, -27.114, 1500);
}

void blueSoloWP(){
    chassis.moveToPoint(10, 10, 1000);
}

void fourRingRed(){
    chassis.setPose(-55,-42,240);
    chassis.moveToPoint(-29.267, -27.114, 1500);
}

void fourRingBlue(){
    chassis.moveToPoint(10, 10, 1000);
}

void skills(){
    chassis.moveToPoint(10, 10, 1000);
}