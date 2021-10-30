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
	const int			sign;
	const int			exec;
	bool				is_signed;
public:
	Form( void );
	Form( const std::string &new_name, int new_sign, int new_exec);
	Form( const Form& origin);
	Form& operator =(const Form& origin);

	~Form( void );

	std::string	getName( void ) const;
	int			getSignG(void ) const;
	int			getExecG (void ) const;
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