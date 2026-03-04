/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:11:50 by didimitr          #+#    #+#             */
/*   Updated: 2026/03/04 12:40:23 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include "Data.hpp"
#include <iostream>

Serializer::Serializer(){
}

Serializer::Serializer(const Serializer& other){
    (void)other;
}

Serializer& Serializer:: operator=(const Serializer& other){
    (void)other;
    return *this;
}

Serializer::~Serializer(){
}

uintptr_t Serializer::serialize(Data* ptr) {

    return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw) {
    return(reinterpret_cast<Data*>(raw));
}