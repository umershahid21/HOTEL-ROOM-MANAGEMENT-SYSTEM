#include <iostream>
#include <limits>  // For numeric_limits
#include <sstream> // For stringstream

using namespace std;

class Hotel {
private:
    struct Node {
        int id, date;
        string name, roomtype;
        Node* next;
    };
public:
    Node* head = NULL;
    void insert();
    void menu();
    void update();
    void search();
    void del();
    void show();
    void list();
};

// Function to convert an integer to a string using stringstream
string intToString(int number) {
    ostringstream oss;
    oss << number;
    return oss.str();
}

void Hotel::menu() {
    while (true) {
        int choice;
        cout <<"\n";
        cout << "\t WELCOME TO UMER HOTEL ROOM MANAGEMENT SYSTEM APPLICATION \n" << endl;
        cout << "\n \t HOW CAN WE ASSIST YOU";
        cout << "\n\n S.No    Functions                      Description" << endl;
        cout << "\n1\t Allocate Room \t\t\t Insert new room ";
        cout << "\n2\t Search room \t\t\t Room with RoomID ";
        cout << "\n3\t Update Room \t\t\t Update Room Record ";
        cout << "\n4\t Delete Room \t\t\t Delete Room with RoomID";
        cout << "\n5\t Show Room Record \t\t Show Room Record that (we added)";
        cout << "\n6\t Exit" << endl;
        cout <<"\n\n Enter your Choice: ";
        
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number between 1 and 6: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        switch (choice) {
            case 1 :
                insert();
                break;

            case 2 :
                search();
                break;

            case 3 :
                update();
                break;

            case 4 :
                del();
                break;

            case 5 :
                show();
                break;

            case 6 :
                exit(0);

            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
                break;
        }
    }
}

void Hotel::insert() {
    cout << "\n\t___Umer Hotel Management System__";
    Node* new_node = new Node;

    cout << "\n Enter Room ID: ";
    while (!(cin >> new_node->id)) {
        cout << "Invalid input. Please enter a valid Room ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->id == new_node->id) {
            cout << "\n\n Room with ID " << new_node->id << " already exists. Room cannot be booked again." << endl;
            delete new_node;
            return;
        }
        ptr = ptr->next;
    }

    cout << "\n Enter Customer Name: ";
    cin >> new_node->name;

    cout << "\n Enter Allocated Date (DDMMYY): ";
    while (!(cin >> new_node->date) || intToString(new_node->date).length() != 6) {
        cout << "Invalid input. Please enter a valid date in DDMMYY format: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\n Enter Room Type (single/double/twin): ";
    while (true) {
        cin >> new_node->roomtype;
        if (new_node->roomtype == "single" || new_node->roomtype == "double" || new_node->roomtype == "twin") {
            break;
        } else {
            cout << "Invalid input. Please enter room type as single, double, or twin: ";
        }
    }

    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node* ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
    cout << "\n\n\t\t New Room Inserted\n";
}

void Hotel::search() {
    cout << "\n\t____Umer Hotel Room Management System__";
    int t_id;
    if (head == NULL) {
        cout << "\n\n Linklist is Empty";
    } else {
        cout << "\n\n Room ID";
        cin >> t_id;
        Node* ptr = head;
        while (ptr != NULL) {
            if (t_id == ptr->id) {
                cout << "\n\n Room ID: " << ptr->id;
                cout << "\n\n Customer Name: " << ptr->name;
                cout << "\n\n Room Allocated Date(DDMMYY): " << ptr->date;
                cout << "\n\n Room Type: " << ptr->roomtype<<"\n";
            }
            ptr = ptr->next;
        }
    }
}

void Hotel::update() {
    cout << "\n\t____Umer Hotel Management System__";
    int t_id;
    if (head == NULL) {
        cout << "\n\n Linked list is Empty";
    } else {
        cout << "\n\n Enter Room ID to update: ";
        cin >> t_id;
        Node* ptr = head;
        bool found = false;

        while (ptr != NULL) {
            if (t_id == ptr->id) {
                found = true;
                cout << "\n\n Room ID: " << ptr->id; 
                cout << "\n\n Enter new Customer Name: ";
                cin >> ptr->name;
                cout << "\n\n Enter new Allocated Date: ";
                while (!(cin >> ptr->date) || intToString(ptr->date).length() != 6) {
                    cout << "Invalid input. Please enter a valid date in DDMMYY format: ";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                cout << "\n\n Enter new Room Type: ";
                while (true) {
                    cin >> ptr->roomtype;
                    if (ptr->roomtype == "single" || ptr->roomtype == "double" || ptr->roomtype == "twin") {
                        break;
                    } else {
                        cout << "Invalid input. Please enter room type as single, double, or twin: ";
                    }
                }
                cout << "\n\n\t\t Record Updated Successfully";
                break;
            }
            ptr = ptr->next;
        }

        if (!found) {
            cout << "\n\n Room with ID " << t_id << " not found.";
        }
    }
}

void Hotel::del() {
    cout << "\n\t____Hotel Management System__";
    int t_id;
    if (head == NULL) {
        cout << "\n\n Linked list is Empty" << endl;
        return;
    }

    cout << "\n\n Enter Room ID: ";
    while (!(cin >> t_id)) {
        cout << "Invalid input. Please enter a valid Room ID: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Node* ptr = head;
    Node* prev = NULL;
    bool found = false;

    while (ptr != NULL) {
        if (ptr->id == t_id) {
            found = true;
            if (prev == NULL) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            delete ptr;
            cout << "\n\n Room Record Deleted Successfully \n";
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    if (!found) {
        cout << "\n\n Room with ID " << t_id << " not found." << endl;
    }
}

void Hotel::show() {
    Node* ptr = head;
    while (ptr != NULL) {
        cout << "\n\n ROOM ID: " << ptr->id;
        cout << "\n\n Customer Name: " << ptr->name;
        cout << "\n\n Allocation Date: " << ptr->date;
        cout << "\n\n Room Type: " << ptr->roomtype;
        ptr = ptr->next;
    }

    int choice;
    cout << "\n\nDo you want to return to the main menu? (1: Yes / 0: No): ";
    cin >> choice;
    if (choice == 1) {
        menu(); 
    } else {
        cout << "Thank you user exiting \n";
        exit(0); 
    }
}

int main() {
    Hotel h;
    h.menu();
}

