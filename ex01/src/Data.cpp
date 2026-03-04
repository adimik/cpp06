/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:17:38 by didimitr          #+#    #+#             */
/*   Updated: 2026/03/04 11:45:15 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Data.hpp"

Data::Data(int num, std::string name) : num(num), name(name) {
    
}

Data::Data(const Data& other){
    if(this != &other)
        *this = other;
}

Data& Data:: operator=(const Data& other) {
    this->num = other.num;
    this->name = other.name;
    return(*this);    
}

Data::~Data(){
    
}

std::string& Data::nameGet() {
    return(this->name);
}

int& Data::numGet() {
    return(this->num);
}