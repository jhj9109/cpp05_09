#include <iostream>
#include "Array.hpp"

/* 제공되는 main문 */
#define MAX_VAL 750
int main(int, char **)
{
    Array<int> numbers(MAX_VAL); // 1. 입력으로 unsigned int가 주어질때, 해당 숫자만큼 길이를 가진 주어진 배열 동적 생성 가능
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value; // 2. number[인덱스]로 접근하여 값을 바꿀 수 있다. && 우측 const?
        mirror[i] = value;
    }
    // SCOPE, 복사 생생성성자
    {
        Array<int> t;
        Array<int> tmp = numbers;
        Array<int> test1(tmp);
        Array<int> test2(tmp);
        Array<int> test3(tmp);
        Array<int> test4(tmp);
        Array<int> test5(tmp);
        Array<int> test6(tmp);
        Array<int> test7(tmp);
        t = numbers; // 할당연산자 오버로딩
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i]) // 3. 2에서 생성된 값이 mirror(실제 int 배열)의 값과 동일한지 확인
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0; // 4. 인덱스 초과시 에러 출력1
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0; // 4. 인덱스 초과시 에러 출력2
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand(); // 5. number[인덱스]로 접근하여 값을 바꿀 수 있다.
    }
    delete[] mirror; //
    system("leaks test");
    return 0;
}