/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:02:51 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/22 14:08:22 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() : name("Default") {
    std::cout << "Data constructor called" << std::endl;
}

Data::Data(const std::string& name) : name(name) {
    std::cout << "Data constructor called" << std::endl;
}

Data::~Data() {
    std::cout << "Data destructor called" << std::endl;
}

Data::Data(const Data& other) : name(other.name) {
    std::cout << "Data copy constructor called" << std::endl;
}

Data& Data::operator=(const Data& other) {
    if (this != &other) {
        name = other.name;
    }
    std::cout << "Data assignment operator called" << std::endl;
    return *this;
}

std::string Data::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Data& data) {
    os << "Data: " << data.getName();
    return os;
}