#include <iostream>
#include <fstream>
#include <cstring>
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

    Bus()
    {
        strcpy(Busid, "");
        strcpy(BusNo, " ");
        strcpy(DriverName, " ");
        strcpy(Departure, " ");
        strcpy(Arrival, " ");
        strcpy(From, " ");
        strcpy(To, " ");
        strcpy(Date, " ");
        strcpy(Day, " ");
        strcpy(Seats, " ");
    }

    void Tabular()
    {   
        cout<<"\t\t\t***BUS DETAILS***"<<"\n\n";
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

    void AddaBus()
    {
        Bus B1;
        int i = 0;
        ofstream fout("Bus1.dat",ios::app|ios::binary);
        for (;;)
        {
            i++;
            cout<<"\t\t\t**Bus Management System**\n";
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

            if (choice != "yes" && choice != "Yes")
            {
                break;
            }
            cout<<"Thank You For Adding Bus";
        }
        fout.close();
    }

    void ReadaBus()
    {
        Bus B1;
        ifstream fin("Bus1.dat", ios::binary);
        if (!fin)
        {
            cout<<"There is No Bus For this Rout";
            return;
        }
        for (; fin.read((char*)(&B1), sizeof(B1));)
        {
            B1.Tabular();
        }
        fin.close();
    }

    void search()
    {
        Bus B1;
        ifstream fin("Bus1.dat", ios::binary);
        if (!fin)
        {
            cout<<"There is No Bus For this Rout";
            return;
        }
        int i = 0;
        for (;;)
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
            while (fin.read((char*)(&B1), sizeof(B1)))
            {
                if (find == B1.From && found == B1.To && Time == B1.Date)
                {
                    cout<<"Bus is Found"<<"\n";
                    B1.Tabular();
                }
            }
            if (B1.From != find || found != B1.To || Time != B1.Date)
            {
                cout<<"Bus is not found"<<"\n";
            }
            string choice;
            cout<<"Do you want to Search Another Bus ?"<<"\n";
            cout<<"Yes/No"<<"\n";
            cin >> choice;
            cin.ignore();
            if (choice != "yes" && choice != "Yes")
            {
                break;
            }  
        }
        fin.close();
    }

    void readacopyfile()
    {
        Bus B1;
        ifstream fin("Buscopy.dat", ios::binary);
        if (!fin) 
        {
            cout<<"Error opening file."<<"\n";
            return;
        }
        while (fin.read((char*)(&B1), sizeof(B1)))
        {
            B1.Tabular();
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
            cout<<"Error opening file."<<"\n";
            return;
        }
        while (fin.read((char*)(&B1), sizeof(B1)))
        {
            fout.write((char*)&B1, sizeof(B1));
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
        while (fin.read((char*)(&B1), sizeof(B1)))
        {
            if (find != B1.BusNo)
            {
                fout.write((char*)&B1, sizeof(B1));
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
            cout<<"Error opening file."<<"\n";
            return;
        }
        while (fin.read((char*)(&B1), sizeof(B1)))
        {
            B1.Tabular();
        }
        fin.close();     
    }

    void UpdateRecord()
    {
        Bus B1;
        ifstream fin("Bus1.dat", ios::binary);
        ofstream fout("temp.dat", ios::binary);
        string find;
        cout<<"Enter a Bus Number which we want to update:";
        cin>>find;
        while (fin.read((char*)(&B1), sizeof(B1)))
        {
            if (find == B1.BusNo)
            {
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
            }
            fout.write((char*)&B1, sizeof(B1));
        }
        fin.close();
        fout.close();
        remove("Bus1.dat");
        rename("temp.dat","Bus1.dat"); 
    }
};

class book : public Bus
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

    book(int sno, char Busid[], char name[], int age, char email[], char address[], char Password[], char Gender[])
    {
        this->sno = sno;
        strcpy(this->Busid, Busid);
        strcpy(this->name, name);
        this->age = age;
        strcpy(this->email, email);
        strcpy(this->address, address);
        strcpy(this->Password, Password);
        strcpy(this->Gender, Gender);
    }

    book()
    {
        sno = 0;
        strcpy(Busid, "");
        strcpy(name, "");
        age = 0;
        strcpy(email, "");
        strcpy(address, " ");
        strcpy(Password, "");
        strcpy(Gender, "");
    }

    void displaybook()
    {
        ifstream fin("Bus1.dat");
        Bus B1;
        while (fin.read((char*)&B1, sizeof(B1)))
        {
            if (strcmp(B1.Busid, Busid) == 0)
            {
                cout << "\t\t\t***BOOKING DETAILS***" << "\n";
                cout << "++++++++++++++++++++++++++++++++++++++++++++++" << "\n";
                cout << "BUS TICKET" << "\n";
                cout << "++++++++++++++++++++++++++++++++++++++++++++++" << "\n";
                cout << "Bus Id:" << B1.Busid << "\n";
                cout << "----------------------------------------------------------------------------------" << "\n";
                cout << "Date:" << B1.Date << "\n";
                cout << "----------------------------------------------------------------------------------" << "\n";
                cout << "Departure From:" << B1.From << " at " << B1.Departure << "\n";
                cout << "----------------------------------------------------------------------------------" << "\n";
                cout << "Arrive To:" << B1.To << " at " << B1.Arrival << "\n";
                cout << "----------------------------------------------------------------------------------" << "\n";
            }
        }
        cout << "Seats Booked:" << sno << "\n\n\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << "\n";
        cout << "CUSTOMER DETAILS" << "\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++++++" << "\n";
        cout << "Name:" << name << "\n";
        cout << "Age:" << age << "\n";
        cout << "Gender:" << Gender << "\n";
        cout << "E-Mail:" << email << "\n";
        cout << "Address:" << address << "\n";
        cout << "----------------------------------------------------------------------------------" << "\n";
        cout << "SUCCESSFUL YOUR SEAT IS ALLOTED" << "\n";
        cout << "----------------------------------------------------------------------------------" << "\n";
        cout << "----------------------------------------------------------------------------------" << "\n";
        cout << "Thank You! For Choosing This Bus" << "\n";
        cout << "----------------------------------------------------------------------------------" << "\n";
    }
};

