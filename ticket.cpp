#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
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
    void Tabular()
    {   
        cout<<"\t\t\t*****BUS DETAILS*****"<<"\n\n";
        cout<<"Bus ID:"<<Busid<<"\n";
        cout<<"----------------------------------------------------------------------------------"<<"\n";
        cout<<"Bus Number"<<"\tDriver Name"<<"\tDeparture"<<"\tArrival"<<"\n";
        cout<<"----------------------------------------------------------------------------------"<<"\n";
        cout<<BusNo<<"\t\t"<<DriverName<<"\t"<<Departure<<"\t\t"<<Arrival<<"\n";
        cout<<"----------------------------------------------------------------------------------"<<"\n";
        cout<<"Date"<<"\t\tFrom"<<"\t\t To"<<"\t\t\tTotal Number of Seats"<<"\n";
        cout<<"----------------------------------------------------------------------------------"<<"\n";
        cout<<Date<<"\t"<<From<<"\t\t"<<To<<"\t\t\t"<<Seats<<"\n";
        cout<<"----------------------------------------------------------------------------------"<<"\n";
    }
};
class book:public Bus
{
    Bus B1;
    public:
    int sno;
    char Busid[20];
    char name[20];
    int age;
    char email[40];
    char address[40];
    char Password[20];
    char Gender[20];
    book(int sno,char Busid[],char name[],int age,char email[],char address[], char Password[],char Gender[])
    {
     this->sno=sno;
    strcpy(this->Busid,Busid);
    strcpy(this->name,name);
     this->age=age;
    strcpy(this->email,email);
    strcpy(this->address,address);
    strcpy(this->Password,Password);
    strcpy(this->Gender,Gender);
    }
    book()
    {
    sno=0;
    strcpy(Busid,"");
    strcpy(name,"");
    age=0;
    strcpy(email,"");
    strcpy(address," ");
    strcpy(Password,"");
    strcpy(Gender,"");
    }

   void displaybook()
   {
    ifstream fin("Bus1.dat");
    Bus B1;
    while(fin.read((char*)&B1,sizeof(B1)))
    {
        if(strcmp(B1.Busid,Busid)==0)
        {
        cout<<"\t\t\t*****BOOKING DETAILS*****"<<"\n";
       cout<<"++++++++++++++++++++++++++++++++++++++++++++++"<<"\n";
       cout<<"            **BUS TICKET**                     "<<"\n";
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++"<<"\n";
       cout<<"Bus Id:"<<B1.Busid<<"\n";
       cout<<"----------------------------------------------------------------------------------"<<"\n";
       cout<<"Date:"<<B1.Date<<"\n";
       cout<<"----------------------------------------------------------------------------------"<<"\n";
       cout<<"Departure From:"<<B1.From<<" at "<<B1.Departure<<"\n";
       cout<<"----------------------------------------------------------------------------------"<<"\n";
       cout<<"Arrive To:"<<B1.To<<" at "<<B1.Arrival<<"\n";
       cout<<"----------------------------------------------------------------------------------"<<"\n";
        }
    }
    cout<<"Seats Booked:"<<sno<<"\n";
    cout<<"----------------------------------------------------------------------------------"<<"\n";
    cout<<"SUCCESSFUL YOUR SEAT IS ALLOTED"<<"\n";
    cout<<"----------------------------------------------------------------------------------"<<"\n";
    cout<<"----------------------------------------------------------------------------------"<<"\n";
    cout<<"Thank You ! For Choicing This Bus"<<"\n";
    cout<<"----------------------------------------------------------------------------------"<<"\n";  
   }
    void displaycustomer()
    {
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++"<<"\n";
    cout<<"          **CUSTOMER DETAILS**                "<<"\n";
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++"<<"\n\n\n";
    cout<<"_________________________________"<<"\n";
    cout<<"| Name |:  "<<name<<"\t\t"      <<"|"<<"\n";
    cout<<"|_______________________________|"<<"\n";
    cout<<"| Age  |:  "<<age<<"\t\t\t"                 <<"|"<<"\n";
    cout<<"|_______________________________|"<<"\n";
    cout<<"|Gender|: "<<Gender<<"\t\t"               <<"|"<<"\n";
    cout<<"|_______________________________|"<<"\n";
    cout<<"|E-Mail|: "<<email<<"\t\t"                <<"|"<<"\n";
    cout<<"|_______________________________|"<<"\n";
    cout<<"|Address|: "<<address<<"\t\t\t"             <<"|"<<"\n";
    cout<<"|_______________________________|"<<"\n";

    }
   
};
class ticket
{
    public:
   char ticketid[20];
   char busid[20];
   char name[20];

   ticket( char ticketid[], char busid[], char name[])
   {
         strcpy(this->ticketid,ticketid);
         strcpy( this->busid,busid);
         strcpy(this->name,name);
   }
   ticket()
   {
    strcpy(ticketid,"");
    strcpy(busid,"");
    strcpy(name,"");
   }
  void displayticketid()
  {
    cout<<"Customer Name:"<<name<<"\n";
    cout<<"Bus Id:"<<busid<<"\n";
    cout<<"Ticket Id:"<<ticketid<<"\n";
  }
};

void ticketwrite()
{
    ticket t1;
    book B2;
    ofstream fot("ticket.dat", ios::app|ios::binary);
    ifstream fib("book.dat",ios::binary);
    int i=0;
    for(;;)
    {
        i++;
        for(;fib.read((char*)&B2,sizeof(B2));)
    {
        B2.displaybook();
        B2.displaycustomer();
    }
        cout<<"Enter Customer Name:";
        cin>>t1.name;
        cout<<"Enter Bus Id:";
        cin>>t1.busid;
        cout<<"Enter Ticket Id:";
        cin>>t1.ticketid;
        fot.write((char*)(&t1),sizeof(t1));
        string choice;
       cout<<"If you want to Add More Ticket Id ?"<<"\n";
       cout<<"Yes/No"<<"\n";
       cin >> choice;
       cin.ignore();

       if( choice != "yes" && choice != "Yes")
       {
        cout<<choice;
        break;
        }

        }
        fot.close();
        fib.close();
    }
    void ticketread()
    {
        ticket t1;
        ifstream fin("ticket.dat", ios::binary);
        for (;fin.read((char*)(&t1), sizeof(t1));)   
        {
           t1.displayticketid();
        }
        fin.close();
    }
int main()
{
    
    // ticketwrite();
    ticketread();
}