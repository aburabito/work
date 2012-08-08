/**********************************************************************//**
 * @file    test.cpp
 * @brief
 * @author  Daisuke Naka<Daisuke.Naka@jp.sony.com>
 * Copyright 2011 Sony Corporation.
 *    Personal Application Design Division Software Design Group
 *    Section 2,Dept.2
 * ================================================================== */
/**********************************************************************/
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/if.hpp>
#include <boost/lambda/loops.hpp>
#include <boost/lambda/switch.hpp>
#include <boost/lambda/exceptions.hpp>
#include <boost/lambda/construct.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <stdexcept>

int
test(int i)
{
    if (i %3 == 0)
    {
        std::cout <<  ": 3 times number \n" << std::endl;
    }
    else
    {
        std::cout <<  ": not 3 times number \n" << std::endl;
    }
    return i + 1;
}

int
main()
{
    using namespace boost::lambda;
    std::vector<uint32_t > is;
    for (uint32_t i = 0; i < 10; i++)
    {
        is.push_back(i);
    }
    std::for_each(is.begin(), is.end(),
                         if_(_1 % 3 == 0)[std::cout << _1 << " : 3 times number \n"].
                         else_[std::cout << _1 << " : not 3 times number \n"]);
    std::for_each(is.begin(), is.end(), _1 = bind(test, _1));
    std::for_each(is.begin(), is.end(),  (std::cout <<  _1 << "result = "  << "\n") );
    return 0;
}



