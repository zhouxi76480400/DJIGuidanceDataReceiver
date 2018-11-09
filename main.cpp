#include <iostream>
#include <string>
#include <unistd.h>
#include "DJI_guidance.h"
#include "GuidanceReceiver.h"

using namespace std;

bool str_is_full_equal(string, string);
void print_error_msg();

int main(int argc, char ** argv) {
    if(argc == 3) {
        string arg1 = string(argv[1]);
        if(str_is_full_equal(arg1,"-p") ||
            str_is_full_equal(arg1,"--port")) {
            // set guidance
            connect_to_guidance("/dev/ttyUSB0");
            





            while (true) {
                cout << "test" << endl;
                sleep(1);
            }
        }else {
            print_error_msg();
        }
    } else {
        print_error_msg();
    }
    return 0;
}

bool str_is_full_equal(string str1, string str2) {
    bool is_find = str1.find(str2) != std::string::npos;
    bool is_length_equals = str1.length() == str2.length();
    return is_find && is_length_equals;
}

void print_error_msg() {
    cout << "Input Error, Example :" << endl;
    cout << "./xxx -p [port_number]" << endl;
    cout << "or" << endl;
    cout << "./xxx --port [port_number]" << endl;
}
