#ifndef _ShrubberyCreationForm_hpp_
#define _ShrubberyCreationForm_hpp_

# include <string>
# include <iostream>
# include <fstream>
# include "Bureaucrat.hpp"
# define FORM_GRADE_MIN_INT_VAL 1
# define FORM_GRADE_MAX_INT_VAL 150

class Bureaucrat;

class ShrubberyCreationForm : public Form {
private:
	const std::string	target;
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( const std::string &target);
	ShrubberyCreationForm( const ShrubberyCreationForm& origin);
	ShrubberyCreationForm& operator =(const ShrubberyCreationForm& origin);

	~ShrubberyCreationForm( void );

	virtual void action() const;

	class GradeTooHighException : public std::exception {
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char * what() const throw();
	};
};

#endif