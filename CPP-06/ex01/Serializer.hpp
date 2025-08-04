/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:25:57 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/07 18:11:59 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include <iostream>
#include <fstream>
#include <stdint.h>

class Serializer{

	public:

	static uintptr_t			serialize(Data* ptr);
	static Data*				deserialize(uintptr_t raw);

	private:

	Serializer ();

};

#endif