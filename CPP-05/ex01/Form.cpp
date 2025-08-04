/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:36:24 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/03/26 16:17:52 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int sign_grade, int exec_grade) : _name(name),
	_signGrade(sign_grade), _execGrade(exec_grade){

	if (_name.empty())
		throw Form::EmptyNameException();
	if (_signGrade > 150)
		throw Form::GradeTooLowException();
	if (_signGrade < 1)
		throw Form::GradeTooHighException();
	if (_execGrade > 150)
		throw Form::GradeTooLowException();
	if (_execGrade < 1)
		throw Form::GradeTooHighException();
	this->_isSigned = false;
	std::cout << "Form constructor called.\n" << std::endl;
};

Form::Form( const Form &other ) : _name(other._name), _isSigned(other._isSigned),
	_signGrade(other._signGrade), _execGrade(other._execGrade){

	std::cout << "Form copy constuctor called." << std::endl;
};

Form &Form::operator=( const Form &other){

	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
	std::cout << "Form = operator overload called.\n" << std::endl;
};

Form::~Form( void ){

	std::cout << "Form destructor called.\n" << std::endl;
};

const std::string	Form::getName( void ) const{

	return(_name);
};

std::string	Form::getSignState( void ) const{

	if (this->_isSigned == true)
		return ("Signed");
	return ("Not Signed");
};

int	Form::getSignGrade( void ) const{

	return(_signGrade);
};

int	Form::getExecGrade( void ) const{

	return(_execGrade);
};

void Form::beSigned( Bureaucrat &one ){

	if (one.getGrade() <= this->_signGrade)
		this->_isSigned = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &Form){

	out << Form.getName() << ", Form state: " << Form.getSignState() << ", grade required for signature: " << Form.getSignGrade() << 
		", grade required for execution: " << Form.getExecGrade() << ".\n" << std::endl;
	return (out);
};