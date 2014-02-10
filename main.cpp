#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


//This Program uses classes and objects to read data of customers through an array of pointers
//It creates customers (IE a Bank customer) with a name, account number, and pin
//Creates a class Customer.
class Customer
{
    private:
        string account_number; //Customer's account number
        string name; //Customer's name
        int pin; //Customer's pin code

    public:
        Customer(); //Constructor
        string get_account_number(); //Returns the customer's account number
        string get_name(); //Returns the customer's name
        int get_pin(); //Returns the generated pin number
        void set_data(); //Reads and stores all data of a bank (account # and name) in objects. Cap is 100 Customers
        void generate_pin(); //Generates and stores a 4-digit pin number using random numbers. Range is 1111-9999
        void display_list(); //Displays a list of each employee record in neat fashion

};

//Constructor for object initialization
Customer::Customer()
{
}

//This returns the account number from the private variables
string Customer::get_account_number()
{
    return account_number;
}

//This returns the name from the private variables
string Customer::get_name()
{
    return name;
}

//This returns the pin from the private variables
int Customer::get_pin()
{
    return pin;
}

//This function inputs the data received via the console into the private member variables name and account number
void Customer::set_data()
{
    cout<<"\nPlease Enter The Customer's Fist and Last Name: ";
    getline (cin, name);
    cout<<"\nPlease Enter The Customer's 9 Digit Account Number (No Dashes): ";
    getline(cin, account_number);
}

//This function generates a random pin to be assigned to the private member variable
//It generates the pin within the range of 1111 to 9999.
void Customer::generate_pin()
{
    int random_pin;
    int lowest = 1111;
    int highest = 9999;
    int range = (highest - lowest)+1;
    random_pin = lowest+int(range*rand()/(RAND_MAX + 1.0));
    pin = random_pin;
}

//This function displays the account number, name, and pin of the customer it is being called upon
void Customer::display_list()
{
    cout<<"\n"<<account_number<<"\t  "<<name<<"\t\t"<<pin<<endl;
}

//The main function
int main()
{
    Customer* Population[100];
    Customer* pointerCustomer;

    string answer = "x";
    int counter = 0;
    int i = 0;

	//Loops through to enter customers into the Customer array. Has a cap of 100
    cout<<"Let's Enter Some Customers\n";
    do
        {
        Population[i] = new Customer();
        pointerCustomer = Population[i];

        pointerCustomer->set_data();
        pointerCustomer->generate_pin();

        i++;
        counter++;
        cout<<"\nType # to stop, press enter to add more customers: ";
        getline (cin, answer);
        } while (answer != "#");

    cout<<"               -----Customer List-----\n"<<endl;
    cout<<"Account Number\t Customer Name\t\t Pin Number";

	//Displays the information by looping through the population array
    for(int i1 = 0; i1<counter; i1++)
    {
        Population[i1]->display_list();
    }

	//Destroys the allocated memory for the pointerCustomer object that was created.
    for(int i2 = 0; i2<counter; i2++)
    {
        delete Population[i2];
    }

    return 0;
}
