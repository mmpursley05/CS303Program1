#include "functions.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>

using namespace std;

// Function to verify if a value exists in the array
int verifyValueExists(int *arr, int size, int value) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == value) {
      return i;
    }
  }
  return -1;
}

// Function to read data from a file and store it in an array
void readDataFromFile(int *&arr, int &size, const string &filename) {
  ifstream inputFile(filename);
  if (!inputFile) {
    throw runtime_error("Could not open file: " + filename); // Handle file opening failure
  }

  size = 0;
  int capacity = 50; // Initial array capacity
  int value;

  try {
    while (inputFile >> value) {
      if (size >= capacity) { // Resize the array if needed 
        capacity *= 2;
        int *newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
          newArr[i] = arr[i];
        }
        delete[] arr; // Clean memory
        arr = newArr; // Point to the new array
      }
      arr[size++] = value; // Add value to the array
    }
  } catch (const exception &e) {
    logError("Error reading value at position " + to_string(size));
    throw;
  }

  inputFile.close();
}

// Function to log errors
void logError(const string &errorMessage) {
  ofstream errorFile("error.txt", ios::app);
  if (errorFile) {
    errorFile << errorMessage << endl;
    errorFile.close();
  } else {
    cerr << "Error opening error.txt for logging" << endl;
  }
}

// Function to modify a value in the array
void modifyValue(int *arr, int size) {
  cout << "Enter the index to modify (0-" << size - 1 << "): ";
  int index;
  while (!(cin >> index) || index < 0 || index >= size) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid index. Please enter a value between 0 and " << size - 1
         << ": ";
  }

  int newValue;
  cout << "Enter the new value: ";
  while (!(cin >> newValue)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Please enter a numeric value: ";
  }

  int originalValue = arr[index]; // Store the original value
  arr[index] = newValue; // Modify the value in the array
  cout << "The value " << originalValue << " was replaced by " << newValue
       << endl;
}

// Function to add a new integer to the end of the array
void addNewInteger(int *&arr, int &size, int &capacity) {
  int newValue;
  cout << "Enter a value to add: ";
  while (!(cin >> newValue)) {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Please enter a numeric value: ";
  }

  if (size >= capacity) { // Resize if needed
    capacity *= 2;
    int *newArr = new int[capacity];
    for (int i = 0; i < size; i++) {
      newArr[i] = arr[i]; // Copy to the new array
    }
    delete[] arr; // Clean memory
    arr = newArr; // Point to the new array
  }

  arr[size++] = newValue;
  cout << "Value " << newValue << " added at position " << size - 1 << endl;
}

// Function to print the array
void printArray(const int *arr, int size) {
  if (size == 0) {
    cout << "Array is empty" << endl;
    return;
  }
  cout << "Current Array Contents" << endl;
  for (int i = 0; i < size; i++) {
    cout << setw(3) << arr[i] << " ";
    if ((i + 1) % 10 == 0) {
      cout << endl;
    }
  }
  cout << endl;
}

// Function to erase a value from the array
void eraseValue(int *arr, int &size, int index) {
  if (index < 0 || index >= size) {
    throw out_of_range("Invalid index for erasure");
  }

  for (int i = index; i < size - 1; i++) {
    arr[i] = arr[i + 1]; // Shift elements to the left
  }
  size--;
}
