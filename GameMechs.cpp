#include "GameMechs.h"
#include "MacUILib.h"

//constructors, setting default
GameMechs::GameMechs()
{
    boardSizeX = 30;
    boardSizeY = 15;
    score = 0;
    loseFlag = false;
    exitFlag = false;

    //foodBucket = new objPosArrayList();
    


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


//get exit flag
bool GameMechs::getExitFlagStatus()
{
    return exitFlag;
}
//get lose flag
bool GameMechs ::  getLoseFlagStatus()
{
    return loseFlag;
}
//get input
char GameMechs::getInput()
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }
    // getting input, if the input is a space, terminate
    if(input== ' ' )
    {
        exitFlag=true;
    }
    return input;
}
//getting X board size
int GameMechs::getBoardSizeX()
{
    return boardSizeX;
}
//getting Y board size
int GameMechs::getBoardSizeY()
{
    return boardSizeY;
}
//getting the score
int GameMechs::getScore()
{
    return score;
}
//setting our exit flag to be true to terminate

void GameMechs::setExitTrue()
{
    exitFlag = true;
}
//setting lose flag true to indicate loss
void GameMechs::setLoseFlag()
{
    loseFlag = true;
}
//function to set input if needed
void GameMechs::setInput(char this_input)
{
    input = this_input;
}
//clearing input after processing
void GameMechs::clearInput()
{
    input = 0;
}
//incrementing score by 1
void GameMechs::incrementScore()
{
    score +=1;
}

//generating our random food
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
        //checking for candidate
       
        foodPos.setObjPos(candidate_x, candidate_y, 'O');
        for (int i =0; i < (blockOff -> getSize()); i++)
        {
            blockOff -> getElement(tempPos, i);
            if (foodPos.isPosEqual(&tempPos))
            {
                candidate_notfound = true;
                break;
            }
        }
        
    }

}

void GameMechs::getFoodPos(objPos &returnPos)
{
    foodPos.getObjPos(returnPos);
}





