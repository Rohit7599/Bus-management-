#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <iomanip>
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
    void Display()
    {
        cout << "Bus ID:" << Busid << "\n";
        cout << "Bus Number:" << BusNo << "\n";
        cout << "Driver Name:" << DriverName << "\n";
        cout << "Departure Timings:" << Departure << "     From:" << From << "\n";
        cout << "Arrival Timings:" << Arrival << "       To:" << To << "\n";
        cout << "Date Of Journey:" << Date << "           Day Of Journey:" << Day << "\n";
        cout << "Number of Seats in a Bus:" << Seats << "\n";
        cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
             << "\n";
    }

    void Tabular()
    {
        cout << setw(20) << left << "***BUS DETAILS***"
             << "\n\n";
        cout << setw(15) << left << "Bus ID: " << Busid << "\n";
        cout << "-----------------------------------------------------------------------"
             << "\n";
        cout << setw(15) << left << "Bus Number" << setw(15) << left << "Driver Name" << setw(15) << left << "Departure" << setw(15) << left << "Arrival"
             << "\n";
        cout << "-----------------------------------------------------------------------"
             << "\n";
        cout << setw(15) << left << BusNo << setw(15) << left << DriverName << setw(15) << left << Departure << setw(15) << left << Arrival << "\n";
        cout << "-----------------------------------------------------------------------"
             << "\n";
        cout << setw(15) << left << "Date" << setw(15) << left << "From" << setw(15) << left << "To" << setw(15) << left << "Total Number of Seats"
             << "\n";
        cout << "-----------------------------------------------------------------------"
             << "\n";
        cout << setw(15) << left << Date << setw(15) << left << From << setw(15) << left << To << setw(15) << left << Seats << "\n";
        cout << "-----------------------------------------------------------------------"
             << "\n";
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
        while (fin.read((char *)&B1, sizeof(B1)))
        {
            if (strcmp(B1.Busid, Busid) == 0)
            {
                cout << "\t\t\t*****BOOKING DETAILS*****"
                     << "\n";
                cout << "++++++++++++++++++++++++++++++++++++++++++++++"
                     << "\n";
                cout << "            **BUS TICKET**                     "
                     << "\n";
                cout << "++++++++++++++++++++++++++++++++++++++++++++++"
                     << "\n";
                cout << "Bus Id:" << B1.Busid << "\n";
                cout << "----------------------------------------------------------------------------------"
                     << "\n";
                cout << "Date:" << B1.Date << "\n";
                cout << "----------------------------------------------------------------------------------"
                     << "\n";
                cout << "Departure From:" << B1.From << " at " << B1.Departure << "\n";
                cout << "----------------------------------------------------------------------------------"
                     << "\n";
                cout << "Arrive To:" << B1.To << " at " << B1.Arrival << "\n";
                cout << "----------------------------------------------------------------------------------"
                     << "\n";
            }
        }
        cout << "Seats Booked:" << sno << "\n";
        cout << "----------------------------------------------------------------------------------"
             << "\n";
        cout << "SUCCESSFUL YOUR SEAT IS ALLOTED"
             << "\n";
        cout << "----------------------------------------------------------------------------------"
             << "\n";
        cout << "----------------------------------------------------------------------------------"
             << "\n";
        cout << "Thank You ! For Choicing This Bus"
             << "\n";
        cout << "----------------------------------------------------------------------------------"
             << "\n";
    }
    void displaycustomer()
    {
        cout << "++++++++++++++++++++++++++++++++++++++++++++++"
             << "\n";
        cout << "          **CUSTOMER DETAILS**                "
             << "\n";
        cout << "++++++++++++++++++++++++++++++++++++++++++++++"
             << "\n\n\n";
        cout << "_________________________________"
             << "\n";
        cout << "| Name |:  " << setw(10) << name << setw(12) << "|"
             << "\n";
        cout << "|_______________________________|"
             << "\n";
        cout << "| Age  |:  " << setw(10) << age << setw(12) << "|"
             << "\n";
        cout << "|_______________________________|"
             << "\n";
        cout << "|Gender|: " << setw(10) << Gender << setw(13) << "|"
             << "\n";
        cout << "|_______________________________|"
             << "\n";
        cout << "|E-Mail|: " << setw(10) << email << setw(13) << "|"
             << "\n";
        cout << "|_______________________________|"
             << "\n";
        cout << "|Address|: " << setw(10) << address << setw(12) << "|"
             << "\n";
        cout << "|_______________________________|"
             << "\n";
    }
};

