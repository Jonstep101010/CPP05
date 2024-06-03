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
		const char* what() const throw() {
			return "Grade is too low\n";
		}
	};
	class GradeTooHigh : public std::exception {
	public:
		const char* what() const throw() {
			return "grade is too high\n";
		}
	};

	// members
	void incrementGrade();
	void decrementGrade();

private:
	const std::string _name;
	int               _grade;
};

std::ostream& operator<<(std::ostream& o, Bureaucrat const& rhs);