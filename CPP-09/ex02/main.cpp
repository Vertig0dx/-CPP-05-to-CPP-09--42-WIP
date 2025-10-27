/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:14:37 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/09/05 14:30:20 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//CANNOT USE MAPS, STACKS
//VECTORS USED
//LISTS USED
//CHOSEN BECAUSE ITERATORS ARE REQUIRED

int main(int argc, char **argv)
{
	PmergeMe			PmergeMe;
	std::list<int>		InputList;
	std::vector<int>	InputVector;
	
	try{
		if (argc < 3)
			throw PmergeMe::InvalidArgumentsException();
		std::cout << "\nArguments: ";
		for (int i = 1; i < argc; ++i)
			std::cout << argv[i] << " ";
		std::cout << std::endl;
		for (int i = 1; i < argc; ++i)
		{
			char* endptr;

			long val = std::strtol(argv[i], &endptr, 10);
			if (*endptr != '\0' || val < 1 || val > INT_MAX)
				throw PmergeMe::InvalidArgumentsException();
		}
		std::cout << "\nValid arguments, proceeding with Ford Johnson sorting algorithm.\n" << std::endl;
		for (int i = 1; i < argc; ++i){
			InputList.push_back(atoi(argv[i]));
			InputVector.push_back(atoi(argv[i]));
		}

		std::cout << "Input vector: ";
		for (std::vector<int>::iterator i = InputVector.begin(); i != InputVector.end(); ++i)
			std::cout << *i << " ";
		std::cout << std::endl;
		//TIME STARTS HERE FOR VECTORS
		clock_t start = clock();
		PmergeMe.generateFinalVector(InputVector);
		clock_t end = clock();
		//TIME ENDS HERE FOR VECTORS
		std::cout << "Vector after merging algorithm:";
		for (std::vector<int>::iterator i = InputVector.begin(); i != InputVector.end(); ++i)
			std::cout << " " << *i;
		std::cout << std::endl;
		double elapsed_secs = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "Time for Vector container algorithm: " << std::fixed 
		<< std::setprecision(6) << elapsed_secs << "s" << std::endl;
		
		std::cout << "\nInput list: ";
		for (std::list<int>::iterator j = InputList.begin(); j != InputList.end(); ++j)
		std::cout << *j << " ";
		std::cout << std::endl;
		//TIME STARTS HERE FOR LISTS
		start = clock();
		PmergeMe.generateFinalList(InputList);
		end = clock();
		//TIME ENDS HERE FOR LISTS
		std::cout << "List after merging algorithm:";
		for (std::list<int>::iterator i = InputList.begin(); i != InputList.end(); ++i)
			std::cout << " " << *i;
		std::cout << std::endl;
		elapsed_secs = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		std::cout << "Time for List container algorithm: " << std::fixed 
		<< std::setprecision(6) << elapsed_secs << "s" << std::endl;
	}
	catch (std::exception &e){

		std::cerr << e.what() << std::endl;
	}
}
