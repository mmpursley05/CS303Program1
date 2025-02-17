// CS303Pgm1Template.cpp : This file contains the 'main' function. Program
// execution begins and ends there.
//
// NAME: Maggie Pursley
// CS303
// PROGRAM 1

// Worked with Sivkan T. and Katy N.
#include "functions.h"
#include <iostream>
#include <limits>

using namespace std;

void displayMenu() {
  cout << "\nMenu:\n";
  cout << "1. Verify that a value exists in the array\n";
  cout << "2. Modify a value in the array\n";
  cout << "3. Add a new integer to the end of the array\n";
  cout << "4. Erase a value\n";
  cout << "5. Print the array\n";
  cout << "6. Exit\n";
  cout << "Enter your choice: ";
}

int main() {
  cout << "Dynamic Arrays\n";
  int capacity = 50;
  int *arr = new int[capacity]; // Dynamically allocate an array
  int size = 0;

  // Load data from file
  try {
    readDataFromFile(arr, size, "A1input.txt");
  } catch (const exception &e) {
    cerr << "Error reading file: " << e.what() << endl;
    delete[] arr;
    return 1;
  }

  bool running = true;
  while (running) {
    displayMenu();
    int choice;
// Validate user input
    while (!(cin >> choice) || choice < 1 || choice > 6) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter a number between 1 and 6: ";
    }

    try {
      switch (choice) {
      case 1: { // Verify that a value exists in the array
        int value;
        cout << "Enter the value to verify: ";
        while (!(cin >> value)) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Invalid input. Please enter a numeric value: ";
        }

        int index = verifyValueExists(arr, size, value);
        if (index != -1) {
          cout << "The value " << value << " was found at position: " << index
               << endl;
        } else {
          cout << "The value " << value << " could not be found" << endl;
        }
        break;
      }
      case 2: { // Modify a value in the array
        modifyValue(arr, size);
        break;
      }
      case 3: { // Add a new integer to the end of the array
        addNewInteger(arr, size, capacity);
        break;
      }
      case 4: { // Erase a value
        int index;
        cout << "Enter the index to erase (0-" << size - 1 << "): ";
        while (!(cin >> index) || index < 0 || index >= size) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Invalid index. Please enter a value between 0 and "
               << size - 1 << ": ";
        }

        int valueToErase = arr[index];
        eraseValue(arr, size, index);
        cout << "The value " << valueToErase << " was erased" << endl;
        break;
      }
      case 5: { // Print the array
        printArray(arr, size);
        break;
      }
      case 6: { // Exit
        running = false;
        cout << "Exiting program...\n";
        break;
      }
      }
    } catch (const exception &e) {
      cerr << "Error: " << e.what() << endl;
    }
  }

  delete[] arr; // Clean up memory
  return 0;
}
