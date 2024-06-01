#pragma once

#include "Bureaucrat.hpp"
#include <ostream>

class Bureaucrat;

class Form {

public:
	Form();
	Form(std::string const&, int, int);
	Form(Form const& src);
	~Form();

	Form& operator=(Form const& rhs);

	// getters
	const std::string& getName() const;
	bool               getSignedStatus() const;
	int                getReqSignGrade() const;
	int                getReqExecGrade() const;

	// members
	void beSigned(Bureaucrat& signee);

	class GradeTooLow : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooHigh : public std::exception {
	public:
		const char* what() const throw();
	};

private:
	const std::string name;
	bool              is_signed;
	const int         req_signing_grade;
	const int         req_execution_grade;
};

std::ostream& operator<<(std::ostream& o, Form const& i);
