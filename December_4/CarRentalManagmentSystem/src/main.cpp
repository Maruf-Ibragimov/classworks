#include <iostream>
#include <chrono> // is for date and time managment
#include <ctime>


#include <CarRentalSystem.h>


using namespace std;


bool getUserPromptString(string prompt, string* input) {
    cout << "Enter " << prompt << ": ";
    cin >> *input;
    return true;
}

bool getUserPromtInt(string prompt , int *input){
    cout<<"Enter "<<prompt<<": ";
    cin>>*input;
    return true;
}

bool getUserPromtDouble(string prompt , double *input){
    cout<<"Enter "<<prompt<<": ";
    cin>>*input;
    return true;
}



void mainPrompt( int* choice){
    cout<<"==========Welcome to Fenix Car Rental Company============="<<"\n";
    cout<<"1. Add a car"<<endl;
    cout<<"2. Add a customer"<<endl;
    cout<<"3. Rent a car"<<endl;
    cout<<"4. Return a car"<<endl;
    cout<<"5. Display all cars"<<endl;
    cout<<"6. Display all available cars"<<endl;
    cout<<"7. Display all rented cars"<<endl;
    cout<<"8. Display all customers"<<endl;
    cout<<"9. Search a car by its plate number."<<endl;
    cout<<"10.Editing car's details."<<endl;
    cout<<"11.Exit"<<endl;
    cout<<"============================================================="<<"\n";
    cin>>*choice;
}



int main() {
    
    
    CarRentalSystem carRentalSystem("Fenix Car Rental Company");   

    int choice;

    int* pChoice = &choice;
    mainPrompt(pChoice);

    do
    {
        switch (choice)
        {
        case 1:
            {
            string make, model, plateNumber;
            int year;
            double price;
            
            getUserPromptString("Company", &make);
            getUserPromptString("Model", &model);
            getUserPromptString("Plate Number",&plateNumber);
            getUserPromtInt("Year",&year);
            getUserPromtDouble("Price",&price);


            carRentalSystem.addCar(make,model,year,price,true,plateNumber);
            carRentalSystem.displayAllCars();
            cout<<endl;
            cout<<"New car has been added to the system successefully.\n";
            cout<<endl;
            mainPrompt(pChoice);
            break;

            }
        case 2:
        {
            string name, email, licence;
            int phone, age;

            getUserPromptString("name",&name);
            getUserPromtInt("phone number",&phone);
            getUserPromtInt("age",&age);
            getUserPromptString("email",&email);
            getUserPromptString("ID number",&licence);

            carRentalSystem.addCustomer(name,phone,age,email,licence);
            carRentalSystem.displayAllCustomers();
            cout<<endl;
            cout<<"New customer has been added to the system successefully.\n";
            cout<<endl;
            mainPrompt(pChoice);
            break;
        
        }
        case 3:
        {
            string make, model, plateNumber;
            int year;
            double price;

            string dr;
           
           getUserPromptString("driver licence number", &dr);
            
            
            getUserPromptString("Plate Number",&plateNumber);
            getUserPromtDouble("Price",&price);

            Car carToRent(make,model,year,price,true,plateNumber);
          
           carRentalSystem.rentCar(carToRent, dr);
         
          mainPrompt(pChoice);
          break;
        }
        case 4:
        {
         string plateNumber;
         getUserPromptString("Car's plate number that needs to be returned",&plateNumber);

         Car carToReturn = carRentalSystem.searchByPlateNumber(plateNumber);
         if (carToReturn.getPlateNumber() == plateNumber) {
         carRentalSystem.returningCar(carToReturn);
        
        } else {
        cout << "Car was not found or it was not rented." << endl;
        }
         mainPrompt(pChoice);
        break;
        }

        
        case 5:
        {   
            cout<<endl;
            cout<<"All the cars on the system.";
            cout<<endl;
            carRentalSystem.displayAllCars();
            
            cin.ignore();
            mainPrompt(pChoice);
            break;
        }
        case 6:
        {  
           cout<<endl;
           cout<<" Currently, All Avaliable Cars.";
            cout<<endl;

           carRentalSystem.displayAllAvailableCars();
           cin.ignore();
           mainPrompt(pChoice);
           break; 
            
        }
        case 7:
        {
            cout<<endl;
            cout<<"All rented cars List.";
            cout<<endl;
            carRentalSystem.displayAllRentedCars();
            cin.ignore();
            mainPrompt(pChoice);
            break;
        }

        case 8:
        {
            cout<<endl;
            cout<<"All customer that system has.";
            cout<<endl;
            carRentalSystem.displayAllCustomers();
            cin.ignore();
            mainPrompt(pChoice);
            break;
        }
        case 9:
        {
            
             string plate;
            getUserPromptString("plate number",&plate);
            Car searchedCar = carRentalSystem.searchByPlateNumber(plate);
             if (searchedCar.getPlateNumber() == plate) {
              
              cout << "Company Name: " << searchedCar.getMake() << "\n";
              cout << "Model of a car: " << searchedCar.getModel() << "\n";
              cout << "Plate number: " << searchedCar.getPlateNumber() << "\n";
              cout << "Year of car: " << searchedCar.getYear() << "\n";
              cout << "Price of a car: $" << searchedCar.getPrice() << "\n";
              } else {
              cout << "Car not found.\n";
             }
             cout<<endl;
             cout << "Here is the car that you have been searching:\n";
             cin.ignore();
            mainPrompt(pChoice);
            break; 
            }
           
          
         
        
        case 10:
        {

         int option;
         cout<<endl;
         cout<<"=======Here is the list to update or edit.======"<<endl;
         cout<<"1.Update car's price."<<endl;
         cout<<"2.Update car's model."<<endl;
         cout<<"3.Update car's avaliablity."<<endl;
         cout<<"4.Back to Main menu."<<endl;
         cout<<"================================================"<<endl;
         
         cout<<"Enter your choice: ";
         cin>>option;
        
        

            switch (option)
            {
            case 1:
            {
            string plateNum;
            double price;
            getUserPromptString("the plate number of the car to update a prrice",&plateNum);
            getUserPromtDouble("the new price",&price);
            
            carRentalSystem.updateCarPrice(plateNum,price);
            carRentalSystem.displayAllCars();

            cout<<endl;
            cout<<"Car with new price.\n";
            cout<<endl;
            
            break;
            }
            case 4:
            {
             string plate;
            bool avaliable= false;
            getUserPromptString("the plate number of the car",&plate);
            
            carRentalSystem.updateCarAvailability(plate,avaliable);
            carRentalSystem.displayAllCars();
            cout<<endl;
            cout<<"Now it is avaliable.";
            cout<<endl;
            break;
            }
            
            default:
                break;
            }
            cin.ignore();
            mainPrompt(pChoice);
            break;
        }
        
        
        }




    } while (choice != 11);
    



    return 0;
}












