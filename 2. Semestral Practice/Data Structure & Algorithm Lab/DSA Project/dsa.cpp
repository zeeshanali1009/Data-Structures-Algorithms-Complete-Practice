#include <iostream>
#include <string>

using namespace std;

// Define a structure to represent a vehicle
struct Vehicle {
    string registrationNumber;
    string make;
    string model;
    int year;
    Vehicle* next; // Pointer to the next vehicle in the list
};

// Define a class for the vehicle register system
class VehicleRegister {
private:
    Vehicle* head; // Pointer to the first vehicle in the list
    bool authenticated; // Flag to track user authentication

public:
    // Constructor to initialize the list and set authentication to false
    VehicleRegister() : head(NULL), authenticated(false) {}

    // Function to authenticate the user
    void authenticateUser() {
        string username, password;

        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        // For demonstration purposes, using a hardcoded username and password
        if (username == "admin" && password == "admin123") {
            authenticated = true;
            cout << "Authentication successful!\n";
        } else {
            authenticated = false;
            cout << "Authentication failed. Incorrect username or password.\n";
        }
    }

    // Function to add a new vehicle to the register
    void addVehicle(const string& regNumber, const string& make, const string& model, int year) {
        if (!authenticated) {
            cout << "Authentication required. Please authenticate first.\n";
            return;
        }

        // Create a new vehicle
        Vehicle* newVehicle = new Vehicle;
        newVehicle->registrationNumber = regNumber;
        newVehicle->make = make;
        newVehicle->model = model;
        newVehicle->year = year;
        newVehicle->next = NULL;

        // Add the new vehicle to the list
        if (head == NULL) {
            head = newVehicle;
        } else {
            Vehicle* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newVehicle;
        }

        cout << "Vehicle added successfully.\n";
    }

    // Function to display all vehicles in the register
    void displayVehicles() {
        if (!authenticated) {
            cout << "Authentication required. Please authenticate first.\n";
            return;
        }

        if (head == NULL) {
            cout << "No vehicles in the register.\n";
        } else {
            cout << "Vehicle Register:\n";
            Vehicle* temp = head;
            while (temp != NULL) {
                cout << "Registration Number: " << temp->registrationNumber << "\n";
                cout << "Make: " << temp->make << "\n";
                cout << "Model: " << temp->model << "\n";
                cout << "Year: " << temp->year << "\n";

                cout << "------------------------\n";
                temp = temp->next;
            }
        }
    }

    // Function to search for a vehicle by registration number
    Vehicle* searchVehicle(const string& regNumber) {
        if (!authenticated) {
            cout << "Authentication required. Please authenticate first.\n";
            return NULL;
        }

        Vehicle* temp = head;
        while (temp != NULL) {
            if (temp->registrationNumber == regNumber) {
                return temp;
            }
            temp = temp->next;
        }
        return NULL; // Vehicle not found
    }

    // Function to update and edit the details of a vehicle
    void updateVehicle(const string& regNumber) {
        if (!authenticated) {
            cout << "Authentication required. Please authenticate first.\n";
            return;
        }

        Vehicle* vehicleToUpdate = searchVehicle(regNumber);

        if (vehicleToUpdate != NULL) {
            cout << "Enter new make: ";
            cin >> vehicleToUpdate->make;

            cout << "Enter new model: ";
            cin >> vehicleToUpdate->model;

            cout << "Enter new year: ";
            cin >> vehicleToUpdate->year;

            cout << "Vehicle details updated successfully.\n";
        } else {
            cout << "Vehicle not found.\n";
        }
    }

    // Function to delete a vehicle by registration number
    void deleteVehicle(const string& regNumber) {
        if (!authenticated) {
            cout << "Authentication required. Please authenticate first.\n";
            return;
        }

        Vehicle* current = head;
        Vehicle* previous = NULL;

        while (current != NULL) {
            if (current->registrationNumber == regNumber) {
                if (previous != NULL) {
                    previous->next = current->next;
                } else {
                    head = current->next;
                }
                delete current;
                cout << "Vehicle deleted successfully.\n";
                return;
            }
            previous = current;
            current = current->next;
        }

        cout << "Vehicle not found.\n";
    }

