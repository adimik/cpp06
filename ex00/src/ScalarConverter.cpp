/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 16:47:28 by didimitr          #+#    #+#             */
/*   Updated: 2026/02/16 21:10:29 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <limits>
#include <cerrno>
#include <iomanip>
#include <cmath>

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter:: operator=(const ScalarConverter& other) {
    (void)other;
    return(*this);
}

ScalarConverter::~ScalarConverter() {
}

// Main convert function
void ScalarConverter::convert(const std::string& input) {
    DataType data = parser(input);
    displayConvert(data, input);
}
ScalarConverter::DataType ScalarConverter::PseudoCheck(const std::string& input) {
    if(input == "nanf" || input == "+inff" || input == "-inff")
        return(PSEUDO_FLOAT);
    if(input == "nan" || input == "+inf" || input == "-inf")
        return(PSEUDO_DOUBLE);
    else 
        return(UNKNOWN);
}

void ScalarConverter::displayConvert(const DataType& data, const std::string& input) {
    if(data == UNKNOWN)
        return;
    displayChar(data, input);
    displayInt(data, input);
    displayFloat(data,input);
    displayDouble(data, input);
}

void ScalarConverter::displayChar(const DataType& data, const std::string& input){
 
    if(data == CHAR)
    {
        std::cout << "char: '" << input << "'" << std::endl;
        return;
    }
    const char *str = input.c_str();
    char *end = NULL;
    errno = 0;
    double i = std::strtod(str, &end);
    if((i > 127 || i < 0) || errno == ERANGE || data == PSEUDO_FLOAT || data == PSEUDO_DOUBLE)
        std::cout << "char: impossible" << std::endl;  
    else if(!std::isprint(static_cast<unsigned char>(i)))
        std::cout << "char: Non displayable" << std::endl;  
    else
        std::cout << "char: '" << (static_cast<char>(i)) << "'" << std::endl;   
}

void ScalarConverter::displayInt(const DataType& data, const std::string& input) {
    if(data == INT)
    {
        std::cout << "int: " << input << std::endl;
        return;
    }
    const char *str = input.c_str();
    char *end = NULL;
    if(data == CHAR)
    {
        std::cout << "int: " << (static_cast<int>(str[0])) << std::endl;
        return;
    }
    errno = 0;
    double i = std::strtod(str, &end);
    if(i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min() || data == PSEUDO_FLOAT || data == PSEUDO_DOUBLE || errno == ERANGE)
        std::cout << "int: impossible" << std::endl;
    else 
    {
        std::cout << "int: " << (static_cast<int>(i)) << std::endl;  
    }
}

void ScalarConverter::displayFloat(const DataType& data, const std::string& input) {
    char *end = NULL;
    errno = 0;
    double i = std::strtod(input.c_str(), &end);
    if(data == PSEUDO_FLOAT)
        std::cout << "float: " << input << std::endl;
    else if(data == PSEUDO_DOUBLE)
        std::cout << "float: " << input << "f" << std::endl;
    else if(data == CHAR)
    {
        const char *ptr = input.c_str();
        i = (static_cast<int>(ptr[0]));
        std::cout << "float: " << (static_cast<float>(i)) << ".0f" << std::endl;
    }
    else if(i > std::numeric_limits<float>::max() || i < -std::numeric_limits<float>::max() || errno == ERANGE)
    {
        std::cout << "float: impossible" << std::endl;
    }
    else
    {
        float f = static_cast<float>(i);
        std::cout << "float: ";
        if (std::fmod(f, 1.0f) == 0.0f)
            std::cout << std::fixed << std::setprecision(1);
        std::cout << f << "f" << std::endl;
    }
}

void ScalarConverter::displayDouble(const DataType& data,const std::string& input){
    errno = 0;
    if(data == PSEUDO_FLOAT)
        std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;  // fix to remove 'f'
    else if (data == PSEUDO_DOUBLE)
        std::cout << "double: " << input << std::endl;
    else if (data == CHAR)
    {
        const char *start = input.c_str();
        std::cout << "double: " << (static_cast<int>(start[0])) << ".0" << std::endl;
    }
    else if (data == INT)
    {
        std::cout << "double: " << input << ".0" << std::endl;
    }
    else
    {
        char *end = NULL;
        double i = std::strtod(input.c_str(), &end);
        if(errno == ERANGE)
        {
            std::cout << "double: impossible" << std::endl;
            return;
        }
        std::cout << "double: ";
        if (std::fmod(i, 1.0) == 0.0)
            std::cout << std::fixed << std::setprecision(1);
        std::cout << i << std::endl;
    }
}

ScalarConverter::DataType ScalarConverter::isInt(const std::string& input) {
    char *end = NULL;
    errno = 0;
    long i = std::strtol(input.c_str(), &end, 10);
    if(*end != '\0')
        return(UNKNOWN);
    if(i > std::numeric_limits<int>::max() || i < std::numeric_limits<int>::min() || errno == ERANGE)
        return(UNKNOWN);
    return(INT);
}

ScalarConverter::DataType ScalarConverter::isChar(const std::string& input) {
    if(input.size() == 1 && std::isprint(static_cast <unsigned char>(input[0])) && !std::isdigit(static_cast <unsigned char>(input[0])))
        return(CHAR);
    return(UNKNOWN);
}

ScalarConverter::DataType ScalarConverter::isFloat(const std::string& input){
    char *end = NULL;
    const char *start = input.c_str();
    errno = 0;
    float i = std::strtof(input.c_str(), &end);
    (void) i;
    if(start == end)
        return(UNKNOWN);
    if(*end == 'f' && end[1] == '\0' && errno != ERANGE)
        return(FLOAT);
    return(UNKNOWN);
}

ScalarConverter::DataType ScalarConverter::isDouble(const std::string& input){
    char *end = NULL;
    const char *start = input.c_str();
    errno = 0;
    double value = std::strtod(input.c_str(), &end);
    (void) value;
    if(start == end || *end != '\0')
        return(UNKNOWN);
    return(DOUBLE);
}

ScalarConverter::DataType ScalarConverter::parser(const std::string& input) {
    
    DataType type = PseudoCheck(input);
    if(type != UNKNOWN)
        return(type);
    if(isChar(input) == CHAR)
        return(CHAR);
    if(isInt(input) == INT) 
        return(INT);
    if(isFloat(input) == FLOAT)
        return(FLOAT);
    if(isDouble(input) == DOUBLE)
        return(DOUBLE);
    return(UNKNOWN);
}