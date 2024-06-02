#pragma once

#include "Bureaucrat.hpp"
#include <ostream>

class Bureaucrat;

class AForm {

public:
	AForm();
	AForm(std::string const&, int, int);
	AForm(AForm const& src);
	~AForm();

	AForm& operator=(AForm const& rhs);

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
	const std::string name;
	bool              is_signed;
	const int         req_signing_grade;
	const int         req_execution_grade;
};

std::ostream& operator<<(std::ostream& o, AForm const& i);
