#include "Intern.hpp"

std::string		Intern::forms[INTERN_CLASS_AMN] = {
		"ShrubberyCreationForm",
		"PresidentialPardonForm",
		"RobotomyRequestForm"
};

Intern::Intern( void ) {
	functions[0] = &Intern::newShrubberyCreationForm;
	functions[1] = &Intern::newPresidentialPardonForm;
	functions[2] = &Intern::newRobotomyRequestForm;
}
Intern::Intern( const Intern& origin) {
	for (int i = 0; i < INTERN_CLASS_AMN; i++) {
		functions[i] = origin.functions[i];
	}
}
Intern& Intern::operator =(const Intern& origin) {
	for (int i = 0; i < INTERN_CLASS_AMN; i++) {
		functions[i] = origin.functions[i];
	}
	return (*this);
}

Intern::~Intern( void ) {

}

Form *Intern::makeForm (std::string new_type, std::string new_target) {
	Form *ret_val = nullptr;
	for (int i = 0; i < INTERN_CLASS_AMN; i++) {
		if (new_type == forms[i]) {
			ret_val = (this->*functions[i])(new_target);
		}
	}
	if (ret_val != nullptr)
		std::cout << "Intern creates " << ret_val->getName() << std::endl;
	else
		std::cout << "Wrong form " << new_type << "!" << std::endl;
	return (ret_val);
}

Form *Intern::newShrubberyCreationForm(std::string new_target) {
	return (new ShrubberyCreationForm(new_target));
}
Form *Intern::newPresidentialPardonForm(std::string new_target) {
	return (new PresidentialPardonForm(new_target));
}
Form *Intern::newRobotomyRequestForm(std::string new_target) {
	return (new RobotomyRequestForm(new_target));
}