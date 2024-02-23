#include "Airline.h"
#include "Booking.h"

int main() {

    // initialize flights
    Time *departure_time = new Time(0,0);
    Time *arrival_time = new Time(5,30);
    Time *dt = new Time(12,00);
    Time *at = new Time(17, 00);
    Flight flight1("43", "Montreal", "Toronto", departure_time, arrival_time, 5);
    Flight flight2("505", "Montreal", "Vancouver", departure_time, arrival_time, 5);
    Flight flight3("420", "California", "Montreal", dt, at, 5);

    // initialize airline
    string name = "Air Canada";
    string address = "737 rue Taba";
    string phoneNumber = "514-666-2593";
    Airline AirCanada(name, address, phoneNumber);

    // add flights to airline
    AirCanada.addFlight(&flight1);
    AirCanada.addFlight(&flight2);
    AirCanada.addFlight(&flight3);

    // initialize passengers
    string id = "001", name1 = "Kevin", address1 = "rue Christoph", phoneNumber1 = "514-555-1522";
    Passenger pass1(id,name1,address1,phoneNumber1);
    Passenger pass2("002", "Marco", "street name", "514-552-5658");

    // initialize bookings
    string seatNumber1 = "55", seatNumber2 = "66", seatNumber3 = "125";
    Booking book1(&pass1, &flight1, seatNumber1);
    Booking book2(&pass1, &flight2, seatNumber2);
    Booking book3(&pass2, &flight3, seatNumber3);

    // set bookings to passenger 1 and display details
    pass1.addBooking(&book1);
    pass1.addBooking(&book2);
    pass1.listBookings();

    // set bookings to passenger 2 and display details
    pass2.addBooking(&book3);
    pass2.listBookings();

    // passenger 1 canceled their first booking
    // display results of cancellation
    pass1.removeBooking(&book1);
    pass1.listBookings();
    flight1.listBookings();

    return 0;
}