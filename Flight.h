#pragma once
#ifndef ASSIGNMENT2_FLIGHT_H
#define ASSIGNMENT2_FLIGHT_H

#include "Time.h"

class Booking;

class Flight {
public:

    // constructors
    Flight();
    Flight(const string& identifier, const string& departureCity,
           const string& arrivalCity, Time* departureTime, Time* arrivalTime, int duration);
    Flight(Flight& other); // copy constructor
    ~Flight(); // destructor

    // getters
    [[nodiscard]] const string& getIdentifier() const;
    [[nodiscard]] const string& getDepartureCity() const;
    [[nodiscard]] const string& getArrivalCity() const;
    [[nodiscard]] int getDuration() const;
    [[nodiscard]] Time * getDepartureTime() const;
    [[nodiscard]] Time* getArrivalTime() const;
    [[nodiscard]] int getNumBookings() const;

    // setters
    void setIdentifier(string&);
    void setDepartureCity(string&);
    void setArrivalCity(string&);
    void setDuration(int);
    void setDepartureTime(Time*);
    void setArrivalTime(Time*);

    // other member functions
    void displayFlightDetails() const;
    void addBooking(Booking*);
    void removeBooking(Booking*);
    void listBookings() const;

private:
    string identifier;
    string departureCity;
    string arrivalCity;
    Time* departureTime;
    Time* arrivalTime;
    int duration;
    int numBookings;
    Booking* books[];
};

#endif //ASSIGNMENT2_FLIGHT_H