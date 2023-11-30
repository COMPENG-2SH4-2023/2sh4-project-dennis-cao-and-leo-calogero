#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

//bool exitFlag;
GameMechs *mechanics;
Player *player1;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(mechanics->getExitFlagStatus() == false)  
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
    MacUILib_clearScreen();
    MacUILib_init();
    mechanics = new GameMechs();
    player1= new Player(mechanics);
    
    objPosArrayList *playerBody = player1->getPlayerPos();
    objPos playerPos;
    playerBody -> getHeadElement(playerPos);
   
    mechanics ->generateFood(playerBody);
    //exitFlag = false; this is implied in game mechainics
    
}

void GetInput(void)
{
   mechanics->getInput();
   
}

void RunLogic(void)
{
    
    objPosArrayList *playerBody = player1->getPlayerPos();
    objPos playerPos;
    playerBody -> getHeadElement(playerPos);
   
    
    player1->updatePlayerDir();
    player1->movePlayer();
    if (player1->checkFoodConsumption() == true)
    {
        mechanics -> incrementScore();
        mechanics -> generateFood(playerBody);
    }
    //testing stuff
    /*
    if (mechanics -> getInput() == 'p')
    {
        mechanics ->generateFood(playerPos);
    
    }
    */

    
    mechanics -> clearInput();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();
    int x_bound=mechanics->getBoardSizeX();
    int y_bound=mechanics->getBoardSizeY();
    objPos foodPos;
    objPos tempBody;
    objPosArrayList *playerBody = player1->getPlayerPos();
    mechanics -> getFoodPos(foodPos);
    bool drawn;
     int X,Y; // 
   
    for(Y=0; Y< y_bound ; Y++)
    {
        for(X=0; X <x_bound ; X++)
        {
            for (int k =0; k < playerBody ->getSize(); k++)
            {
                drawn = false;
                playerBody -> getElement(tempBody, k);
                if(tempBody.x == X && tempBody.y == Y)
                {
                    MacUILib_printf("%c", tempBody.symbol);
                    drawn = true;
                    break;
                }
            }

            if(drawn) continue;
            if ( (X==0) || X== (x_bound-1) || (Y==0) || (Y== y_bound-1) )
            {
                MacUILib_printf("#");
            } 
            
            else if(X == foodPos.x && Y == foodPos.y)
            {
                MacUILib_printf("%c", foodPos.symbol);
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");

    } 
    MacUILib_printf("Player Position: <%d, %d>\n", tempBody.x, tempBody.y); 
    MacUILib_printf("Your Score is: %d ", mechanics -> getScore());
    if (mechanics -> getLoseFlagStatus() == true)
    {
        MacUILib_printf("YOU ARE A LOSER\n");
        mechanics -> setExitTrue();
    }

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{  
    delete player1;
    delete mechanics;
    MacUILib_uninit();
}
