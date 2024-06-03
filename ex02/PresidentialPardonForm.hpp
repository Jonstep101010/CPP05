#pragma once

#include "AForm.hpp"
#include <string>

#define PPF_SIGN 25
#define PPF_EXEC 5

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
	const std::string _target;
	void              execute_action() const;
};
