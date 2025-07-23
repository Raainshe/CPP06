/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakoni <rmakoni@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:12:51 by rmakoni           #+#    #+#             */
/*   Updated: 2025/07/23 10:20:01 by rmakoni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

class Base
{
    public:
        virtual ~Base();
};

// Forward declarations
class A;
class B; 
class C;

// Standalone functions
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif