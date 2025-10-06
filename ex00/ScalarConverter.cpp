/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:41:00 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/06 15:44:27 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <cctype>

bool isSpecial(const std::string& value) {
	return value == "nan" || value == "+nan" || value == "-nan" ||
			value == "inf" || value == "+inf" || value == "-inf";
}

void fromChar(char c) {
	std::cout << "char: ";
	if (std::isprint(c)) {
		std::cout << "'" << c << "'";
	}
	else
		std::cout << "non displayable";
	std::cout << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void fromFloat(double num) {
	std::cout << "char: ";
	if (std::isnan(num) || std::isinf(num))
		std::cout << "impossible" << std::endl;
	else if (num >= 0 && num <= 127 && std::isprint(static_cast<char>(num)))
		std::cout << "'" << static_cast<char>(num) << "'" << std::endl;
	else
		std::cout << "non displayable" << std::endl;

	std::cout << "int: ";
	if (std::isnan(num) || std::isinf(num) ||
		num > static_cast<double>(std::numeric_limits<int>::max()) ||
		num < static_cast<double>(std::numeric_limits<int>::min()))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: ";
	if (std::isnan(num))
		std::cout << "nanf" << std::endl;
	else if (std::isinf(num))
		std::cout << (num > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << static_cast<float>(num) << "f" << std::endl;

	std::cout << "double: ";
	if (std::isnan(num))
		std::cout << "nan" << std::endl;
	else if (std::isinf(num))
		std::cout << (num > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << num << std::endl;
}

void fromDouble(double num) {
	fromFloat(num);
}

void ScalarConverter::convert(const std::string& value) {
	if (isSpecial(value)) {
		double num;
		if (value[0] == '-') num = -std::numeric_limits<double>::infinity();
		else if (value[0] == '+') num = std::numeric_limits<double>::infinity();
		else if (value == "nan") num = std::numeric_limits<double>::quiet_NaN();
		else if (value == "inf") num = std::numeric_limits<double>::infinity();
		fromDouble(num);
		return;
	}
	if (value.length() == 1 && !std::isdigit(value[0])) {
		fromChar(value[0]);
		return;
	}
	std::string tmp = value;
	bool isFloatLiteral = false;
	if (!tmp.empty() && tmp.back() == 'f') {
		tmp.pop_back();
		isFloatLiteral = true;
	}
	try {
		double num = std::stod(tmp);
		if (isFloatLiteral)
			fromFloat(num);
		else
			fromDouble(num);
	} catch (const std::exception& e) {
		std::cerr << "Error: invalid input or out of range" << std::endl;
	}
}
