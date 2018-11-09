//
// Created by zhouxi on 18-11-9.
//

#include "GuidanceReceiver.h"
#include "serial/serial.h"

#include <iostream>
#include <exception>
#include <string>

using namespace std;

void print_tty_error(const char * port);
void print_tty_success(const char * port);

void connect_to_guidance(const char * port) {
    int status = connect_serial(port);
    if(status == 0) {
        print_tty_success(port);
    }else {
        print_tty_error(port);
        throw exception();
    }
}

void print_tty_error(const char * port) {
    cout << "cannot open serial port:" << port << endl;
}

void print_tty_success(const char * port) {
    cout << "open serial port " << port << " success" << endl;
}
