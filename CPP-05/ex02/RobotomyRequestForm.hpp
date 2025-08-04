/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 15:04:13 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/01 14:09:39 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>

class Bureaucrat;

class RobotomyRequestForm : public AForm {

	public:
	
	RobotomyRequestForm							( const std::string target );
	RobotomyRequestForm							( const RobotomyRequestForm &other );
	RobotomyRequestForm			&operator=		( const RobotomyRequestForm &other );
	~RobotomyRequestForm						( void );

	void 				beSigned				( Bureaucrat &one );
	std::string			execute					( Bureaucrat const &executor )const;

	class 			EmptySignatureException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Your RobotomyRequestForm is not signed.\n";
		}
	};

	class 			EmptyTargetException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Your RobotomyRequestForm's target is invalid.\n";
		}
	};
	
	class			GradeTooLowException : public std::exception{
		
		public:

		const char* what() const throw(){
			
			return "Your RobotomyRequestForm's required sign grade is too high.\n";
		}
	};

	class			GradeTooHighException : public std::exception{

		public:

		const char* what() const throw(){
			
			return "Your RobotomyRequestForm's required execution grade is too high.\n";
		}
	};

	private:

	std::string		_target;
	bool			_isSigned;
};

#endif