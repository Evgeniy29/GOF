
#include <conio.h>

#include "SBomber.h"
#include "MyTools.h"
#include"File_Logger.h"
using namespace std;

//========================================================================================================================
extern File_Logger logger("log.txt");

int main(void)
{
    //MyTools::OpenLogFile("log.txt");
    
    SBomber game;

    do {
        game.TimeStart();

        if (_kbhit())
        {
            game.ProcessKBHit();
        }

        MyTools::ClrScr();

        game.DrawFrame();
        game.MoveObjects();
        game.CheckObjects();

        game.TimeFinish();

    } while (!game.GetExitFlag());

    //MyTools::CloseLogFile();

    return 0;
}
