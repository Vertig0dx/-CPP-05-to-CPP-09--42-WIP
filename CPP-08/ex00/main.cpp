/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:12:02 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/16 16:07:19 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main (void){

	std::vector<int>	vector_container;
	std::list<int>		list_container;

	list_container.push_front(10);
	list_container.push_back(20);
	list_container.push_back(30);
	list_container.push_back(40);
	list_container.push_front(50);
	list_container.push_front(60);

	vector_container.push_back(1);
	vector_container.push_back(7);
	vector_container.push_back(3);
	vector_container.push_back(5);
	vector_container.push_back(4);
	vector_container.push_back(6);
	vector_container.push_back(2);
	vector_container.push_back(8);

	easyfind(vector_container, 9);
	easyfind(vector_container, 8);
	easyfind(vector_container, 4);

	easyfind(list_container, 40);
	easyfind(list_container, 60);
	easyfind(list_container, 990);
}