int bookwrite()
{
    book B2;
    Bus B1;
    ofstream fob("book.dat", ios::binary | ios::app);
    ifstream fin("Bus1.dat", ios::binary);
    if (!fin)
    {
        cout << "There is No Bus For this Rout";
        return 0;
    }
    int s = 0;
    string find;
    string found;
    string Time;
    cout << "Enter a Journey you Start From:";
    cin >> find;
    cout << "Enter a Journey you End To:";
    cin >> found;
    cout << "Date Of Journey (Date/Month/Year):";
    cin >> Time;
    while (fin.read((char*)(&B1), sizeof(B1)))
    {
        if (find == B1.From && found == B1.To && Time == B1.Date)
        {
            s = 1;
            cout << "Bus is Found" << "\n";
            B1.Tabular();
            cout << "\t\t\t*CONTINUE THE AMAZING JOURNEY*" << "\n";
            cout << "--PLEASE ENTER YOUR PERSONAL DETAILS FOR BOOKING TICKETS---" << "\n";
            cout << "Enter Your Name:";
            cin >> B2.name;
            cout << "Enter Your Age:";
            cin >> B2.age;
            cout << "Enter Your Gender(Male/Female):";
            cin >> B2.Gender;
            cout << "Enter Your E-Mail:";
            cin >> B2.email;
            cout << "Enter Your Address:";
            cin >> B2.address;
            cout << "Enter Your Password :";
            cin >> B2.Password;
            cout << "----------------------------------------------------------------------------------" << "\n";
            cout << "Please Enter Bus ID:";
            cin >> B2.Busid;
            cout << "Enter Number of Seats:";
            cin >> B2.sno;
            cout << "----------------------------------------------------------------------------------" << "\n";
            cout << "Thank You! For Choosing This Bus" << "\n";
            cout << "----------------------------------------------------------------------------------" << "\n";
            break;
        }
    }
    if (B1.From != find || found != B1.To || Time != B1.Date)
    {
        cout << "Bus is not found" << "\n";
    }
    fob.write((char*)&B2, sizeof(B2));
    fob.close();
    fin.close();
    return s;
}

void Book()
{
    ofstream fob("book.dat", ios::app | ios::binary);
    while (true)
    {
        int s = bookwrite();
        if (s == 1)
        {
            break;
        }
        else
            cout << " ";
    }
    fob.close();
}
void bookread()
{
    book B2;
    ifstream fib("book.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);
    bool isCancelled = false;
    
    for (; fib.read((char*)&B2, sizeof(B2));)
    {
        B2.displaybook();

        cout << "Do you want to cancel this ticket? (Yes/No): ";
        string choice;
        cin >> choice;

        if (choice == "Yes" || choice == "yes")
        {
            isCancelled = true;
            cout << "Ticket cancelled successfully!" << "\n";
        }
        
        if (!isCancelled)
        {
            fout.write((char*)&B2, sizeof(B2));
        }

        isCancelled = false;
    }

    fib.close();
    fout.close();
    
    // Delete the original file
    remove("book.dat");
    
    // Rename the temporary file as the new book.dat
    rename("temp.dat", "book.dat");
}
void busdata()
{
    int choice;
    do {
        cout << "\t\t\t**Bus Management System**\n";
        cout << "1. Add a Bus\n";
        cout << "2. Display All Buses\n";
        cout << "3. Search a Bus\n";
        cout << "4. Delete a Bus Record\n";
        cout << "5. Update a Bus Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Bus().AddaBus();
                break;
            case 2:
                Bus().ReadaBus();
                break;
            case 3:
                Bus().search();
                break;
            case 4:
                Bus().readdelete();
                Bus().DeleteRecord();
                break;
            case 5:
                Bus().readacopyfile();
                Bus().UpdateRecord();
                break;
            case 6:
                cout << "Thank you for using the Bus Management System.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }

        cout << "---------------------------------------\n";
    } while (choice != 6);
}

void bookticket()
{
    int choice;
    cout << "***** BUS BOOKING SYSTEM *****" << "\n";
    cout << "1. Book a Bus" << "\n";
    cout << "2. cansel tiket Bookings" << "\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            Book();
            break;
        case 2:
            bookread();
            break;
        case 3:
            cout << "Thank you for using the bus booking System.\n";
            break;
        default:
            cout << "Invalid choice!" << "\n";
            break;
    }
}

int main()
{
    int choice;
    cout << "***** BUS SYSTEM *****" << "\n";
    cout << "1. Bus Management System" << " \n";
    cout << "2. BUS BOOKING SYSTEM " << "\n";
    cout << "3. Exit" << "\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
            busdata();
            break;
        case 2:
            bookticket();
            break;
        case 3:
            cout << "Thank you for using the bus System." << "\n";
            break;
        default:
            cout << "Invalid choice!" << "\n";
          break;
}
}
