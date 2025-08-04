/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:14:18 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/09 15:14:34 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdlib>
#include <exception>
#include <ctime>

class Base{

	public:

	virtual ~Base			( void );

	private:

};

class A : public Base{
	
};

class B : public Base{

};

class C : public Base{
	
};

Base*	generate ( void );

void	identify ( Base* p );

void	identify ( Base& p );

#endif