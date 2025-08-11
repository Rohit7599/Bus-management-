#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
// SEARCH A BUSS  PART-2
class Bus
{
    public:
    char BusNo[20];
    char DriverName[20];
    char Departure[20];
    char Arrival[20];
    char From[20];
    char To[20];
    char Date[20];
    char Day[20];
    char Seats[20];
    Bus ( )
    {
    strcpy(From," ");
    strcpy(To," ");
    strcpy(Date," ");
    }
    void Display()
    {
        cout<<"Bus Number:"<<BusNo<<"\n";
        cout<<"Driver Name:"<<DriverName<<"\n";
        cout<<"Departure Timings:"<<Departure<<"     From:"<<From<<"\n";
        cout<<"Arrival Timings:"<<Arrival<<"       To:"<<To<<"\n";
        cout<<"Date Of Journey:"<<Date<<"           Day Of Journey:"<<Day<<"\n";
        cout<<"Number of Seats in a Bus:"<<Seats<<"\n";
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<"\n";
    }
};
void filewrite()
{   
    Bus B1;
    ofstream fout("Bus1.dat",ios::app|ios::binary);
    if(!fout)
    {
    cout<<"There is No Bus For this Rout";
    return;
    }
    fout.close();
}
int search()
{
    
int s=0;
    Bus B1;
    ifstream fin("Bus1.dat", ios::binary);
    if(!fin)
    {
    cout<<"There is No Bus For this Rout";
    // return;
    }    
    string find;
    string found;
    string Time;
    cout<<"Enter a Journey you Start From:";
    cin>>find;
    cout<<"Enter a Journey you End To:";
    cin>>found;
    cout<<"Date Of Journey (Date/Month/Year):";
    cin>>Time;
    while(fin.read((char*)(&B1), sizeof(B1)))
    {
        if(find==B1.From && found==B1.To && Time==B1.Date)
        {
            s=1;
        cout<<"Bus is Found"<<"\n";
        B1.Display();
        }
    }
     if(B1.From!=find || found!=B1.To || Time!=B1.Date)
    {
       cout<<"Bus is not found"<<"\n";
       
    }
    return s;
    // string choice;
    // cout<<"Do you want to Search Another Bus ?"<<"\n";
    // cout<<"Yes/No"<<"\n";
    // cin >> choice;
    // cin.ignore();
    // if( choice != "yes" && choice != "Yes")
    // {
    // cout<<choice;
    // break;
    // }  
    // }
    // fin.close();
}
int main()
{
    // filewrite();
    search();
}