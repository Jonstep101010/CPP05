#pragma once

#include "Form.hpp"
#include <string>

class Intern {

public:
	Intern();
	Intern(Intern const& src);
	~Intern();

	Intern& operator=(Intern const& rhs);

	Form* makeForm(std::string const& form_name,
				   std::string const& target);

private:
	class FormNotFoundException : public std::exception {
	public:
		const char* what() const throw() {
			return "form not found";
		}
	};
	typedef Form*(FormFunc)(std::string const& target);
	std::string form_names[3];
	FormFunc*   forms[3];
};

typedef Form*(FormFunc)(std::string const& target);