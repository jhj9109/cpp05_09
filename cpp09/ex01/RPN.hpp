/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:00:38 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/23 18:00:38 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
private:
    std::string _expr;
    RPN(void);

public:
    RPN(const std::string &expr);
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    virtual ~RPN(void);

    void cal(void);
    float op(char op, float a, float b);
};

#endif
