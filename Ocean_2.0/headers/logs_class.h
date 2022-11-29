#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

class Logs
{
public:

	void WriteString(std::string str){

		fout_.open("logs.txt", std::ofstream::app);
		
		if(fout_.is_open())
		{
			fout_ << NowDataTime() << "\t" << str << std::endl;

			fout_.close();
		}
		else
			std::cout << "Log file is not open" << std::endl;
	}


	std::string NowDataTime(){

		time_t now_time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

		tm* tm_struct = localtime(&now_time);

		return std::to_string(tm_struct->tm_mday) + "." + std::to_string(tm_struct->tm_mon) + " " + std::to_string(tm_struct->tm_hour) + ":" + std::to_string(tm_struct->tm_min) + ":" + std::to_string(tm_struct->tm_sec);
	}

private:
	std::ofstream fout_;
};
