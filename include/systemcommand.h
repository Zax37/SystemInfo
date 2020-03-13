#pragma once
#include <string>
#include <vector>

struct SystemCommand {
	std::string command;

	void execute();
	std::vector<std::string> outputAsVector();
	bool hasError();
};
