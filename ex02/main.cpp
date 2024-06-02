#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
	Bureaucrat MEP
		= Bureaucrat("member of parliament", 3);

	Bureaucrat president = Bureaucrat("president", GRADE_MAX);

	AForm executive_order = AForm("executive order 139D", /* minimum signing level */1, 1);

	// should fail (3 > 1)
	MEP.signForm(executive_order);

	// should succeed (1 <= 1)
	std::cout << "- - - - - - - -\nBefore signing request:\n" << executive_order << "- - - - - - - -\n";
	president.signForm(executive_order);
	std::cout << "- - - - - - - -\nAfter signing request:\n" << executive_order  << "- - - - - - - -\n";

	// instantiating a Aform requiring invalid grades should throw an exception
	AForm Aform = AForm("simple", /* minimum signing level */0, 151);

}
