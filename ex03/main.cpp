#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main() {
	Bureaucrat president("Zaphod Beeblebrox", GRADE_MAX);
	Bureaucrat lowly_scribe("Hannah Mckay", GRADE_MIN);

	ShrubberyCreationForm  bushes("frontyard");
	PresidentialPardonForm whistleblower("Julien Assange");
	RobotomyRequestForm    frankenstein("C-3PO");

	try {
		lowly_scribe.signForm(bushes);
		lowly_scribe.signForm(whistleblower);
		lowly_scribe.signForm(frankenstein);

		president.signForm(bushes);
		president.signForm(bushes);
		president.signForm(whistleblower);
		president.signForm(frankenstein);

		president.executeForm(bushes);
		president.executeForm(whistleblower);
		president.executeForm(frankenstein);

		lowly_scribe.executeForm(bushes);
		lowly_scribe.executeForm(whistleblower);
		lowly_scribe.executeForm(frankenstein);

	} catch (std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	{
		Intern someRandomIntern;
		Form*  rrf;
		try {
			rrf = someRandomIntern.makeForm(
				"robotomy request two", "Bender");
			Bureaucrat bendersignexec("Fry", GRADE_MIN + 10);
			bendersignexec.signForm(*rrf);
			bendersignexec.executeForm(*rrf);
		} catch (std::exception& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	}
	return 0;
};