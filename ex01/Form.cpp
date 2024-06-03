#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
	: _name("certificate of birth")
	, _is_signed(false)
	, _req_signing_grade(GRADE_MIN)
	, _req_execution_grade(0) {}

Form::Form(std::string const& name, int req_signing_grade)
	: _name(name)
	, _is_signed(false)
	, _req_signing_grade(req_signing_grade)
	, _req_execution_grade(req_signing_grade) {
	if (req_signing_grade > GRADE_MIN) {
		throw Form::GradeTooLowException();
	}
	if (req_signing_grade < GRADE_MAX) {
		throw Form::GradeTooHighException();
	}
}
Form::Form(std::string const& name, int req_signing_grade,
		   int req_exec_grade)
	: _name(name)
	, _is_signed(false)
	, _req_signing_grade(req_signing_grade)
	, _req_execution_grade(req_exec_grade) {
	if (req_signing_grade > GRADE_MIN
		|| req_exec_grade > GRADE_MIN) {
		throw Form::GradeTooLowException();
	}
	if (req_signing_grade < GRADE_MAX
		|| req_exec_grade < GRADE_MAX) {
		throw Form::GradeTooHighException();
	}
}

Form::Form(const Form& src)
	: _name(src.getName())
	, _is_signed(src.getSignedStatus())
	, _req_signing_grade(src.getReqSignGrade())
	, _req_execution_grade(src.getReqExecGrade()) {}

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
		this->_is_signed = rhs.getSignedStatus();
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
	// lower number means higher grade
	if (signee.getGrade() <= this->getReqSignGrade()) {
		this->_is_signed = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Form::getName() const { return _name; }

bool Form::getSignedStatus() const { return _is_signed; }

int Form::getReqSignGrade() const { return _req_signing_grade; }

int Form::getReqExecGrade() const {
	return _req_execution_grade;
}

/* ************************************************************************** */