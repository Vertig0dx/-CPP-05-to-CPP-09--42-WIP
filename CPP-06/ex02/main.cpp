/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:27:27 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/09 15:28:06 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void){

	Base *test1 = generate();

	std::cout << "POINTER ID TEST START" << std::endl;
	identify(test1);
	
	std::cout << "REFERENCE ID TEST START" << std::endl;
	identify(*test1);

	delete test1;
	return (0);
}