#include "Bureaucrat.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
	: name("default"), grade(GRADE_MIN) {
	std::cout << "created new default bureaucrat\n";
}

Bureaucrat::Bureaucrat(int grade)
	: name("default"), grade(grade) {
	if (grade < GRADE_MAX) {
		throw Bureaucrat::GradeTooHigh();
	}
	if (grade > GRADE_MIN) {
		throw Bureaucrat::GradeTooLow();
	}
	std::cout << "created new bureaucrat with grade " << grade
			  << "\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name), grade(grade) {
	if (grade < GRADE_MAX) {
		throw Bureaucrat::GradeTooHigh();
	}
	if (grade > GRADE_MIN) {
		throw Bureaucrat::GradeTooLow();
	}
	std::cout << "created new bureaucrat with name " << name
			  << " of grade" << grade << "\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
	: name(src.getName()), grade(src.getGrade()) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& rhs) {
	if (this != &rhs) {
		this->grade = rhs.getGrade();
	}
	return *this;
}

Bureaucrat& Bureaucrat::operator++() {
	const int new_grade = this->getGrade() - 1;

	if (new_grade < GRADE_MAX) {
		throw Bureaucrat::GradeTooHigh();
	}
	this->grade = new_grade;
	return *this;
}

Bureaucrat& Bureaucrat::operator--() {
	const int new_grade = this->getGrade() + 1;

	if (new_grade > GRADE_MIN) {
		throw Bureaucrat::GradeTooLow();
	}
	this->grade = new_grade;
	return *this;
}

std::ostream& operator<<(std::ostream&     o,
						 Bureaucrat const& rhs) {
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade()
	  << ".\n";
	return o;
}

const char* Bureaucrat::GradeTooLow::what() const throw() {
	return "grade is too low\n";
}

const char* Bureaucrat::GradeTooHigh::what() const throw() {
	return "grade is too high\n";
}

/*
** ---------------------------------- MEMBER ----------------------------------
*/

void Bureaucrat::incrementGrade() { Bureaucrat::operator++(); }

void Bureaucrat::decrementGrade() { Bureaucrat::operator--(); }

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Bureaucrat::getGrade() const { return this->grade; }

const std::string& Bureaucrat::getName() const {
	return this->name;
}

/* ************************************************************************** */