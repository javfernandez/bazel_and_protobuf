#ifndef LIST_PEOPLE_H
#define LIST_PEOPLE_H

#include <fstream>
#include <google/protobuf/util/time_util.h>
#include <iostream>
#include <string>

#include "point.pb.h"

void ListPeople(const tutorial::AddressBook& address_book);

#endif