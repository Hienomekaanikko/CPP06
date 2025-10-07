/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:34:17 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/07 10:13:01 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

std::ostream &operator<<(std::ostream& os, Data const &other) {
	os << "\033[1;36m"
	<< "Age: "
	<< other.age
	<< ", first name: "
	<< other.first_name
	<< ", last name: "
	<< other.last_name
	<< "\033[0m" << std::endl;
	return (os);
}
