#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>

class AForm;

class RobotomyRequestForm : public AForm {

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const& target);
	RobotomyRequestForm(RobotomyRequestForm const& src);
	~RobotomyRequestForm();

	RobotomyRequestForm&
	operator=(RobotomyRequestForm const& rhs);

private:
	const std::string target;
	void              execute_action() const;
};
