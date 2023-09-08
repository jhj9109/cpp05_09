/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:25:01 by hyeonjan          #+#    #+#             */
/*   Updated: 2023/03/23 17:25:02 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>
#include <set>

struct Record
{
    std::string date;
    float rate;

    // for multiset
    bool operator<(const Record &other) const
    {
        return date < other.date;
    }
};

class BitcoinExchange
{
private:
    std::multiset<Record> _c;
    BitcoinExchange(void);

public:
    BitcoinExchange(const std::string &filename);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    virtual ~BitcoinExchange();

    void readCsv(const std::string &filename);
    void convertToRecord(const std::string &filename);

    bool checkExtension(const std::string &ext, const std::string &filename);
    bool checkDate(const std::string &s);
    bool convertToFloat(const std::string &s, float *dest);
    float cal(const std::string &date, float value);
    float cal2(const std::string &date, float value);

    class InvalidExtentionException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class FailToOpenFileException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class EmptyFileException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class InvalidHeaderFormatException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class InvalidLineFormatException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class NotPositiveNumberException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };

    class TooLargeNumberException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

#endif
