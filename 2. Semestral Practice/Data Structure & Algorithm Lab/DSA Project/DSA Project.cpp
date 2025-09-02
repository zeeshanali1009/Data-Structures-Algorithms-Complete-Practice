#include <iostream>
#include <algorithm>

using namespace std;

// User class to represent different user roles
class User {
public:
    User(const string& username, const string& password, const string& role);

    bool authenticate(const string& enteredPassword) const;

    string getUsername() const;
    string getRole() const;

private:
    string username;
    string password;
    string role;
};

// Vehicle class to represent vehicle details
class Vehicle {
public:
    Vehicle(const string& registrationNumber, const string& type, const string& owner);

    string getRegistrationNumber() const;
    string getType() const;
    string getOwner() const;

private:
    string registrationNumber;
    string type;
    string owner;
};

// Vehicle Registration System class
class VehicleRegistrationSystem {
public:
    // Function to register a new vehicle
    void registerVehicle(const string& registrationNumber, const string& type, const string& owner);

    // Function to display all registered vehicles
    void displayAllVehicles() const;

    // Function to search for a vehicle by registration number
    void searchByRegistrationNumber(const string& registrationNumber) const;

    // Function to update vehicle details
    void updateVehicle(const string& registrationNumber, const string& newType, const string& newOwner);

    // Function to delete a vehicle
    void deleteVehicle(const string& registrationNumber);

    // Function to sort vehicles by registration number
    void sortVehiclesByRegistrationNumber();

    // Function to generate a report
    void generateReport() const;

    // Function to show the menu
    void showMenu();

    // Function to process user's choice
    void processChoice(int choice);

    // Function for user authentication
    void authenticateUser();

private:
    static const int MAX_VEHICLES = 100;  // Maximum number of vehicles (adjust as needed)
    Vehicle vehicles[MAX_VEHICLES];        // Array to store registered vehicles
    int numVehicles = 0;                   // Current number of registered vehicles
    User currentUser;                      // Current logged-in user
    bool isAuthenticated = false;          // Flag to track user authentication status
};

// Implementation of User class
User::User(const string& username, const string& password, const string& role)
    : username(username), password(password), role(role) {}

bool User::authenticate(const string& enteredPassword) const {
    return password == enteredPassword;
}

string User::getUsername() const {
    return username;
}

string User::getRole() const {
    return role;
}

// Implementation of Vehicle class
Vehicle::Vehicle(const string& registrationNumber, const string& type, const string& owner)
    : registrationNumber(registrationNumber), type(type), owner(owner) {}

string Vehicle::getRegistrationNumber() const {
    return registrationNumber;
}

string Vehicle::getType() const {
    return type;
}

string Vehicle::getOwner() const {
    return owner;
}

// Implementation of VehicleRegistrationSystem class
void VehicleRegistrationSystem::registerVehicle(const string& registrationNumber, const string& type, const string& owner) {
    if (numVehicles < MAX_VEHICLES) {
        vehicles[numVehicles].registrationNumber = registrationNumber;
        vehicles[numVehicles].type = type;
        vehicles[numVehicles].owner = owner;
        ++numVehicles;
        cout << "Vehicle registered successfully." << endl;
    } else {
        cout << "Maximum number of vehicles reached. Registration failed." << endl;
    }
}

void VehicleRegistrationSystem::displayAllVehicles() const {
    if (numVehicles == 0) {
        cout << "No vehicles registered." << endl;
    } else {
        cout << "Registered Vehicles:" << endl;
        for (int i = 0; i < numVehicles; ++i) {
            cout << "Registration Number: " << vehicles[i].getRegistrationNumber() << ", Type: " << vehicles[i].getType()
                 << ", Owner: " << vehicles[i].getOwner() << endl;
        }
    }
}

void VehicleRegistrationSystem::searchByRegistrationNumber(const string& registrationNumber) const {
    bool found = false;
    for (int i = 0; i < numVehicles; ++i) {
        if (vehicles[i].getRegistrationNumber() == registrationNumber) {
            found = true;
            cout << "Vehicle found - Registration Number: " << vehicles[i].getRegistrationNumber()
                 << ", Type: " << vehicles[i].getType() << ", Owner: " << vehicles[i].getOwner() << endl;
            break;
        }
    }

    if (!found) {
        cout << "Vehicle not found." << endl;
    }
}

