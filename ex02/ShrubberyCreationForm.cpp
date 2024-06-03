#include "ShrubberyCreationForm.hpp"
#include <fstream>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137)
	, target("default_target") {}

ShrubberyCreationForm::ShrubberyCreationForm(
	std::string const& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm& src)
	: AForm(src), target(src.target) {}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm() {}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	ShrubberyCreationForm const& rhs) {
	//if ( this != &rhs )
	//{
	//this->_value = rhs.getValue();
	//}
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute_action() const {
	std::ofstream file((target + "_shrubbery").c_str(),
					   std::ios::trunc | std::ios::out);

	if (file.is_open()) {
		file << "             .o00o\n";
		file << "           o000000oo\n";
		file << "          00000000000o\n";
		file << "         00000000000000\n";
		file << "      oooooo  00000000  o88o\n";
		file << "   ooOOOOOOOoo  ```''  888888\n";
		file << " OOOOOOOOOOOO'.q0000q. `8888'\n";
		file << "oOOOOOOOOOO'.0000000000/.88'\n";
		file << "OOOOOOOOOO'.0000000000/ /q\n";
		file << " OOOOOOOOO 0000000000/ /00\n";
		file << "   OOOOOOOOO `000000/ /00'\n";
		file << "     OO:F_P:O `000/  /0'\n";
		file << "        \\. \\ |  // |\n";
		file << "        d\\ \\\\|_//\n";
		file << "        qP| \\ _' `|Ob\n";
		file << "           \\  / \\  \\Op\n";
		file << "           |  | O| |\n";
		file << "   _       /\\. \\_/ /\\\n";
		file << "    `---__/|_\\   //|  __\n";
		file << "          `-'  `-'`-'-'\n";
		file << "             .o00o\n";
		file << "           o000000oo\n";
		file << "          00000000000o\n";
		file << "         00000000000000\n";
		file << "      oooooo  00000000  o88o\n";
		file << "   ooOOOOOOOoo  ```''  888888\n";
		file << " OOOOOOOOOOOO'.q0000q. `8888'\n";
		file << "oOOOOOOOOOO'.0000000000/.88'\n";
		file << "OOOOOOOOOO'.0000000000/ /q\n";
		file << " OOOOOOOOO 0000000000/ /00\n";
		file << "   OOOOOOOOO `000000/ /00'\n";
		file << "     OO:F_P:O `000/  /0'\n";
		file << "        \\. \\ |  // |\n";
		file << "        d\\ \\\\|_//\n";
		file << "        qP| \\ _' `|Ob\n";
		file << "           \\  / \\  \\Op\n";
		file << "           |  | O| |\n";
		file << "   _       /\\. \\_/ /\\\n";
		file << "    `---__/|_\\   //|  __\n";
		file << "          `-'  `-'`-'-'\n";
	} else {
		std::cerr << "Error: could not open file\n";
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */