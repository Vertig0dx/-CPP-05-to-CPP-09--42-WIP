/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 17:18:27 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/01 17:07:25 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat{

	public:

	Bureaucrat								( const std::string name, int grade );
	Bureaucrat								( const Bureaucrat &other );
	Bureaucrat		&operator=				( const Bureaucrat &other );
	~Bureaucrat								( void );

	std::string		getName					( void )const;
	int				getGrade				( void )const;
	void			incrementGrade			( void );
	void			decrementGrade			( void );
	void			signForm				( AForm &form );

	void			executeForm				( AForm const &form ) const{

		std::string formType;

		try{
			
			formType = form.execute(*this);
			std::cout << this->_name << " executed " << formType << '\n' << std::endl;
		}
		catch (std::exception &e){
		
			std::cout << this->_name << " couldn't execute " << form.getName() 
				<< " because: " << e.what() << "\n" << std::endl;
		}
	};

	class 			EmptyNameException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Your Bureaucrat's name is invalid.";
		}
	};
	
	class			GradeTooLowException : public std::exception{
		
		public:

		const char* what() const throw(){
			
			return "Your Bureaucrat's grade is too low.";
		}
	};

	class			GradeTooHighException : public std::exception{

		public:

		const char* what() const throw(){
			
			return "Your Bureaucrat's grade is too high.";
		}
	};

	private:

	const std::string	_name;
	int					_grade;
};

std::ostream 		&operator<<	( std::ostream &out, const Bureaucrat &b);

#endif