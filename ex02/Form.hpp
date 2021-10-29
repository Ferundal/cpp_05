#ifndef _Form_hpp_
#define _Form_hpp_

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"
# define FORM_GRADE_MIN_INT_VAL 1
# define FORM_GRADE_MAX_INT_VAL 150

class Bureaucrat;

class Form {
private:
	const std::string	name;
	const int			grade;
	bool				is_signed;
public:
	Form( void );
	Form( const std::string &new_name, int new_grade);
	Form( const Form& origin);
	Form& operator =(const Form& origin);

	~Form( void );

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	bool		isSigned ( void ) const;
	void		beSigned (Bureaucrat &rater);

	virtual void executee(Bureaucrat const & executor) = 0;

	class GradeTooHighException : public std::exception {
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char * what() const throw();
	};
};

std::ostream &operator <<(std::ostream &outstream, const Form &origin);
#endif