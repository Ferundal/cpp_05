#include "Intern.hpp"

int main() {
	try
	{
		Bureaucrat God("God", 1);
		Intern _test_int;
		Form *form_ptr =  _test_int.makeForm("PresidentialPardonForm", "LOH");
		God.signForm(*form_ptr);
		God.executeForm(*form_ptr);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat God("God", 1);
		Intern _test_int;
		Form *form_ptr =  _test_int.makeForm("ShrubberyCreationForm", "LOH");
		God.signForm(*form_ptr);
		God.executeForm(*form_ptr);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat God("God", 1);
		Intern _test_int;
		Form *form_ptr =  _test_int.makeForm("RobotomyRequestForm", "LOH");
		God.signForm(*form_ptr);
		God.executeForm(*form_ptr);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat God("God", 1);
		Intern _test_int;
		Form *form_ptr =  _test_int.makeForm("Lolwhut", "LOH");
		if (form_ptr != nullptr) {
			God.signForm(*form_ptr);
			God.executeForm(*form_ptr);
		}
		else
			std::cout << "NULL" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
