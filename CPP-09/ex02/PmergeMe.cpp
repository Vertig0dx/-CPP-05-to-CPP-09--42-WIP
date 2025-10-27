/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:14:33 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/09/18 14:26:38 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe ( void ){

	std::cout << "\nPmergeMe constructor called." << std::endl;
}

PmergeMe::PmergeMe ( const PmergeMe &other ){

	std::cout << "\nPmergeMe constructor called." << std::endl;
	*this = other;
}

PmergeMe &PmergeMe::operator= ( const PmergeMe &other ){

	std::cout << "\nPmergeMe constructor called." << std::endl;
	if (this != &other)
	{
		//this->_jacobsthal_list = other._jacobsthal_list;
		this->_finalList = other._finalList;
		//this->_jacobsthal_vector = other._jacobsthal_vector;
		this->_finalVector = other._finalVector;
	}
	return (*this);
}

PmergeMe::~PmergeMe ( void ){

	std::cout << "\nPmergeMe destructor called." << std::endl;
}

std::vector<int> PmergeMe::getFinalVector( void ){
	
	return _finalVector;
}

std::list<int>	PmergeMe::generateJacobsthalList( int quantity ){

	std::list<int> mockList;
	int Jacobsthal_number;
	int last_number = 1;
	int penultimate_number = 0;
	
	if (quantity <= 1)
		return mockList;
	mockList.push_back(1);
	while (1)
	{
		Jacobsthal_number = last_number + 2 * penultimate_number;
		if (Jacobsthal_number >= quantity)
			break ;
		mockList.push_back(Jacobsthal_number);
		penultimate_number = last_number;
		last_number = Jacobsthal_number;
	}

	mockList.sort();
	mockList.erase(std::unique(mockList.begin(), mockList.end()), mockList.end());
	return (mockList);
}

std::vector<int>	PmergeMe::generateJacobsthalVector( int quantity ){

	std::vector<int> mockVector;
	int Jacobsthal_number;
	int last_number = 1;
	int penultimate_number = 0;
	
	if (quantity <= 1)
		return mockVector;
	mockVector.push_back(1);
	while (1)
	{
		Jacobsthal_number = last_number + 2 * penultimate_number;
		if (Jacobsthal_number >= quantity)
			break ;
		mockVector.push_back(Jacobsthal_number);
		penultimate_number = last_number;
		last_number = Jacobsthal_number;
	}

	std::sort(mockVector.begin(), mockVector.end());
	mockVector.erase(std::unique(mockVector.begin(), mockVector.end()), mockVector.end());
	return (mockVector);
}

std::list<int>::iterator PmergeMe::listLowerBound(std::list<int>&list, int value){

	std::list<int>::iterator i = list.begin();
	while (i != list.end() && *i < value)
		++i;
	return (i);
}

void PmergeMe::generateFinalVector( std::vector<int> &input_vector ){

	size_t len = input_vector.size();
	
	if (len <= 1)
		return ;
	bool hasLeftover = false;
	if ( len % 2 == 1 )
		hasLeftover = true;

	std::vector<int> big;
	std::vector<int> small;
	std::vector<int>::iterator input = input_vector.begin();
	//IMPORTANT, USE ADVANCE IF WORKING WITH LISTS, LIST ITERATORS ARE NOT RANDOM ACCESS
	for (size_t i = 0; i < (len / 2); ++i, input += 2)
	{
		int pair_first = *input;
		int pair_second = *(input + 1);

		if (pair_first > pair_second)
		{
			big.push_back(pair_first);
			small.push_back(pair_second);
		}
		else
		{
			big.push_back(pair_second);
			small.push_back(pair_first);
		}
	}
	//leftover can be zero because its impossible to have an input lesser than 1, good
	int leftover = 0;
	if (hasLeftover == true)
		leftover = input_vector[len - 1];
	//begin recursivity, utilize big, utilize small? (only big)
	generateFinalVector(big);
	std::sort(small.begin(), small.end());
	std::vector<bool> inserted(small.size(), false);
	if (!small.empty())
	{
		std::vector<int>::iterator firstSmall = std::lower_bound(big.begin(), big.end(), small[0]);
		big.insert(firstSmall, small[0]);
		inserted[0] = true;
	}
	std::vector<int> orderInsert = generateJacobsthalVector(small.size());
	for (size_t i = 0; i < orderInsert.size(); ++i)
	{
		size_t index = orderInsert[i];
		
		if (index >= small.size() || inserted[index])
			continue;
		int insertNumber = small[index];

		std::vector<int>::iterator position = std::lower_bound(big.begin(), big.end(), insertNumber);
		//if (position == big.end() || *position != insertNumber)
		big.insert(position, insertNumber);
		inserted[index] = true;
	}
	for (size_t i = 0; i < small.size(); ++i) {
		if (!inserted[i]) {
			int insertNumber = small[i];
			std::vector<int>::iterator position = std::lower_bound(big.begin(), big.end(), insertNumber);
			big.insert(position, insertNumber);
			inserted[i] = true;
		}
	}
	if (hasLeftover == true)
	{
		std::vector<int>::iterator position = std::lower_bound(big.begin(), big.end(), leftover);
		//if (position == big.end() || *position != leftover)
		big.insert(position, leftover);
	}
	input_vector = big;
}

