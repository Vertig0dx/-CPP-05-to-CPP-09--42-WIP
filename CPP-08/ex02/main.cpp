/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:18:55 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/05/21 15:34:12 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main ( void ){

	//SUBJECT EXAMPLE CODE
	MutantStack<int> mstack;

	mstack.push(17);
	mstack.push(5);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::mIterator it = mstack.begin();
	MutantStack<int>::mIterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << '\n' << std::endl;

	std::stack<int> s(mstack);

	//RIT AND RITE

	MutantStack<int>::reverse_mIterator rit = mstack.rbegin();
	MutantStack<int>::reverse_mIterator rite = mstack.rend();

	std::cout << "stack: ";
	while (rit != rite)
	{
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << '\n' << std::endl;
	return 0;
}