    // Function to display details of a selected vehicle
    void displayVehicleDetails(const Vehicle* vehicle) {
        if (!authenticated) {
            cout << "Authentication required. Please authenticate first.\n";
            return;
        }

        if (vehicle != NULL) {
            cout << "Vehicle Details:\n";
            cout << "Registration Number: " << vehicle->registrationNumber << "\n";
            cout << "Make: " << vehicle->make << "\n";
            cout << "Model: " << vehicle->model << "\n";
            cout << "Year: " << vehicle->year << "\n";
            // Display other details as needed
            // ...
        } else {
            cout << "Vehicle not found.\n";
        }
    }

    // Function to search for vehicles based on make
    void searchByMake(const string& makeToSearch) {
        if (!authenticated) {
            cout << "Authentication required. Please authenticate first.\n";
            return;
        }

        bool found = false;
        Vehicle* temp = head;

        while (temp != NULL) {
            if (temp->make == makeToSearch) {
                cout << "Vehicle Found:\n";
                cout << "Registration Number: " << temp->registrationNumber << "\n";
                cout << "Make: " << temp->make << "\n";
                cout << "Model: " << temp->model << "\n";
                cout << "Year: " << temp->year << "\n";
                cout << "------------------------\n";
                found = true;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "No vehicles found with the specified make.\n";
        }
    }

    // Destructor to free memory when the object is destroyed
    ~VehicleRegister() {
        // Release memory for all nodes in the linked list
        Vehicle* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Function to display the extended menu and get user's choice
int displayExtendedMenu() {
    cout << "Vehicle Register System Extended Menu:\n";
    cout << "1. Authenticate User\n";
    cout << "2. Add a Vehicle\n";
    cout << "3. Display Vehicles\n";
    cout << "4. Search for a Vehicle\n";
    cout << "5. Update and Edit Vehicle\n";
    cout << "6. Delete a Vehicle\n";
    cout << "7. Display Vehicle Details\n";
    cout << "8. Search and Retrieval by Make\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    return choice;
}

int main() {
    VehicleRegister registerSystem;

    int choice;
    do {
        choice = displayExtendedMenu();

        switch (choice) {
            case 1:
                registerSystem.authenticateUser();
                break;
            case 2: {
                string regNumber, make, model;
                int year;

                cout << "Enter Registration Number: ";
                cin >> regNumber;

                cout << "Enter Make: ";
                cin >> make;

                cout << "Enter Model: ";
                cin >> model;

                cout << "Enter Year: ";
                cin >> year;

                registerSystem.addVehicle(regNumber, make, model, year);
                break;
            }
            case 3:
                registerSystem.displayVehicles();
                break;
            case 4: {
                string regNumber;
                cout << "Enter Registration Number to search: ";
                cin >> regNumber;
                Vehicle* foundVehicle = registerSystem.searchVehicle(regNumber);
                registerSystem.displayVehicleDetails(foundVehicle);
                break;
            }
            case 5: {
                string regNumber;
                cout << "Enter Registration Number to update: ";
                cin >> regNumber;
                registerSystem.updateVehicle(regNumber);
                break;
            }
            case 6: {
                string regNumber;
                cout << "Enter Registration Number to delete: ";
                cin >> regNumber;
                registerSystem.deleteVehicle(regNumber);
                break;
            }
            case 7: {
                string regNumber;
                cout << "Enter Registration Number to display details: ";
                cin >> regNumber;
                Vehicle* foundVehicle = registerSystem.searchVehicle(regNumber);
                registerSystem.displayVehicleDetails(foundVehicle);
                break;
            }
            case 8: {
                string makeToSearch;
                cout << "Enter Make to search: ";
                cin >> makeToSearch;
                registerSystem.searchByMake(makeToSearch);
                break;
            }
            case 9:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}

