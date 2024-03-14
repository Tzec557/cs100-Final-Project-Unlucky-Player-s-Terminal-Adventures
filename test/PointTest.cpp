#include "../header/Point.hpp"
#include <gtest/gtest.h>

TEST(PointTests, testinitializer){
    Point *p = new Point();
    ASSERT_NE(p,nullptr);
}
TEST(PointTests, testGetPoint){
    Point *p = new Point();
    p->addPoint(30);
    ASSERT_EQ(p->getPoint(),30);
}
