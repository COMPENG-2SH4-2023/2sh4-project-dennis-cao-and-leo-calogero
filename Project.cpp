#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000
// SPACEBAR IS TO TERMINATE
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
    //creating our objects
    
    objPosArrayList *playerBody = player1->getPlayerPos();
    //getting playerposition
    objPos playerPos;
    playerBody -> getHeadElement(playerPos);
    //getting ourhead element
   
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
    //from the player1's objPosArrayList, we are creating a pointer to the playerBody.
    objPos playerPos;
    playerBody -> getHeadElement(playerPos);
   //we set the head element as "playerPos"
    
    player1->updatePlayerDir();
    //updatee the movement
    player1->movePlayer();
    //move
    if (player1->checkFoodConsumption() == true)
    {
        //checking if consumed food, increment score and generate new food
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
    //creating foodPos and tempBody objects // tempBody is for looping through the body element
    objPosArrayList *playerBody = player1->getPlayerPos();
    mechanics -> getFoodPos(foodPos);
    bool drawn;
    //if we have already drawn the element, we can skip it in the board drawing implementation
     int X,Y; // 
   //generating board
    for(Y=0; Y< y_bound ; Y++)
    {
        for(X=0; X <x_bound ; X++)
        {
            for (int k =0; k < playerBody ->getSize(); k++)
            {
                drawn = false; //if drawn, we won't draw at that location anymore
                //checking for the body
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
                MacUILib_printf("%c", foodPos.symbol); //checking for the food
            }
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");

    } 
    //printing extra stuff, i.e position, score
    MacUILib_printf("Player Position: <%d, %d>\n", tempBody.x, tempBody.y); 
    MacUILib_printf("Your Score is: %d\n ", mechanics -> getScore());
    if (mechanics -> getLoseFlagStatus() == true)
    {
        //if lose Flag is true, we will set Exit to true and leave a kind message
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
    //freeing heap members
    delete player1;
    delete mechanics;
    MacUILib_uninit();
}
