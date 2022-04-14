#include <iostream>
#include <string>
#include <fstream>
#include <chrono>

#include "File_Logger.h"

using namespace std;
// void __fastcall OpenLogFile(const string& FN)
File_Logger::File_Logger(const string& FN)
{
    logOut.open(FN, ios_base::out);
}

//void CloseLogFile()
File_Logger::~File_Logger()
{
    if (logOut.is_open())
    {
        logOut.close();
    }
}



//void __fastcall WriteToLog(const string& str)
void File_Logger::WriteToLog(const string& str)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << endl;
    }
}

//void __fastcall WriteToLog(const string& str, int n)
void File_Logger::WriteToLog(const string& str, int n)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << n << endl;
    }
}

//void __fastcall WriteToLog(const string& str, double d)
void File_Logger::WriteToLog(const string& str, double d)
{
    if (logOut.is_open())
    {
        logOut << GetCurDateTime() << " - " << str << d << endl;
    }
}
string File_Logger::GetCurDateTime()
{
    auto cur = chrono::system_clock::now();
    time_t time = chrono::system_clock::to_time_t(cur);
    char buf[64] = { 0 };
    ctime_s(buf, 64, &time);
    buf[strlen(buf) - 1] = '\0';
    return string(buf);
}