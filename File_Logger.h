#pragma once

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class File_Logger
{
	ofstream logOut;

public:
	File_Logger(const string& FN);
	~File_Logger();
	void WriteToLog(const string& str);
	void WriteToLog(const string& str, int n);
	void WriteToLog(const string& str, double d);
	string GetCurDateTime();

	
};