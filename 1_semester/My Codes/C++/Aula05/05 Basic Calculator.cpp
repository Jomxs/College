#include <iostream>

using namespace std;

int main () {

    int a;
    int b;
    int sum;

    cout << "Enter a number! \n";
    //cin >>: take the information from the user and give it to the computer (computer in)
    cin >> a;
    cout << "Enter another number! \n";
    cin >> b;

    sum = a + b;
    cout << "The sum of those numbers is: \n" << sum << endl;


    return 0;
}

