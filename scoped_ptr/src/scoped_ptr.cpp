//============================================================================
// Name        : scoped_ptr.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <stdint.h>
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <memory>

class test
{
public:
    test(const uint32_t  val)
        : m_val(val)
    {
        std::cout << "constructor called " << m_val << std::endl;;
    }
    ~test()
    {
        std::cout << "destructor called " << m_val << std::endl;;
    }
    void
    test_function()
    {
        std::cout << "call test func" << std::endl;
    }
private:
    const uint32_t m_val;
};

int
main()
{
    std::cout << "normal test" << std::endl;
    test obj0(0);
    obj0.test_function();

    std::cout << "shared test" << std::endl;
    boost::shared_ptr<test > obj1;
    obj1 = boost::shared_ptr<test > (new test(1));
    obj1 = boost::shared_ptr<test > (new test(2));

    std::cout << "scoped test" << std::endl;
    {
        boost::scoped_ptr<test > obj2(new test(3));
        test* tmp = obj2.get();
        tmp->test_function();
    }
    std::cout << "scoped test end" << std::endl;
    return 0;
}
