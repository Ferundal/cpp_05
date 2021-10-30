#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) :
					Form("PresidentialPardonForm", 25, 5),
					target("no target") {
}

PresidentialPardonForm::PresidentialPardonForm( const std::string &new_target) :
					Form("PresidentialPardonForm", 25, 5),
					target(new_target) {

}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& origin) :
					Form(origin), target(origin.target) {

}
PresidentialPardonForm& PresidentialPardonForm::operator =(const PresidentialPardonForm& origin) {
	(void)origin;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

}

void PresidentialPardonForm::action() const {
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}