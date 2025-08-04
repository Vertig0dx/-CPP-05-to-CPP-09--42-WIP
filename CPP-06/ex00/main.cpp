/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:24:46 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/07 16:10:46 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main( int argc, char **argv ){

	(void)argc;
	
	if (argc != 2 || argv[1] == NULL)
		return (-1);
	ScalarConverter::convert(argv[1]);
	return (0);
}
