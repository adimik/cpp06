/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:46:24 by didimitr          #+#    #+#             */
/*   Updated: 2026/02/06 18:27:41 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "Wrong amount of inputs" << std::endl;
        return(1);
    }
    std::string input = argv[1];
    ScalarConverter::convert(input);
    return(0);
}