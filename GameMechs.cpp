#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
    loseFlag = false;
    exitFlag = false;


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
        input = MacUILib_getChar();
    }
    
    if(input== ' ' )
    {
        exitFlag=true;
    }
    return input;
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

void GameMechs::generateFood(objPosArrayList* blockOff)
{
    //creating candidate positino for our food
    int candidate_x = 0;
    int candidate_y = 0;

    //setting a condition if our candidate is not found
    bool candidate_notfound = true;
    objPos tempPos;
    //tempPos to loop through the body
    srand(time(NULL));

    while(candidate_notfound == true)
    {
        candidate_notfound = false;
        candidate_x = (rand() % (boardSizeX - 2)) + 1;
        candidate_y = (rand() % (boardSizeY - 2)) + 1;
        //generating random x, y coordinate
       
        foodPos.setObjPos(candidate_x, candidate_y, 'O');
        //creating our food
        for (int i =0; i < (blockOff -> getSize()); i++)
        {
            blockOff -> getElement(tempPos, i);
            if (foodPos.isPosEqual(&tempPos))
            {
                //if we find an element that matches the position of our food, we will break and set not found to true
                // loop through and find a  new candidate
                candidate_notfound = true;
                break;
            }
        }
        
    }

}

void GameMechs::getFoodPos(objPos &returnPos)
{
    foodPos.getObjPos(returnPos);
    //return the position of food into the object
}





