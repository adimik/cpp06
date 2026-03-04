/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didimitr <didimitr@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 11:17:29 by didimitr          #+#    #+#             */
/*   Updated: 2026/03/04 11:33:26 by didimitr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Data {
    private:
        int num;
        std::string name;
    public:
        Data(int num, std::string name);
        Data(const Data& other);
        Data& operator=(const Data& other);
        ~Data();
        
        int& numGet();
        std::string& nameGet();
};