void VehicleRegistrationSystem::updateVehicle(const string& registrationNumber, const string& newType, const string& newOwner) {
    for (int i = 0; i < numVehicles; ++i) {
        if (vehicles[i].getRegistrationNumber() == registrationNumber) {
            vehicles[i].getType() = newType;
            vehicles[i].getOwner() = newOwner;
            cout << "Vehicle updated successfully." << endl;
            return;
        }
    }

    cout << "Vehicle not found." << endl;
}

void VehicleRegistrationSystem::deleteVehicle(const string& registrationNumber) {
    for (int i = 0; i < numVehicles; ++i) {
        if (vehicles[i].getRegistrationNumber() == registrationNumber) {
            for (int j = i; j < numVehicles - 1; ++j) {
                vehicles[j] = vehicles[j + 1];
            }
            --numVehicles;
            cout << "Vehicle deleted successfully." << endl;
            return;
        }
    }

    cout << "Vehicle not found." << endl;
}

void VehicleRegistrationSystem::sortVehiclesByRegistrationNumber() {
    for (int i = 0; i < numVehicles - 1; ++i) {
        for (int j = 0; j < numVehicles - i - 1; ++j) {
            if (vehicles[j].getRegistrationNumber() > vehicles[j + 1].getRegistrationNumber()) {
                swap(vehicles[j], vehicles[j + 1]);
            }
        }
    }

    cout << "Vehicles sorted by registration number." << endl;
}

void VehicleRegistrationSystem::generateReport() const {
    cout << "Generating report..." << endl;
    // Implement report generation logic
}

void VehicleRegistrationSystem::showMenu() {
    cout << "-----------------------------" << endl;
    cout << "Vehicle Registration System" << endl;
    cout << "-----------------------------" << endl;
    cout << "1. Register a Vehicle" << endl;
    cout << "2. Display All Vehicles" << endl;
    cout << "3. Search for a Vehicle" << endl;
    cout << "4. Update Vehicle Details" << endl;
    cout << "5. Delete a Vehicle" << endl;
    cout << "6. Sort Vehicles by Registration Number" << endl;
    cout << "7. Generate Report" << endl;
    cout << "8. Exit" << endl;
    cout << "-----------------------------" << endl;
}

void VehicleRegistrationSystem::processChoice(int choice) {
    switch (choice) {
        case 1: {
            string regNumber, vehicleType, ownerName;
            cout << "Enter Registration Number: ";
            cin >> regNumber;
            cout << "Enter Vehicle Type: ";
            cin >> vehicleType;
            cout << "Enter Owner Name: ";
            cin >> ownerName;

            registerVehicle(regNumber, vehicleType, ownerName);
            break;
        }
        case 2:
            displayAllVehicles();
            break;
        case 3: {
            string regNumber;
            cout << "Enter Registration Number to Search: ";
            cin >> regNumber;

            searchByRegistrationNumber(regNumber);
            break;
        }
        case 4: {
            string regNumber, newType, newOwner;
            cout << "Enter Registration Number to Update: ";
            cin >> regNumber;
            cout << "Enter New Vehicle Type: ";
            cin >> newType;
            cout << "Enter New Owner Name: ";
            cin >> newOwner;

            updateVehicle(regNumber, newType, newOwner);
            break;
        }
        case 5: {
            string regNumber;
            cout << "Enter Registration Number to Delete: ";
            cin >> regNumber;

            deleteVehicle(regNumber);
            break;
        }
        case 6:
            sortVehiclesByRegistrationNumber();
            break;
        case 7:
            generateReport();
            break;
        case 8:
            cout << "Exiting... Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void VehicleRegistrationSystem::authenticateUser() {
    string enteredUsername, enteredPassword;

    cout << "Enter username: ";
    cin >> enteredUsername;
    cout << "Enter password: ";
    cin >> enteredPassword;

    if (currentUser.authenticate(enteredPassword)) {
        isAuthenticated = true;
        cout << "Authentication successful. Welcome, " << currentUser.getUsername() << "!" << endl;
    } else {
        isAuthenticated = false;
        cout << "Authentication failed. Invalid username or password." << endl;
    }
}

int main() {
    VehicleRegistrationSystem system;
    int choice;

    // Basic user authentication (for demonstration purposes)
    system.authenticateUser();

    if (!system.isAuthenticated) {
        cout << "Exiting... Thank you!" << endl;
        return 0;
    }

    do {
        system.showMenu();
        cout << "Enter your choice (1-8): ";
        cin >> choice;

        system.processChoice(choice);

    } while (choice != 8);

    return 0;
}

