#include <iostream>

using namespace std;

int main() {
    double envTemp, humidity, bodyTemp;
    cout << "Enter environment temperature: ";
    cin >> envTemp;
    cout << "Enter humidity: ";
    cin >> humidity;
    cout << "Enter body temperature: ";
    cin >> bodyTemp;

    if (envTemp > bodyTemp && humidity < 61) {
        cout << "HomeThermostat is cooling the room." << endl;
        for (int i = envTemp; i >= bodyTemp - 7; i--) {
            cout << "Current room temperature is " << i << endl;
        }
    } else if (envTemp < bodyTemp && humidity < 61) {
        cout << "HomeThermostat is heating the room." << endl;
        for (int i = envTemp; i <= bodyTemp + 2; i++) {
            cout << "Current room temperature is " << i << endl;
        }
    }
    cout << "HomeThermostat has stopped." << endl;

    return 0;
}
