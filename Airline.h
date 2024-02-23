#pragma once
#ifndef ASSIGNMENT2_AIRLINE_H
#define ASSIGNMENT2_AIRLINE_H

#include "Flight.h"

class Airline {
public:

    // constructors
    Airline();
    Airline(const string&, const string&, const string&);
    ~Airline(); // destructor

    void addFlight(Flight*);
    void removeFlight(Flight*);
    void listAllFlights() const;
    void listFlightsDepartingFrom(const string& city) const;
    void listFlightsArrivingTo(const string& city) const;
    void listFlightsDepartingAndArriving(const string& departureCity, const string& arrivalCity) const;
    [[nodiscard]] static int getNumberOfFlights() ;

private:
    string name;
    string address;
    string phoneNumber;
    Flight* flights[];
};

#endif //ASSIGNMENT2_AIRLINE_H