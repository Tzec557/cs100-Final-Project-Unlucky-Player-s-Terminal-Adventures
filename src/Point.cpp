#include <iostream>
#include "../header/Point.hpp"

using namespace std;

Point::Point(){
    pointNum = 0;
}

Point::~Point() {
}

int Point::getPoint(){
    return pointNum;
}

void Point::addPoint(int num){
    pointNum += num;
}
