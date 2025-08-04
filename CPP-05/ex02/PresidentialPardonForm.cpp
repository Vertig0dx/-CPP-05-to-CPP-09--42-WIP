/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:14:46 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/01 14:35:49 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( const std::string target ) : AForm ( "PresidentialPardonForm", 25, 5 ){

	if (target.empty())
		throw PresidentialPardonForm::EmptyTargetException();
	this->_target = target;
	std::cout << "PresidentialPardonForm constuctor called.\n" << std::endl;
};

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other ): AForm ( other ){

	std::cout << "PresidentialPardonForm copy constuctor called.\n" << std::endl;
};

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &other){

	if (this != &other)
		_target = other._target;
	return *this;
	std::cout << "PresidentialPardonForm = operator overload called.\n" << std::endl;
};

PresidentialPardonForm::~PresidentialPardonForm( void ){

	std::cout << "PresidentialPardonForm destructor called.\n" << std::endl;
};

/* void PresidentialPardonForm::beSigned( Bureaucrat &one ){

	if (one.getGrade() <= 25)
		this->_isSigned = true;
	else
	{
		this->_isSigned = false;
		throw PresidentialPardonForm::GradeTooLowException();
	}
}; */

std::string PresidentialPardonForm::execute			( Bureaucrat const &executor )const{

	if (this->getSignState() == "Not Signed" || (this->getSignState() == "Signed" && executor.getGrade() > 25))
		throw EmptySignatureException();
	if (executor.getGrade() > 5)
		throw GradeTooHighException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox.\n" << std::endl;
	return ("PresidentialPardonForm");
};
