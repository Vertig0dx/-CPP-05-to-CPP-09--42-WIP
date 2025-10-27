/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:16:51 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/29 18:27:29 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <string>

class RPN{

	public:

	RPN									( void );
	RPN									( RPN &other );
	RPN	&operator=						( RPN &other );
	~RPN								( void );

	void	solveStack					( int argc, char** argv );

	class			InvalidArgumentsException : public std::exception{

		public:

		const char* what() const throw(){

			return "Empty/invalid arguments.";
		}
	};

	class			InvalidEquationException : public std::exception{

		public:

		const char* what() const throw(){

			return "Your notation is invalid, valid notation requires at least 2 operands before an operator.";
		}
	};

	class			InvalidOperatorOperandException : public std::exception{

		public:

		const char* what() const throw(){

			return "Invalid operator/operand, only +-*/ and single numbers from 0 to 9 are allowed.";
		}
	};

	class			InvalidNotationException : public std::exception{

		public:

		const char* what() const throw(){

			return "Insuficient/excessive elements, operator quantity must always be one less than operand quantity.";
		}
	};
};

#endif