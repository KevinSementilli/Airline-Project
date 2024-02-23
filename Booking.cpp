// Booking.cpp
#include "Booking.h"


Booking::Booking(Passenger* _passenger, Flight* _flight, string &_seatNumber){
    passenger = _passenger;
    flight = _flight;
    seatNumber = _seatNumber;

}

Booking::Booking() {
    seatNumber = "";
    passenger = nullptr;
    flight = nullptr;

}

Flight * Booking::getFlight() const {
    return flight;
}

Passenger* Booking::getPassenger() const {
    return passenger;
}

string Booking::getSeatNumber() const {
    return seatNumber;
}

void Booking::setFlight(Flight &_flight) {
    flight = &_flight;
}

void Booking::setPassenger(Passenger &_passenger) {
    passenger = &_passenger;
}

void Booking::setSeatNumber(string &_seatNumber) {
    seatNumber = _seatNumber;
}

void Booking::printBooking() {
    flight->displayFlightDetails();
    cout << "Seat Number " << seatNumber << endl;
}