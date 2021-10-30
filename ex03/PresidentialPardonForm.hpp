#ifndef _PresidentialPardonForm_hpp_
#define _PresidentialPardonForm_hpp_

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# define FORM_GRADE_MIN_INT_VAL 1
# define FORM_GRADE_MAX_INT_VAL 150

class Bureaucrat;

class PresidentialPardonForm : public Form {
private:
	const std::string	target;
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( const std::string &target);
	PresidentialPardonForm( const PresidentialPardonForm& origin);
	PresidentialPardonForm& operator =(const PresidentialPardonForm& origin);

	~PresidentialPardonForm( void );

	virtual void action() const;

	class GradeTooHighException : public std::exception {
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char * what() const throw();
	};
};

#endif