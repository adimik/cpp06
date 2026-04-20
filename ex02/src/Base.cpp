/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:35:14 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/20 16:04:15 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
}

Base* generate(void) {
    int i = rand() % 3;
    if(i == 0)
        return(new A);
    else if(i == 1)
        return(new B);
    else
        return(new C);
}

void identify(Base* p) {
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))  
        std::cout << "B" << std::endl;  
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p){
    if(dynamic_cast<A*>(&p))
    {
        std::cout << "A" << std::endl;
    }
    else if(dynamic_cast<B*>(&p))
    {
        std::cout << "B" << std::endl;
    }
    else if(dynamic_cast<C*>(&p))
    {
        std::cout << "C" << std::endl;
    }
}