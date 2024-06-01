#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
	: name("certificate of birth")
	, is_signed(false)
	, req_signing_grade(GRADE_MIN)
	, req_execution_grade(0) {}

Form::Form(std::string const& name, int req_signing_grade,
		   int req_exec_grade)
	: name(name)
	, is_signed(false)
	, req_signing_grade(req_signing_grade)
	, req_execution_grade(req_exec_grade) {
	if (req_signing_grade > 150 || req_exec_grade > 150) {
		throw Form::GradeTooLowException();
	}
	if (req_signing_grade < 1 || req_exec_grade < 1) {
		throw Form::GradeTooHighException();
	}
}

Form::Form(const Form& src)
	: name(src.getName())
	, is_signed(src.getSignedStatus())
	, req_signing_grade(src.getReqSignGrade())
	, req_execution_grade(src.getReqExecGrade()) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form& Form::operator=(Form const& rhs) {
	if (this != &rhs) {
		// @follow-up is this correct?
		this->is_signed = rhs.getSignedStatus();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& o, Form const& i) {
	o << "name = " << i.getName()
	  << "\nis_signed = " << i.getSignedStatus()
	  << "\nreq_signing_grade = " << i.getReqSignGrade()
	  << "\nreq_exec_grade = " << i.getReqExecGrade()
	  << std::endl;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat& signee) {
	(void)signee;
	// lower number means higher grade
	if (signee.getGrade() <= this->getReqSignGrade()) {
		this->is_signed = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Form::getName() const { return name; }

bool Form::getSignedStatus() const { return is_signed; }

int Form::getReqSignGrade() const { return req_signing_grade; }

int Form::getReqExecGrade() const { return req_execution_grade; }

/* ************************************************************************** */