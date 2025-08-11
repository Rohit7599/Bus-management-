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
class book 
{
    

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

   void displaybook2()
   {
    ifstream fin("Bus1.dat");
    Bus B1;
    while(fin.read((char*)&B1,sizeof(B1)))
    {
        if(strcmp(B1.Busid,Busid)==0)
        {
        cout<<"\t\t\t*****BOOKING DETAILS*****"<<"\n";
       cout<<"++++++++++++++++++++++++++++++++++++++++++++++"<<"\n";
       cout<<"**BUS TICKET**"<<"\n";
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
       cout<<"Seats Booked:"<<sno<<"\n\n\n";
        cout<<"++++++++++++++++++++++++++++++++++++++++++++++"<<"\n";
//        cout<<"**CUSTOMER DETAILS**"<<"\n";
//        cout<<"Name:"<<name<<"\n";
//        cout<<"Age:"<<age<<"\n";
//        cout<<"Gender:"<<Gender<<"\n";
//        cout<<"E-Mail:"<<email<<"\n";
//        cout<<"Address:"<<address<<"\n";

//     cout<<"----------------------------------------------------------------------------------"<<"\n";
//    cout<<"SUCCESSFUL YOUR SEAT IS ALLOTED"<<"\n";
//    cout<<"----------------------------------------------------------------------------------"<<"\n";
//    cout<<"----------------------------------------------------------------------------------"<<"\n";
//    cout<<"Thank You ! For Choicing This Bus"<<"\n";
//    cout<<"----------------------------------------------------------------------------------"<<"\n"; 
       
   }
};
int booksearch()
{
    book B2;
    Bus B1;
    ifstream fib("book.dat", ios::binary);
    //  ifstream fin("bus1.dat", ios::binary);
    if(!fib)
    {
    cout<<"There is No Bus For this Rout";
    }
    int s=0;    
    string find;
    string found;
    cout<<"Enter Your Name:";
    cin>>find;
    cout<<"Enter Your Email:";
    cin>>found;
     while(fib.read((char*)(&B2), sizeof(B2)))
    {
        if(find==B2.name && found==B2.email)
        {
        s=1;
        cout<<"Booking is Found"<<"\n";
        B2.displaybook2();
        }
    }
     if(B2.Busid!=find)
    {
       cout<<"Booking is not found"<<"\n";
    }
    return s;
    fib.close();
}
void Book()
{
    while(true)
    {
    int s=booksearch();
    if(s==1)
    {
        break;
    }
    else
        cout<<"";
    }
}
void BookCopy()
{
    book B2;
    ifstream fin("book.dat", ios::binary);
    ofstream fout("Bookcopy.dat", ios::binary);
    if (!fin) 
    {
        cout << "Error opening file." << "\n";
        return;
    }
    while(fin.read((char*)(&B2), sizeof(B2)))
    {
        fout.write((char*)&B2,sizeof(B2));
    }
    fin.close();  
    fout.close();
    // remove("Bus1.dat");
    // rename("Buscopy.dat","Bus1.dat");
}
void bookreadcopy()
{
     book B2;
    ifstream fin("Book.dat", ios::binary);
    if (!fin) 
    {
        cout << "Error opening file." << "\n";
        return;
    }
    while(fin.read((char*)(&B2), sizeof(B2)))
    {
        cout<<"YOUR TICKET IS CANCELLED!!!!"<<"\n";
    }
    fin.close();
}
void deletebook()
{
     book B2;
   ifstream fin("book.dat", ios::binary);
   ofstream fout("temp3.dat", ios::binary);
   string find;
   cout<<"Enter a Bus ID which we want to delete:";
   cin>>find;
   while(fin.read((char*)(&B2), sizeof(B2)))
    {
        if(find!=B2.Busid)
        {
            fout.write((char*)&B2,sizeof(B2));
        }
    }
    fin.close();
    fout.close();
    remove("book.dat");
    rename("temp3.dat","book.dat");
}
void readdeletebook()
{
    book B2;
   ifstream fin("book.dat", ios::binary);
    if (!fin) 
    {
        cout << "Error opening file." << "\n";
        return;
    }
   while(fin.read((char*)(&B2), sizeof(B2)))
    {
        cout<<"YOUR TICKET IS CANCELLED!!!"<<"\n";
    }
    fin.close();  
}
int main()
{
    booksearch();
    // Book();
    // BookCopy();
    // bookreadcopy();
    // deletebook();
    // readdeletebook();
}