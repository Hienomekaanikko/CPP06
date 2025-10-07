/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msuokas <msuokas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:37:16 by msuokas           #+#    #+#             */
/*   Updated: 2025/10/07 11:40:35 by msuokas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Base {
    public:
        virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);