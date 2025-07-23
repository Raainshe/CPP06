/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:15:40 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 10:20:34 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main()
{
    std::cout << "=== Testing Base Type Identification ===" << std::endl;
    
    // Test multiple generations and identifications
    for (int i = 0; i < 5; i++) {
        std::cout << "\n--- Test " << (i + 1) << " ---" << std::endl;
        
        // Generate a random object
        Base* obj = generate();
        
        if (obj) {
            // Test identify with pointer
            std::cout << "identify(Base* p): ";
            identify(obj);
            
            // Test identify with reference
            std::cout << "identify(Base& p): ";
            identify(*obj);
            
            // Clean up
            delete obj;
        } else {
            std::cout << "Failed to generate object!" << std::endl;
        }
    }
    
    std::cout << "\n=== Test Complete ===" << std::endl;
    return 0;
}