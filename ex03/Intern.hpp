#ifndef _Intern_hpp_
#define _Intern_hpp_

# include <string>
# include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
# define INTERN_CLASS_AMN 3

class Intern {
private:
	static std::string		forms[INTERN_CLASS_AMN];
	Form					*(Intern::*functions[INTERN_CLASS_AMN])(std::string new_target);
public:
	Intern( void );
	Intern( const Intern& origin);
	Intern& operator =(const Intern& origin);

	~Intern( void );

	Form *makeForm (std::string new_type, std::string new_target);

	Form *newShrubberyCreationForm(std::string new_target);
	Form *newPresidentialPardonForm(std::string new_target);
	Form *newRobotomyRequestForm(std::string new_target);
};
#endif