#include "Form.hpp"

Form::Form( void ) : grade(-1), is_signed(false) {

}

Form::Form( const std::string &new_name, int new_grade) : name(new_name), grade(new_grade), is_signed(false) {
	if (grade > FORM_GRADE_MAX_INT_VAL) {
		throw GradeTooLowException();
	}
	if (grade < FORM_GRADE_MIN_INT_VAL) {
		throw GradeTooHighException();
	}
}
Form::Form( const Form& origin) : name (origin.name), grade(origin.grade), is_signed(origin.is_signed) {

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
int			Form::getGrade ( void ) const {
	return grade;
}
bool		Form::isSigned ( void ) const {
	return is_signed;
}

void		Form::beSigned (Bureaucrat &rater) {
	if (grade < rater.getGrade()) {
		throw GradeTooHighException();
	}
	is_signed = true;
}

const char * Form::GradeTooHighException::what() const throw() {
	return ("Form grade too high!");
}

const char * Form::GradeTooLowException::what() const throw() {
	return ("Form grade too low!");
}

std::ostream &operator <<(std::ostream &outstream, const Form &origin) {
	outstream << origin.getName() << ", bureaucrat grade " << origin.getGrade() << "!";
	return (outstream);
}