/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:12:05 by didimitr          #+#    #+#             */
/*   Updated: 2026/03/04 12:49:11 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serialization.hpp"
#include <iostream>

int main(){
    Data* ptr2;
    Data* ptr;
    Data data(22, "test text");
    ptr = &data;
    uintptr_t test;
    test = Serializer::serialize(ptr);
    ptr2 = Serializer::deserialize(test);
    if(ptr == ptr2)
        std::cout << "this two pointers are matching!" << std::endl;
    std::cout << ptr2->nameGet() << " :did it printed the name right?" << std::endl;
    std::cout << ptr2->numGet() << " test of num print." << std::endl;
    return(0);
}