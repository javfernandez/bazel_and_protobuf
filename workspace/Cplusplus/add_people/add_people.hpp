#ifndef ADD_PEOPLE_H
#define ADD_PEOPLE_H

#include <fstream>
#include <google/protobuf/util/time_util.h>
#include <iostream>
#include <string>

#include "point.pb.h"

void PromptForAddress(tutorial::Person* person);

#endif