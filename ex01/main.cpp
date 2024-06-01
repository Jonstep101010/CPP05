#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	Bureaucrat MEP
		= Bureaucrat("member of parliament", 3);

	Bureaucrat president = Bureaucrat("president", GRADE_MAX);

	Form executive_order = Form("executive order 139D", /* minimum signing level */1, 1);

	// should fail (3 > 1)
	MEP.signForm(executive_order);

	// should succeed (1 <= 1)
	president.signForm(executive_order);

	// instantiating a form requiring invalid grades should throw an exception
	Form form = Form("simple", /* minimum signing level */0, 151);
}
