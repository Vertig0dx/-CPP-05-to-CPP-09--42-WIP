/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:52:22 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/15 16:28:53 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main(void)
{
	int x = 10;
	int y = 20;
	int z = 10;

	//TESTING SWAP
	swap(x, y);
	std::cout << "a = " << x << std::endl;
	std::cout << "b = " << y << std::endl;

	x = 10;
	y = 20;
	z = 10;

	//TESTING MAX
	std::cout << max(x, y) << std::endl;
	std::cout << max(x, z) << std::endl;

	x = 10;
	y = 20;
	z = 10;

	//TESTING MIN
	std::cout << min(x, y) << std::endl;
	std::cout << min(x, z) << std::endl;

	//CODE PROVIDED IN SUBJECT, SHOULD RETURN THE REQUESTED OUTPUT
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
		
	//TESTING TO PROVE TEMPLATES ONLY ACCEPT SAME TYPE
	//SHOULD GIVE A COMPILATION ERROR IF UNCOMMENTED

	/* 	int 	test1 = 1;
		double	test2 = 1.6;
		std::cout << max(test1, test2) << std::endl;
	*/
}