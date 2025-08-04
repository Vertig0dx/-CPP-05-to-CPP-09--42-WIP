/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:06 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/03/31 17:13:18 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>

class Bureaucrat;

class PresidentialPardonForm : public AForm {

	public:
	
	PresidentialPardonForm						( const std::string target );
	PresidentialPardonForm						( const PresidentialPardonForm &other );
	PresidentialPardonForm			&operator=	( const PresidentialPardonForm &other );
	~PresidentialPardonForm						( void );

	void 				beSigned				( Bureaucrat &one );
	std::string			execute					( Bureaucrat const &executor )const;

	class 			EmptySignatureException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Your PresidentialPardonForm is not signed.\n";
		}
	};

	class 			EmptyTargetException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Your PresidentialPardonForm's target is invalid.\n";
		}
	};
	
	class			GradeTooLowException : public std::exception{
		
		public:

		const char* what() const throw(){
			
			return "Your PresidentialPardonForm's required sign grade is too high.\n";
		}
	};

	class			GradeTooHighException : public std::exception{

		public:

		const char* what() const throw(){
			
			return "Your PresidentialPardonForm's required execution grade is too high.\n";
		}
	};

	private:

	std::string		_target;
	bool			_isSigned;
};

#endif