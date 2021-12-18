#include "gtest/gtest.h"
#include <vector>
#include <iostream>
#include <fstream>


TEST(processIdbyNames, sum_zero)
{

    std::ifstream a("out1.txt");
    std::ifstream b("out2.txt");


    std::string genfile((std::istreambuf_iterator<char>(a)), std::istreambuf_iterator<char>());
    std::string genfile2((std::istreambuf_iterator<char>(b)), std::istreambuf_iterator<char>());

    ASSERT_EQ(genfile, genfile2);
}
