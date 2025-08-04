/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:51:32 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/15 16:29:32 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <cstdlib>
# include <string>

template <typename type>
void swap(type &a, type &b){

	std::cout << "Swap template called" << std::endl;
	type temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename type>
type min(type a, type b){

	std::cout << "Min template called" << std::endl;
	if (a < b)
		return a;
	return b;
}

template<typename type>
type max(type a, type b){

	std::cout << "Max template called" << std::endl;
	if (a <= b)
		return b;
	return a;
}

#endif