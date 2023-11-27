#include <iostream>
#include "MacUILib.h"
#include "objPos.h"


using namespace std;

#define DELAY_CONST 100000

//bool exitFlag;
GameMechs *mechanics;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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
    MacUILib_init();
    MacUILib_clearScreen();
    mechanics = new GameMechs();

    //exitFlag = false; this is implied in game mechainics
}

void GetInput(void)
{
   char input_char = mechanics->getInput();
   
}

void RunLogic(void)
{
    mechanics->setInput(input_char);
    mechanics -> clearInput();
}

void DrawScreen(void)
{
     MacUILib_clearScreen();
    int x_bound=mechanics->getBoardSizeX();
    int y_bound=mechanics->getBoardSizeY();
     int X,Y; // 
   
    for(Y=0; Y< y_bound ; Y++)
    {
        for(X=0; X <x_bound ; X++)
        {
            if ( X==0 || X== x_bound-1 || Y==0 || Y== y_bound-1 )
            {
                MacUILib_printf("#");
            } 
            else
            {
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }  

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
    delete mechanics;
    MacUILib_uninit();
}
