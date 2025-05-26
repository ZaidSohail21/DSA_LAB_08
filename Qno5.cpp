#include "myDLL.h"

using namespace std;

int main()
{
    int a = 1;
    myDLL book1;
    myDLL book2;

    do {
        cout << "Press 1: to add student to reservation list" << endl;
        cout << "Press 2: to remove student from reservation list" << endl;
        cout << "Press 3: to update student priority" << endl;
        cout << "Press 4: to display reservation list" << endl;
        cout << "Press 5: to count total students in reservation list" << endl;
        cout << "Press 6: to remove student at front (book returned)" << endl;
        cout << "Press 0: to exit the program" << endl;
        cin >> a;

        if (a == 1) {
            int bookChoice, studentID;
            string priority;
            cout << "Select Book (1 or 2): ";
            cin >> bookChoice;
            cout << "Enter Student ID: ";
            cin >> studentID;
            cout << "Enter Priority (casual, research, assignment): ";
            cin >> priority;

           
            if (bookChoice == 1) {
                if (priority == "casual") {
                    book1.insertAtTail(studentID); 
                }
                else if (priority == "research") {
                    book1.insertAtHead(studentID); 
                }
                else if (priority == "assignment") {
                    
                    book1.insertAtPosition(studentID, 2);
                }
                else {
                    cout << "Invalid priority!" << endl;
                }
            }
            else if (bookChoice == 2) {
                if (priority == "casual") {
                    book2.insertAtTail(studentID); 
                }
                else if (priority == "research") {
                    book2.insertAtHead(studentID);  
                }
                else if (priority == "assignment") {
                    
                    book2.insertAtPosition(studentID, 2);
                }
                else {
                    cout << "Invalid priority!" << endl;
                }
            }
            else {
                cout << "Invalid book selection." << endl;
            }
        }
        else if (a == 2) {
            int bookChoice, studentID;
            cout << "Select Book (1 or 2): ";
            cin >> bookChoice;
            cout << "Enter Student ID to remove: ";
            cin >> studentID;

            if (bookChoice == 1) {
                book1.deleteValue(studentID);  
            }
            else if (bookChoice == 2) {
                book2.deleteValue(studentID); 
            }
            else {
                cout << "Invalid book selection." << endl;
            }
        }
        else if (a == 3) {
            int bookChoice, studentID;
            string newPriority;
            cout << "Select Book (1 or 2): ";
            cin >> bookChoice;
            cout << "Enter Student ID to update priority: ";
            cin >> studentID;
            cout << "Enter New Priority (casual, research, assignment): ";
            cin >> newPriority;

            
            if (bookChoice == 1) {
                book1.deleteValue(studentID); 
                if (newPriority == "casual") {
                    book1.insertAtTail(studentID);  
                }
                else if (newPriority == "research") {
                    book1.insertAtHead(studentID); 
                }
                else if (newPriority == "assignment") {
                    book1.insertAtPosition(studentID, 2);  
                }
                else {
                    cout << "Invalid priority!" << endl;
                }
            }
            else if (bookChoice == 2) {
                book2.deleteValue(studentID);  
                if (newPriority == "casual") {
                    book2.insertAtTail(studentID);  
                }
                else if (newPriority == "research") {
                    book2.insertAtHead(studentID);  
                }
                else if (newPriority == "assignment") {
                    book2.insertAtPosition(studentID, 2);  
                }
                else {
                    cout << "Invalid priority!" << endl;
                }
            }
            else {
                cout << "Invalid book selection." << endl;
            }
        }
        else if (a == 4) {
            int bookChoice;
            cout << "Select Book (1 or 2): ";
            cin >> bookChoice;

            if (bookChoice == 1) {
                book1.displayFromHead();  
            }
            else if (bookChoice == 2) {
                book2.displayFromHead(); 
            }
            else {
                cout << "Invalid book selection." << endl;
            }
        }
        else if (a == 5) {
            int bookChoice;
            cout << "Select Book (1 or 2): ";
            cin >> bookChoice;

            if (bookChoice == 1) {
                cout << "Total students in the reservation list for Book 1: " << book1.count() << endl;
            }
            else if (bookChoice == 2) {
                cout << "Total students in the reservation list for Book 2: " << book2.count() << endl;
            }
            else {
                cout << "Invalid book selection." << endl;
            }
        }
        else if (a == 6) {
            int bookChoice;
            cout << "Select Book (1 or 2): ";
            cin >> bookChoice;

            if (bookChoice == 1) {
                book1.deleteFromHead(); 
            }
            else if (bookChoice == 2) {
                book2.deleteFromHead();  
            }
            else {
                cout << "Invalid book selection." << endl;
            }
        }
        else if (a == 0) {
            cout << "Exiting program." << endl;
            break;
        }
        else {
            cout << "Enter a valid Number" << endl;
        }

    } while (a != 0);

    return 0;
}
