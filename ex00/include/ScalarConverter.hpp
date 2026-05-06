/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:47:17 by didimitr          #+#    #+#             */
/*   Updated: 2026/05/06 13:22:03 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();           
    public:
        static void convert(const std::string& input);
};

enum DataType{UNKNOWN,CHAR,INT,FLOAT,DOUBLE,PSEUDO_FLOAT,PSEUDO_DOUBLE};
DataType PseudoCheck(const std::string& input);
DataType isChar(const std::string& input);
DataType isInt(const std::string& input);
DataType isFloat(const std::string& input);
DataType isDouble(const std::string& input);
DataType parser(const std::string& input);
void displayConvert(const DataType& data, const std::string& input);
void displayChar(const DataType& data, const std::string& input);
void displayInt(const DataType& data, const std::string& input);
void displayFloat(const DataType& data, const std::string& input);
void displayDouble(const DataType& data,const std::string& input);
