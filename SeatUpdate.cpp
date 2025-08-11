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
void copy()
{
    passenger P1;
    ifstream fip("user.dat", ios::binary);
    ofstream fop("usercopy.dat", ios::binary);
    if (!fip) 
    {
        cout << "Error opening file." << "\n";
        return;
    }
    while(fip.read((char*)(&P1), sizeof(P1)))
    {
        fop.write((char*)&P1,sizeof(P1));
    }
    fip.close();  
    fop.close();
    remove("user.dat");
    rename("usercopy.dat","user.dat");
}
void readcopy()
{
    passenger P1;
    ifstream fip("user.dat", ios::binary);
    if (!fip) 
    {
        cout << "Error opening file." << "\n";
        return;
    }
    while(fip.read((char*)(&P1), sizeof(P1)))
    {
        P1.Display1();
    }
    fip.close();   
}
void deleteuser()
{
    passenger P1;
   ifstream fip("user.dat", ios::binary);
   ofstream fop("temp1.dat", ios::binary);
   string find;
   cout<<"Enter a Name which we want to delete:";
   cin>>find;
   while(fip.read((char*)(&P1), sizeof(P1)))
    {
        if(find!=P1.name)
        {
            fop.write((char*)&P1,sizeof(P1));
        }
    }
    fip.close();
    fop.close();
    remove("user.dat");
    rename("temp1.dat","user.dat");
}
void readdeleteuser()
{
    passenger P1;
   ifstream fip("user.dat", ios::binary);
    if (!fip) 
    {
        cout << "Error opening file." << "\n";
        return;
    }
   while(fip.read((char*)(&P1), sizeof(P1)))
    {
        P1.Display1();
    }
    fip.close();      
}
void updateuser()
{
   passenger P1;
    ifstream fip("user.dat", ios::binary);
    ofstream fop("temp1.dat", ios::binary);
    string  find;
    cout<<"Enter Your Name which we want to update:";
    cin>>find;
    while(fip.read((char*)(&P1), sizeof(P1)))
    {
        if(find==P1.name)
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
        }
        fop.write((char*)&P1,sizeof(P1));
    }
    fip.close();
    fop.close();
    remove("user.dat");
    rename("temp1.dat","user.dat");  
}
int main()
{
//   copy();
//   readcopy();
//   deleteuser();
//   readdeleteuser();
  updateuser();  
}