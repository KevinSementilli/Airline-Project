#pragma once
#ifndef ASSIGNMENT2_BOOKING_H
#define ASSIGNMENT2_BOOKING_H

#include "Time.h"
#include "Flight.h"
#include "Passenger.h"

class Flight;
class Passenger;

class Booking {
public:
    Booking();
    Booking(Passenger*, Flight *, string&);

    // getters
    [[nodiscard]] Flight * getFlight() const;
    [[nodiscard]] Passenger* getPassenger() const;
    [[nodiscard]] string getSeatNumber() const;

    // setters
    void setFlight(Flight&);
    void setPassenger(Passenger&);
    void setSeatNumber(string&);

    void printBooking();

private:
    Passenger* passenger;
    Flight* flight;
    string seatNumber;

};

#endif //ASSIGNMENT2_BOOKING_H