#include <iostream>
#include <ctime>
#include <fstream>
#include <google/protobuf/util/time_util.h>
#include <string>

#include "point.pb.h"

using google::protobuf::util::TimeUtil;

int main(void) {
    std::cout<<"Hello, World!"<< std::endl;

    // my_protos::point::Point p;
    // p.set_x(123);
    // p.set_y(456);
    // std::cout << p.DebugString();

    return 0;
}