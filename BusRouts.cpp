#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
// Routs Of BUSS  PART-3
class Bus                                    
{
    public:
    char Busid[20];
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
    strcpy(Busid,"");
    strcpy(BusNo," ");
    strcpy(DriverName," ");
    strcpy(Departure," ");
    strcpy(Arrival," ");
    strcpy(From," ");
    strcpy(To," ");
    strcpy(Date," ");
    strcpy(Day," ");
    strcpy(Seats," ");
    }
    void Display()
    {    
        cout<<"\t\t\t\t****Routs Of Buses****"<<"\n\n";
        cout<<"Bus ID:"<<Busid<<"\n";
        cout<<"Bus Number:"<<BusNo<<"\n";
        cout<<"Driver Name:"<<DriverName<<"\n";
        cout<<"Departure Timings:"<<Departure<<"\t\tFrom:"<<From<<"\n";
        cout<<"Arrival Timings:"<<Arrival<<"\t\t\tTo:"<<To<<"\n";
        cout<<"Date Of Journey:"<<Date<<"\t\tDay Of Journey:"<<Day<<"\n";
        cout<<"Number of Seats in a Bus:"<<Seats<<"\n";
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<"\n";
    }
};
    void ReadaBus()
    {
        Bus B1;
        ifstream fin("Bus1.dat", ios::binary);
        for (;fin.read((char*)(&B1), sizeof(B1));)   
        {
           B1.Display();
        }
        fin.close();
    };
int main()
{
    ReadaBus();
}