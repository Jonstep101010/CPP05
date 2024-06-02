#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(
	std::string const& target)
	: AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm& src) {
	(void)src;
}

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
	const bool robotomy_success
		= /* @follow-up randomize 50% */ true;

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