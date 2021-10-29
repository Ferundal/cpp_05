#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : grade(-1), is_signed(false) {

}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &new_name, int new_grade) : name(new_name), grade(new_grade), is_signed(false) {
	if (grade > FORM_GRADE_MAX_INT_VAL) {
		throw GradeTooLowException();
	}
	if (grade < FORM_GRADE_MIN_INT_VAL) {
		throw GradeTooHighException();
	}
}
ShrubberyCreationForm::ShrubberyCreationForm( const Form& origin) : name (origin.name), grade(origin.grade), is_signed(origin.is_signed) {

}

ShrubberyCreationForm&		ShrubberyCreationForm::operator =(const Form& origin) {
	is_signed = origin.is_signed;
	return (*this);
}

ShrubberyCreationForm::~Form( void ) {

}

std::string	ShrubberyCreationForm::getName( void ) const {
	return name;
}
int			ShrubberyCreationForm::getGrade ( void ) const {
	return grade;
}
bool		ShrubberyCreationForm::isSigned ( void ) const {
	return is_signed;
}

void		ShrubberyCreationForm::beSigned (Bureaucrat &rater) {
	if (grade < rater.getGrade()) {
		throw GradeTooHighException();
	}
	is_signed = true;
}

const char * ShrubberyCreationForm::GradeTooHighException::what() const throw() {
	return ("Form grade too high!");
}

const char * ShrubberyCreationForm::GradeTooLowException::what() const throw() {
	return ("Form grade too low!");
}

std::ostream &operator <<(std::ostream &outstream, const Form &origin) {
	outstream << origin.getName() << ", bureaucrat grade " << origin.getGrade() << "!";
	return (outstream);
}