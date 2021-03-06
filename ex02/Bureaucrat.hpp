#ifndef _Bureaucrat_hpp_
#define _Bureaucrat_hpp_

# include <string>
# include <iostream>
# include "Form.hpp"
# define GRADE_MIN_INT_VAL 1
# define GRADE_MAX_INT_VAL 150

class Form;

class Bureaucrat {
protected:
	const std::string	name;
	int					grade;
public:
	Bureaucrat( void );
	Bureaucrat( const std::string &new_name, int new_grade);
	Bureaucrat( const Bureaucrat& origin);
	Bureaucrat& operator =(const Bureaucrat& origin);

	~Bureaucrat( void );

	Bureaucrat operator ++(int);
	Bureaucrat operator --(int);

	std::string	getName( void ) const;
	int			getGrade ( void ) const;
	void		signForm (Form &_form);
	void		executeForm(Form const & form);

	class GradeTooHighException : public std::exception {
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char * what() const throw();
	};
};

std::ostream &operator <<(std::ostream &outstream, const Bureaucrat &origin);
#endif