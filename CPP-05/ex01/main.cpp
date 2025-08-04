/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:17:29 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/03/31 14:10:49 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){

	try{
		
	Bureaucrat	Jill("Jill", 3);
	Form 		STARS("S.T.A.R.S Exam", 17, 19);
	Form		RACOON("Sandwich", 1, 1);

	std::cout << STARS;
	std::cout << RACOON;
	Jill.signForm(STARS);
	std::cout << STARS;
	Jill.signForm(RACOON);
	std::cout << RACOON;
	std::cout << "TESTING INVALID FORMS.\n" << std::endl;
	}
	catch (std::exception &e){

		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
	
	try{

		Form A("", 4, 4);
	}
	catch (std::exception &e){

		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
	
	try{

		Form B("B", 0, 4);
	}
	catch (std::exception &e){

		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
	
	try{

		Form C("C", 4, 0);
	}
	catch (std::exception &e){

		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
	
	try{

		Form D("D", 151, 4);
	}
	catch (std::exception &e){

		std::cerr << "Exception detected: " << e.what() << std::endl;
	}

	try{

		Form E("E", 4, 151);
	}
	catch (std::exception &e){

		std::cerr << "Exception detected: " << e.what() << std::endl;
	}

	try{

		Form F("F", 0, 0);
	}
	catch (std::exception &e){

		std::cerr << "Exception detected: " << e.what() << std::endl;
	}

	try{

		Form G("G", 151, 151);
	}
	catch (std::exception &e){

		std::cerr << "Exception detected: " << e.what() << std::endl;
	}

	try{

		Form H("", 151, 151);
	}
	catch (std::exception &e){

		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
}