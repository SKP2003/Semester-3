import java.util.List;

public interface Display {

    void displayRegUsersForAllFlight();

    void displayRegUsersForASpecificFlight(String flightNum);

    void displayHeaderForUsers(Flight flight, List<Customer> c);

    void displayFlightsRegByOneUser(String userID);

    void displayArtWork(int options);
}