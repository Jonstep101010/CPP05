#pragma once

#include <ostream>

class Form {

public:
	Form();
	Form(Form const& src);
	~Form();

	Form& operator=(Form const& rhs);

private:
};

std::ostream& operator<<(std::ostream& o, Form const& i);
