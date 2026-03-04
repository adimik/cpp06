/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:38:24 by didimitr          #+#    #+#             */
/*   Updated: 2026/03/04 20:59:13 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
    std::srand(std::time(NULL));
    Base* a;

    a = generate();
    identify(*a);
    identify(a);
    delete a;
    return(0);
}