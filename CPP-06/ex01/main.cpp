/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:36:37 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/07 18:13:20 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void){

	Data data;
	data.index = 1;
	data.name = "2B";
	data.unit_type = "Executioner";
	data.pod_num = 042;

	uintptr_t raw_ptr = Serializer::serialize(&data);
	std::cout << "raw_ptr = " << raw_ptr << std::endl;

	Data *dataptr = Serializer::deserialize(raw_ptr);

	std::cout << "Verifying Android Encryption..." << std::endl;
	if (&data == dataptr){
		
		std::cout << "Verified." << std::endl;
		std::cout << "Deserialized Android data: " << std::endl;
		std::cout << "Unit Index = " << dataptr->index << std::endl;
		std::cout << "Unit Designation = " << dataptr->name << std::endl;
		std::cout << "Unit Type = " << dataptr->unit_type << std::endl;
		std::cout << "Assigned Pod Number = " << dataptr->pod_num << std::endl;
		std::cout << "YoRHa, for the glory of Mankind." << std::endl;
	}
	else
		std::cout << "Android Signature does not match YoRHa database." << std::endl;
	return (0);

	
}