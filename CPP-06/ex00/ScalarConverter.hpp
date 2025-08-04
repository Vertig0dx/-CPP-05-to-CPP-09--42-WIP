/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:03:49 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/07 16:07:16 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <cmath>
#include <string>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <limits>

class ScalarConverter{

	public:

	ScalarConverter					( const ScalarConverter &other );
	ScalarConverter		&operator=	( const ScalarConverter &other );
	~ScalarConverter				( void );

	void  static convert 					( std::string target );

	private:

	ScalarConverter( );
};

#endif