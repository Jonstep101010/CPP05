#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
	: Form("RobotomyRequestForm", RRF_SIGN, RRF_EXEC)
	, _target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(
	std::string const& target)
	: Form("RobotomyRequestForm", RRF_SIGN, RRF_EXEC)
	, _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm& src)
	: Form(src), _target(src._target) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm&
RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
	if (this != &rhs) {
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute_action() const {
	srand(time(NULL)); // seed random number generator
	const bool robotomy_success = rand() % 2 == 0;

	std::cout << "iirrrrrierrrrirerrreirerrirerrirerrirerirerire"
				 "rirerrierrierirrerrerirrrrrrrrrrrrrrr\n";
	if (robotomy_success) {
		std::cout << _target
				  << " has been robotomized successfully!\n";
	} else {
		std::cout << _target << "'s robotomy has failed!\n";
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */