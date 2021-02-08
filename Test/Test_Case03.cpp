#include "gtest/gtest.h"
#include "Case03.hpp"

using namespace Interview;

TEST(ECSTest, Case03)
{
    int matrix[] = {
        1, 2, 8, 9,
        2, 4, 9, 12,
        4, 7, 10, 13,
        6, 8, 11, 15
    };

    EXPECT_FALSE(ExistNumInArray(matrix, 4, 4, 5));
    EXPECT_TRUE(ExistNumInArray(matrix, 4, 4, 7));
}