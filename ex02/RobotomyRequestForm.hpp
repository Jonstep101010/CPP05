#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>

class AForm;

class RobotomyRequestForm : public AForm {

public:
	RobotomyRequestForm();
	RobotomyRequestForm(RobotomyRequestForm const& src);
	~RobotomyRequestForm();

	RobotomyRequestForm&
	operator=(RobotomyRequestForm const& rhs);

private:
};

// std::ostream& operator<<(std::ostream&              o,
// 						 RobotomyRequestForm const& i);

// sign 72, exec 45
// Makes some drilling noises. Then, informs that <target> has been robotomized
// successfully 50% of the time. Otherwise, informs that the robotomy failed.