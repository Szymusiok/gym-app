#include <iostream>
#include <string>
#include "User.h";

int main() {
    User szymon;
    szymon.setUserName("Szymon");
    szymon.setUserSurname("Kubica");
    std::cout<<szymon;
    return 0;
}
