#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

int main(int ac, char **av)
{
    if (ac > 1)
    {
        // std::string str(av[1]);
        std::ifstream infile(av[1]);
        std::string str;
        std::cout << "1: " << std::getline(infile, str) << std::endl;
        str = "";
        std::cout << "2: " << std::getline(infile, str) << std::endl;
        str = "";
        std::cout << "3: " << std::getline(infile, str) << std::endl;
        str = "";
        std::cout << "4: " << std::getline(infile, str) << std::endl;
        std::cout << "str: " << str << std::endl;

        // 1. substr 테스트 => 길면 에러 난다.
        // std::string str1 = str.substr();
        // std::string str2 = str.substr(3);
        // std::string str3 = str.substr(10);
        // std::string str4 = str.substr(13);
        // std::string str5 = str.substr(16);
        // std::cout << "substr(): " << str << std::endl;
        // std::cout << "substr(3): " << str2 << std::endl;
        // std::cout << "substr(10): " << str3 << std::endl;
        // std::cout << "substr(13): " << str4 << std::endl;
        // std::cout << "substr(16): " << str5 << std::endl;

        // 2. 간단 함수 체크
        // std::cout << str << std::endl;
        // std::cout << "size(): " << str.size() << std::endl;
        // std::cout << "size(): " << str.size() << std::endl;

        // 3. getLine 기능 체크

        std::istringstream ss(str.c_str());
        // case1: 1,2
        // case2: 1,2,
        // case3: 1,2,3
        std::string col1;
        std::string col2;
        std::string col3;
        // , 파싱 테스트
        // std::cout << "std::getline(ss, col1, ','): " << std::getline(ss, col1, ',') << std::endl;
        // std::cout << "std::getline(ss, col2, ','): " << std::getline(ss, col2, ',') << std::endl;
        // std::cout << "std::getline(ss, col3, ','): " << std::getline(ss, col3) << std::endl;
        // std::cout << "col1: " << col1 << std::endl;
        // std::cout << "col2: " << col2 << std::endl;
        // std::cout << "col3: " << col3 << std::endl;

        // 개행 테스트
        std::cout << "std::getline(ss, col1): " << std::getline(ss, col1, ',') << std::endl;
        std::cout << "std::getline(ss, col2): " << std::getline(ss, col2, ',') << std::endl;
        std::cout << "std::getline(ss, col3): " << std::getline(ss, col3) << std::endl;
        std::cout << "col1: " << col1 << std::endl;
        std::cout << "col2: " << col2 << std::endl;
        std::cout << "col3: " << col3 << std::endl;

        char *endPtr = NULL;
        float f1 = std::strtof(col1.c_str(), &endPtr);
        std::cout << "endPtr: " << endPtr << std::endl;
        float f2 = std::strtof(col2.c_str(), &endPtr);
        std::cout << "endPtr: " << endPtr << std::endl;
        float f3 = std::strtof(col3.c_str(), &endPtr);
        std::cout << "endPtr: " << endPtr << std::endl;

        // is digit 테스트

        std::string number = "1-223";
        std::cout << "isdigit(" << number << "): " << std::isdigit(number.at(0)) << std::endl;
        std::cout << "isdigit(" << number << "): " << std::isdigit(number.at(1)) << std::endl;
        std::cout << "isdigit(" << number << "): " << std::isdigit(number.at(2)) << std::endl;
        std::cout << "isdigit(" << number << "): " << std::isdigit(number.at(3)) << std::endl;
    }

    // system("leaks a.out");
}