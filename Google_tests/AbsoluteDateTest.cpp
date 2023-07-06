#include "gtest/gtest.h"
#include "Gregorian.h"


TEST(AbsoluteDateTestSuite, ExampleDate){ // 7/1/2023 -> 738702
    GregorianDate gregDate;
    gregDate.SetMonth(7);
    gregDate.SetDay(1);
    gregDate.SetYear(2023);

    EXPECT_EQ(gregDate.getAbsoluteDate(),738702);
}


TEST(AbsoluteDateTestSuite, IncorrectDate){ // 7/0/2023 -> 0
    GregorianDate gregDate;
    gregDate.SetMonth(7);
    gregDate.SetDay(0);
    gregDate.SetYear(2023);

    ASSERT_EQ(gregDate.getAbsoluteDate(),0);
}