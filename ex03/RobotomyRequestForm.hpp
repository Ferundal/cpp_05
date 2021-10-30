#ifndef _RobotomyRequestForm_hpp_
#define _RobotomyRequestForm_hpp_

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# define FORM_GRADE_MIN_INT_VAL 1
# define FORM_GRADE_MAX_INT_VAL 150

class Bureaucrat;

class RobotomyRequestForm : public Form {
private:
	const std::string	target;
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( const std::string &target);
	RobotomyRequestForm( const RobotomyRequestForm& origin);
	RobotomyRequestForm& operator =(const RobotomyRequestForm& origin);

	~RobotomyRequestForm( void );

	virtual void action() const;

	class GradeTooHighException : public std::exception {
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char * what() const throw();
	};
};

#endif