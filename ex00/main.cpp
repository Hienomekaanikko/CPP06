/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:13:01 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/06 13:18:44 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	if (ac != 2)
		std::cout << "Error: Invalid input" << std::endl;
	else
		ScalarConverter::convert(av[1]);
}
