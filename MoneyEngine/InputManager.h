#pragma once

#include <string>



class InputManager {
public:
	std::string CommandInput(const std::string& command); // This should deal with everything, outputs False if input fails
		

	std::string ParametersInput(const std::string& parameters);
};