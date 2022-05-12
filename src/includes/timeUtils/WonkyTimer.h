//
// Created by abe on 5/11/22.
//

#ifndef MY_CCP_GAME_WONKYTIMER_H
#define MY_CCP_GAME_WONKYTIMER_H


class WonkyTimer {
public:
    float seconds =  0.0f;
    float timeAccumulator = 0.0f;
    WonkyTimer(float milliseconds);

    virtual ~WonkyTimer();

    void addDeltaTime(float deltaTime);

    float ms;
    bool trigger;
};


#endif //MY_CCP_GAME_WONKYTIMER_H
