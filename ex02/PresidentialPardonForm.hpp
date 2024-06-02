#pragma once

#include "AForm.hpp"
#include <iostream>
#include <string>

class AForm;

class PresidentialPardonForm : public AForm {

public:
	PresidentialPardonForm();
	PresidentialPardonForm(PresidentialPardonForm const& src);
	~PresidentialPardonForm();

	PresidentialPardonForm&
	operator=(PresidentialPardonForm const& rhs);

private:
};

// std::ostream& operator<<(std::ostream&                 o,
// 						 PresidentialPardonForm const& i);

// sign 25, exec 5
// Informs that <target> has been pardoned by Zaphod Beeblebrox.