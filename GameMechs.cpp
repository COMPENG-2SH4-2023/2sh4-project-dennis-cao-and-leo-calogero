#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
    loseFlag = false;
    exitFlag = false;
    objPos foodPos;


}

GameMechs::GameMechs(int boardX, int boardY)
{
    boardSizeX = boardX;
    boardSizeY = boardY;
    score = 0;
    loseFlag = false;
    exitFlag = false;
}

// do you need a destructor?



bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}

bool GameMechs ::  getLoseFlagStatus()
{
    return loseFlag;
}

char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        return MacUILib_getChar();
    }
    return 0;
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}

int GameMechs::getScore()
{
    return score;
}


void GameMechs::setExitTrue()
{
    exitFlag = true;
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;
}

void GameMechs::setInput(char this_input)
{
    input = this_input;
}

void GameMechs::clearInput()
{
    input = 0;
}

void GameMechs::incrementScore()
{
    score +=1;
}

void GameMechs::generateFood(objPos blockOff)
{
    int candidate_x = 0;
    int candidate_y = 0;
    bool candidate_found = false;
    srand(time(NULL));

    while(candidate_found != true);
    {
        candidate_x = (rand() % (boardSizeX - 2)) + 1;
        candidate_y = (rand() % (boardSizeY - 2)) + 1;

        foodPos.setObjPos(candidate_x, candidate_y, 'O');
        if (!(foodPos.isPosEqual(&blockOff)))
        {
            return;
        }
    }
    
}

void GameMechs::getFoodPos(objPos &returnPos)
{
    foodPos.getObjPos(returnPos);
}





