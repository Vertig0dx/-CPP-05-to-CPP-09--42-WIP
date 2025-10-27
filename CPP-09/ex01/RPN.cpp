/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 16:38:00 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/29 18:47:00 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN ( void ){

	std::cout << "Reverse Polish Notation constructor called." << std::endl;
}

RPN::RPN ( RPN &other ){

	std::cout << "Reverse Polish Notation copy constructor called." << std::endl;
	*this = other;
}

RPN &RPN::operator= ( RPN &other ){

	std::cout << "Reverse Polish Notation overloaded operator called, following set instructions." << std::endl;
	if (this != &other)
		*this = other;
	return (*this);
}

RPN::~RPN ( void ){

	std::cout << "Reverse Polish Notation destructor called." << std::endl;
}

void RPN::solveStack( int argc, char** argv ){

	int i = 0;
	int value_to_push;
	int value1;
	int operand_value = 0;
	int operator_value = 0;
	std::stack<int>	mock_stack;

	if (argc < 2)
		throw RPN::InvalidArgumentsException();
	while (argv[1][i])
	{
		if (argv[1][i] == ' ')
			i++;
		else if (argv[1][i] >= '0' && argv[1][i] <= '9' && (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\0'))
		{
			mock_stack.push(argv[1][i] - '0');
			operand_value++;
			i++;
		}
		else if ((argv[1][i] == '+' || argv[1][i] == '-' || argv[1][i] == '*' || argv[1][i] == '/') && (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\0'))
		{
			if (mock_stack.size() >= 2)
			{
				if (argv[1][i] == '+')
				{
					value1 = mock_stack.top();
					mock_stack.pop();
					value_to_push = mock_stack.top() + value1;
					mock_stack.pop();
					mock_stack.push(value_to_push);
					operator_value++;
				}
				else if (argv[1][i] == '-')
				{
					value1 = mock_stack.top();
					mock_stack.pop();
					value_to_push = mock_stack.top() - value1;
					mock_stack.pop();
					mock_stack.push(value_to_push);
					operator_value++;
				}
				else if (argv[1][i] == '*')
				{
					value1 = mock_stack.top();
					mock_stack.pop();
					value_to_push = mock_stack.top() * value1;
					mock_stack.pop();
					mock_stack.push(value_to_push);
					operator_value++;
				}
				else if (argv[1][i] == '/')
				{
					value1 = mock_stack.top();
					mock_stack.pop();
					value_to_push = mock_stack.top() / value1;
					mock_stack.pop();
					mock_stack.push(value_to_push);
					operator_value++;
				}
			}
			else
				throw RPN::InvalidEquationException();
			i++;
		}
		else
			throw RPN::InvalidOperatorOperandException();
	}
	if (operator_value != operand_value - 1 || mock_stack.size() > 1 )
		throw RPN::InvalidNotationException();
	std::cout << mock_stack.top() << std::endl;
}
