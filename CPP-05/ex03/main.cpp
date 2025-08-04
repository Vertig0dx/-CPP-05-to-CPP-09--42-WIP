/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:48:21 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/01 17:08:56 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void){

	try{
		
		Intern Rebecca;
		Bureaucrat Chris("Chris Redfield", 145);
		AForm *Garden = NULL;
		AForm *Tyrant = NULL;
		AForm *Ruler = NULL;

		Garden = Rebecca.makeForm("Shrubbery", "Eden");
		if (Garden != NULL){
			
			Chris.signForm(*Garden);
			Chris.executeForm(*Garden);
			delete Garden;
		}
		
		Tyrant = Rebecca.makeForm("Robotomy", "Nemesis");
		if (Tyrant != NULL){
			
			Chris.signForm(*Tyrant);
			Chris.executeForm(*Tyrant);
			delete Tyrant;
		}
		
		Ruler = Rebecca.makeForm("Presidential", "Umbrella");
		if (Ruler != NULL){

			Chris.signForm(*Ruler);
			Chris.executeForm(*Ruler);
			delete Ruler;
		}
	}
	catch (std::exception &e){

		std::cerr << "Exception detected: " << e.what() << std::endl;
	}
};
