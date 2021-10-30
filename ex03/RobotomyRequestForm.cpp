#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) :
					Form("RobotomyRequestForm", 72, 45),
					target("no target") {
}

RobotomyRequestForm::RobotomyRequestForm( const std::string &new_target) :
					Form("RobotomyRequestForm", 72, 45),
					target(new_target) {

}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& origin) :
					Form(origin), target(origin.target) {

}
RobotomyRequestForm& RobotomyRequestForm::operator =(const RobotomyRequestForm& origin) {
	(void)origin;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

}

void RobotomyRequestForm::action() const {
	std::cout << this->target;
	std::srand(std::time(nullptr));
	if (std::rand() % 2)
		std::cout << " has been robotomized!" << std::endl;
	else
		std::cout << " has not been robotomized!" << std::endl;
}