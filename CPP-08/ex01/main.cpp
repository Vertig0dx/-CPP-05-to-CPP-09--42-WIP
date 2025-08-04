/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:43:59 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/21 14:16:18 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void){
	
	//TESTING REGULAR ADDNUMBER AND SPANS
	try{
		
		Span TestStack(5);
		
		TestStack.addNumber(9);
		TestStack.addNumber(3);
		TestStack.addNumber(2);
		TestStack.addNumber(4);
		TestStack.addNumber(5);
		std::cout << "Sortest span = " << TestStack.shortestSpan() << std::endl;
		std::cout << "Longest span = " << TestStack.longestSpan() << std::endl;
		//ADDING A NUMBER THAT EXCEEDS SIZE, SHOULD RESULT IN AN EXCEPTION BEING THROWN
		TestStack.addNumber(10);
	}
	catch (std::exception &e){
	
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}

	//TESTING SINGLE ELEMENT STACK EXCEPTION
	try{
		
		Span TestStack(1);
		
		TestStack.addNumber(9);
		std::cout << "Sortest span = " << TestStack.shortestSpan() << std::endl;
	}
	catch (std::exception &e){
	
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}

	//TESTING EMPTY STACK EXCEPTION
	try{
		
		Span EmptyTestStack(0);
		
		EmptyTestStack.addNumber(9);
		std::cout << "Sortest span = " << EmptyTestStack.shortestSpan() << std::endl;
	}
	catch (std::exception &e){
	
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
	
	//TESTING ADDNUMBER_RANGE
	try{
		
		Span 						TestStack1(10000);
		Span						TestStack2(10000);
		std::vector<int>			test_vector;

		srand((unsigned) time(NULL));
		
		for (int i = 0; i < 10000; ++i){
			int l = rand() % 1000000000;
			test_vector.push_back(l);
		}
		TestStack1.addNumberRange(test_vector.begin(), test_vector.end());
		std::cout << "Sortest span = " << TestStack1.shortestSpan() << std::endl;
		std::cout << "Longest span = " << TestStack1.longestSpan() << std::endl;

		for(int i = 0; i < 10000; ++i)
			TestStack2.addNumber(i);
		std::cout << "Sortest span = " << TestStack2.shortestSpan() << std::endl;
		std::cout << "Longest span = " << TestStack2.longestSpan() << std::endl;
	}
	catch (std::exception &e){
	
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
}