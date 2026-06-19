#ifndef PERSON_H
#define PERSON_H


#include <iostream>
#include <string>

class Person{
protected:
    std::string username;
    std::string password;
public:
    Person(){
        username = "";
        password = "";
    }
    Person(std::string u, std::string p){
        username = u;
        password = p;
    }
    
    virtual ~Person(){};                //polymorphism
    virtual void showRole() const {
    std::cout << "Person: " << username << std::endl;
}
};

#endif