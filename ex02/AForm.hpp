#pragma once

#include "Bureaucrat.hpp"
#include <ostream>

class Bureaucrat;

class AForm {

public:
	AForm();
	AForm(std::string const&, int, int);
	AForm(AForm const& src);
	virtual ~AForm();

	AForm& operator=(AForm const& rhs);

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
	const std::string name;
	bool              is_signed;
	const int         req_signing_grade;
	const int         req_execution_grade;
};

std::ostream& operator<<(std::ostream& o, AForm const& i);
