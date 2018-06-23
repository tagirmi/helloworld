#include <gtest/gtest.h>
#include "lib.h"

TEST(lib_test, test)
{
    EXPECT_GT(mylib::version(), 0);
}
