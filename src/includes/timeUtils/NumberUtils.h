//
// Created by abe on 5/18/22.
//

#ifndef MY_CCP_GAME_NUMBERUTILS_H
#define MY_CCP_GAME_NUMBERUTILS_H


class NumberUtils {
public:
    NumberUtils();
    bool  first = true;
    virtual ~NumberUtils();

    int getRandom(int min, int max);
};


#endif //MY_CCP_GAME_NUMBERUTILS_H
