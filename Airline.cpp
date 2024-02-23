#include "Airline.h"

static int numFlights = 0;

Airline::Airline() {
    name = "";
    address = "";
    phoneNumber = "";
}

Airline::Airline(const string& _name,const string& _address, const string& _phoneNumber)
        : name(_name), address(_address), phoneNumber(_phoneNumber) {
    // Implementation of the constructor
}

Airline::~Airline() {
    delete *flights;
}

void Airline::addFlight(Flight* flight) {
    // Implementation to add a flight
    flights[numFlights] = flight;
    numFlights++;
}

void Airline::removeFlight(Flight* flight) {
    // Implementation to remove a flight
    int indexToRemove{};
    for (int i{}; i < numFlights; i++) {
        if(flights[i]->getIdentifier() == flight->getIdentifier()) {
            indexToRemove = i;
            break;
        }
    }

    if (indexToRemove < numFlights){
        numFlights--;
        for (int j = indexToRemove; j < numFlights; j++){
            flights[j] = flights[j+1];
        }
    }
}

void Airline::listAllFlights() const {
    // Implementation to list all flights
    cout << "\nList of all flight:\n";
    for (int i{}; i < numFlights; i++) {
        cout << "\nFlight " << i+1 << ":\n";
        cout << "----------\n";
        flights[i]->displayFlightDetails();
    }
}

void Airline::listFlightsDepartingFrom(const string& city) const {
    // Implementation to list flights departing from a given city
    cout << "\nList of all flights departing from " << city << endl;
    for (int i{}; i < numFlights; i++) {
        if (flights[i]->getDepartureCity() == city) {
            cout << "\nFlight " << i + 1 << ":\n";
            cout << "----------\n";
            flights[i]->displayFlightDetails();
        }
    }
}

void Airline::listFlightsArrivingTo(const string& city) const {
    // Implementation to list flights arriving to a certain city
    cout << "\nList of all flights arriving in " << city << endl;
    for (int i{}; i < numFlights; i++) {
        if (flights[i]->getArrivalCity() == city) {
            cout << "\nFlight " << i + 1 << ":\n";
            cout << "----------\n";
            flights[i]->displayFlightDetails();
        }
    }
}

void Airline::listFlightsDepartingAndArriving(const string& departureCity, const string& arrivalCity) const {
    // Implementation to list flights departing from and arriving to specific cities
    cout << "\nList of all flights departing from " << departureCity << " to " << arrivalCity << endl;
    for (int i{}; i < numFlights; i++) {
        if (flights[i]->getDepartureCity() == departureCity && flights[i]->getArrivalCity() == arrivalCity) {
            cout << "\nFlight " << i + 1 << ":\n";
            cout << "----------\n";
            flights[i]->displayFlightDetails();
        }
    }
}

int Airline::getNumberOfFlights() {
    // Implementation to return the number of flights
    return numFlights;
}