// Flight.cpp
#include "Flight.h"
#include "Booking.h"

// default constructor
Flight::Flight() {
    identifier = "";
    departureCity = "";
    arrivalCity = "";
    departureTime = nullptr;
    arrivalTime = nullptr;
    duration = 0;
    numBookings = 0;
}

// constructor by value
Flight::Flight(const string& _identifier, const string& _departureCity,
               const string& _arrivalCity, Time* _departureTime, Time* _arrivalTime, int _duration)
        : identifier(_identifier), departureCity(_departureCity), arrivalCity(_arrivalCity),
          departureTime(_departureTime), arrivalTime(_arrivalTime), duration(_duration) {
    // Implementation of the constructor
    numBookings = 0;
}

// copy constructor
Flight::Flight(Flight& other) {
    identifier = other.getIdentifier();
    departureCity = other.getDepartureCity();
    arrivalCity = other.getArrivalCity();
    *departureTime = *other.getDepartureTime();
    *arrivalTime = *other.getArrivalTime();
    duration = other.getDuration();
    numBookings = other.getNumBookings();
}

// deconstructor
Flight::~Flight() {

    delete departureTime;
    delete arrivalTime;
}


void Flight::displayFlightDetails() const {
    // Implementation to display flight details
    cout << "Flight ID " << identifier << "\tfrom " << departureCity << " to " << arrivalCity;
    cout << "\nDeparture time: ";
    departureTime->display();
    cout << "\tEstimated arrival time: ";
    arrivalTime->display();
    cout << "\nEstimated travel time: " << duration << endl;
    cout << "Total flight bookings " << numBookings << endl;
}


// getters
const string& Flight::getIdentifier() const {
    return identifier;
}

const string& Flight::getDepartureCity() const {
    return departureCity;
}

const string& Flight::getArrivalCity() const {
    return arrivalCity;
}

int Flight::getDuration() const {
    return duration;
}

Time * Flight::getDepartureTime() const {
    return departureTime;
}

Time* Flight::getArrivalTime() const {
    return arrivalTime;
}

int Flight::getNumBookings() const {
    return numBookings;
}

// setters
void Flight::setIdentifier(string & _identifier) {
    identifier = _identifier;
}

void Flight::setDepartureCity(string& _departureCity) {
    departureCity = _departureCity;
}

void Flight::setArrivalCity(string& _arrivalCity) {
    arrivalCity = _arrivalCity;
}

void Flight::setDuration(int _duration) {
    duration = _duration;
}

void Flight::setDepartureTime(Time* _departureTime) {
    departureTime = _departureTime;
}

void Flight::setArrivalTime(Time* _arrivalTime) {
    arrivalTime = _arrivalTime;
}

void Flight::addBooking(Booking *booking) {
    books[numBookings] = booking;
    numBookings++;
}

void Flight::removeBooking(Booking *booking) {

    int indexToRemove = 0;
    for (int i{}; i < numBookings; i++) {
        if(books[i]->getSeatNumber() == booking->getSeatNumber()) {
            indexToRemove = i;
        }
    }
    if (indexToRemove < numBookings) {
        numBookings--;
        for(int j = indexToRemove; j < numBookings; j++) {
            books[j] = books[j+1];
        }
    }
}

void Flight::listBookings() const {
    cout << "\nBooking for flight " << identifier << ":\n";
    cout << "------------------------\n";
    if (numBookings == 0) {
        cout << "No bookings available.\n";
    } else {
        for (int i{}; i < numBookings; i++) {
            cout << "Passenger " << books[i]->getPassenger()->getName();
            cout << " in seat " << books[i]->getSeatNumber() << endl;
        }
    }
}
