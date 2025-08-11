#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
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
    // void Tabular()
    // {   
    //     cout<<"\t\t\t*****BUS DETAILS*****"<<"\n\n";
    //     cout<<"Bus ID:"<<Busid<<"\n";
    //     cout<<"----------------------------------------------------------------------------------"<<"\n";
    //     cout<<"Bus Number"<<setw(15)<<"Driver Name"<<setw(15)<<"Departure"<<setw(15)<<"Arrival"<<"\n";
    //     cout<<"----------------------------------------------------------------------------------"<<"\n";
    //     cout<<BusNo<<setw(15)<<DriverName<<setw(15)<<Departure<<setw(15)<<Arrival<<"\n";
    //     cout<<"----------------------------------------------------------------------------------"<<"\n";
    //     cout<<"Date"<<setw(15)<<"From"<<setw(15)<<"To"<<setw(20)<<"Total Number of Seats"<<"\n";
    //     cout<<"----------------------------------------------------------------------------------"<<"\n";
    //     cout<<Date<<setw(15)<<From<<setw(15)<<To<<setw(15)<<Seats<<"\n";
    //     cout<<"----------------------------------------------------------------------------------"<<"\n";
    // }
     void Tabular()
    {
        cout << setw(20) << left << "***BUS DETAILS***" << "\n\n";
        cout << setw(15) << left << "Bus ID: " << Busid << "\n";
        cout << "-----------------------------------------------------------------------" << "\n";
        cout << setw(15) << left << "Bus Number" << setw(15) << left << "Driver Name" << setw(15) << left << "Departure" << setw(15) << left << "Arrival" << "\n";
        cout << "-----------------------------------------------------------------------" << "\n";
        cout << setw(15) << left << BusNo << setw(15) << left << DriverName << setw(15) << left << Departure << setw(15) << left << Arrival << "\n";
        cout << "-----------------------------------------------------------------------" << "\n";
        cout << setw(15) << left << "Date" << setw(15) << left << "From" << setw(15) << left << "To" << setw(15) << left << "Total Number of Seats" << "\n";
        cout << "-----------------------------------------------------------------------" << "\n";
        cout << setw(15) << left << Date << setw(15) << left << From << setw(15) << left << To << setw(15) << left << Seats << "\n";
        cout << "-----------------------------------------------------------------------" << "\n";
    }

};
class ticket
{
    public:
   char ticketid[20];
   char busid[20];
   char name[40];

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
class book:public Bus , public ticket
{
    Bus B1;
    public:
    int sno;
    char Busid[20];
    char ticketid[20];
    char name[40];
    int age;
    char email[40];
    char address[40];
    char Password[20];
    char Gender[20];
    book(int sno, char ticketid[],char Busid[],char name[],int age,char email[],char address[], char Password[],char Gender[])
    {
     this->sno=sno;
    strcpy(this->Busid,Busid);
    strcpy(this->ticketid,ticketid);
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
    strcpy(ticketid,"");
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
       cout<<"          **BUS TICKET**                      "<<"\n";
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++"<<"\n";
       cout<<"----------------------------------------------------------------------------------"<<"\n";
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
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++"<<"\n";
    cout<<"Seats Booked:"<<sno<<"\n\n\n";
    cout<<"++++++++++++++++++++++++++++++++++++++++++++++"<<"\n";
    cout<<"----------------------------------------------------------------------------------"<<"\n";
   cout<<"SUCCESSFUL YOUR SEAT IS ALLOTED"<<"\n";
   cout<<"----------------------------------------------------------------------------------"<<"\n";
   cout<<"----------------------------------------------------------------------------------"<<"\n";
   cout<<"Thank You ! For Choicing This Bus"<<"\n";
   cout<<"----------------------------------------------------------------------------------"<<"\n";  
   }
   void customerdetails()
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

int bookwrite()
{
    book B2;
    Bus B1;
    ticket t1;
    ofstream fob("book.dat",ios::binary|ios::app);
    ifstream fin("Bus1.dat", ios::binary);
    ifstream fit("ticket.dat",ios::binary);
    if(!fin)
    {
    cout<<"There is No Bus For this Rout";
    }
    int s=0;    
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
        B1.Tabular();
        cout<<"\t\t\t***CONTINUE THE AMAZING JOURNEY***"<<"\n";
        cout<<"--PLEASE ENTER YOUR PERSONAL DETAILS FOR BOOKING TICKETS---"<<"\n";
        cout<<"Enter Your Name:";
        cin>>B2.name;
        cout<<"Enter Your Age:";
        cin>>B2.age;
        cout<<"Enter Your Gender(Male/Female):";
        cin>>B2.Gender;
        cout<<"Enter Your E-Mail:";
        cin>>B2.email;
        cout<<"Enter Your Address:";
        cin>>B2.address;
        cout<<"Enter Your Password :";
        cin>>B2.Password;
        cout<<"----------------------------------------------------------------------------------"<<"\n";
        cout<<"****Ticket Id details*****"<<"\n";
         string nameid;
        cout<<"Please Enter Your name(TICKET ID ALLOTEMENT):";
        cin>>nameid;
         while(fin.read((char*)(&t1), sizeof(t1)))
        {
            if(nameid==t1.name)
            {
                cout<<"YOUR TICKET ID IS SUCCESSFULLY ALLOTED"<<"\n";
            }
        }
        cout<<"----------------------------------------------------------------------------------"<<"\n";
        cout<<"----------------------------------------------------------------------------------"<<"\n";
        cout<<"Please Enter Ticket ID:";
        cin>>B2.ticketid;
        cout<<"Please Enter Bus ID:";
        cin>>B2.Busid;
        cout<<"Enter Number of Seats:";
        cin>>B2.sno;
        cout<<"----------------------------------------------------------------------------------"<<"\n";
        cout<<"Thank You ! For Choicing This Bus"<<"\n";
        cout<<"----------------------------------------------------------------------------------"<<"\n";
        break;
        }
    }
     if(B1.From!=find || found!=B1.To || Time!=B1.Date)
    {
       cout<<"Bus is not found"<<"\n";
    }
    fob.write((char*)&B2,sizeof(B2));
    return s;
    fob.close();
    fin.close();
}
void Book()
{
    ofstream fob("book.dat",ios::app|ios::binary);
    while(true)
    {
    int s=bookwrite();
    if(s==1)
    {
        break;
    }
    else
        cout<<" ";
    }
    fob.close();
}
void bookread()
{
    book B2;
    ifstream fib("book.dat",ios::binary);
    for(;fib.read((char*)&B2,sizeof(B2));)
    {
        
        B2.displaybook();
    }
    fib.close();
}
void customer()
{
     book B2;
    ifstream fib("book.dat",ios::binary);
    for(;fib.read((char*)&B2,sizeof(B2));)
    {
        
        B2.customerdetails();
    }
    fib.close();
}

int main()
{
    // bookwrite();/
    Book();
    // bookread();
//     // customer();
}