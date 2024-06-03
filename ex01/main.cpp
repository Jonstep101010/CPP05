#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	Bureaucrat MEP("member of parliament", 3);

	Bureaucrat president("president", GRADE_MAX);

	Form executive_order("executive order 139D",
						 /* minimum signing level */ GRADE_MAX);

	// should fail (3 > 1)
	MEP.signForm(executive_order);

	// should succeed (1 <= 1)
	std::cout << "- - - - - - - -\nBefore signing request:\n"
			  << executive_order << "- - - - - - - -\n";
	president.signForm(executive_order);
	std::cout << "- - - - - - - -\nAfter signing request:\n"
			  << executive_order << "- - - - - - - -\n";

	// instantiating a form requiring invalid grades should throw an exception
	Form form("simple",
			  /* minimum signing level */ GRADE_MAX - 1,
			  GRADE_MIN + 1);
}
