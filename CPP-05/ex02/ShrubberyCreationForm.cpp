/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:02:40 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/03/31 18:26:30 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string target ) : AForm ( "ShrubberyCreationForm", 145, 137 ){

	if (target.empty())
		throw ShrubberyCreationForm::EmptyTargetException();
	this->_target = target;
	std::cout << "ShrubberyCreationForm constuctor called.\n" << std::endl;
};

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ): AForm ( other ){

	std::cout << "ShrubberyCreationForm copy constuctor called.\n" << std::endl;
};

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other){

	if (this != &other)
		_target = other._target;
	return *this;
	std::cout << "ShrubberyCreationForm = operator overload called.\n" << std::endl;
};

ShrubberyCreationForm::~ShrubberyCreationForm( void ){

	std::cout << "ShrubberyCreationForm destructor called.\n" << std::endl;
};

// void ShrubberyCreationForm::beSigned( Bureaucrat &one ){

// 	if (one.getGrade() <= 145)
// 		this->_isSigned = true;
// 	else
// 	{
// 		this->_isSigned = false;
// 		throw ShrubberyCreationForm::GradeTooLowException();
// 	}
// 	std::cout << "beSigned this->isSigned = " << this->_isSigned << '\n' << std::endl;
// };

std::string ShrubberyCreationForm::execute	( Bureaucrat const &executor ) const{

	if (this->getSignState() == "Not Signed" || (this->getSignState() == "Signed" && executor.getGrade() > 145))
		throw EmptySignatureException();
	if (executor.getGrade() > 137)
		throw GradeTooHighException();
	std::ofstream	targetFile;
	targetFile.open ((_target + "_shrubbery").c_str());
	if (!targetFile){
		targetFile.close();
		throw EmptyTargetException();
	}
	targetFile << "		               ,@@@@@@@,					" << std::endl;
	targetFile << "		       ,,,.   ,@@@@@@/@@,  .oo8888o.		" << std::endl;
	targetFile << "		    ,&%&&%&&%,@@@@@/@@@@@@,8888|88/8o		" << std::endl;
	targetFile << "		   ,%&&%&&%&&%,@@@|@@@/@@@88|88888/88'		" << std::endl;
	targetFile << "		   %&&%&%&/%&&%@@|@@/ /@@@88888|88888'		" << std::endl;
	targetFile << "		   %&&%/ %&&%&&@@| V /@@' `88|8 `/88'		" << std::endl;
	targetFile << "		   `&%| ` /%&'    |.|        | '|8'			" << std::endl;
	targetFile << "		       |o|        | |         | |			" << std::endl;
	targetFile << "		       |.|        | |         | |			" << std::endl;
	targetFile << "		    \\| ._|//_/__/  ,|_//__\\|.  |-//__/_	" << std::endl;
	targetFile.close();
	return ("ShrubberyCreationForm");
};

