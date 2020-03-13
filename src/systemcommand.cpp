#include "../include/systemcommand.h"
#include "../../tiny-process-library/process.hpp"
#include <sstream>

std::vector<std::string> output;
bool hadError;

void SystemCommand::execute() {
	output.clear();
	std::wstring cmd;
	cmd.assign(command.begin(), command.end());
	TinyProcessLib::Process process(cmd, L"", [](const char* bytes, size_t n) {
		std::istringstream f(bytes, n);
		std::string line;
		while (std::getline(f, line)) {
			line.pop_back(); // remove \r
			line.pop_back(); // remove \r
			output.push_back(line);
		}
		/*char* pch = strtok((char*)bytes, "\r\n");
		while (pch != NULL) {
			output.push_back(pch);
			pch = strtok((char*)bytes, "\r\n");
		}*/
	});
	hadError = process.get_exit_status() != 0;
}

std::vector<std::string> SystemCommand::outputAsVector() {
	return output;
}

bool SystemCommand::hasError() {
	return hadError;
}
