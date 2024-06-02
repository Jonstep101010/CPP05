#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() {}

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

// std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
// {
// 	//o << "Value = " << i.getValue();
// 	return o;
// }

/*
** --------------------------------- METHODS ----------------------------------
*/

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */