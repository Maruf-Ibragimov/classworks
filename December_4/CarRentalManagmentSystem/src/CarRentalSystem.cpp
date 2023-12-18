#include <CarRentalSystem.h>

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

CarRentalSystem::CarRentalSystem(string n): name(n){};



bool CarRentalSystem::addCar(string make, string model, int year, double price, bool isAvailable, string plateNumber) {
    Car car(make, model, year, price, isAvailable, plateNumber);
    cars.push_back(car);
    return true;
}



bool CarRentalSystem::addCustomer( string name, int phone, int age, string email, string licence){

    Customer customer(name, phone,age, email,licence);
    customers.push_back(customer);
    

    return true;
}

bool CarRentalSystem::updateCustomerPhone(string driver, int number){
    for (auto &customer : customers)
    {
        if(customer.getLicenceNumber() == driver){
            customer.setPhone(number);
            return true;
        }
    }
    return false;
    
}

bool CarRentalSystem::updateCustomerEmail(string driver, string newEmail){
     for(auto &customer : customers){
        if(customer.getLicenceNumber() == driver)
        {
             customer.setEmail(newEmail);
             return true;
        }
     }
     return false;
}

bool CarRentalSystem::updateCustomerAge(string driver, int  new_age){
     for (auto &customer : customers)
     {
        if(customer.getLicenceNumber() == driver)
        {
            customer.setAge(new_age);
            return true;
        }
     }
     return false;
     
}

Car CarRentalSystem::searchByPlateNumber(string plateNumber){
    for( auto &car : cars)
    {
      if(car.getPlateNumber() == plateNumber)
      {
        return car;
      }
    }
   
    
}


bool CarRentalSystem::updateCarPrice(string plateNumber, double price) {
    for (auto &car : cars) {
        if (car.getPlateNumber() == plateNumber) {
            car.setPrice(price);
            return true;
        }
    }

    return false; 
}

bool CarRentalSystem::updateCarModel(string plateNumber, string newModel){
    for (auto &all: cars)
    {
       if(all.getPlateNumber()  == plateNumber){
          all.setModel(newModel);
          return true;
       }
    }
    return false;
}





bool CarRentalSystem::updateCarAvailability(string plateNumber, bool isAvailable){
    Car car = searchByPlateNumber(plateNumber);
    
        car.setIsAvailable(isAvailable);
        return true;
    
}


void CarRentalSystem::deleteCar(string plateNumber){
   for(auto it = cars.begin() ; it!=cars.end(); ++it)
   {
       if(it->getPlateNumber() == plateNumber)
       {
        it = cars.erase(it);
        cout<<"Car has been deleted from the system.";
        cout<<endl;
        return;
       }
   }
   cout<<"Car with following plate number has not been found.";
    cout<<endl;
}

void CarRentalSystem::deleteCustomer(string driver){
    for(auto it = customers.begin(); it != customers.end(); ++it){
        if(it->getLicenceNumber() == driver)
        {
            it = customers.erase(it);
            cout<<"Customer has been deleted from the system."<<endl;
            return;
        }
    }
    cout<<"Customer with a following driver licence number has not been found."<<endl;
}


void CarRentalSystem::displayAllCars() const{
    for (int i = 0; i < cars.size(); i++){
       cout<<endl;
       cout<<"Company Name: "<<cars[i].getMake()<<"\n";
       cout<<endl;
       cout<<"Model of a car: "<<cars[i].getModel()<<"\n";
       cout<<endl;
       cout<<"Plate number: "<<cars[i].getPlateNumber()<<"\n";
       cout<<endl;
       cout<<"Year of Car: "<<cars[i].getYear()<<"\n";
       cout<<endl;
       cout<<"Price of a car: $"<<cars[i].getPrice()<<"\n";
       cout<<endl;
    }
}

void CarRentalSystem::displayAllCustomers()const{
    for(int i=0;i<customers.size();i++){
       cout<<endl;
       cout<<"Name of a cutomer: "<<customers[i].getName()<<"\n";
       cout<<endl;
       cout<<"Phone number: "<<customers[i].getPhone()<<"\n";
       cout<<endl;
       cout<<"Email Address: "<<customers[i].getEmail()<<"\n";
       cout<<endl;
       cout<<"Driver licence number: "<<customers[i].getLicenceNumber()<<"\n";
       cout<<endl;
    }
}



void CarRentalSystem::rentCar(Car &car, const string dr) 

{

    for(auto & cs : customers)
    {
        if(cs.getLicenceNumber() == dr)
        {
            auto it = std::find(cars.begin(), cars.end(), car);

    if (it != cars.end() && it->getIsAvailable()) {
        it->setIsAvailable(false);
        cout << endl;
        cout << "Car rented successfully." << endl;
        cout << endl;
    } else if (it != cars.end() && !it->getIsAvailable()) {
        cout << "Car is not available to rent." << endl;
        cout << endl;
    } else {
        cout << "Car not found." << endl;
        cout << endl;
    }
        }
    }
    
}


void CarRentalSystem::returningCar(const Car &car) {
    for (auto &c : cars) {
        if (c.getPlateNumber() == car.getPlateNumber() && !c.getIsAvailable()) {
            c.setIsAvailable(true);  // Mark the car as available
            cout << endl;
            cout << "Car has been returned to the system." << endl;
            cout << endl;
            return;
        }else{
    cout << endl;
    cout << "Error. No such car exist." << endl;
    cout << endl;
    }
    }
    
}


void CarRentalSystem::displayAllRentedCars() {
    bool foundRentedCar = false;

    for ( auto &car : cars) {
        if (!car.getIsAvailable()) {
            cout << endl;
            cout << "Company Name: " << car.getMake() << "\n";
            cout << "Model of a car: " << car.getModel() << "\n";
            cout << "Plate number: " << car.getPlateNumber() << "\n";
            cout << "Year of a Car: " << car.getYear() << "\n";
            cout << "Price of a car: $" << car.getPrice() << "\n";
            cout << endl;

            foundRentedCar = true;  
        }
    }

    if (!foundRentedCar) {
        cout << endl;
        cout << "Not found." << endl;
        cout << endl;
    }
}




void CarRentalSystem::displayAllAvailableCars()  {
    bool foundAvailableCar = true;

    for ( auto &car : cars) {
        if (car.getIsAvailable()) {
            cout << endl;
            cout << "Company Name: " << car.getMake() << "\n";
            cout << "Model of a car: " << car.getModel() << "\n";
            cout << "Plate number: " << car.getPlateNumber() << "\n";
            cout << "Year of a Car: " << car.getYear() << "\n";
            cout << "Price of a car: $" << car.getPrice() << "\n";
            cout << endl;

            foundAvailableCar = false;
        }
    }
   
}











