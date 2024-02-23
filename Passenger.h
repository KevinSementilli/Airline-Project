#pragma once
#ifndef ASSIGNMENT2_PASSENGER_H
#define ASSIGNMENT2_PASSENGER_H

#include "iostream"
using namespace std;

class Booking;

// done
class Passenger {
public:
    Passenger();
    Passenger( string id,  string name,
               string address,  string phoneNumber);

    // getters
    string getID();
    string getName();
    string getAddress();
    string getPhoneNumber();

    // setters
    void setID(string&);
    void setName(string&);
    void setAddress(string&);
    void setPhoneNumber(string&);

    // booking function
    void addBooking(Booking*);
    void removeBooking(Booking*);
    void listBookings();

private:
    
    string id;
    string name;
    string address;
    string phoneNumber;
    int numBookings;
    Booking *books[];
};

#endif //ASSIGNMENT2_PASSENGER_H