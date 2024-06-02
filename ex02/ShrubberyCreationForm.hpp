#pragma once

#include <iostream>
#include <string>

#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&
	operator=(ShrubberyCreationForm const& rhs);

private:
};

// std::ostream& operator<<(std::ostream&                o,
// 						 ShrubberyCreationForm const& i);

// sign 147, exec 137
// Create a file <target>_shrubbery in the working directory, and write ASCII trees inside