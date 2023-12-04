#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

using namespace std;


class GameMechs
{
    // Construct the remaining declaration from the project manual.

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    private:
        char input;
        bool exitFlag;
        bool loseFlag;
        int score;
        int boardSizeX;
        int boardSizeY;
       // objPosArrayList* foodBucket;
        objPos foodPos;
        
    public:
        //constructors
        GameMechs();
        GameMechs(int boardX, int boardY);
        //getter methods
        bool getExitFlagStatus();
        bool getLoseFlagStatus();
        char getInput();
        int getBoardSizeX();
        int getBoardSizeY();
        int getScore();

        //setter methods
        void setExitTrue();
        void setLoseFlag();
        void setInput(char this_input);
        void clearInput();
        void incrementScore();

       //more methods

       void generateFood(objPosArrayList* blockOff);
       void getFoodPos(objPos &returnPos);

        
      

};

#endif