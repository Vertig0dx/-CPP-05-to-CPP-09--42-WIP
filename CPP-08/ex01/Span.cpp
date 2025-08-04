/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:43:27 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/21 14:14:16 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span ( void ) : _size( 0 )
{
	std::cout << "Span default class constructor called." << std::endl;
}

Span::Span ( unsigned int size ) : _size( size )
{
	std::cout << "Span class constructor called." << std::endl;
}

Span::Span( const Span &other )
{
	std::cout << "Span class copy constructor called." << std::endl;
	*this = other;
}

Span &Span::operator=( const Span &other )
{
	std::cout << "Span overloaded operator detected, overwriting default function." << std::endl;
	if (this != &other){
		this->_stack = other._stack;
		this->_size = other._size;
	}
	return (*this);
}

Span::~Span( void )
{
	std::cout << "Span class destructor called." << std::endl;
}

void Span::addNumber( int to_add )
{
	if (this->_stack.size() == this->_size)
		throw Span::FullStackException();
	this->_stack.push_back(to_add);
}

void Span::addNumberRange( std::vector<int>::iterator first_number, std::vector<int>::iterator last_number)
{
	//impossible to do with C++98 algorithms, would require at least C++23 with vector.insert_range (false, use vector.insert... for some reason, 
	//it works with ranges and they felt the need to add an insert_range in CPP23)
	if (this->_stack.size() + std::distance(first_number, last_number) > this->_size)
		throw Span::FullStackException();
	this->_stack.insert(this->_stack.end(), first_number, last_number);
}
int Span::shortestSpan( void ) const
{
	int current_min;

	if (this->_stack.size() < 2)
		throw Span::InvalidSpanException();
	std::vector<int>		temp_vector = this->_stack;

	std::sort(temp_vector.begin(), temp_vector.end());
	current_min = temp_vector[1] - temp_vector[0];
	for(unsigned int i = 1; i < temp_vector.size(); ++i){
		if (temp_vector[i] - temp_vector[i - 1] < current_min)
			current_min = temp_vector[i] - temp_vector[i - 1];
	}
	return (current_min);
}

int Span::longestSpan( void ) const
{
	if (this->_stack.size() < 2)
		throw Span::InvalidSpanException();
	std::vector<int>		temp_vector = this->_stack;

	std::sort(temp_vector.begin(), temp_vector.end());
	return (temp_vector[temp_vector.size() - 1] - temp_vector[0]);
}