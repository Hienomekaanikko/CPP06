/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:04:46 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/07 10:16:08 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main(void) {
	Data things;
	things.age = 2;
	things.first_name = "Deer";
	things.last_name = "Furry";

	std::cout << "Original data struct: " << things;
	uintptr_t serialized = Serializer::serialize(&things);
	std::cout << "Serialized ptr: " << serialized << std::endl;

	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized data struct: " << things;
	return 0;
}
