/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:12:27 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 10:23:28 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base() {}

Base* generate(void) {
    static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(NULL));
        seeded = true;
    }
    
    int random = std::rand() % 3;
    
    switch (random) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A();
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B();
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C();
        default:
            return nullptr;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::bad_cast&) {}
    
    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (const std::bad_cast&) {}
    
    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::bad_cast&) {}
    
    std::cout << "Unknown type" << std::endl;
}