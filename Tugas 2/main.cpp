#include <iostream>

using namespace std;

int max (int a, int b);
int min (int a, int b);
int maxArray (int arr[], int arrLength);
int minArray (int arr[], int arrLength);
bool isEven (int a);
bool isOdd (int a);
bool isFactor (int a, int b);
int search (int a, int arr[], int arrLength);
bool isFound (int a, int arr[], int arrLength);
int sumEven (int arr[], int arrLength);
int sumOdd (int arr[], int arrLength);

int main () {
  int a = 10, b = 3, arrLength = 8;
  int arr[] = {2, 23, 9, 30, 180, 20, 92, 92};

  cout << "max: "      << max(a, b)                  << endl;
  cout << "min: "      << min(a, b)                  << endl;
  cout << "maxArray: " << maxArray(arr, arrLength)   << endl;
  cout << "minArray: " << minArray(arr, arrLength)   << endl;
  cout << "isEven: "   << isEven(a)                  << endl;
  cout << "isOdd: "    << isOdd(a)                   << endl;
  cout << "isFactor: " << isFactor(a, b)             << endl;
  cout << "search: "   << search(a, arr, arrLength)  << endl;
  cout << "isFound: "  << isFound(a, arr, arrLength) << endl;
  cout << "sumEven: "  << sumEven(arr, arrLength)    << endl;
  cout << "sumOdd: "   << sumOdd(arr, arrLength)     << endl;

  return 0;
}

int max (int a, int b) {
  return a > b ? a : b;
}

int min (int a, int b) {
  return a < b ? a : b;
}

int maxArray (int arr[], int arrLength) {
  int temp = arr[0];
  for (int i = 0; i < arrLength; i++) {
    temp = max(temp, arr[i]);
  }
  return temp;
}

int minArray (int arr[], int arrLength) {
  int temp = arr[0];
  for (int i = 0; i < arrLength; i++) {
    temp = min(temp, arr[i]);
  }
  return temp;
}

bool isEven (int a) {
  return a % 2 == 0;
}

bool isOdd (int a) {
  return a % 2 != 0;
}

bool isFactor (int a, int b) {
  return a % b == 0;
}

int search (int a, int arr[], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    if (a == arr[i]) {
      return i;
    }
  }
  return 0;
}

bool isFound (int a, int arr[], int arrLength) {
  for (int i = 0; i < arrLength; i++) {
    if (a == arr[i]) {
      return true;
    }
  }
  return false;
}

int sumEven (int arr[], int arrLength) {
  int sum = 0;
  for (int i = 0; i < arrLength; i++) {
    if (arr[i] % 2 == 0) {
      sum += arr[i];
    }
  }
  return sum;
}

int sumOdd (int arr[], int arrLength) {
  int sum = 0;
  for (int i = 0; i < arrLength; i++) {
    if (arr[i] % 2 != 0) {
      sum += arr[i];
    }
  }
  return sum;
}
