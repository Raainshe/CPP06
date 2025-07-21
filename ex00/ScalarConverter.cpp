/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:12:41 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/21 16:46:32 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Static member variable definitions
// Static variables are initialized at class level, not per instance
char ScalarConverter::_char = 0;
int ScalarConverter::_int = 0;
float ScalarConverter::_float = 0.0f;
double ScalarConverter::_double = 0.0;

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = other;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    // Static variables are not copied, so we don't need to copy them
    (void)other;
    return *this;
}

void ScalarConverter::convert(const std::string &literal)
{
    // Handle special cases first
    if (literal == "nan" || literal == "nanf")
    {
        _float = std::nanf("nan");
        _double = std::nan("nan");
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    else if (literal == "+inf" || literal == "inf" || literal == "+inff" || literal == "inff")
    {
        _float = std::numeric_limits<float>::infinity();
        _double = std::numeric_limits<double>::infinity();
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
        return;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        _float = -std::numeric_limits<float>::infinity();
        _double = -std::numeric_limits<double>::infinity();
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }

    // Handle single character input
    if (literal.length() == 1 && !std::isdigit(literal[0]))
    {
        _char = literal[0];
        _int = static_cast<int>(_char);
        _float = static_cast<float>(_char);
        _double = static_cast<double>(_char);
        
        // Print char
        if (_int < 32 || _int > 126)
        {
            std::cout << "char: Non displayable" << std::endl;
        }
        else
        {
            std::cout << "char: '" << _char << "'" << std::endl;
        }
        
        // Print int
        std::cout << "int: " << _int << std::endl;
        
        // Print float and double
        printFloat();
        printDouble();
        return;
    }

    // Try to convert as double first (most precise)
    try
    {
        _double = std::stod(literal);
        _float = static_cast<float>(_double);
        
        // Check if conversion to int is possible
        if (_double > std::numeric_limits<int>::max() || 
            _double < std::numeric_limits<int>::min() ||
            std::isnan(_double) || std::isinf(_double))
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
        }
        else
        {
            _int = static_cast<int>(_double);
            
            // Check if conversion to char is possible
            if (_int < 0 || _int > 127)
            {
                std::cout << "char: impossible" << std::endl;
            }
            else if (_int < 32 || _int > 126)
            {
                _char = static_cast<char>(_int);
                std::cout << "char: Non displayable" << std::endl;
            }
            else
            {
                _char = static_cast<char>(_int);
                std::cout << "char: '" << _char << "'" << std::endl;
            }
            
            std::cout << "int: " << _int << std::endl;
        }
        
        printFloat();
        printDouble();
    }
    catch (const std::exception &e)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }
}


void ScalarConverter::printFloat()
{
    if (std::isnan(_float))
    {
        std::cout << "float: nanf" << std::endl;
    }
    else if (std::isinf(_float))
    {
        if (_float > 0)
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    else
    {
        std::cout << "float: " << std::fixed;
        if (_float == static_cast<int>(_float))
            std::cout << std::setprecision(1);
        else
            std::cout << std::setprecision(6);
        std::cout << _float << "f" << std::endl;
    }
}

void ScalarConverter::printDouble()
{
    if (std::isnan(_double))
    {
        std::cout << "double: nan" << std::endl;
    }
    else if (std::isinf(_double))
    {
        if (_double > 0)
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
    else
    {
        std::cout << "double: " << std::fixed;
        if (_double == static_cast<int>(_double))
            std::cout << std::setprecision(1);
        else
            std::cout << std::setprecision(6);
        std::cout << _double << std::endl;
    }
}

void ScalarConverter::printAll()
{
    printFloat();
    printDouble();
}