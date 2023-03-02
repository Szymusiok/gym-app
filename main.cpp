#include <iostream>
#include <string>
#include "User.h"
#include <vector>
#include <stdlib.h>
#include <iomanip>
#include <limits>
#include <fstream>

//Function declaration
void displayUsers(std::vector<User>users);
void displayMainMenu(std::vector<User>&users);
void addUser(std::vector<User>&users);
void displayUserMenu(User &user);
void changePersonalInformation(User &user);
void changeUserWeight(User &user);
void userDelete(std::vector<User> &users);
void readUsers(std::vector<User> &users);
void saveExercises(User user);
bool isValidNumber(std::string word);
//end of declaration

bool isValidNumber(std::string word){
    for (char const letter : word)
        if(std::isdigit(letter)==0)
            return false;
    return true;
}

void readUsers(std::vector<User> &users){
    std::fstream users_database;
    users_database.open("users_database.txt",std::ios::in);
    if(!users_database)
        throw 1;
    std::string firstName, lastName,weight,age,read;
    std::string::size_type pos;

    while(getline(users_database,read)){
        if(read=="||ENDOFUSERS||")
            return;
        pos = read.find('|');
        firstName = read.substr(0,pos);
        read.erase(0,pos+1);

        pos = read.find('|');
        lastName = read.substr(0,pos);
        read.erase(0,pos+1);

        pos = read.find('|');
        age = read.substr(0,pos);
        read.erase(0,pos+1);

        weight = read;



        users.push_back(User(firstName,lastName,std::stoi(age),std::stod(weight)));


    }
}

void saveExercises(User user){

}

void userDelete(std::vector<User> &users){
    system("cls");
    displayUsers(users);
    std::string select;
    std::cout<<"\nEnter '0' to return."<<std::endl;
    std::cout<<"Which user do you want to delete?: ";
    getline(std::cin,select);

    if(isValidNumber(select)) {
        if (!(std::stoi(select) > 0 && std::stoi(select) <= users.size()))
            throw 2;
    }else
        throw 1;

    switch(std::stoi(select)){
        case 0:
            break;
        default:
            users.erase(users.begin()+std::stoi(select)-1);
    }
    std::cout<<"User deleted succesfully!"<<std::endl;
}

void changePersonalInformation(User &user){
    std::string newName,age;

    std::cout<<"Enter new first name: ";
    getline(std::cin,newName);
    user.setUserFirstName(newName);

    std::cout<<"Enter new last name: ";
    getline(std::cin,newName);
    user.setUserLastname(newName);

    std::cout<<"Enter new age: ";
    getline(std::cin,age);
    if(!isValidNumber(age))
        throw 2;
    user.setUserAge(std::stoi(age));
}

void changeUserWeight(User &user){
    std::cout << "Enter new weight:";
    std::string weight;
    getline(std::cin,weight);
    if(!isValidNumber(weight))
        throw 2;
    user.setUserWeight(std::stoi(weight));
}

void displayUserMenu(User &user) {
    std::string select;
    while(select!="0") {
        system("cls");

        std::cout << user << std::endl;

        std::cout << "Training plan:" << std::endl;
        user.displayExercises();

        std::cout << std::endl;
        std::cout << std::left<<std::setw(25)<<"1. Add exercise."<<std::left<<std::setw(35)<<"4. Change personal information."<<"S. Save exercises"<<std::endl;
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
                    changeUserWeight(user);
                    break;
                case 'S':
                    saveExercises(user);
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
        catch(...) {
            std::cout << "Unexpected error!" << std::endl;
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

        std::cout << "Enter user weight: ";

        if(!(std::cin >> UserWeight))
            throw 0;

        users.emplace_back(UserFirstName, UserLastName, UserAge, UserWeight);
        std::cout<<"\nCreated a new user!"<<std::endl<<std::endl;

    }
    catch(...){
        std::cout<<"Wrong input! Try again."<<std::endl;
    }
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
    try {
        readUsers(users);
    }
    catch(int error){
        std::cout<<"file did not open!"<<std::endl;
    }
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

            if(isValidNumber(select))
                if (!(std::stoi(select) >= 0 && std::stoi(select) <= users.size()))
                    throw 2;
            if(select.size()>1)
                throw 1;

            switch(select[0]){
                case '0':
                    return;
                case '+':
                    addUser(users);
                    break;
                case '-':
                    userDelete(users);
                    break;
                default:
                    displayUserMenu(users.at(std::stoi(select)-1));
            }
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
        catch(...) {
            std::cout << "Unexpected error!" << std::endl;
        }

        system("pause");
        system("cls");
    }

}

int main() {
    std::vector<User>users;
    users.emplace_back("Szymon","Kubica",21,85);

    displayMainMenu(users);

    return 0;
}
