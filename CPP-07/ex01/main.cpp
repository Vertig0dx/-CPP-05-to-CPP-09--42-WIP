/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:52:22 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/15 14:13:41 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	//INTEGER ARRAY

	int x[] = {1, 2, 3, 4, 5};

	iter(x, 5, increment <int>);
	for (int i = 0; i < 5; ++i)
		std::cout << "x[i] = " << x[i] << std::endl;

	//DOUBLE ARRAY

	double y[] = {1.1, 1.2, 1.3, 1.4, 1.5};

	iter(y, 5, increment <double>);
	for (int i = 0; i < 5; ++i)
		std::cout << "y[i] = " << y[i] << std::endl;

	//FLOAT ARRAY

	float z[] = {2.1f, 2.2f, 2.3f, 2.4f, 2.5f};
	
	iter(z, 5, increment <float>);
	for (int i = 0; i < 5; ++i)
		std::cout << "z[i] = " << z[i] << std::endl;
}