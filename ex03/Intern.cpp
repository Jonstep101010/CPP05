#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
	: forms() {

	form_names[0] = "shrubbery creation";
	form_names[1] = "robotomy request";
	form_names[2] = "presidential pardon";
}

Intern::Intern(const Intern& src)
	: forms() {
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern& Intern::operator=(Intern const& rhs) {
	if (this != &rhs) {
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Form* makeShrubbery(std::string const& target) {
	return new ShrubberyCreationForm(target);
}

Form* makeRobotomy(std::string const& target) {
	return new RobotomyRequestForm(target);
}

Form* makePardon(std::string const& target) {
	return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(std::string const& form_name,
					   std::string const& target) {
	forms[0] = &makeShrubbery;
	forms[1] = &makeRobotomy;
	forms[2] = &makePardon;

	for (int i = 0; i < 3; i++) {
		if (form_name == form_names[i]) {
			std::cout << "Intern creates " << form_name << "\n";
			return forms[i](target);
		}
	}
	std::cerr << "Form not found: " << form_name << "\n";
	throw Intern::FormNotFoundException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */