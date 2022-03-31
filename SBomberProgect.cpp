
#include <conio.h>

#include "SBomber.h"
#include "MyTools.h"

using namespace std;

//========================================================================================================================

int main(void)
{
    //MyTools::OpenLogFile("log.txt");
    MyTools::FileLoggerSingleton::getInstance().OpenLogFile("log.txt");
    SBomber game;

    /*do {
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

    } while (!game.GetExitFlag());*/
    game.run();

    //MyTools::CloseLogFile();
    MyTools::FileLoggerSingleton::getInstance().CloseLogFile();
    return 0;
}