void AddaBus() // Add a Bus Part-1
{
    Bus B1;
    int i = 0;
    ofstream fout("Bus1.dat", ios::app | ios::binary);
    for (;;)
    {
        i++;
        cout << "\t\t\t****Bus Management System****\n";
        cout << "1.Add A Bus\n";
        cout << "Enter Bus ID:";
        cin >> B1.Busid;
        cout << "Enter Bus Number:";
        cin >> B1.BusNo;
        cout << "Enter Driver Name:";
        cin >> B1.DriverName;
        cout << "Enter Departure Timings(12 hr format):";
        cin >> B1.Departure;
        cout << "Enter Arrival Timings(12 hr format):";
        cin >> B1.Arrival;
        cout << "From:";
        cin >> B1.From;
        cout << "To:";
        cin >> B1.To;
        cout << "Enter Date of Journey(DD/MM/YYYY):";
        cin >> B1.Date;
        cout << "Enter Day Of Journey:";
        cin >> B1.Day;
        cout << "Enter Number of Seats in a Bus:";
        cin >> B1.Seats;

        fout.write((char *)(&B1), sizeof(B1));
        string choice;
        cout << "If you want to Add More Bus ?"
             << "\n";
        cout << "Yes/No"
             << "\n";
        cin >> choice;
        cin.ignore();

        if (choice != "yes" && choice != "Yes")
        {
            cout << choice;
            break;
        }
        cout << "Thank You For Adding Bus";
    }
    fout.close();
}
void ReadaBus() // Routs of Bus Part-2
{
    Bus B1;
    ifstream fin("Bus1.dat", ios::binary);
    for (; fin.read((char *)(&B1), sizeof(B1));)
    {
        B1.Display();
    }
    fin.close();
}
void search() // Search a Bus Part-3
{
    Bus B1;
    ifstream fin("Bus1.dat", ios::binary);
    if (!fin)
    {
        cout << "There is No Bus For this Rout";
        return;
    }
    int i = 0;
        string choice;
    // do
    // {
        
        char find[20];
        char found[20];
        char Time[20];
        cout << "Enter a Journey you Start From:";
        cin >> find;
        cout << "Enter a Journey you End To:";
        cin >> found;
        cout << "Date Of Journey (Date/Month/Year):";
        cin >> Time;
        int c = 0;

        while (fin.read((char *)(&B1), sizeof(B1)))
        {
            if (strcmp(find, B1.From) == 0 && strcmp(found, B1.To) == 0 && strcmp(Time, B1.Date) == 0)
            {
                c = 1;
                cout << "Bus is Found"
                     << "\n";
                B1.Display();
                break;
                // goto exitloop;
            }
        }

        if (c == 0)
        {
            cout << "Bus is not found"
                 << "\n";
        }
        // cout << "Do you want to Search Another Bus ?"
        //      << "\n";
        // cout << "Yes/No"
        //      << "\n";
        // cin >> choice;
        // cin.ignore();
        // if (choice != "yes" && choice != "Yes")
        // {
        //     cout << choice;
        //     break;
        // }
    // }while(choice != "yes" && choice != "Yes");
    // exitloop:
    fin.close();
}
void readacopyfile() // Copy a file for Update And Delete
{
    Bus B1;
    ifstream fin("Buscopy.dat", ios::binary);
    if (!fin)
    {
        cout << "Error opening file."
             << "\n";
        return;
    }
    while (fin.read((char *)(&B1), sizeof(B1)))
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
        cout << "Error opening file."
             << "\n";
        return;
    }
    while (fin.read((char *)(&B1), sizeof(B1)))
    {
        fout.write((char *)&B1, sizeof(B1));
    }
    fin.close();
}
void DeleteRecord() // Delete a Bus Record Part-4
{
    Bus B1;
    ifstream fin("Bus1.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);
    string find;
    cout << "Enter a Bus ID which we want to delete:";
    cin >> find;
    while (fin.read((char *)(&B1), sizeof(B1)))
    {
        if (find != B1.Busid)
        {
            fout.write((char *)&B1, sizeof(B1));
        }
    }
    fin.close();
    fout.close();
    remove("Bus1.dat");
    rename("temp.dat", "Bus1.dat");
}
void readdelete()
{
    Bus B1;
    ifstream fin("Bus1.dat", ios::binary);
    if (!fin)
    {
        cout << "Error opening file."
             << "\n";
        return;
    }
    while (fin.read((char *)(&B1), sizeof(B1)))
    {
        B1.Display();
    }
    fin.close();
}
void UpdateRecord() // Update a Bus Record Part-5
{
    Bus B1;
    ifstream fin("Bus1.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);
    string find;
    cout << "Enter a Bus ID which we want to update:";
    cin >> find;
    while (fin.read((char *)(&B1), sizeof(B1)))
    {
        if (find == B1.Busid)
        {
            cout << "Enter Bus ID:";
            cin >> B1.Busid;
            cout << "Enter Bus Number:";
            cin >> B1.BusNo;
            cout << "Enter Driver Name:";
            cin >> B1.DriverName;
            cout << "Enter Departure Timings:";
            cin >> B1.Departure;
            cout << "Enter Arrival Timings:";
            cin >> B1.Arrival;
            cout << "From:";
            cin >> B1.From;
            cout << "To:";
            cin >> B1.To;
            cout << "Enter Date of Journey:";
            cin >> B1.Date;
            cout << "Enter Day Of Journey:";
            cin >> B1.Day;
            cout << "Enter Number of Seats in a Bus:";
            cin >> B1.Seats;
            cout << "*************************************************************"
                 << "\n";
            cout << " SUCCESFULLY UPDATED BUS DETAILs "
                 << "\n";
            cout << "*************************************************************"
                 << "\n";
        }
        // else if (find != B1.Busid)
        // {
        //     cout << "--------------------------------------------------------"
        //          << "\n";
        //     cout << "NO BUS IS FOUND"
        //          << "\n";
        //     cout << "--------------------------------------------------------"
        //          << "\n";
        //     Sleep(100);
        // }
        fout.write((char *)&B1, sizeof(B1));
    }
    fin.close();
    fout.close();
    remove("Bus1.dat");
    rename("temp.dat", "Bus1.dat");
}

int bookwrite()
{
    book B2;
    Bus B1;
    ofstream fob("book.dat", ios::binary | ios::app);
    ifstream fin("Bus1.dat", ios::binary);
    if (!fin)
    {
        cout << "There is No Bus For this Rout";
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
    while (fin.read((char *)(&B1), sizeof(B1)))
    {
        if (find == B1.From && found == B1.To && Time == B1.Date)
        {
            s = 1;
            cout << "Bus is Found"
                 << "\n";
            B1.Tabular();
            cout << "\t\t\t***CONTINUE THE AMAZING JOURNEY***"
                 << "\n";
            cout << "--PLEASE ENTER YOUR PERSONAL DETAILS FOR BOOKING TICKETS---"
                 << "\n";
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
            cout << "----------------------------------------------------------------------------------"
                 << "\n";
            cout << "Please Enter Bus ID:";
            cin >> B2.Busid;
            cout << "Enter Number of Seats:";
            cin >> B2.sno;
            cout << "----------------------------------------------------------------------------------"
                 << "\n";
            cout << "Thank You ! For Choicing This Bus"
                 << "\n";
            cout << "----------------------------------------------------------------------------------"
                 << "\n";
            break;
        }
    }
    if (B1.From != find || found != B1.To || Time != B1.Date)
    {
        cout << "Bus is not found"
             << "\n";
    }
    fob.write((char *)&B2, sizeof(B2));
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
    for (; fib.read((char *)&B2, sizeof(B2));)
    {
        B2.displaybook();
    }
    fib.close();
}

void customerread()
{
    book B2;
    ifstream fib("book.dat", ios::binary);
    for (; fib.read((char *)&B2, sizeof(B2));)
    {
        B2.displaycustomer();
    }
    fib.close();
}

void cancelaticket()
{
    book B2;
    ifstream fib("book.dat", ios::binary);
    ofstream fout("temp3.dat", ios::binary);
    bool isCancelled = false;

    for (; fib.read((char *)&B2, sizeof(B2));)
    {
        B2.displaybook();
        cout << "Do you want to cancel this ticket? (Yes/No): ";
        string choice;
        cin >> choice;

        if (choice == "Yes" || choice == "yes")
        {
            isCancelled = true;
            cout << "Ticket cancelled successfully!"
                 << "\n";
        }

        if (!isCancelled)
        {
            fout.write((char *)&B2, sizeof(B2));
            cout << "No Ticket Found!!"
                 << "\n";
        }
        isCancelled = false;
    }

    fib.close();
    fout.close();
    // Delete the original file
    remove("book.dat");
    // Rename the temporary file as the new book.dat
    rename("temp3.dat", "book.dat");
}
bool authenticateUser(const string &username, const string &password)
{
    const string validUsername = "admin";
    const string validPassword = "password";

    return (username == validUsername && password == validPassword);
}

void login()
{
    string username;
    string password;

    cout << "\n\n        ::::::::::::::::::::::::::  LOGIN FORM  ::::::::::::::::::::::::::  ";
    cout << " \n                              ENTER USER ID:-";
    cin >> username;
    cout << "                              ENTER PASSWORD:-";
    cin >> password;

    if (authenticateUser(username, password))
    {
        cout << "Login successful!"
             << "\n";
    }
    else
    {
        cout << "Login failed. Invalid username or password."
             << "\n";
    }
}
int main()
{
p:
    int c;
    int d;
    int e;
    cout << "\t\t\t-----------------------------------------------------------------"
         << "\n";
    cout << "\t\t\t                  BUS MANAGEMENT SYSTEM                           "
         << "\n";
    cout << "\t\t\t-----------------------------------------------------------------"
         << "\n\n\n";
    cout << "\t\t\t________________________MENU______________________________________"
         << "\n\n";
    cout << "\t\t\t| PRESS-1: BUS ADMINISTRATOR               |"
         << "\n";
    cout << "\t\t\t| PRESS-2: PASSENGER TICKET BOOKING        |"
         << "\n";
    cout << "\t\t\t| PRESS-3: EXIT                            |"
         << "\n\n\n";
    cout << "\t\t\t| PLEASE ENTER YOUR CHOICE ::";
    cin >> c;
    switch (c)
    {
    case 1:
        system("cls");
        login();
        r:
        // system("cls");
        cout << "\t\t\t-----------------------------------------------------------------"
             << "\n";
        cout << "\t\t\t                  BUS MANAGEMENT SYSTEM                           "
             << "\n";
        cout << "\t\t\t-----------------------------------------------------------------"
             << "\n\n";
        cout << "\t\t\t*******************BUS ADMINISTRATOR SYSTEM***********************"
             << "\n\n\n";
        cout << "\t\t\t________________________MENU______________________________________"
             << "\n\n";
        cout << "\t\t\t| PRESS-1: ADD A BUS                |"
             << "\n";
        cout << "\t\t\t| PRESS-2: SEARCH A BUS             |"
             << "\n";
        cout << "\t\t\t| PRESS-3: ROUTS OF BUSES           |"
             << "\n";
        cout << "\t\t\t| PRESS-4: UPDATE A BUS DETAILS     |"
             << "\n";
        cout << "\t\t\t| PRESS-5: DELETE A BUS DETAILS     |"
             << "\n";
        cout << "\t\t\t| PRESS-6: EXIT                     |"
             << "\n\n\n";
        cout << "\t\t\t| PLEASE ENTER YOUR CHOICE ::";
        cin >> d;
        switch (d)
        {
        case 1:
            system("cls");
            AddaBus();
            goto r;
            break;
        case 2:
            system("cls");
            search();
            goto r;
            break;
        case 3:
            system("cls");
            ReadaBus();
            Sleep(8000);
            goto r;
            break;
        case 4:
            system("cls");
            UpdateRecord();
            goto r;
            break;
        case 5:
            system("cls");
            DeleteRecord();
            cout << "*************************************************************"
                 << "\n";
            cout << " SUCCESFULLY Deleted BUS DETAILs "
                 << "\n";
            cout << "*************************************************************"
                 << "\n";
            Sleep(1500);
            goto r;
            break;
        case 6:
            cout << "Thank you for using the Bus Management System.\n";
            system("cls");
            goto p;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    case 2:
    o:
        system("cls");
        cout << "\t\t\t-----------------------------------------------------------------"
             << "\n";
        cout << "\t\t\t                  BUS MANAGEMENT SYSTEM                           "
             << "\n";
        cout << "\t\t\t-----------------------------------------------------------------"
             << "\n\n";
        cout << "\t\t\t****************PASSENGERS TICKET BOOKING SYSTEM******************"
             << "\n\n\n";
        cout << "\t\t\t________________________MENU______________________________________"
             << "\n\n";
        cout << "\t\t\t| PRESS-1: BOOK A TICKET            |"
             << "\n";
        cout << "\t\t\t| PRESS-2: SHOW A BUS TICKET        |"
             << "\n";
        cout << "\t\t\t| PRESS-3: VIEW CUSTOMER DETAILS    |"
             << "\n";
        cout << "\t\t\t| PRESS-4: CANCEL A TICKET          |"
             << "\n";
        cout << "\t\t\t| PRESS-5: EXIT                     |"
             << "\n\n\n";
        cout << "\t\t\t| PLEASE ENTER YOUR CHOICE ::";
        cin >> e;
        switch (e)
        {
        case 1:
            system("cls");
            //    bookwrite();
            Book();
            goto o;
            break;
        case 2:
            system("cls");
            bookread();
            Sleep(10000);
            goto o;
            break;
        case 3:
            system("cls");
            customerread();
            Sleep(10000);
            goto o;
            break;
        case 4:
            system("cls");
            cancelaticket();
            goto o;
            break;
        case 5:
            cout << "Thank you for using the bus booking System.\n";
            system("cls");
            goto p;
            break;
        default:
            cout << "Invalid choice!"
                 << "\n";
            break;
        }
    }
}