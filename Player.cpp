#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos;
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*'); //initial x ,y , symbol
    playerPosList = new objPosArrayList();
    playerPosList->insertHead(tempPos);

}


Player::~Player()
{
    //will be implemented during iteration 3
    // delete any heap members here
    delete playerPosList;
}

objPosArrayList* Player::getPlayerPos()
{
    return playerPosList;
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    //verify on monday
    char input= mainGameMechsRef->getInput();

    

    switch(input)
    {
        case 'w':
                if (myDir!=UP && myDir!=DOWN) //not moving up or down 
                {
                    myDir=UP;
                }
                
                break;
        case 'a':
                if (myDir != LEFT && myDir != RIGHT) //not moving left or right
                {
                    myDir=LEFT;
                }
                
                break;
            
            case 's':
                if (myDir!= UP && myDir!= DOWN) //move left/right
                {
                    myDir=DOWN;
                }
                break;
            case 'd':
                if (myDir != LEFT && myDir != RIGHT) //moving up/down
                {
                   myDir=RIGHT;
                }
                break;
            default:
                break;
    }
    // PPA3 input processing logic        
}

void Player::movePlayer()
{
    objPos currentHead; //holding the information of the current head
    playerPosList->getHeadElement(currentHead);


     switch(myDir)
    {
        case RIGHT: 
            currentHead.x +=1;
            break;
        case LEFT: 
           currentHead.x-=1;
            break;
        case UP: 
            currentHead.y -=1;
            break;
        case DOWN: 
           currentHead.y+=1;
            break;
        default:
            break;    
    }

    if(currentHead.y==0)
    {
       currentHead.y=mainGameMechsRef->getBoardSizeY()-2; // wrap to bottom if at top
    }
    else if(currentHead.y==mainGameMechsRef->getBoardSizeY()-1) //at bottom, wrap to top
    {
        currentHead.y=1;
    }
    
    if (currentHead.x==0)
    {
        currentHead.x=mainGameMechsRef->getBoardSizeX()-2;
    }
    else if (currentHead.x==mainGameMechsRef->getBoardSizeX()-1)
    {
       currentHead.x= 1;
    }

    playerPosList -> insertHead(currentHead);
    if(checkFoodConsumption() == false)
    {
        
        playerPosList -> removeTail();
    }
  
}

bool Player::checkFoodConsumption()
{
    objPos foodPos;
    objPos tempPos;
    playerPosList -> getHeadElement(tempPos);
    mainGameMechsRef -> getFoodPos(foodPos);
    if (tempPos.isPosEqual(&foodPos))
    {
        return true;
    }
    else 
    {
        
        return false;
    }
}

/*void Player::increasePlayerLength()
{
    objPos tempPos;
    objPos tempFood;
    mainGameMechsRef -> getFoodPos(tempFood);
    playerPosList -> getHeadElement(tempPos);
    playerPosList -> insertHead(tempFood);
}
*/