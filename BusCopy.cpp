#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
// ADD A BUSS  PART-1
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
    void fileread()
{
    Bus B1;
    ifstream fin("Bus1.dat", ios::binary);
    if(!fin)
    {
    cout<<"There is No Bus For this Rout";
    return;
    }
    int i=0;
    for(;;)
    {
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
        cout<<"Bus is Found"<<"\n";
        B1.Display();
        }
    }
     if(B1.From!=find || found!=B1.To || Time!=B1.Date)
    {
       cout<<"Bus is not found"<<"\n";
    }
    string choice;
    cout<<"Do you want to Search Another Bus ?"<<"\n";
    cout<<"Yes/No"<<"\n";
    cin >> choice;
    cin.ignore();
    if( choice != "yes" && choice != "Yes")
    {
    cout<<choice;
    break;
    }  
    }
    fin.close();
}
void readafile()
{
    Bus B1;
    ifstream fin("Buscopy.dat", ios::binary);
    if (!fin) 
    {
        cout << "Error opening file." << "\n";
        return;
    }
    while(fin.read((char*)(&B1), sizeof(B1)))
    {
        B1.Display();
    }
    fin.close(); 
}
void copytofile()
{
 
    Bus B1;
    ifstream fin("Bus1.dat", ios::binary);
    
    ofstream fout("Buscopy.dat", ios::binary);
    if (!fin) 
    {
        cout << "Error opening file." << "\n";
        return;
    }
    while(fin.read((char*)(&B1), sizeof(B1)))
    {
        fout.write((char*)&B1,sizeof(B1));
    }
    fin.close();   
}
int main()
{
    // AddaBus();
    //  copytofile();
      readafile();
}