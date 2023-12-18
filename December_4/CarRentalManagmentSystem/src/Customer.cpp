#include <Customer.h>
#include <Car.h>

#include <string>



using namespace std;


Customer::Customer(string n, int p, int a, string e,string l)
    : name(n), phone(p), age(a), email(e) , licenceNumber(l){}


string Customer::getName() const {
    return name;
}

int  Customer::getPhone() const {
    return phone;
}

int Customer::getAge()const {
    return age;
}

string Customer::getEmail() const {
    return email;
}

string Customer::getLicenceNumber() const{
    return licenceNumber;
}

void Customer::setName(string name) {
    this->name = name;
}

void Customer::setPhone(int phone) {
    this->phone = phone;
}

void Customer::setAge(int age){
    this->age == age;
}
void Customer::setEmail(string email) {
    this->email = email;
}

void Customer::setLicenceNumber(string licence){
    this->licenceNumber = licence;
}



