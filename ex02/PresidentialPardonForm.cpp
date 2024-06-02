#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& src) {
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm& PresidentialPardonForm::operator=(
	PresidentialPardonForm const& rhs) {
	//if ( this != &rhs )
	//{
	//this->_value = rhs.getValue();
	//}
	(void)rhs;
	return *this;
}

// std::ostream& operator<<(std::ostream&                 o,
// 						 PresidentialPardonForm const& i) {
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