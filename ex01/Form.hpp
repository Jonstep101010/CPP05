#pragma once

#include "Bureaucrat.hpp"
#include <ostream>

class Form {

public:
	Form();
	Form(Form const& src);
	~Form();

	Form& operator=(Form const& rhs);

	// getters
	const std::string& getName() const;
	bool               getSignedStatus() const;
	int                getReqSignGrade() const;
	int                getReqExecGrade() const;

	// members
	void beSigned(Bureaucrat const& signee);

private:
	const std::string name;
	bool              is_signed;
	const int         req_signing_grade;
	const int         req_execution_grade;
};

std::ostream& operator<<(std::ostream& o, Form const& i);
