#include<iostream>
using namespace std;
#include<string>

class Train{
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;
public:
    void setTrain(){

        cout << "Train Number: ";
        cin >> trainNumber;

        cout << "Train Name: ";
        cin >> trainName;

        cout << "Source: ";
        cin >> source;

        cout << "Destination: ";
        cin >> destination;

        cout << "Train Time: ";
        cin >> trainTime;
    }

    void display(){
        cout << "\n----------------------------\n";
        cout << "Train Number : " << trainNumber << endl;
        cout << "Train Name   : " << trainName << endl;
        cout << "Source       : " << source << endl;
        cout << "Destination  : " << destination << endl;
        cout << "Train Time   : " << trainTime << endl;
    }
    int getTrainNumber(){
        return trainNumber;
    }
};
class RailwaySystem{
private:
    Train trains[100];
    int totalTrains = 0;

public:
    void addTrain(){
        if(totalTrains < 100){
            trains[totalTrains].setTrain();
            totalTrains++;
            cout << "\nTrain Added Successfully...\n";
        }
        else{
            cout << "\nStorage Full...\n";
        }
    }
    void displayTrain(){
        if(totalTrains == 0){
            cout << "\nNo Train Records Found...\n";
            return;
        }
        for(int i = 0; i < totalTrains; i++){
            trains[i].display();
        }
    }
    void search(){
        int number;

        cout << "\nEnter Train Number To Search: ";
        cin >> number;

        for(int i = 0; i < totalTrains; i++){

            if(number == trains[i].getTrainNumber()){
                cout << "\nTrain Found:\n";
                trains[i].display();
                return;
            }
        }
        cout << "\nTrain Not Found...\n";
    }
};

int main(){

    int choice;
     RailwaySystem r;
    do{
    cout << "------- Railway Reservation System -------\n";
    cout << "1. Add New Train Record\n";
    cout << "2. Display All Train Records\n";
    cout << "3. Search Train by Number\n";

    cout<< "enter your choice:";
    cin >> choice;
    cout<< "----------------------------------\n";
    switch(choice){
        case 1:
            r.addTrain();
            break;
        case 2:
            r.displayTrain();
            break;
        case 3:
             r.search();
             break;
        case 4:
            cout<<"Exiting the system. Goodbye!";
            break;
        default:
            cout<< "invalid choice";
    }
    }while(choice != 4);
}