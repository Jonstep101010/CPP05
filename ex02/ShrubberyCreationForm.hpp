#pragma once

#include <iostream>
#include <string>

#include "AForm.hpp"

class AForm;

class ShrubberyCreationForm : public AForm {

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&
	operator=(ShrubberyCreationForm const& rhs);

private:
	const std::string target;
	void              execute_action() const;
};
