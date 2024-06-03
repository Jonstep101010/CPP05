#include "PresidentialPardonForm.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", PPF_SIGN, PPF_EXEC)
	, _target("default_target") {}

PresidentialPardonForm::PresidentialPardonForm(
	std::string const& target)
	: AForm("PresidentialPardonForm", PPF_SIGN, PPF_EXEC)
	, _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& src)
	: AForm(src), _target(src._target) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm& PresidentialPardonForm::operator=(
	PresidentialPardonForm const& rhs) {
	if (this != &rhs) {
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execute_action() const {
	std::cout << _target
			  << " has been pardoned by Zaphod Beeblebrox\n";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */