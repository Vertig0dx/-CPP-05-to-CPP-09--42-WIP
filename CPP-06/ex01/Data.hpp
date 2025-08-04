/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmiguel- <lmiguel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:23:53 by lmiguel-          #+#    #+#             */
/*   Updated: 2025/04/07 18:00:48 by lmiguel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include "Serializer.hpp"
#include <string>

struct Data{

	int				index;
	int				pod_num;
	std::string		name;
	std::string		unit_type;
};

#endif