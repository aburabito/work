/**********************************************************************//**
 * @file    test.cpp
 * @brief
 * @author  Daisuke Naka<Daisuke.Naka@jp.sony.com>
 * Copyright 2011 Sony Corporation.
 *    Personal Application Design Division Software Design Group
 *    Section 2,Dept.2
 * ================================================================== */
/**********************************************************************/
#include <iostream>

template<uint32_t ID,  uint32_t VAL >
struct val_num
{
    enum
    {
        id  = ID,
    };
    enum
    {
        val = VAL,
    };
};

typedef val_num<1, 10> test1;
typedef val_num<2, 10> test2;

template<typename T >
class test
{
public:
    test()
    {
    }
    void
    func()
    {
        std::cout << "test func" << std::endl;
    }
};

template<>
class test<test1 >
{
public:
     void
     func()
     {
         std::cout << "test func1" << std::endl;
     }
};


int
main()
{
    test<int > obj1;
    obj1.func();
    test<test1 > obj2;
    obj2.func();
    return 0;
}





