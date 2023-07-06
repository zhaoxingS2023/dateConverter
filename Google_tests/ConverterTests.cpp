#include "gtest/gtest.h"
#include "Julian.h"
#include "Gregorian.h"


class DateConverterFixture : public ::testing::Test {

protected:
    virtual void SetUp()
    {
        gregDate = new GregorianDate();
        julDate = new JulianDate();
    }

    virtual void TearDown() {
        delete gregDate;
        delete julDate;
    }

    GregorianDate * gregDate;
    JulianDate * julDate;
};

TEST_F(DateConverterFixture, FirstDay){ // 1/1/1 -> 1/3/1

    gregDate->SetMonth(1);
    gregDate->SetDay(1);
    gregDate->SetYear(1);

    int absGregDate = gregDate->getAbsoluteDate();
    julDate->CalcJulianDate(absGregDate);

    EXPECT_EQ(julDate->getMonth(),1);
    EXPECT_EQ(julDate->getDay(),3);
    EXPECT_EQ(julDate->getYear(),1);

}

TEST_F(DateConverterFixture, Today){ // 7/1/2023 -> 6/18/2023

    gregDate->SetMonth(7);
    gregDate->SetDay(1);
    gregDate->SetYear(2023);

    int absGregDate = gregDate->getAbsoluteDate();
    julDate->CalcJulianDate(absGregDate);

    EXPECT_EQ(julDate->getMonth(),6);
    EXPECT_EQ(julDate->getDay(),18);
    EXPECT_EQ(julDate->getYear(),2023);
}
