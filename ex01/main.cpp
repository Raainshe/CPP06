/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:00:00 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 10:08:37 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data data("Ryan");
    
    uintptr_t raw = Serializer::serialize(&data);
    Data* deserialized = Serializer::deserialize(raw);
    std::cout << "Original value: " << data << std::endl;
    std::cout << "Raw value: " << raw << std::endl;
    std::cout << "Deserialized value: " << deserialized->getName() << std::endl;
    return 0;
}