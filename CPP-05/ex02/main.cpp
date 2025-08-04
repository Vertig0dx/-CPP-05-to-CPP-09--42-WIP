/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:48:21 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/01 15:06:09 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){

	try{
		
		Bureaucrat Chris("Chris Redfield", 145);
		ShrubberyCreationForm Garden("Eden"); //sign 145, exec 137
		RobotomyRequestForm Tyrant("Nemesis"); //sign 72, exec 45
		PresidentialPardonForm Ruler("King"); //sign 25, exec 5

		Chris.signForm(Garden);
		Chris.executeForm(Garden);
		Chris.signForm(Tyrant);
		Chris.executeForm(Tyrant);
		Chris.signForm(Ruler);
		Chris.executeForm(Ruler);
	}
	catch (std::exception &e){
		
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}

	try{
		
		ShrubberyCreationForm Garden("Eden"); //sign 145, exec 137
		RobotomyRequestForm Tyrant("Nemesis"); //sign 72, exec 45
		PresidentialPardonForm Ruler("King"); //sign 25, exec 5
		Bureaucrat Leon("Leon S Kennedy", 72);
		
		Leon.signForm(Garden);
		Leon.executeForm(Garden);
		Leon.signForm(Tyrant);
		Leon.executeForm(Tyrant);
		Leon.signForm(Ruler);
		Leon.executeForm(Ruler);
	}
	catch (std::exception &e){
		
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}

	try{
		
		ShrubberyCreationForm Garden("Eden"); //sign 145, exec 137
		RobotomyRequestForm Tyrant("Nemesis"); //sign 72, exec 45
		PresidentialPardonForm Ruler("King"); //sign 25, exec 5
		Bureaucrat Ada("Ada Wong", 1);
		
		Ada.signForm(Garden);
		Ada.executeForm(Garden);
		Ada.signForm(Tyrant);
		Ada.executeForm(Tyrant);
		Ada.signForm(Ruler);
		Ada.executeForm(Ruler);
	}
	catch (std::exception &e){
		
		std::cerr << "Exception detected: " << e.what() << std::endl;
	}

};
