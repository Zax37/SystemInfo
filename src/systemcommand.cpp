#include "../include/systemcommand.h"
#include "../../tiny-process-library/process.hpp"

void SystemCommand::execute() {
	std::wstring cmd;
	cmd.assign(command.begin(), command.end());
	TinyProcessLib::Process process(cmd, L"", [this](const char* bytes, size_t n) {
		std::string returnString = std::string(bytes, n);
		size_t foundPosition;
		while (foundPosition = returnString.find("\r\r\n"), foundPosition != std::string::npos) {
			output.push_back(returnString.substr(0, foundPosition));
			returnString = returnString.substr(foundPosition + 3);
		}
	});
	hadError = process.get_exit_status() != 0;
}

bool SystemCommand::hasError() {
	return hadError;
}
