#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) :
					Form("ShrubberyCreationForm", 145, 137),
					target("no target") {
}

ShrubberyCreationForm::ShrubberyCreationForm( const std::string &new_target) :
					Form("ShrubberyCreationForm", 145, 137),
					target(new_target) {

}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& origin) :
					Form(origin), target(origin.target) {

}
ShrubberyCreationForm& ShrubberyCreationForm::operator =(const ShrubberyCreationForm& origin) {
	(void)origin;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

}

void ShrubberyCreationForm::action() const {
	std::ofstream output;
	output.open((this->target + "_shrubbery").c_str());
	if (!output.is_open())
		std::cout << "Can't create replace file!" << std::endl;
	output << "   ********    " << std::endl;
	output << " ************  " << std::endl;
	output << "  **********   " << std::endl;
	output << "      **       " << std::endl;
	output << "      **       " << std::endl;
	output << "     *****     " << std::endl;
	output.close();
}