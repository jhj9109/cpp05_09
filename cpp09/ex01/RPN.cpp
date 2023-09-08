/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:00:15 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/23 18:00:16 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <string>
#include <iostream>

RPN::RPN(void) {}
RPN::RPN(const std::string &expr) : _expr(expr) {}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _expr = other._expr;
    }
    return *this;
}
RPN::~RPN() {}

void RPN::cal(void)
{
    std::stack<float> s;
    if (_expr.size() < 5)
    {
        throw "Error: 필요 최소 토큰 3개를 만족하기 위해서 최소 길이 5 필요;";
    }
    if (_expr.size() % 2 == 0 || (_expr.size() + 1) % 4 == 0)
    {
        throw "Error: 제대로 된 토큰은 길이 홀수 && 토큰 수도 홀수";
    }
    float a, b;
    for (size_t i = 0; i < _expr.size(); i += 2)
    {
        if (i + 1 < _expr.size() && _expr[i + 1] != ' ')
            throw "Error: 홀수번째는 공백이여야 합니다";
        if (std::isdigit(_expr[i]))
        {
            s.push(_expr[i] - '0');
            continue;
        }
        if (s.size() < 2)
            throw "Error: 연산을 위해 현재 스택안에 넘버가 최소 2개 필요";
        b = s.top();
        s.pop();
        a = s.top();
        s.pop();
        s.push(op(_expr[i], a, b));
    }
    if (s.size() != 1)
        throw "Error: 남은 토큰 수가 이상함";
    std::cout << s.top() << std::endl; // 종말 단계: 계산 결과 출력후 종료.
}

float RPN::op(char op, float a, float b)
{
    if (op == '/' && b == 0)
        throw "Error: 분모 0 에러";
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    if (op == '*')
        return a * b;
    if (op == '/')
        return a / b;
    throw "Error: 잘못된 토큰";
}