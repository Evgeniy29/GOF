#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
namespace MyTools {

    // Палитра цветов от 0 до 15
    enum  ConsoleColor
    {
        CC_Black = 0,
        CC_Blue,
        CC_Green,
        CC_Cyan,
        CC_Red,
        CC_Magenta,
        CC_Brown,
        CC_LightGray,
        CC_DarkGray,
        CC_LightBlue,
        CC_LightGreen,
        CC_LightCyan,
        CC_LightRed,
        CC_LightMagenta,
        CC_Yellow,
        CC_White
    };
  

	//=============================================================================================

	void ClrScr();

	void __fastcall GotoXY(double x, double y);

	uint16_t GetMaxX();

	uint16_t GetMaxY();

    void SetColor(ConsoleColor color);

	//=============================================================================================

	//void __fastcall OpenLogFile(const std::string& FN);

	//void CloseLogFile();

	//void __fastcall WriteToLog(const std::string& str);

	//void __fastcall WriteToLog(const std::string& str, int n);

	//void __fastcall WriteToLog(const std::string& str, double d);

	//=============================================================================================
    class Logger
    {
    public:
        virtual void OpenLogFile(const std::string& FN) = 0;
        virtual void CloseLogFile() = 0;
        virtual void WriteToLog(const std::string& str) = 0;
        virtual void WriteToLog(const std::string& str, int n) = 0;
        virtual void WriteToLog(const std::string& str, double d) = 0;
        virtual ~Logger() {}
    };

    class FileLoggerSingleton : public Logger
    {
    public:
        static FileLoggerSingleton& getInstance()
        {
            static FileLoggerSingleton _instance;
            return _instance;
        }
        void OpenLogFile(const std::string& FN) override;
        void CloseLogFile() override;
        void WriteToLog(const std::string& str) override;
        void WriteToLog(const std::string& str, int n) override;
        void WriteToLog(const std::string& str, double d) override;
        ~FileLoggerSingleton();
    private:
        FileLoggerSingleton() {}
        FileLoggerSingleton(const FileLoggerSingleton&) = delete;
        FileLoggerSingleton& operator=(const FileLoggerSingleton&) = delete;
        FileLoggerSingleton& operator=(FileLoggerSingleton&&) = delete;
    };

   /* class LoggerSingleton : public Logger
    {
    public:
        static LoggerSingleton& getInstance()
        {
            static LoggerSingleton _instance;
            return _instance;
        }

        void OpenLogFile(const std::string& FN) override;
        void CloseLogFile() override;
        void WriteToLog(const std::string& str) override;
        void WriteToLog(const std::string& str, int n) override;
        void WriteToLog(const std::string& str, double d) override;
        ~LoggerSingleton();

    private:
        LoggerSingleton() {}
        LoggerSingleton(const LoggerSingleton&) = delete;
        LoggerSingleton& operator=(const LoggerSingleton&) = delete;
        LoggerSingleton& operator=(LoggerSingleton&&) = delete;
              
    };*/

};