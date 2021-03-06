
#include <conio.h>
#include <windows.h>
#include <stdint.h>
#include <time.h> 
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <numeric>

#include "MyTools.h"

using namespace std;

namespace MyTools {

    ofstream logOut;

    //=============================================================================================

    void ClrScr()
    {
        system("cls");
    }

    void GotoXY(double x, double y)
    {
        const COORD cc = { short(x), short(y) };
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cc);
    }

    uint16_t GetMaxX()
    {
        HANDLE hWndConsole;
        if (hWndConsole = GetStdHandle(-12))
        {
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
            {
                return consoleInfo.srWindow.Right;
                int height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
            }
        }

        return 0;
    }

    uint16_t GetMaxY()
    {
        HANDLE hWndConsole;
        if (hWndConsole = GetStdHandle(-12))
        {
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            if (GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo))
            {
                return consoleInfo.srWindow.Bottom;
            }
        }

        return 0;
    }

    void  SetColor(ConsoleColor color)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color); // color =  (WORD)((BackgroundColor << 4) | TextColor))
    }

    //=============================================================================================

    /*void __fastcall OpenLogFile(const string& FN)
    {
        logOut.open(FN, ios_base::out);
    }*/

    void FileLoggerSingleton::OpenLogFile(const std::string& FN)
    {
        logOut.open(FN, std::ios_base::out);
    }

    /*void CloseLogFile()
    {
        if (logOut.is_open())
        {
            logOut.close();
        }
    }*/

    void FileLoggerSingleton::CloseLogFile()
    {
        if (logOut.is_open())
        {
            logOut.close();
        }
    }

    string GetCurDateTime()
    {
        auto cur = std::chrono::system_clock::now();
        time_t time = std::chrono::system_clock::to_time_t(cur);
        char* buf = ctime(&time);
        return std::string(buf);
       /* char buf[64] = { 0 };
        ctime_s(buf, 64, &time);
        buf[strlen(buf) - 1] = '\0';
        return string(buf);*/
    }

   /* void __fastcall WriteToLog(const string& str)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << endl;
        }
    }*/
    void FileLoggerSingleton::WriteToLog(const std::string& str)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << std::endl;
        }
    }

    /*void __fastcall WriteToLog(const string& str, int n)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << n << endl;
        }
    }*/
    void FileLoggerSingleton::WriteToLog(const std::string& str, int n)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << n << std::endl;
        }
    }

    /*void __fastcall WriteToLog(const string& str, double d)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << d << endl;
        }
    }*/
    void FileLoggerSingleton::WriteToLog(const std::string& str, double d)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << d << std::endl;
        }
    }
    FileLoggerSingleton::~FileLoggerSingleton()
    {

    }
    //=============================================================================================
   /* void LoggerSingleton::OpenLogFile(const std::string& FN)
    {
        
        logOut.open(FN, std::ios_base::out);
    }

    void LoggerSingleton::CloseLogFile()
    {
       
        if (logOut.is_open())
        {
            logOut.close();
        }
    }

    void LoggerSingleton::WriteToLog(const std::string& str)
    {




             
       
        
            
    }

    void LoggerSingleton::WriteToLog(const std::string& str, int n)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << n << std::endl;
        }
    }

    void LoggerSingleton::WriteToLog(const std::string& str, double d)
    {
        if (logOut.is_open())
        {
            logOut << GetCurDateTime() << " - " << str << d << std::endl;
        }
    }*/
    
   

} // namespace MyTools