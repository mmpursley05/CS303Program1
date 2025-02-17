#pragma once
#include <string>
using namespace std;

int verifyValueExists(int *arr, int size, int value);
void readDataFromFile(int *&arr, int &size, const string &filename);
void logError(const string &errorMessage);
void logError(const string &errorMessage);
void addNewInteger(int *&arr, int &size, int &capacity);
void modifyValue(int *arr, int size);
void modifyValue(int* arr, int size); 
void printArray(const int *arr, int size);
void eraseValue(int *arr, int &size, int index);
