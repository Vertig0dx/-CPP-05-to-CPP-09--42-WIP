/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:09:50 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/20 16:03:07 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <list>

class Span{

	public:

	Span( void );
	Span( unsigned int size);
	Span( const Span &other );
	Span &operator=( const Span &other );
	~Span( void );

	void	addNumber( int to_add );
	void	addNumberRange( std::vector<int>::iterator first_number , std::vector<int>::iterator last_number );
	int		shortestSpan( void ) const;
	int		longestSpan( void ) const;

	class 			FullStackException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Your Stack is full.";
		}
	};

	class 			InvalidSpanException : public std::exception{
	
		public:

		const char* what() const throw(){

			return "Cannot calculate span on current Stack size.";
		}
	};

	private:

	std::vector<int>					_stack;
	unsigned int						_size;
};

#endif