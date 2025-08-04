/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:36:42 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/03/26 16:11:41 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form{

	public:

	Form								( const std::string name, int sign_grade, int exec_grade );
	Form								( const Form &other );
	Form				&operator=		( const Form &other );
	~Form								( void );
	
	const std::string	getName			( void )const;
	std::string			getSignState	( void )const;
	int					getSignGrade	( void )const;
	int					getExecGrade	( void )const;
	void				beSigned		( Bureaucrat &one );
	
	class 			EmptyNameException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Your Form's name is invalid.";
		}
	};
	
	class			GradeTooLowException : public std::exception{
		
		public:

		const char* what() const throw(){
			
			return "Your Form's grade is too low.";
		}
	};

	class			GradeTooHighException : public std::exception{

		public:

		const char* what() const throw(){
			
			return "Your Form's grade is too high.";
		}
	};

	private:

	const std::string	_name;
	bool				_isSigned;
	const int			_signGrade;
	const int			_execGrade;

};

std::ostream 		&operator<<	( std::ostream &out, const Form &f);

#endif