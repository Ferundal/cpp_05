#include "Bureaucrat.hpp"
#include "Form.hpp"
#define ANIMAL_ARRAY_SIZE 2

int main() {
	try
	{
		Form not_ok_form ("not_ok_form", -7);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form not_ok_form ("not_ok_form", 155);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "----------ok_high_bur------------------------" <<std::endl;
	try
	{
		Form		ok_form ("ok_form", 70);
		Bureaucrat	ok_high_bur ("ok_high_bur", 13);
		ok_form.beSigned(ok_high_bur);
		std::cout << "Signed from beSigned" <<std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------ok_low_bur--------------------" <<std::endl;
	try
	{
		Form		ok_form ("ok_form", 70);
		Bureaucrat	ok_low_bur ("ok_low_bur", 130);
		ok_form.beSigned(ok_low_bur);
		std::cout << "Signed from beSigned" <<std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------ok_equal_bur------------------" <<std::endl;
	try
	{
		Form		ok_form ("ok_form", 70);
		Bureaucrat	ok_equal_bur ("ok_equal_bur", 70);
		ok_form.beSigned(ok_equal_bur);
		std::cout << "Signed from beSigned" <<std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------" <<std::endl;
	try
	{
		Form		ok_form ("ok_form", 70);
		Bureaucrat	ok_high_bur ("ok_high_bur", 13);
		ok_high_bur.signForm(ok_form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------" <<std::endl;
	try
	{
		Form		ok_form ("ok_form", 70);
		Bureaucrat	ok_low_bur ("ok_low_bur", 130);
		ok_low_bur.signForm(ok_form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------" <<std::endl;
	try
	{
		Form		ok_form ("ok_form", 70);
		Bureaucrat	ok_equal_bur ("ok_equal_bur", 70);
		ok_equal_bur.signForm(ok_form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------" <<std::endl;
	try
	{
		Form		ok_form ("ok_form", 70);
		Bureaucrat	ok_first_bur ("ok_equal_bur", 70);
		Bureaucrat	ok_second_bur ("ok_equal_bur", 70);
		ok_first_bur.signForm(ok_form);
		ok_second_bur.signForm(ok_form);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "-------------------------------------------" <<std::endl;
	try
	{
		Bureaucrat	not_ok_bur ("ok_equal_bur", 167);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}