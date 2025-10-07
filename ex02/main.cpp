/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:52:02 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/07 11:40:28 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void) {
    Base* thing = nullptr;
    try {
        thing = generate();
        identify(thing);
        identify(*thing);
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    delete thing;
}