/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:23:16 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/23 15:47:55 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstdlib>
# include <string>

template <typename address, typename length, typename function>
void iter(address addr, length len, function f){

	for(length i = 0; i < len; ++i)
		f(addr[i]);
};

template <typename type>
void increment(type &a){

	std::cout << "Increment template called" << std::endl;
	a++;
};

#endif