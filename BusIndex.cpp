#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
// ADD A BUSS  PART-1
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
        cout<<"Bus ID:"<<Busid<<"\n";
        cout<<"Bus Number:"<<BusNo<<"\n";
        cout<<"Driver Name:"<<DriverName<<"\n";
        cout<<"Departure Timings:"<<Departure<<"     From:"<<From<<"\n";
        cout<<"Arrival Timings:"<<Arrival<<"       To:"<<To<<"\n";
        cout<<"Date Of Journey:"<<Date<<"           Day Of Journey:"<<Day<<"\n";
        cout<<"Number of Seats in a Bus:"<<Seats<<"\n";
        cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<"\n";
    }
    friend void AddaBus();
};
    void AddaBus()
    {
        Bus B1;
        int i=0;
        ofstream fout("Bus1.dat",ios::app|ios::binary);
        for(; ;)
        {
        i++;
        cout<<"\t\t\t****Bus Management System****\n";
        cout<<"1.Add A Bus\n";
        cout<<"Enter Bus ID:";
        cin>>B1.Busid;
        cout<<"Enter Bus Number:";
        cin>>B1.BusNo;
        cout<<"Enter Driver Name:";
        cin>>B1.DriverName;
        cout<<"Enter Departure Timings:";
        cin>>B1.Departure;
        cout<<"Enter Arrival Timings:";
        cin>>B1.Arrival;
        cout<<"From:";
        cin>>B1.From;
        cout<<"To:";
        cin>>B1.To;
        cout<<"Enter Date of Journey:";
        cin>>B1.Date;
        cout<<"Enter Day Of Journey:";
        cin>>B1.Day;
        cout<<"Enter Number of Seats in a Bus:";
        cin>>B1.Seats;

       fout.write((char*)(&B1),sizeof(B1));
       string choice;
       cout<<"If you want to Add More Bus ?"<<"\n";
       cout<<"Yes/No"<<"\n";
       cin >> choice;
       cin.ignore();

       if( choice != "yes" && choice != "Yes")
       {
        cout<<choice;
        break;
        }
        cout<<"Thank You For Adding Bus";
        }
         fout.close();
    }
int main()
{
    AddaBus();
}
