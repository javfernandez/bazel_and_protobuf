#include "add_people.hpp"

using namespace std;

using google::protobuf::util::TimeUtil;

// This function fills in a Person message based on user input.
void PromptForAddress(tutorial::Person* person) {
    cout << "Enter person ID number: " << endl;
    int id;
    cin >> id;
    person->set_id(id);
    // Ignore delimeter
    // ignores first 256 characters or all the character until it encounters delimeter (here \n in your case), 
    // whichever comes first (here \n is the first character, so it ignores until \n is encountered).
    cin.ignore(256, '\n');

    cout << "Enter name: " << endl;
    getline(cin, *person->mutable_name());

    cout << "Enter email address (blank for none): " << endl;
    string email;
    getline(cin, email);
    if (!email.empty()) {
        person->set_email(email);
    }

    // Add multiple phone numbers
    while (true) {
        cout << "Enter a phone number (or leave blank to finish): " << endl;
        string number;
        getline(cin, number);
        if (number.empty()) {
            break;
        }

        //Because "repeated PhoneNumber phones", we have "add" prefix.
        tutorial::Person::PhoneNumber* phone_number = person->add_phones();
        phone_number->set_number(number);

        cout << "Is this a mobile, home, or work phone? mobile | home | work " << endl;
        string type;
        getline(cin, type);
        if (type == "mobile") {
            phone_number->set_type(tutorial::Person::MOBILE);
        } 
        else if (type == "home") {
            phone_number->set_type(tutorial::Person::HOME);
        } 
        else if (type == "work") {
            phone_number->set_type(tutorial::Person::WORK);
        } 
        else {
            cout << "Unknown phone type.  Using default." << endl;
        }
    }
}

