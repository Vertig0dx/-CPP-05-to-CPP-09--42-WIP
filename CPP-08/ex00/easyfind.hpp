/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:12:15 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/16 16:08:30 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <list>

template <typename T>

int easyfind(T container, int to_find){

	std::cout << "easyfind function template called" << std::endl;
	if (std::find(container.begin(), container.end(), to_find) == container.end()){
		std::cout << "Could not detect " << to_find << " inside container." << std::endl;
		return (0);
	}
	std::cout << "Container contains " << to_find << std::endl;
	return (1);
}

#endif