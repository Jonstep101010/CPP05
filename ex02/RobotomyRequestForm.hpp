#pragma once

#include "AForm.hpp"
#include <string>

#define RRF_SIGN 72
#define RRF_EXEC 45

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
	const std::string _target;
	void              execute_action() const;
};
