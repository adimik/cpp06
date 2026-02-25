/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:47:17 by didimitr          #+#    #+#             */
/*   Updated: 2026/02/12 17:39:10 by didimitr         ###   ########.fr       */
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
        enum DataType{UNKNOWN,CHAR,INT,FLOAT,DOUBLE,PSEUDO_FLOAT,PSEUDO_DOUBLE};
        static DataType parser(const std::string& input);
        static void displayConvert(const DataType& data, const std::string& input);
        static void displayChar(const DataType& data, const std::string& input);
        static void displayInt(const DataType& data, const std::string& input);
        static void displayFloat(const DataType& data, const std::string& input);
        static void displayDouble(const DataType& data,const std::string& input);
        static DataType PseudoCheck(const std::string& input);
        static DataType isChar(const std::string& input);
        static DataType isInt(const std::string& input);
        static DataType isFloat(const std::string& input);
        static DataType isDouble(const std::string& input);
    public:
        static void convert(const std::string& input);
};