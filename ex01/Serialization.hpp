/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 09:34:30 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/07 10:10:53 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Data.hpp"
#include <cstdint>

class Serializer {
	public:
		Serializer() = delete;
		~Serializer() = delete;
		Serializer(const Serializer& other) = delete;
		Serializer& operator=(const Serializer& other) = delete;

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

std::ostream &operator<<(std::ostream& os, Data const &other);
