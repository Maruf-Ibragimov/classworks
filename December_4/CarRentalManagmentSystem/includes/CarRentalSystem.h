
#ifndef CAR_RENTAL_SYSTEM_H                                                                      // this is header guard, it prevents the compiler from including the same header file more than once
#define CAR_RENTAL_SYSTEM_H

#include <Car.h>
#include <Customer.h>
#include <Rental.h>
#include <vector>
#include <string>

using namespace std; 

class CarRentalSystem{ 

    vector<Car> cars;
    vector<Customer> customers; 
    vector<Rental> rentals; 

    string name; 


    public:
    CarRentalSystem(string n  ); 


    bool addCar( string make, string model, int year, double price, bool isAvailable, string plateNumber );
 
    Car searchByPlateNumber(string plateNumber);
    bool updateCarPrice(string plateNumber, double price);
    bool updateCarAvailability(string plateNumber, bool isAvailable);
    bool updateCarModel(string plateNumber, string model);

    void deleteCar(string plateNumber);
    
    void displayAllCars() const;

    

    bool addCustomer( string name, int  phone, int age, string email, string licence);
    bool updateCustomerPhone(string driver, int number);
    bool updateCustomerEmail(string driver, string email);
    bool updateCustomerAge(string driver, int age);

    void displayAllCustomers() const;

 
   

     

  

    void rentCar(Car & car, const string drlicence);
    
    
    void returningCar(const Car &car);
    void displayAllRentedCars();

    void displayAllAvailableCars();

    void deleteCustomer(string driver);
    
    
    
};







#endif


