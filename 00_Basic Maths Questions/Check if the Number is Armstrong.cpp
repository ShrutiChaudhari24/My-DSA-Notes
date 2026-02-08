#include <iostream>
using namespace std;

int digit_count(int n) {
    int count = 0;
    while (n != 0) {
        count++;
        n /= 10;
    }
    return count;
}

int int_pow(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++)
        result *= base;
    return result;
}

int main() {
    int n;
    cout << "Enter a number to check whether it is an Armstrong number: ";
    cin >> n;

    int x = n;
    int count = digit_count(n);
    int sum = 0;

    while (x != 0) {
        int digit = x % 10;
        sum += int_pow(digit, count);  // integer-only power
        x /= 10;
    }

    if (sum == n) {
        cout << "The given number is an Armstrong number.";
    } else {
        cout << "The given number is not an Armstrong number.";
    }

    return 0;
}
