/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:36:42 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/01 14:33:26 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <fstream>
#include <exception>
#include <cstdlib>

class Bureaucrat;

class AForm {

	public:

	AForm										( std::string name, int sign_grade, int exec_grade );
	AForm										( const AForm &other );
	AForm						&operator=		( const AForm &other );
	virtual 					~AForm			( void ) = 0;
	
	const std::string			getName			( void )const;
	std::string					getSignState	( void )const;
	int							getSignGrade	( void )const;
	int							getExecGrade	( void )const;
	void						beSigned		( Bureaucrat const &one );
	virtual std::string			execute			( Bureaucrat const &executor )const = 0;

	class 			EmptyNameException : public std::exception{
	
		public:

		virtual const char* what() const throw(){

			return "Your AForm's name is invalid.";
		}
	};
	
	class			GradeTooLowException : public std::exception{
		
		public:

		virtual const char* what() const throw(){
			
			return "Your form's sign grade is too high.";
		}
	};

	class			GradeTooHighException : public std::exception{

		public:

		virtual const char* what() const throw(){
			
			return "Your form's execute grade is too high.";
		}
	};

	private:

	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

};

std::ostream 		&operator<<	( std::ostream &out, const AForm &f);

#endif