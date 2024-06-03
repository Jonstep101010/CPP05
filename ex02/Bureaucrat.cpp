#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
	: name("default"), grade(GRADE_MIN) {
	std::cout << "created new default bureaucrat\n";
}

static int _validate_grade(int grade) {
	if (grade < GRADE_MAX) {
		throw Bureaucrat::GradeTooHighException();
	}
	if (grade > GRADE_MIN) {
		throw Bureaucrat::GradeTooLowException();
	}
	return grade;
}

Bureaucrat::Bureaucrat(int grade)
	: name("default"), grade(_validate_grade(grade)) {
	std::cout << "created new bureaucrat with grade " << grade
			  << "\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade)
	: name(name), grade(_validate_grade(grade)) {
	std::cout << "created new bureaucrat with name '" << name
			  << "' of grade " << grade << "\n";
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
		throw Bureaucrat::GradeTooHighException();
	}
	this->grade = new_grade;
	return *this;
}

Bureaucrat& Bureaucrat::operator--() {
	const int new_grade = this->getGrade() + 1;

	if (new_grade > GRADE_MIN) {
		throw Bureaucrat::GradeTooLowException();
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

/*
** ---------------------------------- MEMBER ----------------------------------
*/

void Bureaucrat::incrementGrade() { Bureaucrat::operator++(); }

void Bureaucrat::decrementGrade() { Bureaucrat::operator--(); }

#define RED(string) "\033[31m\033[1m" << string << "\033[0m"
#define GREEN(string) "\033[32m" << string << "\033[0m"

void Bureaucrat::signForm(AForm& form_to_sign) {
	try {
		form_to_sign.AForm::beSigned(*this);
		std::cout << this->getName() << GREEN(" signed ")
				  << form_to_sign.getName() << "\n";
	} catch (AForm::GradeTooLowException& e) {
		std::cout << this->getName() << RED(" couldn't sign ")
				  << form_to_sign.getName() << " because "
				  << e.what() << ".\n";
	};
}

void Bureaucrat::executeForm(AForm const& form) const {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed "
				  << form.getName() << "\n";
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

int Bureaucrat::getGrade() const { return this->grade; }

const std::string& Bureaucrat::getName() const {
	return this->name;
}

/* ************************************************************************** */