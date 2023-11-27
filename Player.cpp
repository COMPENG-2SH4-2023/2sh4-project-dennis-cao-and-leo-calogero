#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    playerPos.setObjPos(mainGameMechsRef.boardSizeX/2, mainGameMechsRef.boardSizeY/2, '@'); //initial x ,y , symbol

}


Player::~Player()
{
    //will be implemented during iteration 3
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    returnPos.setObjPos(playerPos.x,playerPos.y, playerPos.symbol);
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    //verify on monday
    char input= mainGameMechsRef->GetInput();

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
                if (myDir!= LEFT && myDir!= RIGHT) //move left/right
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
     switch(myDir)
    {
        case RIGHT: 
            player.x+=1;
            break;
        case LEFT: 
            player.x-=1;
            break;
        case UP: 
            player.y-=1;
            break;
        case DOWN: 
            player.y+=1;
            break;
        default:
            break;    
    }
  
}

