/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:36:24 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/03/31 18:23:56 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int sign_grade, int exec_grade) : _name(name),
	_signGrade(sign_grade), _execGrade(exec_grade){

	if (_name.empty())
		throw AForm::EmptyNameException();
	if (_signGrade > 150)
		throw AForm::GradeTooLowException();
	if (_signGrade < 1)
		throw AForm::GradeTooHighException();
	if (_execGrade > 150)
		throw AForm::GradeTooLowException();
	if (_execGrade < 1)
		throw AForm::GradeTooHighException();
	this->_isSigned = false;
	std::cout << "AForm constructor called.\n" << std::endl;
};

void AForm::beSigned( Bureaucrat const &one ){

	if (one.getGrade() <= _signGrade)
		this->_isSigned = true;
	else
	{
		this->_isSigned = false;
		throw AForm::GradeTooLowException();
	}
};

AForm::AForm( const AForm &other ) : _name(other._name), _isSigned(other._isSigned),
	_signGrade(other._signGrade), _execGrade(other._execGrade){

	std::cout << "AForm copy constuctor called." << std::endl;
};

AForm &AForm::operator=( const AForm &other){

	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
	std::cout << "AForm = operator overload called.\n" << std::endl;
};

AForm::~AForm( void ){

	std::cout << "AForm destructor called.\n" << std::endl;
};

const std::string	AForm::getName( void ) const{

	return(_name);
};

std::string	AForm::getSignState( void ) const{

	if (this->_isSigned == 1)
		return ("Signed");
	return ("Not Signed");
};

int	AForm::getSignGrade( void ) const{

	return(_signGrade);
};

int	AForm::getExecGrade( void ) const{

	return(_execGrade);
};

std::ostream &operator<<(std::ostream &out, const AForm &AForm){

	out << AForm.getName() << ", AForm state: " << AForm.getSignState() << ", grade required for signature: " << AForm.getSignGrade() << 
		", grade required for execution: " << AForm.getExecGrade() << ".\n" << std::endl;
	return (out);
};