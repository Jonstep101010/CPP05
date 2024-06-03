#pragma once

#include "Form.hpp"
#include <string>

#define SCF_SIGN 145
#define SCF_EXEC 137

class Form;

class ShrubberyCreationForm : public Form {

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const& target);
	ShrubberyCreationForm(ShrubberyCreationForm const& src);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&
	operator=(ShrubberyCreationForm const& rhs);

private:
	const std::string _target;
	void              execute_action() const;
};
