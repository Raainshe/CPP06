/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:02:55 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/22 14:07:35 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
    private:
        std::string name;
    public:
    Data(const std::string& name);
    Data();
    ~Data();
    Data(const Data& other);
    Data& operator=(const Data& other);
    std::string getName() const;
};

std::ostream& operator<<(std::ostream& os, const Data& data);


#endif