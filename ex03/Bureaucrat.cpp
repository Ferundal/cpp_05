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

void	Bureaucrat::signForm (Form &form) {
	if (form.isSigned()) {
		std::cout << name << "can't signs " << form.getName() << " becouse form is already signed!" << std::endl;
		return;
	}
	try {
		form.beSigned(*this);
	}
	catch (std::exception & e)
	{
		std::cout << name << " can't signs " << form.getName() << " becouse his grade " << grade << ", needed " << form.getSignG() << std::endl;
		return;
	}
	std::cout << name << " signs " << form.getName() << std::endl;
}

void	Bureaucrat::executeForm(Form const & form) {
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->getName() << " do not executes " << form.getName() << std::endl;
	}
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Bureaucrat grade too high!");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Bureaucrat grade too low!");
}

std::ostream &operator <<(std::ostream &outstream, const Bureaucrat &origin) {
	outstream << origin.getName() << ", bureaucrat grade " << origin.getGrade() << "!";
	return (outstream);
}