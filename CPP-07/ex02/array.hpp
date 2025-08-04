/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:57:49 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/15 14:37:39 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <string>
# include <exception>

template <typename T>
class Array{

	public:
	
	Array( void ) : _size(0)
	{
		std::cout << "Default constructor called." << std::endl;
		this->_array = new T[this->_size];
	}

	Array(unsigned int val) : _size(val)
	{
		if (this->_size < 0 || this->_size > 4294967285)
			throw Array<T>::BadIndexException();
		std::cout << "Unsigned int detected, creating an array of size " << this->_size << std::endl;
		this->_array = new T[this->_size];
	}

	Array(const Array &other) : _size(other.getSize())
	{
		std::cout << "Copy constructor called." << std::endl;
		this->_array = NULL;
		*this = other;
	}

	Array	&operator=(const Array &other)
	{
		if (this->_array != NULL)
			delete [] this->_array;
		if (other.getSize() != 0)
		{
			this->_size = other.getSize();
			this->_array = new T[this->_size];
			for (unsigned int i = 0; i < this->getSize(); ++i)
				this->_array[i] = other._array[i];
		}
		return (*this);
	}

	T	&operator[](unsigned int index)
	{
		if (index >= this->getSize()){
			std::cout << "Current index = " << index << std::endl;
			throw Array<T>::BadIndexException();
		}
		return (this->_array[index]);
	}

	~Array()
	{
		if (this->_array != NULL)
			delete [] this->_array;
	}

	unsigned int getSize() const
	{
		return (this->_size);
	}

	class BadIndexException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	private:

	T						*_array;
	unsigned int			_size;
};

template< typename T >
const char	*Array<T>::BadIndexException::what() const throw()
{
	return ("Fatal error: Invalid Index Detected.");
}

#endif