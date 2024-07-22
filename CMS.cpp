#include <iostream>
#include <cstring>
using namespace std;
struct Contact {
char name[100];
char phoneNumber[20];
struct Contact* next;
};
void addContact(Contact*& start) {
Contact* newContact = new Contact;
cout << "Enter the name: ";
cin.ignore(); // Clear the newline character from the previous input
cin.getline(newContact->name, 100);
cout << "Enter the phone number: ";
cin.getline(newContact->phoneNumber, 20);
newContact->next = start->next;
start->next = newContact;
cout << "Contact added successfully." << endl;
}
void deleteContact(Contact* start, const char* name) {
Contact* prev = start;
Contact* current = start->next;
while (current != nullptr) {
if (strcmp(current->name, name) == 0) {
prev->next = current->next;
delete current;
cout << "Contact deleted successfully." << endl;
return;
}
prev = current;
current = current->next;
}
cout << "Contact not found." << endl;
}
int countContacts(Contact* start) {
int count = 0;
Contact* current = start->next;
while (current != nullptr) {
count++;
current = current->next;
}
return count;
}
void searchContact(Contact* start, const char* name) {
Contact* current = start->next;
while (current != nullptr) {
if (strcmp(current->name, name) == 0) {
cout << "Contact found:" << endl;
cout << "Name: " << current->name << endl;
cout << "Phone Number: " << current->phoneNumber << endl;
return;
}
current = current->next;
}
cout << "Contact not found." << endl;
}
void editContact(Contact* start, const char* name) {
Contact* current = start->next;
while (current != nullptr) {
if (strcmp(current->name, name) == 0) {
cout << "Enter the new name: ";
cin.ignore();
cin.getline(current->name, 100);
cout << "Enter the new phone number: ";
cin.getline(current->phoneNumber, 20);
cout << "Contact edited successfully." << endl;
return;
}
current = current->next;
}
cout << "Contact not found." << endl;
}
void printContacts(Contact* start) {
Contact* current = start->next;
while (current != nullptr) {
cout << "Name: " << current->name << endl;
cout << "Phone Number: " << current->phoneNumber << endl;
current = current->next;
}
}
int main() {
int choice;
char name[100];
Contact* start = new Contact;
start->next = nullptr;
cout << "***** Contact Management System *****" << endl;
do {
cout << "\n1. Add Contact\n2. Delete Contact\n3. Count Contacts\n4. Search Contact\n5. Edit Contact\n6. Display Contacts\n7.Exit" << endl;
cout << "Enter your choice: ";
cin >> choice;
switch (choice) {
case 1:
addContact(start);
break;
case 2:
cout << "Enter the name of the contact to delete: ";
cin.ignore();
cin.getline(name, 100);
deleteContact(start, name);
break;
case 3:
cout << "Total Contacts: " << countContacts(start) << endl;
break;
case 4:
cout << "Enter the name of the contact to search: ";
cin.ignore();
cin.getline(name, 100);
searchContact(start, name);
break;
case 5:
cout << "Enter the name of the contact to edit: ";
cin.ignore();
cin.getline(name, 100);
editContact(start, name);
break;
case 6:
cout << "Contacts:" << endl;
printContacts(start);
break;
case 7:
cout << "Exiting the program." << endl;
break;
default:
cout << "Invalid choice. Please try again." << endl;
}
} while (choice != 7);
Contact* current = start->next;
while (current != nullptr) {
Contact* temp = current;
current = current->next;
delete temp;
}
delete start;
return 0;
}