void PmergeMe::generateFinalList( std::list<int> &input_list ){

	size_t len = input_list.size();
	
	if (len <= 1)
		return ;
	bool hasLeftover = false;
	if ( len % 2 == 1 )
		hasLeftover = true;

	std::list<int> big;
	std::list<int> small;
	std::list<int>::iterator input = input_list.begin();
	//IMPORTANT, USE ADVANCE IF WORKING WITH LISTS, LIST ITERATORS ARE NOT RANDOM ACCESS
	for (size_t i = 0; i < (len / 2); ++i, std::advance(input, 2)) 
	{
		int pair_first = *input;
		std::list<int>::iterator temp = input;
		std::advance(temp, 1);
		int pair_second = *temp;

		if (pair_first > pair_second)
		{
			big.push_back(pair_first);
			small.push_back(pair_second);
		}
		else
		{
			big.push_back(pair_second);
			small.push_back(pair_first);
		}
	}
	//leftover can be zero because its impossible to have an input lesser than 1, good
	int leftover = 0;
	if (hasLeftover == true)
		leftover = *input_list.rbegin();
	//begin recursivity, utilize big, utilize small? (only big)
	generateFinalList(big);
	small.sort();
	std::list<bool> inserted(small.size(), false);
	if (!small.empty())
	{
		std::list<int>::iterator pos = listLowerBound(big, *small.begin());
		big.insert(pos, *small.begin());
		std::list<bool>::iterator insertedIterator = inserted.begin();
		*insertedIterator = true;
	}
	std::list<int> orderInsert = generateJacobsthalList(small.size());
	std::list<int>::iterator orderIterator = orderInsert.begin();
	for (; orderIterator != orderInsert.end(); ++orderIterator)
	{
		size_t index = *orderIterator;
		
		if (index >= small.size())
			continue;
		std::list<bool>::iterator insertedIterator = inserted.begin();
		std::advance(insertedIterator, index);
		if (*insertedIterator)
			continue;
		*insertedIterator = true;
		
		std::list<int>::iterator smallIterator = small.begin();
		std::advance(smallIterator, index);
		int insertNumber = *smallIterator;

		std::list<int>::iterator position = listLowerBound(big, insertNumber);
		//if (position == big.end() || *position != insertNumber)
		big.insert(position, insertNumber);
	}
	for (size_t i = 0; i < small.size(); ++i) {
		std::list<bool>::iterator insertedIt = inserted.begin();
		std::advance(insertedIt, i);

	if (!(*insertedIt)) {
		
		std::list<int>::iterator smallIterator = small.begin();
		std::advance(smallIterator, i);
		
		int insertNumber = *smallIterator;
		std::list<int>::iterator position = listLowerBound(big, insertNumber);
		
		big.insert(position, insertNumber);
		*insertedIt = true;
	}
}
	if (hasLeftover == true)
	{
		std::list<int>::iterator position = listLowerBound(big, leftover);
		//if (position == big.end() || *position != leftover)
		big.insert(position, leftover);
	}
	input_list = big;
}

