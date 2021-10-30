#include "Form.hpp"

Form::Form( void ) : sign(-1),
					exec(-1),
					is_signed(false) {

}

Form::Form( const std::string &new_name, int new_sign, int new_exec) :
															name(new_name),
															sign(new_sign),
															exec(new_exec),
															is_signed(false) {
	if (sign > FORM_GRADE_MAX_INT_VAL || exec > FORM_GRADE_MAX_INT_VAL) {
		throw GradeTooLowException();
	}
	if (sign < FORM_GRADE_MIN_INT_VAL || exec < FORM_GRADE_MIN_INT_VAL) {
		throw GradeTooHighException();
	}
}
Form::Form( const Form& origin) : name (origin.name),
									sign(origin.sign),
									exec(origin.exec),
									is_signed(origin.is_signed) {

}

Form&		Form::operator =(const Form& origin) {
	is_signed = origin.is_signed;
	return (*this);
}

Form::~Form( void ) {

}

std::string	Form::getName( void ) const {
	return name;
}
int			Form::getSignG (void ) const {
	return sign;
}
int			Form::getExecG (void ) const {
	return exec;
}
bool		Form::isSigned ( void ) const {
	return is_signed;
}

void		Form::beSigned (Bureaucrat &rater) {
	if (sign < rater.getGrade()) {
		throw GradeTooHighException();
	}
	is_signed = true;
}
void		Form::execute(Bureaucrat const & executor) const {
	if (is_signed == false || exec < executor.getGrade())
		throw GradeTooHighException();
	action();
}


const char * Form::GradeTooHighException::what() const throw() {
	return ("Form grade too high!");
}

const char * Form::GradeTooLowException::what() const throw() {
	return ("Form grade too low!");
}

std::ostream &operator <<(std::ostream &outstream, const Form &origin) {
	outstream << origin.getName() << " form needs " << origin.getSignG() << " to sign and " << origin.getExecG() << " to execute!";
	return (outstream);
}