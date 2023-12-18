#ifndef CUSTOMER_H                                                                      // this is header guard, it prevents the compiler from including the same header file more than once
#define CUSTOMER_H




#include <string>
#include <vector>




using namespace std; 

class Customer { 

    string name; 
    int phone;
    int age;
    string email;
    string licenceNumber;

    public:
    Customer(string n, int p, int a, string e,string l);


    string getName() const;
    int getPhone() const;
    int getAge() const;
    string getEmail() const;
    string getLicenceNumber()const;

    void setName(string name);
    void setPhone(int phone);
    void setEmail(string email);
    void setLicenceNumber(string licenceNumber);
    void setAge(int age);

    void slam();
    
    

   
};






#endif
