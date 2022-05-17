//
// Created by abe on 5/11/22.
//

#include <iostream>
#include <math.h>
#include "WonkyTimer.h"

WonkyTimer::WonkyTimer(float milliseconds) {
    ms = milliseconds;
}

void WonkyTimer::addDeltaTime(float deltaTime) {
    timeAccumulator += deltaTime * 1000.0f;
    //seconds = floor(timeAccumulator);
    if(timeAccumulator >= ms) {
        trigger = true;
        //listener should set it to false;
        timeAccumulator = 0.0f;
    }
    //std::cout<<" "<<std::endl;
    //std::cout<<"time " << timeAccumulator<<std::endl;
    //std::cout<<"seconds " << seconds <<std::endl;
}


WonkyTimer::~WonkyTimer() {

}


