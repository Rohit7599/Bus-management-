#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class passenger
{
    public:
    char name[20];
    int age;
    char email[40];
    char address[40];
    char password[20];
    char Password[20];
    char Gender[20];
   passenger()
   {
    strcpy(name,"");
    age=0;
    strcpy(email,"");
    strcpy(address," ");
    strcpy(password,"");
    strcpy(Password,"");
    strcpy(Gender,"");
   }
   void Display1()
   {   
       cout<<"\t\t\t*****PERSONAL DETAILS*****"<<"\n\n";
       cout<<"Name:"<<name<<"\n";
       cout<<"Age:"<<age<<"\n";
       cout<<"Gender:"<<Gender<<"\n";
       cout<<"E-Mail:"<<email<<"\n";
       cout<<"Address:"<<address<<"\n";
       cout<<"Password:"<<Password<<"\n";
       cout<<"THANK YOU!"<< name <<" FOR ADDING YOUR PERSONAL DETAILS"<<"\n";
   }
};
void Details()
{
    passenger P1;
    ofstream fop("user.dat",ios::app|ios::binary);
    int i=0;
    for(;;)
    {
    cout<<"Enter Your Name:";
    cin>>P1.name;
    cout<<"Enter Your Age:";
    cin>>P1.age;
    cout<<"Enter Your Gender(Male/Female):";
    cin>>P1.Gender;
    cout<<"Enter Your E-Mail:";
    cin>>P1.email;
    cout<<"Enter Your Address:";
    cin>>P1.address;
    cout<<"Enter Your Password :";
    cin>>P1.Password;

    fop.write((char*)(&P1),sizeof(P1));
    string choice;
    cout<<"If you want to Add More Personal Details ?"<<"\n";
    cout<<"Yes/No"<<"\n";
    cin >> choice;
    cin.ignore();

    if( choice != "yes" && choice != "Yes")
    {
    cout<<choice;
    break;
    }
    }
    fop.close();
}
void readDetails()
{
    passenger P1;
    ifstream fip("user.dat", ios::binary);
    for (;fip.read((char*)(&P1), sizeof(P1));)   
    {
        P1.Display1();
    }
    fip.close();
}
int main()
{
    // Details();
    readDetails();
}