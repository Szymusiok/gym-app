#include <iostream>
#include <string>
#include "User.h"
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <limits>

//Function declaration
void clearInput();
void displayUsers(std::vector<User>users);
void displayMainMenu(std::vector<User>&users);
void addUser(std::vector<User>&users);
void displayUserMenu(User &user);
void changePersonalInformation(User &user);
void userDelete(std::vector<User> &users);
bool isValidNumber(std::string word);
//end of declaration

bool isValidNumber(std::string word){
    for (char const letter : word)
        if(std::isdigit(letter)==0)
            return false;
    return true;
}

void userDelete(std::vector<User> &users){
    system("cls");
    displayUsers(users);
    int select;
    std::cout<<"\nEnter '0' to return."<<std::endl;
    std::cout<<"Which user do you want to delete?: ";
    std::cin>>select;
    if(select==0)
        return;
    else if(select>0&&select<=users.size())
        users.erase(users.begin()+select-1);
    else
        std::cout<<"Wrong user."<<std::endl;
}

void changePersonalInformation(User &user){
    std::string newName;
    int age;

    std::cout<<"Enter new first name: ";
    std::cin.clear();
    getline(std::cin,newName);
    user.setUserFirstName(newName);

    std::cout<<"Enter new last name: ";
    getline(std::cin,newName);
    user.setUserLastname(newName);

    std::cout<<"Enter new age: ";
    std::cin>>age;
    user.setUserAge(age);
}

void displayUserMenu(User &user) {
    std::string select;
    while(select!="0") {
        system("cls");

        std::cout << user << std::endl;

        std::cout << "Training plan:" << std::endl;
        user.displayExercises();

        std::cout << std::endl;
        std::cout << std::left<<std::setw(25)<<"1. Add exercise."<<"4. Change personal information."<<std::endl;
        std::cout << std::left<<std::setw(25)<<"2. Delete exercise."<<"5. Change user weight."<<std::endl;
        std::cout << std::left<<std::setw(25)<<"3. Update exercise."<<"0. Return."<<std::endl;
        std::cout<<"Enter: ";
        getline(std::cin,select);

        try {
            if(select.size()>1)
                throw 1;
            if(select.size()==0)
                throw 3;

            switch (select[0]) {
                case '0':
                    break;
                case '1':
                    user.addExercise();
                    break;
                case '2':
                    user.deleteExercise();
                    break;
                case '3':
                    user.updateExercise();
                    break;
                case '4':
                    changePersonalInformation(user);
                    break;
                case '5':
                    std::cout << "Enter new weight:";
                    double weight;
                    user.setUserWeight(weight);
                    break;
                default:
                    std::cout << "Wrong choice, try again." << std::endl;
            }
        }
        catch(int error){
            switch(error) {
                case 1:
                    std::cerr<<"Wrong input! Try again."<<std::endl;
                    break;
                case 2:
                    std::cerr<<"Not a number! Try again."<<std::endl;
                    break;
                case 3:
                    std::cerr << "Wrong number! Try again." << std::endl;
                    break;
                case 4:
                    std::cerr<<"Tooo long, max length is 25!"<<std::endl;
                    break;
            }
        }
        system("pause");
    }
}

void addUser(std::vector<User>&users){
    system("cls");
    std::cout<<"Creating new user."<<std::endl<<std::endl;
//    std::cout<<"If you want to return, enter 0."<<std::endl;
//    int returnSign;
//    std::cin>>returnSign;

    std::string UserFirstName;
    std::string UserLastName;
    unsigned int UserAge;
    double UserWeight;

    std::cout << "Enter the first name: ";
    getline(std::cin,UserFirstName);
    std::cout << "Enter the last name: ";
    getline(std::cin,UserLastName);

    try {
        std::cout << "Enter user age: ";

        if(!(std::cin >> UserAge))
            throw 0;
        clearInput();

        std::cout << "Enter user weight: ";

        if(!(std::cin >> UserWeight))
            throw 0;
        clearInput();

        users.emplace_back(UserFirstName, UserLastName, UserAge, UserWeight);
        std::cout<<"\nCreated a new user!"<<std::endl<<std::endl;

    }
    catch(...){
        std::cout<<"Wrong input! Try again."<<std::endl;
    }
    clearInput();
    system("pause");
    system("cls");
}

void displayUsers(std::vector<User>users){
    int ID = 1;
    for (User user : users){
        std::cout << ID << ". " << user.getUserFirstName() << " " << user.getUserLastname() << std::endl;
        ID++;
    }
}

void displayMainMenu(std::vector<User>&users){
    std::string select="1";

    while(select!="x") {
        std::cout << "GYM PROGRESS TRACKING APP" << std::endl << std::endl;
        if (users.empty())
            std::cout << "There are no users, add some!" << std::endl << std::endl;
        else
            displayUsers(users);

        std::cout << std::left<<std::setw(40)<<"\nType '+' to add another profile."<<"Type '-' to delete user"<<
                                               "\nType '0' to exit."
                                               "\nEnter your profile: ";
        getline(std::cin,select);

        try {

            if(select!="+" && select!="-" && select!="0" && !isValidNumber(select))
                throw 1;

            //todo: change this down into something better -> switch case
            if(isValidNumber(select)) {
                if (!(std::stoi(select) >= 0 && std::stoi(select) <= users.size()))
                    throw 2;
                if(std::stoi(select)==0)
                    break;
                displayUserMenu(users.at(std::stoi(select) - 1));
            }
            else if(select=="+")
                addUser(users);
            else if(select=="-")
                userDelete(users);
        }
        catch(int error){
            switch(error) {
                case 1:
                    std::cerr << "Wrong input! Try again." << std::endl;
                    break;
                case 2:
                    std::cerr << "Profile does not exist! Try again." << std::endl;
                    break;
            }
        }

        system("pause");
        system("cls");
    }

}

void clearInput(){
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

int main() {
    std::vector<User>users;

    users.emplace_back("Szymon","Kubica",21,85);

    displayMainMenu(users);

    return 0;
}
