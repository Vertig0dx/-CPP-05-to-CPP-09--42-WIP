/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:18:58 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/21 15:30:38 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <algorithm>
#include <cstdlib>
#include <string>
#include <stack>
#include <iomanip>
#include <iostream>
#include <list>

template <typename stack_t>

class MutantStack : public std::stack <stack_t>{

	public:

	//CONSTRUCTORS AND DESTRUCTOR
	MutantStack( void ){
		
		std::cout << "MutantStack constructor called. " << std::endl;
	}
	
	MutantStack( const MutantStack &other ){

		*this = other;
		std::cout << "MutantStack copy constructor called. " << std::endl;
	}
	
	MutantStack operator=( const MutantStack &other){

		std::cout << "Overloaded operator detected, initiating assignment. " << std::endl;
		if ( *this != other )
			*this = other;
		return ( *this );
	}

	~MutantStack( void ){

		std::cout << "MutantStack destructor called. " << std::endl;
	}

	//REMEMBER TO EXPLAIN THAT STACK IS NOT A CONTAINER, MERELY A "CLASS" THAT CONTAINS THE ACTUAL CONTAINER IN IT, DEQUE
	//REMEMBER TO EXPLAIN THAT STACK IS NOT A CONTAINER, MERELY A "CLASS" THAT CONTAINS THE ACTUAL CONTAINER IN IT, DEQUE
	//REMEMBER TO EXPLAIN THAT STACK IS NOT A CONTAINER, MERELY A "CLASS" THAT CONTAINS THE ACTUAL CONTAINER IN IT, DEQUE
	//REMEMBER TO EXPLAIN THAT STACK IS NOT A CONTAINER, MERELY A "CLASS" THAT CONTAINS THE ACTUAL CONTAINER IN IT, DEQUE
	
	//ITERATOR
	typedef typename std::stack<stack_t>::container_type::iterator mIterator;
	
	mIterator begin(){

		return (std::stack<stack_t>::c.begin());
	};
	mIterator end(){

		return (std::stack<stack_t>::c.end());
	};

	//CONST INTERATOR
	typedef typename std::stack<stack_t>::container_type::const_iterator const_mIterator;

	const_mIterator begin() const{

		return (std::stack<stack_t>::c.begin());
	};
	const_mIterator end() const{

		return (std::stack<stack_t>::c.end());
	};

	//REVERSE ITERATOR
	typedef typename std::stack<stack_t>::container_type::reverse_iterator reverse_mIterator;

	reverse_mIterator rbegin(){

		return (std::stack<stack_t>::c.rbegin());
	};
	reverse_mIterator rend(){

		return (std::stack<stack_t>::c.rend());
	};

	//CONST REVERSE ITERATOR
	typedef typename std::stack<stack_t>::container_type::const_reverse_iterator const_reverse_mIterator;

	const_reverse_mIterator rbegin() const{

		return (std::stack<stack_t>::c.rbegin());
	};
	const_reverse_mIterator rend() const{

		return (std::stack<stack_t>::c.rend());
	};
};

#endif