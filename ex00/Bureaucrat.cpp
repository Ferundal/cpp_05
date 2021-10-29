#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) {

}

Bureaucrat::Bureaucrat( const std::string &new_name, int new_grade) : name(new_name) {
	if (new_grade > GRADE_MAX_INT_VAL) {
		throw GradeTooLowException();
	}
	if (new_grade < GRADE_MIN_INT_VAL) {
		throw GradeTooHighException();
	}
	grade = new_grade;
}
Bureaucrat::Bureaucrat( const Bureaucrat& origin) : name (origin.name), grade(origin.grade) {

}

Bureaucrat& Bureaucrat::operator =(const Bureaucrat& origin) {
	grade = origin.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat( void ) {

}

Bureaucrat Bureaucrat::operator ++(int) {
	Bureaucrat ret_val (*this);
	if (grade == GRADE_MIN_INT_VAL) {
		throw GradeTooHighException();
	}
	--grade;
	return (ret_val);
}
Bureaucrat Bureaucrat::operator --(int) {
	Bureaucrat ret_val (*this);
	if (grade == GRADE_MAX_INT_VAL) {
		throw GradeTooLowException();
	}
	return (ret_val);
}
std::string Bureaucrat::getName( void ) const {
	return name;
}
int Bureaucrat::getGrade ( void ) const {
	return grade;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low!");
}

std::ostream &operator <<(std::ostream &outstream, const Bureaucrat &origin) {
	outstream << origin.getName() << ", bureaucrat grade " << origin.getGrade() << "!";
	return (outstream);
}