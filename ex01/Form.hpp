#pragma once

#include "Bureaucrat.hpp"
#include <ostream>

class Bureaucrat;

class Form {

public:
	Form();
	Form(std::string const& name, int req_signing_grade);
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

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const throw() {
			return "grade is too low";
		}
	};
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const throw() {
			return "grade is too high";
		}
	};

private:
	const std::string _name;
	bool              _is_signed;
	const int         _req_signing_grade;
	const int         _req_execution_grade;
};

std::ostream& operator<<(std::ostream& o, Form const& i);
