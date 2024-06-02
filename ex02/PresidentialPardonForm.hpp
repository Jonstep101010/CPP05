#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>

class AForm;

class PresidentialPardonForm : public AForm {

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const& target);
	PresidentialPardonForm(PresidentialPardonForm const& src);
	~PresidentialPardonForm();

	PresidentialPardonForm&
	operator=(PresidentialPardonForm const& rhs);

private:
	const std::string target;
	void              execute_action() const;
};
