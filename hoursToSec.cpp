#include<iostream>
using namespace std;

int main(){
    int hours, minutes, seconds;
    cout << "enter a Hours:";
    cin >> hours;
    cout << "enter a minutes:";
    cin >> minutes;
    cout << "enter a seconds:";
    cin >> seconds;

    int totalSec = (hours * 3600) + (minutes * 60) + seconds;
    cout <<"your total second is:"<<totalSec;
    

}