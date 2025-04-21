#include <fstream>
#include "Station.h"

using namespace std;


void showMenu();
void ALL_ticket() ;

int main()
{
    clearScreen();
    intro() ;
    showMenu() ;
    delete maintrain;
    return 0 ;
}


void showMenu() 
{
    clearScreen();
    int choice;
    string A ;
    do 
    {
        clearScreen();
        MENU() ;
        cout << endl << "1. Reserve your train ticket" << endl;
        cout << "2. show all" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> A;
        if (!isDigitsOnly(A)) 
        {
            continue;
        }
        if(A.length()>6) 
        {
            cout << "\n\033[1;31mx-------------------คุณใส่ค่ามากเกินไปแล้ว-------------------x\033[0m\n\n";
            continue;
        }
        else choice = stoi(A);
        switch (choice) 
        {
            case 1:
                start_program();
                break;
            case 2:
                clearScreen();
                ALL_ticket() ;
                ticketList.sort();
                ticketList.show_all();
                cout << "กดอะไรก็ได้เพื่อกลับหน้าหลัก" << endl ;
                pause() ;
                break;
            case 3:
                clearScreen();
                cout << endl << "Exiting the program. Goodbye!" << endl << endl;
                BYEBYE() ;
                break;
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    } while (choice != 3);
}