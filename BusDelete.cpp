#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
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
    strcpy(From," ");
    strcpy(To," ");
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
};
void search()
{
    Bus B1;
    ifstream fin("Bus.dat", ios::binary);
    if (!fin) 
    {
        cout << "Error opening file." << "\n";
        return;
    }
    string find;
    cout<<"Enter a Bus Number which we want to serach:";
    cin>>find;
    while(fin.read((char*)(&B1), sizeof(B1)))
    {
        
        if(find==B1.BusNo)
        {
            cout<<"Bus is Found";
            B1.Display();
        }
    }
    if(B1.BusNo!=find)
    {
       cout<<"Bus is not found";
    }
    fin.close(); 
}
void copyafile()
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
    fout.close();
    // remove("Bus1.dat");
    // rename("Buscopy.dat","Bus1.dat");
}
void readfile()
{
 
    Bus B1;
    ifstream fin("Bus1.dat", ios::binary);
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
void DeleteRecord()
{
   Bus B1;
   ifstream fin("Bus1.dat", ios::binary);
   ofstream fout("temp.dat", ios::binary);
   string find;
   cout<<"Enter a Bus Number which we want to delete:";
   cin>>find;
   while(fin.read((char*)(&B1), sizeof(B1)))
    {
        if(find!=B1.BusNo)
        {
            fout.write((char*)&B1,sizeof(B1));
        }
    }
    fin.close();
    fout.close();
    remove("Bus1.dat");
    rename("temp.dat","Bus1.dat");
}
void readdelete()
{
   Bus B1;
   ifstream fin("Bus1.dat", ios::binary);
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
void UpdateRecord()
{
    Bus B1;
    ifstream fin("Bus1.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);
    string  find;
    cout<<"Enter a Bus Number which we want to update:";
    cin>>find;
    while(fin.read((char*)(&B1), sizeof(B1)))
    {
        if(find==B1.BusNo)
        {
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
        }
        fout.write((char*)&B1,sizeof(B1));
    }
    fin.close();
    fout.close();
    remove("Bus1.dat");
    rename("temp.dat","Bus1.dat"); 
}
int main()
{
   
    //  copyafile();
    readfile();
    // DeleteRecord();
    // readdelete();
    // UpdateRecord();

}