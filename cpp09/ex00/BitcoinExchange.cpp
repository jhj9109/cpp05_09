/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:24:53 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/23 17:24:54 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange(void) {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) { *this = other; }
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _c = other._c;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
    readCsv(filename);
}

void BitcoinExchange::readCsv(const std::string &filename)
{
    _c.clear();
    // 1. .csv 파일 검색
    if (!checkExtension(".csv", filename))
    {
        throw InvalidExtentionException();
    }

    std::ifstream inputFile(filename.c_str());

    // 2. 파일 오픈
    if (!inputFile.is_open())
    {
        throw FailToOpenFileException();
    }

    // 3. 빈파일 여부
    std::string header_line;
    if (!std::getline(inputFile, header_line))
    {
        throw EmptyFileException();
    }

    // 4. 헤더 체크
    std::string header_format("date,exchange_rate");
    if (header_line != header_format)
    {
        throw InvalidHeaderFormatException();
    }

    std::string line;

    while (std::getline(inputFile, line))
    {
        // 5. 라인 바이 라인 체크
        std::istringstream ss(line);
        std::string dateStr, rateStr;
        // DEBUG: std::cout << "line: " << line << std::endl;
        // 5.1 2022-03-07,38032.5 파싱
        Record rawData;
        if (!std::getline(ss, dateStr, ',') ||
            !std::getline(ss, rateStr) ||
            !checkDate(dateStr) ||
            !convertToFloat(rateStr, &rawData.rate))
        {
            // DEBUG: std::cout << "InvalidLineFormatException 발생: " << dateStr << ", " << rateStr << std::endl;
            throw InvalidLineFormatException();
        }
        else
        {
            // 음수 처리 안함 => 유가도 -인적이 있다!
            rawData.date = dateStr;
            _c.insert(rawData);
        }
    }
    inputFile.close();
}

void BitcoinExchange::convertToRecord(const std::string &filename)
{
    // 0. 파일확장명 체크는 불필요한듯
    std::ifstream inputFile(filename);

    // 1. 파일 오픈
    if (!inputFile.is_open())
    {
        throw FailToOpenFileException();
    }

    // 2. 빈파일 여부
    std::string header_line;
    if (!std::getline(inputFile, header_line))
    {
        throw EmptyFileException();
    }

    // 3. 헤더 체크
    std::string header_format("date | value");
    if (header_line != header_format)
    {
        throw InvalidHeaderFormatException();
    }

    std::string line;

    while (std::getline(inputFile, line))
    {
        // 4. 라인 바이 라인 체크 => 출력 (노 에러)
        std::istringstream ss(line);
        std::string dateStr, valueStr, dummy1, dummy2;
        // DEBUG: std::cout << "line: " << line << std::endl;
        float value;
        // 5.1 2022-03-07,38032.5 파싱
        if (!std::getline(ss, dateStr, ' ') ||
            !std::getline(ss, dummy1, '|') ||
            dummy1 != "" ||
            !std::getline(ss, dummy2, ' ') ||
            dummy2 != "" ||
            !std::getline(ss, valueStr) ||
            !checkDate(dateStr) ||
            !convertToFloat(valueStr, &value))
        {
            std::cout << "Error: bad input => " << line << std::endl;
        }
        else if (value < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
        }
        else if (value > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
        }
        else
        {
            std::cout << dateStr << " => "
                      << value << " = " << cal2(dateStr, value) << std::endl;
        }
    }
    inputFile.close();
}

bool BitcoinExchange::checkExtension(const std::string &ext, const std::string &filename)
{
    return (ext.size() <= filename.size() &&
            filename.substr(filename.size() - ext.size()) == ext);
}

bool BitcoinExchange::checkDate(const std::string &s)
{
    std::istringstream ss(s);
    std::string res;

    // 2009-01-02
    // year
    if (!std::getline(ss, res, '-') || res.size() != 4 ||
        !std::isdigit(res.at(0)) || !std::isdigit(res.at(1)) ||
        !std::isdigit(res.at(2)) || !std::isdigit(res.at(3)))
    {
        // DEBUG: std::cout << "1. res.at(0): " << res.at(0) << ", isdigit: " << std::cout << std::isdigit(res.at(0)) << std::endl;
        return false;
    }
    // month
    if (!std::getline(ss, res, '-') || res.size() != 2 ||
        !std::isdigit(res.at(0)) || !std::isdigit(res.at(1)))
    {
        // DEBUG: std::cout << "2. res.at(0): " << res.at(0) << ", isdigit: " << std::cout << std::isdigit(res.at(0)) << std::endl;
        return false;
    }
    // date
    if (!std::getline(ss, res) || res.size() != 2 ||
        !std::isdigit(res.at(0)) || !std::isdigit(res.at(1)))
    {
        // DEBUG: std::cout << "3. res.at(0): " << res.at(0) << ", isdigit: " << std::cout << std::isdigit(res.at(0)) << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::convertToFloat(const std::string &s, float *dest)
{
    char *endPtr;
    *dest = std::strtof(s.c_str(), &endPtr);
    return std::strcmp(endPtr, "") == 0 || std::strcmp(endPtr, "f") == 0;
}

float BitcoinExchange::cal(const std::string &date, float value)
{
    float rate = 0;
    for (std::multiset<Record>::iterator it = _c.begin(); it != _c.end(); ++it)
    {
        // DEBUG: std::cout << it->date << " vs " << date << " = " << (it->date > date) << std::endl;
        if (it->date > date)
            break;
        rate = it->rate;
    }
    // DEBUG:
    // std::cout << "cal(" << date << ", " << value << ") => "
    //           << rate << " * " << value << " = " << (rate * value) << std::endl;
    return rate * value;
}

float BitcoinExchange::cal2(const std::string &date, float value)
{
    Record key;
    key.date = date;

    std::multiset<Record>::iterator it = _c.upper_bound(key);
    if (it == _c.begin())
        return 0; // 가격 기록이 있기 이전은 가치 산출 불가 => 0으로
    return (--it)->rate * value;
}

const char *BitcoinExchange::InvalidExtentionException::what() const throw()
{
    return "Error: invalid extension.";
}
const char *BitcoinExchange::InvalidHeaderFormatException::what() const throw()
{
    return "Error: invalid header format.";
}
const char *BitcoinExchange::FailToOpenFileException::what() const throw()
{
    return "Error: could not open file.";
}
const char *BitcoinExchange::EmptyFileException::what() const throw()
{
    return "Error: empty file.";
}
const char *BitcoinExchange::InvalidLineFormatException::what() const throw()
{
    return "Error: InvalidLine.";
}
const char *BitcoinExchange::NotPositiveNumberException::what() const throw()
{
    return "Error: not a positive number.";
}
const char *BitcoinExchange::TooLargeNumberException::what() const throw()
{
    return "Error: too large a number.";
}
