/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:57:29 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/06/02 14:17:43 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//MAPS USED

int main( int argc, char **argv )
{
	if (argc != 2){
		std::cout << "Invalid arguments." << std::endl;
		return (0);
	}
	
	BitcoinChecker	btc (argv[1]);
	std::ifstream	infile;
	
	try{
		
		btc.verifyInfile( infile, argv[1] );
		btc.setDateValueRatio();
		btc.convertValue( infile );
		infile.close();
	}
	catch (std::exception &e){

		if (infile.is_open())
			infile.close();
		std::cerr << e.what() << std::endl;
	}
}