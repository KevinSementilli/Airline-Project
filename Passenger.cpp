// Passenger.cpp
#include "Passenger.h"
#include "Booking.h"
#include <utility>

Passenger::Passenger() {
    id = "";
    name = "";
    address = "";
    phoneNumber = "";
    numBookings = 0;
}

//constructor
Passenger::Passenger( string _id,  string _name, string _address,  string _phoneNumber)
        : id(std::move(_id)), name(std::move(_name)), address(std::move(_address)), phoneNumber(std::move(_phoneNumber)) {
    numBookings = 0;

}

// getters
string Passenger::getID() {
    return id;
}

string Passenger::getName() {
    return name;
}

string Passenger::getAddress() {
    return address;
}

string Passenger::getPhoneNumber() {
    return phoneNumber;
}

// setters
void Passenger::setID(string& _id) {
    id = _id;
}

void Passenger::setName(string &_name) {
    name = _name;
}

void Passenger::setAddress(string &_address) {
    address = _address;
}

void Passenger::setPhoneNumber(string &_phoneNumber) {
    phoneNumber = _phoneNumber;
}

void Passenger::addBooking(Booking *booking){
    books[numBookings] = booking;
    (booking->getFlight())->addBooking(booking);
    numBookings ++;
}

void Passenger::removeBooking(Booking *booking){

    // invoke removeBooking from flight clas, so you don't have to remove
    // the booking for passenger and flight
    (booking->getFlight())->removeBooking(booking);

    int indexToRemove{};
    for (int i{}; i < numBookings; i++){
        if(books[i]->getSeatNumber() == booking->getSeatNumber()){
            indexToRemove = i;
        }
    }

    if(indexToRemove < numBookings) {
        numBookings--;
        for (int j = indexToRemove; j < numBookings; j++) {
            books[j] = books[j+1];
        }
    }
}

void Passenger::listBookings() {

    cout << "\nList of Bookings for " << name << ":\n";
    for (int i{}; i < numBookings; i++) {
        cout << "\nBooking " << i+1 << endl;
        cout << "----------\n";
        books[i]->printBooking();
    }
}