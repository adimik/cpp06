/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:35:11 by didimitr          #+#    #+#             */
/*   Updated: 2026/03/04 20:33:33 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include "Base.hpp"
#include <iostream>
#include <ctime>

class Base {
    public:
        virtual ~Base();
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);