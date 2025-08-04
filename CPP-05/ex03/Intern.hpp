/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:15:47 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/01 16:10:52 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern{

	public:

	Intern							( void );
	Intern							( const Intern &other );
	Intern		&operator=			( const Intern &other );
	~Intern							( void );

	AForm		*makeForm 			( std::string form, std::string target);

	class			EmptyTargetException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Your Intern requires a target.\n";
		}
	};

	class			InvalidNameException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Your Intern can only create these forms: Shrubbery, Robotomy or Presidential.\n";
		}
	};

	private:

};

#endif