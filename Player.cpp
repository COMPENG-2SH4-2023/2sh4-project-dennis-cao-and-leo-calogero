#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    objPos tempPos; //creating a temp object to store our head
    tempPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2, mainGameMechsRef->getBoardSizeY()/2, '*'); //initial x ,y , symbol
    //setting the object head as default
    playerPosList = new objPosArrayList();
    //creating a new list on the heap with the name playerPosList
    playerPosList->insertHead(tempPos);
    //insert the newly created head to start

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
    objPos tempPos;

    //setting out currentHead object to the next iteration based on the processing in updatePlayerDir; 
    // stored in new object, not body yet.
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
    //inserting the new head
    playerPosList -> insertHead(currentHead);

    //if we consume a food, we will not remove the tail
    // if we do not consume a food, we remove tail to show movement of the snake body
    if(checkFoodConsumption() == false)
    {
        
        playerPosList -> removeTail();
    }
  
    //checking for loser condition
    //looping through the body, such that if headpos = position of any other element, loseflag is set to true
    for (int i = 1; i < playerPosList -> getSize(); i++)
    {
        playerPosList -> getElement(tempPos, i);
        if (currentHead.isPosEqual(&tempPos))
        {
            mainGameMechsRef -> setLoseFlag();
        }
    }
}

bool Player::checkFoodConsumption()
{
    //checking if the food position is equal to the head position, true if it is, false if not
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