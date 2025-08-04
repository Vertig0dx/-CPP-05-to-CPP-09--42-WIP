/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 14:19:29 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/03/31 14:08:30 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){

	if (_name.empty())
		throw Bureaucrat::EmptyNameException();
	if (_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Bureaucrat constructor called.\n" << std::endl;
};

Bureaucrat::Bureaucrat( const Bureaucrat &other ) : _name(other._name), _grade(other._grade){

	std::cout << "Bureaucrat copy constuctor called." << std::endl;
};

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other){

	if (this != &other)
		_grade = other._grade;
	return *this;
	std::cout << "Bureaucrat = operator overload called." << std::endl;
};

Bureaucrat::~Bureaucrat( void ){

	std::cout << "Bureaucrat destructor called.\n" << std::endl;
};

std::string	Bureaucrat::getName( void ) const{

	return(_name);
};

int	Bureaucrat::getGrade( void ) const{

	return(_grade);
};

void	Bureaucrat::incrementGrade( void ){

	std::cout << "\nIncrementing grade...\n" << std::endl;
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
};

void	Bureaucrat::decrementGrade( void ){

	std::cout << "\nDecrementing grade...\n" << std::endl;
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
};

void	Bureaucrat::signForm( Form &form ){

	try{
		
	form.beSigned(*this);
	if (form.getSignState() == "Signed")
		std::cout << this->_name << " signed " << form.getName() + "\n" << std::endl;
	}
	catch (std::exception &e){
		
		std::cout << this->_name << " couldn't sign " << form.getName() 
			<< " because: " << e.what() << "\n" << std::endl;
	}
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &Bureaucrat){

	out << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade() << "." << std::endl;
	return (out);
};
