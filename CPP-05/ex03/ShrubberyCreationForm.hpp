/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:02:53 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/03/31 17:10:05 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {

	public:
	
	ShrubberyCreationForm						( const std::string target );
	ShrubberyCreationForm						( const ShrubberyCreationForm &other );
	ShrubberyCreationForm			&operator=	( const ShrubberyCreationForm &other );
	~ShrubberyCreationForm						( void );

	void 				beSigned				( Bureaucrat &one );
	std::string			execute					( Bureaucrat const &executor ) const;

	class 			EmptySignatureException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Your ShrubberyCreationForm is not signed\n";
		}
	};

	class 			EmptyTargetException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Your ShrubberyCreationForm's target is invalid.\n";
		}
	};
	
	class			GradeTooLowException : public std::exception{
		
		public:

		const char* what() const throw(){
			
			return "Your ShrubberyCreationForm's required sign grade is too high.\n";
		}
	};

	class			GradeTooHighException : public std::exception{

		public:

		const char* what() const throw(){
			
			return "Your ShrubberyCreationForm's required execution grade is too high.\n";
		}
	};

	private:

	std::string		_target;
	bool			_isSigned;
};

#endif