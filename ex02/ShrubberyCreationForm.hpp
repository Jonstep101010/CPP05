#pragma once

#include "AForm.hpp"
#include <string>

#define SCF_SIGN 145
#define SCF_EXEC 137


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
	const std::string _target;
	void              execute_action() const;
};
