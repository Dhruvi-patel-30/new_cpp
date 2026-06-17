#include<iostream>
using namespace std;

class Movie{
    public:
    string title;
    string genre;
    int releasedYear ;

    void setdata(string t, string g, int y){
        title = t;
        genre = g;
        releasedYear = y;
    }
    void display(){
        cout<<"\ntitle:"<<title;
        cout<< "\ngener: " <<genre;
        cout << "\nreleased year:" << releasedYear;
    }
};
int main(){
    Movie m[3];
    m[0].setdata("Bahubali","Action",2016);
    m[1].setdata("Pushpa","Action",2022);
    m[2].setdata("Chhava","Action",2056);

    for(int i = 0; i < 3; i++){
        m[i].display();
        cout<< endl;
        cout<<"--------------";
    }
}