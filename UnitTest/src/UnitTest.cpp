//============================================================================
// Name        : UnitTest.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdint.h>
#include <boost/tr1/tuple.hpp>
#include <boost/tr1/functional.hpp>


namespace std
{
    using namespace tr1;
}

class functor
{
public:
    functor()
    {
    }
    void
    operator()(const uint32_t val1, const uint32_t val2)
    {
        std::cout << "test "<< std::endl;
    }
};

uint32_t
func(const uint32_t val1, const uint32_t val2)
{
	std::tuple<uint32_t, uint32_t > test(val1, val2);
	std::cout << std::get<1 >(test) << std::endl;
	return 0;
}

int
main()
{
	func(1, 2);
	std::cout << "!!!Hello World!!!" << std::endl;

	std::function<uint32_t ( uint32_t)  > test(std::bind(func, 1, std::placeholders::_1));
	test(5);

	functor()(1, 2);
	return 0;
}
