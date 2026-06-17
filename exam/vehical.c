#include <iostream>
using namespace std;


class Vehicle
{
private:
    string model;
    double speed;

public:
    void setData(string m, double s)
    {
        model = m;
        speed = s;
    }

    string getModel()
    {
        return model;
    }

    double getSpeed()
    {
        return speed;
    }

    virtual void displayDetails() = 0;
};


class Car : public Vehicle
{
public:
    void calculateTime(double distance)
    {
        double time = distance / getSpeed();

        cout << "\n--- Car Time Calculation ---" << endl;
        cout << "Distance : " << distance << " km" << endl;
        cout << "Time Taken : " << time << " hours" << endl;
    }

    void displayDetails() override
    {
        cout << "\n--- Car Details ---" << endl;
        cout << "Model : " << getModel() << endl;
        cout << "Speed : " << getSpeed() << " km/h" << endl;
    }
};

class Bike : public Vehicle
{
public:
    void calculateTime(double distance)
    {
        double time = distance / getSpeed();

        cout << "\n--- Bike Time Calculation ---" << endl;
        cout << "Distance : " << distance << " km" << endl;
        cout << "Time Taken : " << time << " hours" << endl;
    }

    void displayDetails() override
    {
        cout << "\n--- Bike Details ---" << endl;
        cout << "Model : " << getModel() << endl;
        cout << "Speed : " << getSpeed() << " km/h" << endl;
    }
};

int main()
{
    Car car;
    Bike bike;

    string model;
    double speed, distance;

    cout << "Enter Car Model: ";
    getline(cin, model);

    cout << "Enter Car Speed (km/h): ";
    cin >> speed;

    car.setData(model, speed);

    cout << "Enter Distance for Car (km): ";
    cin >> distance;

    car.calculateTime(distance);

    cin.ignore();

    cout << "\nEnter Bike Model: ";
    getline(cin, model);

    cout << "Enter Bike Speed (km/h): ";
    cin >> speed;

    bike.setData(model, speed);

    cout << "Enter Distance for Bike (km): ";
    cin >> distance;

    bike.calculateTime(distance);

    Vehicle *v[2];

    v[0] = &car;
    v[1] = &bike;

    cout << "\n\n===== Vehicle Details Using Polymorphism =====" << endl;

    for (int i = 0; i < 2; i++)
    {
        v[i]->displayDetails();
    }
}