/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:23:21 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/02 16:26:16 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ScalarConverter {
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);

		static void convert(const std::string& literal);
};
