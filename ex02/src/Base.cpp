/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:35:14 by didimitr          #+#    #+#             */
/*   Updated: 2026/03/04 20:53:40 by didimitr         ###   ########.fr       */
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
        std::cout << "Im class A!" << std::endl;
    else if(dynamic_cast<B*>(p))  
        std::cout << "Im class B!" << std::endl;  
    else if(dynamic_cast<C*>(p))
        std::cout << "Im class C!" << std::endl;
}

void identify(Base& p){
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "Im class A!" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {}
    try
    {
        dynamic_cast<B&>(p);
        std::cout << "Im class B!" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
    }   
    try
    {
        dynamic_cast<C&>(p);
        std::cout << "Im class C!" << std::endl;
        return;
    }
    catch(const std::exception& e)
    {
    }
}