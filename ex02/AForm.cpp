#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm()
	: name("certificate of birth")
	, is_signed(false)
	, req_signing_grade(GRADE_MIN)
	, req_execution_grade(0) {}

AForm::AForm(std::string const& name, int req_signing_grade,
		   int req_exec_grade)
	: name(name)
	, is_signed(false)
	, req_signing_grade(req_signing_grade)
	, req_execution_grade(req_exec_grade) {
	if (req_signing_grade > 150 || req_exec_grade > 150) {
		throw AForm::GradeTooLowException();
	}
	if (req_signing_grade < 1 || req_exec_grade < 1) {
		throw AForm::GradeTooHighException();
	}
}

AForm::AForm(const AForm& src)
	: name(src.getName())
	, is_signed(src.getSignedStatus())
	, req_signing_grade(src.getReqSignGrade())
	, req_execution_grade(src.getReqExecGrade()) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm& AForm::operator=(AForm const& rhs) {
	if (this != &rhs) {
		// @follow-up is this correct?
		this->is_signed = rhs.getSignedStatus();
	}
	return *this;
}

std::ostream& operator<<(std::ostream& o, AForm const& i) {
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

void AForm::beSigned(Bureaucrat& signee) {
	(void)signee;
	// lower number means higher grade
	if (signee.getGrade() <= this->getReqSignGrade()) {
		this->is_signed = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string& AForm::getName() const { return name; }

bool AForm::getSignedStatus() const { return is_signed; }

int AForm::getReqSignGrade() const { return req_signing_grade; }

int AForm::getReqExecGrade() const { return req_execution_grade; }

/* ************************************************************************** */