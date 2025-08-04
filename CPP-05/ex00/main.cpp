/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:14:11 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/03/26 14:22:45 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void){
	
	std::cout << "\nTESTING << OPERATOR OVERLOAD\n" << std::endl;
	Bureaucrat Dahlia("Dahlia", 7);
	std::cout << Dahlia;
	try{
		std::cout << "\nTESTING WITH INVALID NAME.\n" << std::endl;
		Bureaucrat Harry("", 120);
		std::cout << "\nNothing was caught.\n" << std::endl;
	}
	catch (std::exception &e){
		
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
	
	try{
		
		std::cout << "\nTESTING WITH INVALID GRADE (TOO LOW).\n" << std::endl;
		Bureaucrat Cybil("Cybil", 156);
		std::cout << "\nNothing was caught.\n" << std::endl;
	}
	catch (std::exception &e){
		
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
	
	try{
		
		std::cout << "\nTESTING WITH INVALID GRADE (TOO HIGH).\n" << std::endl;
		Bureaucrat Alessa("Alessa", 0);
		std::cout << "\nNothing was caught.\n" << std::endl;
	}
	catch (std::exception &e){
		
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}

	try{
		
		std::cout << "\nTESTING WITH INVALID BUREAUCRAT DECREMENT.\n" << std::endl;
		Bureaucrat Vincent("Vincent", 150);
		std::cout << Vincent;
		Vincent.decrementGrade();
		std::cout << Vincent;
		std::cout << "\nNothing was caught.\n" << std::endl;
	}
	catch (std::exception &e){
		
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
	
	try{
		
		std::cout << "\nTESTING WITH INVALID BUREAUCRAT INCREMENT.\n" << std::endl;
		Bureaucrat Douglas("Douglas", 150);
		std::cout << Douglas;
		Douglas.incrementGrade();
		std::cout << Douglas;
		std::cout << "\nNothing was caught.\n" << std::endl;
	}
	catch (std::exception &e){
		
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
	
	try{
		
		std::cout << "\nTESTING WITH VALID BUREAUCRAT.\n" << std::endl;
		Bureaucrat Heather("Heather", 100);
		std::cout << Heather;
		Heather.incrementGrade();
		std::cout << Heather;
		Heather.decrementGrade();
		std::cout << Heather;
		std::cout << "\nNothing was caught.\n" << std::endl;
	}
	catch (std::exception &e){
		
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
}
