/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:10 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/01 15:00:50 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( const std::string target ) : AForm ( "RobotomyRequestForm", 72, 45 ){

	if (target.empty())
		throw RobotomyRequestForm::EmptyTargetException();
	this->_target = target;
	std::cout << "RobotomyRequestForm constuctor called.\n" << std::endl;
};

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ): AForm ( other ){

	std::cout << "RobotomyRequestForm copy constuctor called.\n" << std::endl;
};

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &other){

	if (this != &other)
		_target = other._target;
	return *this;
	std::cout << "RobotomyRequestForm = operator overload called.\n" << std::endl;
};

RobotomyRequestForm::~RobotomyRequestForm( void ){

	std::cout << "RobotomyRequestForm destructor called.\n" << std::endl;
};

/* void RobotomyRequestForm::beSigned( Bureaucrat &one ){

	if (one.getGrade() <= 72)
		this->_isSigned = true;
	else
	{
		this->_isSigned = false;
		throw RobotomyRequestForm::GradeTooLowException();
	}
}; */

std::string	RobotomyRequestForm::execute	( Bureaucrat const &executor )const{

	if (this->getSignState() == "Not Signed" || (this->getSignState() == "Signed" && executor.getGrade() > 72))
		throw EmptySignatureException();
	if (executor.getGrade() > 45)
		throw GradeTooHighException();
	std::cout << "DRILLLLLLLLLLLLLLLLLLLLLLLLLLLLL" << std::endl;
	srand(static_cast<unsigned int>(time(0)));
	int	random = rand();
	if ((random % 2) == 0)
		std::cout << _target << " robotomy successful." << std::endl;
	else
		std::cout << "Robotomy unsuccessful..." << std::endl;
	return ("RobotomyRequestForm");
};

