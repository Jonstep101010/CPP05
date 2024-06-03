#pragma once

#include "Bureaucrat.hpp"
#include <ostream>

class Bureaucrat;

class Form {

public:
	Form();
	Form(std::string const&, int, int);
	Form(Form const& src);
	virtual ~Form();

	Form& operator=(Form const& rhs);

	// getters
	const std::string& getName() const;
	bool               getSignedStatus() const;
	int                getReqSignGrade() const;
	int                getReqExecGrade() const;

	// members
	void beSigned(Bureaucrat& signee);

	void execute(Bureaucrat const& executor) const;

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
	class NotSignedException : public std::exception {
	public:
		const char* what() const throw() {
			return "form is not signed";
		}
	};

private:
	virtual void      execute_action() const = 0;
	const std::string _name;
	bool              _is_signed;
	const int         _req_signing_grade;
	const int         _req_execution_grade;
};

std::ostream& operator<<(std::ostream& o, Form const& i);
