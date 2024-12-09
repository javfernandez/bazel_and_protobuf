#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "google/protobuf/util/message_differencer.h"
  
#include "point.pb.h"

TEST(Single_entry, MessageEquality)   //Test for a single protobuffer entry
{
    std::string serialized;
    std::string serialized2;

    // Create and initilized a proto buffer pointer -> person 
    tutorial::AddressBook address_book;
    tutorial::Person *person = address_book.add_people();

    // Create and initilized a proto buffer pointer -> desperson
    tutorial::AddressBook address_book2;
    tutorial::Person *desperson = address_book2.add_people();

    /*
        1. The person pointer is loaded with valid values.
        2. Then the data is serialized to string serialized.   
        3. The data store in serialized is parsed to desperson.
        4. The parsed data is serialized again to a new string in serialized2
        5. Serialized and serialized2 is compared to see the hole process works. 
    */
    
    person->set_id(1);
    person->set_name("Nombre_test");
    person->set_email("Nombre@gmail.com");

    tutorial::Person::PhoneNumber* phone_number = person->add_phones();
    phone_number->set_number("1234567890");
    phone_number->set_type(tutorial::Person::MOBILE);

    person->SerializeToString(&serialized);
    
    std::cout << serialized << std::endl;
    
    desperson->ParseFromString(serialized);
    desperson->SerializeToString(&serialized2);
    
    EXPECT_EQ(person->id(), 1);
    EXPECT_EQ(person->name(), "Nombre_test");
    EXPECT_EQ(person->email(), "Nombre@gmail.com");
    EXPECT_EQ(phone_number->number(), "1234567890");
    EXPECT_EQ(phone_number->type(), tutorial::Person::MOBILE);

    EXPECT_EQ(serialized, serialized2);
}

TEST(Single_entry_two_phones, MessageEquality) //Test for a single protobuffer entry with two phone numbers
{
    std::string serialized;
    std::string serialized2;

    // Create and initilized a proto buffer pointer -> person 
    tutorial::AddressBook address_book;
    tutorial::Person *person = address_book.add_people();

    // Create and initilized a proto buffer pointer -> desperson
    tutorial::AddressBook address_book2;
    tutorial::Person *desperson = address_book2.add_people();

    /*
        1. The person pointer is loaded with valid values.
        2. Then the data is serialized to string serialized.   
        3. The data store in serialized is parsed to desperson.
        4. The parsed data is serialized again to a new string in serialized2
        5. Serialized and serialized2 is compared to see the hole process works. 
    */
    
    person->set_id(1);
    person->set_name("Nombre_test");
    person->set_email("Nombre@gmail.com");

    tutorial::Person::PhoneNumber* phone_number = person->add_phones();
    phone_number->set_number("1234567890");
    phone_number->set_type(tutorial::Person::MOBILE);

    tutorial::Person::PhoneNumber* phone_number2 = person->add_phones();
    phone_number2->set_number("0987654321");
    phone_number2->set_type(tutorial::Person::WORK);

    person->SerializeToString(&serialized);
    
    desperson->ParseFromString(serialized);
    desperson->SerializeToString(&serialized2);

    std::cout << serialized << std::endl;
    
    EXPECT_EQ(person->id(), 1);
    EXPECT_EQ(person->name(), "Nombre_test");
    EXPECT_EQ(person->email(), "Nombre@gmail.com");
    EXPECT_EQ(phone_number->number(), "1234567890");
    EXPECT_EQ(phone_number->type(), tutorial::Person::MOBILE);
    EXPECT_EQ(phone_number2->number(), "0987654321");
    EXPECT_EQ(phone_number2->type(), tutorial::Person::WORK);

    EXPECT_EQ(serialized, serialized2);
}

TEST(Two_entry_two_phones, MessageEquality) //Test for a two protobuffer entry with two phone numbers
{
    std::string serialized;
    std::string serialized2;

    // Create and initilized a proto buffer pointer -> person 
    tutorial::AddressBook address_book;
    tutorial::Person *person = address_book.add_people();

    // Create and initilized a proto buffer pointer -> desperson
    tutorial::AddressBook address_book2;
    
    /*
        1. The person pointer is loaded with valid values.
        2. Then the data is serialized to string serialized.   
        3. The data store in serialized is parsed to desperson.
        4. The parsed data is serialized again to a new string in serialized2
        5. Serialized and serialized2 is compared to see the hole process works. 
    */
    
    person->set_id(1);
    person->set_name("Nombre_test");
    person->set_email("Nombre@gmail.com");

    tutorial::Person::PhoneNumber* phone_number = person->add_phones();
    phone_number->set_number("1234567890");
    phone_number->set_type(tutorial::Person::MOBILE);

    tutorial::Person::PhoneNumber* phone_number2 = person->add_phones();
    phone_number2->set_number("0987654321");
    phone_number2->set_type(tutorial::Person::WORK);

    tutorial::Person *person2 = address_book.add_people();

    person2->set_id(2);
    person2->set_name("name_test");
    person2->set_email("name@gmail.com");

    tutorial::Person::PhoneNumber* phone_number3 = person2->add_phones();
    phone_number3->set_number("0192837465");
    phone_number3->set_type(tutorial::Person::MOBILE);

    tutorial::Person::PhoneNumber* phone_number4 = person2->add_phones();
    phone_number4->set_number("1029384756");
    phone_number4->set_type(tutorial::Person::WORK);


    address_book.SerializeToString(&serialized);
    
    address_book2.ParseFromString(serialized);
    address_book2.SerializeToString(&serialized2);

    std::cout << serialized << std::endl;
    
    EXPECT_EQ(person->id(), 1);
    EXPECT_EQ(person->name(), "Nombre_test");
    EXPECT_EQ(person->email(), "Nombre@gmail.com");
    EXPECT_EQ(phone_number->number(), "1234567890");
    EXPECT_EQ(phone_number->type(), tutorial::Person::MOBILE);
    EXPECT_EQ(phone_number2->number(), "0987654321");
    EXPECT_EQ(phone_number2->type(), tutorial::Person::WORK);

    EXPECT_EQ(person2->id(), 2);
    EXPECT_EQ(person2->name(), "name_test");
    EXPECT_EQ(person2->email(), "name@gmail.com");
    EXPECT_EQ(phone_number3->number(), "0192837465");
    EXPECT_EQ(phone_number3->type(), tutorial::Person::MOBILE);
    EXPECT_EQ(phone_number4->number(), "1029384756");
    EXPECT_EQ(phone_number4->type(), tutorial::Person::WORK);


    EXPECT_EQ(serialized, serialized2);
}


TEST(data_test, MessageEquality)
{
    // Create and initilized a proto buffer pointer -> person 
    tutorial::AddressBook address_book;
    tutorial::Person *person = address_book.add_people();

    int i_id = 1;
    char c_id = 1;
    long int li_id = 1;
    float f_id = 1;
    double d_id = 1;

    person->set_id(i_id);
    EXPECT_EQ(person->id(), 1);

    person->set_id(c_id);
    EXPECT_EQ(person->id(), 1);

    person->set_id(li_id);
    EXPECT_EQ(person->id(), 1);

    person->set_id(f_id);
    EXPECT_EQ(person->id(), 1);

    person->set_id(d_id);
    EXPECT_EQ(person->id(), 1);

    for (int i = 0; i < 100000000; i++){
        person->set_id(i);
        EXPECT_EQ(person->id(), i);
    }


    /*
        If you try to set a protobuff field with an invalid data type, the test does not compile. 
    */
}

