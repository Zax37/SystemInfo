#pragma once
#include <string>
#include <vector>

class SystemCommand {
	std::string command;
	std::vector<std::string> output;
	bool hadError;
	
public:
	SystemCommand(std::string command) : command(command) {}
	void execute();
	std::vector<std::string> outputAsVector() { return output; }
	bool hasError();
};
