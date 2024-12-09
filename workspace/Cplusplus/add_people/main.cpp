#include "add_people.hpp"

using namespace std;

using google::protobuf::util::TimeUtil;



// Main function:  Reads the entire address book from a file,
// add people based on user input, then writes it back out to the same file.
int main(int argc, char* argv[]) {
    // Verify that the version of the library that we linked against is
    // compatible with the version of the headers we compilsed against.
    // https://github.com/protocolbuffers/protobuf/blob/master/src/google/protobuf/stubs/common.h#L116
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    if (argc != 2) {
        cerr << "Usage:  " << argv[0] << " ADDRESS_BOOK_FILE" << endl;
        return -1;
    }

    tutorial::AddressBook address_book;
    
    {
        // Read the existing address book.
        fstream input(argv[1], ios::in | ios::binary);
        if (!input) {
            cout << argv[1] << ": File not found.  Creating a new file." << endl;
        } 
        else if (!address_book.ParseFromIstream(&input)) {
            cerr << "Failed to parse address book." << endl;
            return -1;
        }
    }

    // Keep adding address until user say no.
    while (true)
    {
        cout << "Add person to address book? yes | no" << endl;
        string choice;
        getline(cin, choice);
        if ((choice != "yes") && (choice != "no")) {
            cout << "Please enter yes or no." << endl;
            continue;
        }
        if (choice == "no") {
            break;
        } 
        else {
            PromptForAddress(address_book.add_people());
        }
    }


    {
        // Write the new address book back to disk.
        fstream output(argv[1], ios::out | ios::trunc | ios::binary);
        if (!address_book.SerializeToOstream(&output)) {
            cerr << "Failed to write address book." << endl;
            return -1;
        }
    }

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}