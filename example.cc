#include "pipeline.hh"
#include <iostream>
#include <string>


int incr(float a)
{
    return static_cast<int>(a + 1);
}

struct Func
{
    std::string operator()(int i)
    {
        if (i == 42)
            return "42";
        else
            return "Other";
    }
};


struct Func2
{
    int operator()(const std::string& s)
    {
        if (s == "42")
            return 42;
        else
            return 0;
    }
};


int main()
{
    auto f = [](int a) -> float
    {
        return static_cast<float>(a + 1);
    };

    Func2 f2;


    std::cout << 
        pipeline(
            39, // Input argument of the pipeline
            incr,
            std::move(f),
            [](float f) -> int { return static_cast<int>(f + 1); },
            Func{},
            f2,
            [](int&& i) -> int { return i + 2; },
            [](const int& i) -> int { return i - 2; })
        << std::endl;
    return 0;
}
