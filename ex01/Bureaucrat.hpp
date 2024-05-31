#pragma once

#include <exception>
#include <string>

#define GRADE_MAX 1
#define GRADE_MIN 150

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
	class GradeTooLow : public std::exception {
	public:
		const char* what() const throw();
	};
	class GradeTooHigh : public std::exception {
	public:
		const char* what() const throw();
	};

	// members
	void incrementGrade();
	void decrementGrade();
	// void signForm();// @todo implement try/catch

private:
	const std::string name;
	int               grade;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs);