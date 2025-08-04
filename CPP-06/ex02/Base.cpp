/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:14:10 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/13 14:31:43 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base( void ){

	std::cout << "Base destructor called." << std::endl;
};

Base*	generate ( void ){

	srand((unsigned) time(NULL));

	int random = rand() % 3;
	std::cout << "the value of random is : " << random << std::endl;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else if (random == 2)
		return new C();
	else
		return (NULL);
};

void	identify ( Base* p ){

	if (dynamic_cast<A*>(p))
		std::cout << "Current pointer is: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Current pointer is: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Current pointer is: C" << std::endl;
	else
		std::cout << "Current pointer is: Unknown..." << std::endl;
};

void	identify ( Base& p ){

	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "Current reference is: A" << std::endl;
		return ;
	}
	catch (std::exception &e){};
	try{
		
		(void)dynamic_cast<B&>(p);
		std::cout << "Current reference is: B" << std::endl;
		return ;
	}
	catch (std::exception &e){};
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "Current reference is: C" << std::endl;
		return ;
	}
	catch (std::exception &e){};
	std::cout << "Your Base does not match any known bases...somehow." << std::endl;
};