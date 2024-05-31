#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
	: is_signed(false)
	, req_signing_grade(0)
	, req_execution_grade(0) {}

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

// @todo implement signing exceptions
void	Form::beSigned(Bureaucrat const& signee) {
	(void)signee;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& Form::getName() const { return name; }

bool Form::getSignedStatus() const { return is_signed; }

int Form::getReqSignGrade() const { return req_signing_grade; }

int Form::getReqExecGrade() const { return req_execution_grade; }

/* ************************************************************************** */