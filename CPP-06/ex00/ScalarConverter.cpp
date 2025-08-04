/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:03:47 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/13 14:10:34 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert ( std::string target ){

//convert input to double, seems to be the easiest way to begin... (it is)
	char		*number_end;
	double		converted_input;
	bool		valid = false;
	
	converted_input = std::strtod(target.c_str(), &number_end);
	if ((*number_end == '\0' || (*number_end == 'f' && *(number_end + 1) == '\0')) && !target.empty())
		valid = true;
	else{
		std::cout << "Invalid input." << std::endl;
		return ;
	}
	if (target.size() == 1 && !(target[0] >= '0' && target[0] <= '9')){ //strings of size 1
		if (target[0] > 32 && target[0] < 126)
			std::cout << "Char = " << static_cast <char> (target[0]) << std::endl;
		else
			std::cout << "Char = " << "Unprintable." << std::endl;
		std::cout << "Int = " << static_cast<int>(target[0]) << std::endl;
		std::cout << "Float = " << std::fixed << std::setprecision(1) << static_cast <float> (target[0]) << "f" << std::endl;
		std::cout << "Double = " << static_cast <double> (target[0]) << std::endl;
		return ;
	}
	if (valid == true)
		converted_input = strtod(target.c_str(), NULL);

	//chars

	if (converted_input > 0 && converted_input < 127){
		if (converted_input > 32 && converted_input < 127)
			std::cout << "Char = " << static_cast <char> (converted_input) << std::endl;
		else
			std::cout << "Unprintable." << std::endl;
	}
	else
		std::cout << "Char = Cannot convert." << std::endl;

	//ints
	
	if (converted_input < std::numeric_limits<int>::min() || converted_input > std::numeric_limits<int>::max())
		std::cout << "Int = Cannot convert." << std::endl;
	else if (std::isnan(converted_input))
		std::cout << "Int = Cannot convert." << std::endl;
	else
		std::cout << "Int = " << static_cast <int> (converted_input) << std::endl;

	//floats (deal with +inff, -inff and nanf)

	if (converted_input == std::numeric_limits<float>::infinity() || converted_input == -std::numeric_limits<float>::infinity())
		std::cout << "Float = Cannot convert." << std::endl;
	else{
		if (converted_input < -std::numeric_limits<float>::max() || converted_input > std::numeric_limits<float>::max())
			std::cout << "Float = Cannot convert." << std::endl;
		else if (std::isnan(converted_input))
			std::cout << "Float = nanf." << std::endl;
		else
			std::cout << "Float = " << std::fixed << std::setprecision(1) << static_cast <float> (converted_input) << "f" << std::endl;
	}

	//doubles (deal with +inf, -inf and nan)

	if (converted_input == std::numeric_limits<double>::infinity() || converted_input == -std::numeric_limits<double>::infinity()) {
		std::cout << "Double = Cannot convert." << std::endl;
	}
	else{
		if (converted_input < -std::numeric_limits<double>::max() || converted_input > std::numeric_limits<double>::max())
			std::cout << "Double = Cannot convert." << std::endl;
		else if (std::isnan(converted_input))
			std::cout << "Double = nanf." << std::endl;
		else
			std::cout << "Double = " << static_cast <double> (converted_input) << std::endl;
	}
};

