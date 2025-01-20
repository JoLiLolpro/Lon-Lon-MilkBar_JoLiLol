#pragma once

#include <fstream>
#include <iomanip>
#include <ctime>
#include <direct.h>
#include <string>
#include <iostream>
#include <windows.h>
#include <shared_mutex>

/*
	LEVEL
	0 = Information
	1 = Warning
	2 = Debug
*/
#define LEVEL 2

namespace Logging
{

	static std::ofstream LogFile;
	static DWORD Timer;
	static std::string TimerName = "";
	static std::shared_mutex LogMutex;

	static class LoggerService
	{
	private:
		static void WriteToLog(std::string Message, std::string LogType, const char* caller = "");
		static std::string GetTimeAsString(int Format);

	public:
		static void StartLoggerService();
		
		static void LogDebug(std::string Message, const char * caller = "");
		static void LogWarning(std::string Message, const char* caller = "");
		static void LogInformation(std::string Message, const char* caller = "");
		static void LogCritical(std::string Message, const char* caller = "");
		static void LogError(std::string Message, const char* caller = "");

		static void StartTimer(std::string timerName);
		static void FinishTimer();

	};
}