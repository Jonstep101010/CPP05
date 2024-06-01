#pragma once

#include "Form.hpp"
#include <exception>
#include <string>

#define GRADE_MAX 1
#define GRADE_MIN 150

class Form;

class Bureaucrat {

public:
	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const& src);
	~Bureaucrat();

	Bureaucrat& operator++();
	Bureaucrat& operator--();
	Bureaucrat& operator=(Bureaucrat const& rhs);

	// getters
	int                getGrade() const;
	const std::string& getName() const;

	// exceptions
	class GradeTooLowException : public std::exception {
		const char* what() const throw() {
			return "grade is too low\n";
		}
	};
	class GradeTooHighException : public std::exception {
		const char* what() const throw() {
			return "grade is too high\n";
		}
	};

	// members
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form_to_sign);

private:
	const std::string name;
	int               grade;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs);