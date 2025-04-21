#include <iostream>
#include <string>
#include <ctime>  

using namespace std;

int seat11 = 1;
int seat21 = 1;
int seat22 = 1;
int seat23 = 1;
int seat33 = 1;

string Prefix(string input) 
{
     while (input.length() < 3) 
     {
         input += "0";
     }
     return input;
}

string Suffix() 
{
     srand(time(0));
     string num = "";
     for (int i = 0; i < 5; i++) 
     {
         num += to_string(rand() % 10) ;  // Random digit 0–9
     }
     return num;
}

class Ticket
{
     public:
          string TicketNo;
          string SavedStation ;
          string SavedNum;
          string SavedClass;
          string SavedDist ;
          string SavedDest ;
          float  SavedPrice ;
          Ticket* next;

          Ticket(string , string , string , string , float , string);
          void show_ticket();
          Ticket* move_next();
          ~Ticket() {}
};

Ticket:: Ticket(string a , string b, string c, string d, float x , string e)
{    
     string t1,t2,t3;
     if(c == "*") {c = "ชั้น 3 นั่งพัดลม" ; t2 = "33";}
     else if(c == "**") {c = "ชั้น 2 นั่งพัดลม" ; t2 = "23";}
     else if(c == "***") {c = "ชั้น 2 นั่ง/นอน พัดลม" ; t2 = "22";}
     else if(c == "****") {c = "ชั้น 2 นั่ง/นอน ปรับอากาศ" ; t2 = "21";}
     else if(c == "*****") {c = "ชั้น 1 นั่ง/นอน ปรับอากาศ" ; t2 = "11";}
     t1 = Prefix(b);
     t3 = Suffix();
     TicketNo = t1 + t2 + t3 ;
     SavedStation = a ;
     SavedNum = b ;
     SavedClass = c ;
     SavedDist = d ;
     SavedPrice = x ;
     SavedDest = e ;
     next=NULL;
}

Ticket* Ticket::move_next()
{
     return next;
}

void  Ticket:: show_ticket()
{
     cout << endl ;
     cout << "----------------------------------------------------------------------------------\n" ;
     cout << "          รหัสตั๋ว       : " << TicketNo << endl ;
     cout << "          สถานีต้นทาง   : " << SavedStation << " น. : เวลาออก " <<endl ;
     cout << "          สถานีปลายทาง : " << SavedDest << " น. :  เวลาถึง " << endl ;
     cout << "          ขบวนที่       : " << SavedNum << endl ;
     cout << "          ชั้นที่นั่ง       : " << SavedClass << endl ;
     cout << "          ระยะทาง     : " << SavedDist << " กิโลเมตร " << endl ;
     cout << "          ราคา        : " << SavedPrice << " บาท " << endl ;
     cout << "----------------------------------------------------------------------------------\n" ;
}


class LL
{
     public:
          Ticket* hol;
          int size;

          void add_node(Ticket*&);
          void show_all();
          void show_lastest() ;
          void swap_tickets(Ticket* , Ticket* );
          void sort();
          int countticket(const string&);
          bool countclass(const string&,const string& trainNum);
          ~LL();
          LL();
     
};

LL::LL()
{
     hol=NULL;
     size=0;
}

LL::~LL()
{
     //clear all nodes
     Ticket* current = hol;
     while (current != NULL)
     {
          Ticket* next = current->move_next();
          delete current;
          current = next;
          size--;
     }
}

void LL::show_all()
{
     Ticket* t=hol;
     int i;
     if (t==NULL) cout << endl << "\033[1;33mx -------------No ticket in system------------- x\033[0m" << endl << endl;
     
     for(i = 0 ; i < size ; i++)
     {
          t->show_ticket();
          t = t->move_next();
     }
}

void LL::show_lastest()
{
     Ticket* t=hol;
     t->show_ticket();
}

void LL::add_node(Ticket *&A)
{
     if (hol == nullptr) 
     {
          A->next = nullptr;
     } else 
     {
          A->next = hol;
     }
     hol = A;
     size++;
}

LL ticketList;

void LL::swap_tickets(Ticket* a, Ticket* b)
{
     swap(a->TicketNo, b->TicketNo);
     swap(a->SavedStation, b->SavedStation);
     swap(a->SavedNum, b->SavedNum);
     swap(a->SavedClass, b->SavedClass);
     swap(a->SavedDist, b->SavedDist);
     swap(a->SavedDest, b->SavedDest);
     swap(a->SavedPrice, b->SavedPrice);
}

void LL::sort()
{
    if (!ticketList.hol || !ticketList.hol->next) return;

    bool swapped;
    Ticket* ptr1;
    Ticket* lptr = nullptr;

    do 
    {
          swapped = false;
          ptr1 = ticketList.hol;

          while (ptr1->next != lptr) 
         {
               if (ptr1->SavedNum > ptr1->next->SavedNum) 
               {
                    swap_tickets(ptr1, ptr1->next);
                    swapped = true;
               }
            ptr1 = ptr1->next;
         }
          lptr = ptr1;
    } while (swapped);
}

int LL::countticket(const string& trainNum)
{
     int count = 0;
     Ticket* current = hol;
     while (current) {
         if (current->SavedNum == trainNum) count++;
         current = current->next;
     }
     return count;
}

bool LL::countclass(const string& currclass,const string& trainNum)
{
     bool tem = false;
     int temp = 0 ;
     string comcode;
     if (currclass == "*") {temp = seat11; comcode = "33";}
     if (currclass == "**") {temp = seat21; comcode = "23";}
     if (currclass == "***") {temp = seat22; comcode = "22";}
     if (currclass == "****") {temp = seat23; comcode = "21";}
     if (currclass == "*****") {temp = seat33; comcode = "11";}

     int count = 0;
     Ticket* current = hol;
     while (current) 
     {
         if (current->SavedNum == trainNum &&current->TicketNo.substr(3, 2) == comcode) count++;
         current = current->next;
     }
     if(count >= temp) tem=true;
     return tem;
}