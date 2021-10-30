#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
	{
		ShrubberyCreationForm ok_sh_form ("home");
		std::cout << ok_sh_form <<std::endl;
		PresidentialPardonForm ok_pres_form ("home");
		std::cout << ok_pres_form <<std::endl;
		RobotomyRequestForm ok_rob_form("home");
		std::cout << ok_rob_form <<std::endl;
	}
	try
	{
		ShrubberyCreationForm ok_form ("home");
		Bureaucrat rater("Bob", 140);
		Bureaucrat executer("Bill", 130);
		rater.signForm(ok_form);
		ok_form.execute(executer);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		PresidentialPardonForm ok_pres_form ("home");
		Bureaucrat rater("Bob", 24);
		Bureaucrat executer("Bill", 4);
		rater.signForm(ok_pres_form);
		ok_pres_form.execute(executer);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		RobotomyRequestForm ok_rob_form("home");
		Bureaucrat rater("Bob", 71);
		Bureaucrat executer("Bill", 44);
		rater.signForm(ok_rob_form);
		ok_rob_form.execute(executer);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------------"  <<std::endl;
	try
 	{
		ShrubberyCreationForm ok_form ("home");
		Bureaucrat rater("Bob", 140);
		Bureaucrat executer("Bill", 140);
		rater.signForm(ok_form);
		ok_form.execute(executer);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------------"  <<std::endl;
	try
	{
		ShrubberyCreationForm ok_form ("home");
		Bureaucrat rater("Bob", 149);
		Bureaucrat executer("Bill", 130);
		rater.signForm(ok_form);
		ok_form.execute(executer);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------------"  <<std::endl;
	try
	{
		PresidentialPardonForm ok_pres_form ("home");
		Bureaucrat rater("Bob", 24);
		Bureaucrat executer("Bill", 7);
		rater.signForm(ok_pres_form);
		ok_pres_form.execute(executer);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------------"  <<std::endl;
	try
	{
		PresidentialPardonForm ok_pres_form ("home");
		Bureaucrat rater("Bob", 30);
		Bureaucrat executer("Bill", 1);
		rater.signForm(ok_pres_form);
		ok_pres_form.execute(executer);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------------"  <<std::endl;
	try
	{
		RobotomyRequestForm ok_rob_form("home");
		Bureaucrat rater("Bob", 71);
		Bureaucrat executer("Bill", 100);
		rater.signForm(ok_rob_form);
		ok_rob_form.execute(executer);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "------------------------------------------"  <<std::endl;
	try
	{
		RobotomyRequestForm ok_rob_form("home");
		Bureaucrat rater("Bob", 75);
		Bureaucrat executer("Bill", 40);
		rater.signForm(ok_rob_form);
		ok_rob_form.execute(executer);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "+++++++++++++++++++++++"  <<std::endl;
	try
	{
		RobotomyRequestForm ok_rob_form("home");
		Bureaucrat god("God", 1);
		Bureaucrat trash("Trash", 150);
		god.signForm(ok_rob_form);
		god.executeForm(ok_rob_form);
		trash.executeForm(ok_rob_form);
	}
	catch (std::exception & e)
	{
		std::cout << "Shoud not see that message!" << std::endl;
	}


}