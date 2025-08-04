/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:44:09 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/15 14:38:54 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "array.hpp"

int main( void )
{
	try{
		
	Array<int>a( void );
	Array<int>b(10);
	
	std::cout << "ASSIGN VALUES TO b IN MULTIPLES OF 10\n" << std::endl;
	
	for (int i = 0; i < 10; ++i){
		std::cout << "i = " << i << std::endl;
		b[i] = i * 10;
		std::cout <<  "b[i] = " << b[i] << "\n" << std::endl;
	}
	
	std::cout << "TEST COPY CONSTRUCTOR\n" << std::endl;
	
	Array<int> c(b);
	for (int i = 0; i < 10; ++i){
		std::cout << "i = " << i << std::endl;
		std::cout <<  "c[i] = " << c[i] << "\n" << std::endl;
	}

	b[2] = 42;
	c[2] = 109;
	std::cout << "b[2] = " << b[2] << std::endl;
	std::cout << "c[2] = " << c[2] << std::endl;

	std::cout << "TEST ASSIGNMENT OVERLOAD\n" << std::endl;

	c[2] = b[2];
	std::cout << "c[2] = " << c[2] << '\n' << std::endl;

	
	std::cout << "TEST VALID & INVALID INDEX\n" << std::endl;
	
	b[1];
	b[101];

	}
	catch (std::exception &e){

		std::cerr << e.what() << std::endl;
	}
}

/* 	std::cout << "TEST ARRAY WITH NEGATIVE SIZE (SHOULD TRIP INVALID UINT PROTECTION AND THROW EXCEPTION)\n" << std::endl;

	Array<int>invalid(-9999);
	invalid[1]; */