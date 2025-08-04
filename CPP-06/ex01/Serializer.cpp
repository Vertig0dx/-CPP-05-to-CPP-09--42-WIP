/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:26:05 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/07 17:47:44 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {}

uintptr_t	Serializer::serialize(Data *ptr){

	return reinterpret_cast<uintptr_t>(ptr);
};

Data*		Serializer::deserialize(uintptr_t raw){

	return reinterpret_cast<Data *>(raw);
}