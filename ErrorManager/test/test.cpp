#include "../src/errormanager.h"
#include<iostream>

int main() {
    std::cout << "Testing Error Manager library ..." << std::endl;
    errormanager::Throw(1);
    errormanager::Throw(2);
    errormanager::Throw(3);
    errormanager::Throw(4);
    errormanager::Throw(5);
    int errorCode = errormanager::Query();
    std::cout << "Error code: " << errorCode << ". Successful!" << std::endl;
}