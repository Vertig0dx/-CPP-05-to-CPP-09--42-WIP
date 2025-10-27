/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:58:16 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/09/18 14:08:05 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//CANNOT USE MAPS
//STACK USED (TECHNICALLY, STD::DEQUE IS USED SINCE IT IS THE WHAT A STD::STACK CALL DEFAULTS TO)

int main( int argc, char **argv)
{
	RPN rpn;
	
	try{
		rpn.solveStack(argc, argv);
	}
	catch (std::exception &e){

		std::cerr << e.what() << std::endl;
	}
}