#include <iostream>
using namespace std;

int main(){
    int totalSeconds;
    cout << "Enter the total number of seconds: ";
    cin>>totalSeconds;
    

    int hours = totalSeconds/3600;
    int min = (totalSeconds % 3600) / 60;
    int sec = totalSeconds % 60;
    
    cout<<"HH:MM:SS:"<<hours<<":"<<min<<":";
    if(sec<10){
        cout<<"0"<<sec;
    }
    else{
        cout<<sec;
    }
}