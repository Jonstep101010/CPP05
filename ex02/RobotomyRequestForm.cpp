#include "RobotomyRequestForm.hpp"
#include <cstdlib>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45)
	, target("default_target") {}

RobotomyRequestForm::RobotomyRequestForm(
	std::string const& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm& src)
	: AForm(src), target(src.target) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm&
RobotomyRequestForm::operator=(RobotomyRequestForm const& rhs) {
	//if ( this != &rhs )
	//{
	//this->_value = rhs.getValue();
	//}
	(void)rhs;
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
		std::cout << target
				  << " has been robotomized successfully!\n";
	} else {
		std::cout << target << "'s robotomy has failed!\n";
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */