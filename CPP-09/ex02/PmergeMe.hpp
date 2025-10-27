/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:15:50 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/09/04 15:00:25 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <iomanip>
#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <limits.h>

class PmergeMe {

	public:

	PmergeMe 											( void );
	PmergeMe											( const PmergeMe	&other );
	PmergeMe	&operator=								( const PmergeMe	&other );
	~PmergeMe											( void );

	std::vector<int>									getFinalVector();
	std::list<int>										generateJacobsthalList( int quantity );
	std::vector<int>									generateJacobsthalVector( int quantity );
	void												generateFinalList( std::list<int> &input_list );
	void												generateFinalVector( std::vector<int> &input_vector );
	std::list<int>::iterator							listLowerBound(std::list<int>&list, int value);
	
	class			InvalidArgumentsException : public std::exception{

		public:

		const char* what() const throw(){

			return "Empty/invalid arguments.";
		}
	};

	private:

//	std::list<int>										_jacobsthal_list;
//	std::list<int>										_sorted_max_list;
//	std::list<int>										_sorted_min_list;
	std::list<int>										_finalList;
//	std::vector<int>									_jacobsthal_vector;
//	std::vector<int>									_sorted_max_vector;
//	std::vector<int>									_sorted_min_vector;
	std::vector<int>									_finalVector;
};

#endif