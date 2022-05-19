//
// Created by abe on 5/18/22.
//

#include <cstddef>
#include <ctime>
#include <cstdlib>
#include "NumberUtils.h"

NumberUtils::NumberUtils() {}

NumberUtils::~NumberUtils() {


}

//https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
int NumberUtils::getRandom(int min, int max) {
    if (first)
    {
        srand( time(NULL) ); //seeding for the first time only!
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}