#ifndef _ShrubberyCreationForm_hpp_
#define _ShrubberyCreationForm_hpp_

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# define FORM_GRADE_MIN_INT_VAL 1
# define FORM_GRADE_MAX_INT_VAL 150

class Bureaucrat;

class ShrubberyCreationForm {
private:
	const std::string	name;
	const int			grade;
	bool				is_signed;
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( const std::string &new_name, int new_grade);
	ShrubberyCreationForm( const Form& origin);
	ShrubberyCreationForm& operator =(const Form& origin);

	~ShrubberyCreationForm( void );

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	bool		isSigned ( void ) const;
	void		beSigned (Bureaucrat &rater);

	class GradeTooHighException : public std::exception {
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char * what() const throw();
	};
};

std::ostream &operator <<(std::ostream &outstream, const Form &origin);
#endif