/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:38:24 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/21 15:14:18 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <sys/time.h>

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

int main(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    std::srand(tv.tv_sec * 1000000 + tv.tv_usec);
    Base* a;

    a = generate();
    identify(*a);
    identify(a);
    delete a;
    return(0);
}