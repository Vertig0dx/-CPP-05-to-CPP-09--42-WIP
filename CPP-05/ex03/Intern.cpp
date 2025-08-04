/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:15:34 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/01 16:58:05 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void ){

	std::cout << "Intern constructor called.\n" << std::endl;
};

Intern::Intern(const Intern &other){

	*this = other;
	std::cout << "Intern copy constructor called.\n" << std::endl;
};

Intern &Intern::operator=(const Intern &other){

	if (this == &other)
		return *this;
	else
		return *this;
	std::cout << "Intern = operator overload called.\n" << std::endl;
};

Intern::~Intern( void ){

	std::cout << "Intern destructor called.\n" << std::endl;
};

AForm* Intern::makeForm( std::string name, std::string target){

	AForm *Form;

	if (target.empty())
		throw Intern::EmptyTargetException();
	if (name == "Shrubbery"){
		Form = new ShrubberyCreationForm (target);
		std::cout << "Intern created ShrubberyCreationForm." << std::endl;
	}
	else if (name == "Robotomy"){
		Form = new RobotomyRequestForm (target);
		std::cout << "Intern created RobotomyRequestForm." << std::endl;
	}
	else if (name == "Presidential"){
		Form = new PresidentialPardonForm (target);
		std::cout << "Intern created PresidentialPardonForm." << std::endl;
	}
	else
		throw Intern::InvalidNameException();
	return (Form);
};