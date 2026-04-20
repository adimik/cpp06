/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:38:24 by didimitr          #+#    #+#             */
/*   Updated: 2026/04/20 16:07:34 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <sys/time.h>

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