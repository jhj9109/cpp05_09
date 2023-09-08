#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>

const std::string BLACK = "\033[30m";
const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string WHITE = "\033[37m";
const std::string DEFAULT = "\033[39m";

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

Base *generate(void)
{
    Base *generated = NULL;
    switch (rand() % 3)
    {
    case 0:
        generated = new A();
        break;
    case 1:
        generated = new B();
        break;
    case 2:
        generated = new C();
        break;
    default: // 도달 불가;
        break;
    }
    return generated;
}

void identify(Base *p)
{
    std::cout << (dynamic_cast<A *>(p) ? "A" : dynamic_cast<B *>(p) ? "B"
                                           : dynamic_cast<C *>(p)   ? "C"
                                                                    : "?")
              << std::endl;
}

void identify(Base &p)
{
    int i = 1;
    try
    {
        // (void) 처리 안 하면 에러.
        (void)dynamic_cast<A &>(p);
    }
    catch (const std::exception &e)
    {
        i++;
        try
        {
            (void)dynamic_cast<B &>(p);
        }
        catch (const std::exception &e)
        {
            i++;
            try
            {
                (void)dynamic_cast<C &>(p);
            }
            catch (const std::exception &e)
            {
                i = 0;
            }
        }
    }
    std::cout << "?ABC"[i] << std::endl;
}

int main(void)
{
    // 안 해주면 계속 같은 rand가 먼저 호출되는듯?
    std::srand(time(NULL));

    Base *p = generate();
    if (!p)
    {
        return EXIT_FAILURE;
    }

    std::cout << YELLOW << std::endl;
    identify(p);
    identify(*p);
    delete p;

    std::cout << WHITE << std::endl;

    system("leaks test");
    return EXIT_SUCCESS;
}