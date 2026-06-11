#include <iostream>
using namespace std;
#include<string>

class Vehicle
{
protected:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;

        totalVehicles++;
    }
    Vehicle(int id, string manu, string mod, int y)
{
    vehicleID = id;
    manufacturer = manu;
    model = mod;
    year = y;

    totalVehicles++;
}
void display()
    {
        cout << "\nVehicle ID : " << vehicleID;
        cout << "\nManufacturer : " << manufacturer;
        cout << "\nModel : " << model;
        cout << "\nYear : " << year;
    }
    void setVehicleID(int id){
        vehicleID = id;
    }
    void setManufacturer(string manu){
         manufacturer = manu;
    }
    void setModel(string mod){
        model = mod;
    }
    void setYear(int y){
        year = y;
    }

    int getVehicleID(){
        return vehicleID;
    }
    string getManufacturer(){
        return manufacturer;
    }
    string getModel(){
        return model;
    }
    int getYear(){
        return year;
    }
    static void showTotalVehicles()
    {
        cout << "\nTotal Vehicles : " << totalVehicles;
    }
};
class Car : public Vehicle{
    protected:
    string fuelType;
    public:
    Car(){
        fuelType = "" ;
    }
    void setFuel(string f){
        fuelType = f;
    }
    string getFuel(){
        return fuelType;
    }
    void displayCar(){
        display();
        cout<< "\nFuel Type:"<<fuelType;
    }
};

class ElectricCar : public Car{
    protected:
    int batteryCapacity;

    public:
    ElectricCar(){
        batteryCapacity = 0;
    }
    void setBatteryCapacity(int battery)
    {
        batteryCapacity = battery;
    }

    int getBatteryCapacity()
    {
        return batteryCapacity;
    }
    void displayElectricCar(){
        displayCar();
        cout<<"\nBattery Capacity : "<<batteryCapacity<<"kwh";
    }
};
class SUV : public Car
{
public:
    SUV()
    {
    }
    void display()
    {
        displayCar();
        cout << "\nType : SUV";
    }
};
class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar()
    {
        topSpeed = 0;
    }

    void setTopSpeed(int speed)
    {
        topSpeed = speed;
    }

    int getTopSpeed()
    {
        return topSpeed;
    }

    void displaySportsCar()
    {
        displayElectricCar();

        cout << "\nTop Speed : " << topSpeed << " km/h";
    }
};
class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }
    void setFlightRange(int r)
    {
        flightRange = r;
    }

    void displayAircraft()
    {
        cout << "\nFlight Range : " << flightRange << " km";
    }
};
class FlyingCar : public Car, public Aircraft
{
public:
    void displayFlyingCar()
    {
        display();
        displayAircraft();

        cout << "\nFlying Car Mode Enabled";
    }
};
class VehicleRegistry
{
private:
    Vehicle* vehicles[100];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }
        void addVehicle(Vehicle* v)
    {
        vehicles[count] = v;
        count++;
    }
        void displayAll()
    {
        for(int i = 0; i < count; i++)
        {
            vehicles[i]->display();
            cout << endl;
        }
    }
        void searchById(int id)
    {
        for(int i = 0; i < count; i++)
        {
            if(vehicles[i]->getVehicleID() == id)
            {
                vehicles[i]->display();
                return;
            }
        }

        cout << "Vehicle Not Found";
    }
};
int Vehicle::totalVehicles = 0;

int main()
{
    VehicleRegistry vr;
    int choice;
    do
    {
        cout << "\n\n1. Add Car";
        cout << "\n2. Add SUV";
        cout << "\n3. Add Electric Car";
        cout << "\n4. View All";
        cout << "\n5. Search by ID";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        int id, year;
        string manu, model, fuel;

        switch(choice)
        {
        case 1:
        {
            Car* c = new Car();

            cout << "\nEnter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> model;
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Fuel Type: ";
            cin >> fuel;

            c->setVehicleID(id);
            c->setManufacturer(manu);
            c->setModel(model);
            c->setYear(year);
            c->setFuel(fuel);

            vr.addVehicle(c);
            break;
        }

        case 2:
        {
            SUV* s = new SUV();

            cout << "\nEnter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> model;
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Fuel Type: ";
            cin >> fuel;

            s->setVehicleID(id);
            s->setManufacturer(manu);
            s->setModel(model);
            s->setYear(year);
            s->setFuel(fuel);

            vr.addVehicle(s);
            break;
        }

        case 3:
        {
            ElectricCar* e = new ElectricCar();

            int battery;

            cout << "\nEnter ID: ";
            cin >> id;
            cout << "Enter Manufacturer: ";
            cin >> manu;
            cout << "Enter Model: ";
            cin >> model;
            cout << "Enter Year: ";
            cin >> year;
            cout << "Enter Battery (kWh): ";
            cin >> battery;

            e->setVehicleID(id);
            e->setManufacturer(manu);
            e->setModel(model);
            e->setYear(year);
            e->setFuel("Electric");
            e->setBatteryCapacity(battery);

            vr.addVehicle(e);
            break;
        }

        case 4:
            vr.displayAll();
            break;

        case 5:
        {
            cout << "\nEnter ID: ";
            cin >> id;
            vr.searchById(id);
            break;
        }

        case 6:
            cout << "Exiting...";
            break;
        }

    } while(choice != 6);

}