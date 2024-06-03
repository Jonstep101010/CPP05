#include "Bureaucrat.hpp"
#include <cstdio>
#include <iostream>

#define EXC_PRINT(cause, num, reason)                           \
	std::cout << "Caught an exception " << cause "\033[31m "    \
			  << num << ": " << reason << "\033[0m"

int main() {
	{
		// creates the lowest ranking of scribes, grade 150 (GRADE_MIN)
		Bureaucrat default_scribe;

		std::cout << default_scribe;

		// should not throw exceptions
		Bureaucrat(GRADE_MAX);
		Bureaucrat(GRADE_MIN);
	}
	{
		// try catching a lower grade exception on construction
		try {
			Bureaucrat invalid_low = Bureaucrat(GRADE_MIN + 1);
		} catch (Bureaucrat::GradeTooLow& e) {
			EXC_PRINT("", GRADE_MIN + 1, e.what());
		}
		// try catching a higher grade exception on construction
		try {
			Bureaucrat invalid_high = Bureaucrat(GRADE_MAX - 1);
		} catch (Bureaucrat::GradeTooHigh& e) {
			EXC_PRINT("", GRADE_MAX - 1, e.what());
		}
	}
	{
		// try catching a lower grade exception
		Bureaucrat valid_low = Bureaucrat(GRADE_MIN);
		try {
			valid_low.decrementGrade();
		} catch (Bureaucrat::GradeTooLow& e) {
			EXC_PRINT("decrementing", valid_low.getGrade(),
					  e.what());
		}
		// try catching a higher grade exception
		Bureaucrat valid_high = Bureaucrat(GRADE_MAX);
		try {
			valid_high.incrementGrade();
		} catch (Bureaucrat::GradeTooHigh& e) {
			EXC_PRINT("incrementing", valid_high.getGrade(),
					  e.what());
		}
	}
	{
		// valid decrement
		Bureaucrat valid_low = Bureaucrat(GRADE_MIN - 1);
		try {
			valid_low.decrementGrade();
		} catch (Bureaucrat::GradeTooLow& e) {
			EXC_PRINT("decrementing", valid_low.getGrade(),
					  e.what());
		}
		// valid increment
		Bureaucrat valid_high = Bureaucrat(GRADE_MAX + 1);
		try {
			valid_high.incrementGrade();
		} catch (Bureaucrat::GradeTooHigh& e) {
			EXC_PRINT("incrementing", valid_high.getGrade(),
					  e.what());
		}
	}
	return 0;
}