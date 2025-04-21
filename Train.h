#include <fstream>
#include <sstream>
#include <set>


#include "Class.h"
#include "Ticket_LL.h"

using namespace std ;

class Train
{
    public:
        int totalseat;
        int class_11_seat = seat11;
        int class_21_seat = seat21;
        int class_22_seat = seat22;
        int class_23_seat = seat23;
        int class_33_seat = seat33;

        double fareRate;
        
        string target_station ;
        string currentNum;
        string currentClass;
        string currentDist ;
        string ReachTime ;
        float  currentPrice ;

        void setTotalseat(string);
        void setTarget(string x) {target_station = x;}
        void setNum(string x) {currentNum = x;}
        void setClass(string x) {currentClass = x;}
        void setDist(string x) {currentDist = x;}
        void setPrice(float x) {currentPrice = x;}
        void settime(string x) {ReachTime = x ;}

        void SearchTrain(const string& , const string&) ;
        string TrainTime(const string& , const string&) ;
        float CalculatePrice(string,string)  ;

        void saveticket(string , string , string , string , float , string);
};

Train* maintrain = new Train;
extern LL ticketlist;

const set<string> Rapid = {"167", "168", "169", "170", "171", "172"} ;
const set<string> Express = {"83", "84", "85", "86"} ;
const set<string> Extra_Express = {"31", "32", "37", "38"} ;

void Train::setTotalseat(string trainnum)
{
    if (Rapid.count(trainnum)) 
    {
        maintrain->totalseat = maintrain->class_21_seat + maintrain->class_22_seat + maintrain->class_23_seat + maintrain->class_33_seat ;
    } 
    else if (Express.count(trainnum)||Extra_Express.count(trainnum)) 
    {
        maintrain->totalseat = maintrain->class_11_seat + maintrain->class_21_seat +  maintrain->class_23_seat + maintrain->class_33_seat ;
    } 
}

void Train::SearchTrain(const string& num, const string& keyword) 
{
    ifstream file(num + ".txt");
    string line;
    bool found = false;
    if (file.is_open())
    {
        
        while (getline(file, line))
        {
            istringstream iss(line);
            string station;
            iss >> station;
            if (station == "ศาลายา")
            {
                if(Rapid.count(num))
                {
                    cout << "รถเร็ว " << endl ;
                }
                else if(Express.count(num))
                {
                    cout << "รถด่วน " << endl ;
                }
                else if(Extra_Express.count(num))
                {
                    cout << "รถด่วนพิเศษ " << endl ;
                }
                cout << "หมายเลขขบวน : " << num << endl;
                cout << "จาก " << line << endl;
            }
            if (station == keyword)
            {
                cout << "ถึง  " << line << endl;
                found = true;
                cout << "----------------------------------------------------" << endl ;
            }
        }
        file.close();
    }
    else
    {
        cout << "ไม่สามารถเปิดไฟล์ได้" << endl;
    }

    if (!found)
    {
        cout << "ไม่พบข้อมูล" << endl;
    }
}

string Train::TrainTime(const string& num, const string& keyword) 
{
    ifstream file(num + ".txt");
    string line;
    string target ;
    bool found = false;
    if (file.is_open())
    {
        
        while (getline(file, line))
        {
            istringstream iss(line);
            string station;
            iss >> station;
            if (station == keyword)
            {
                target = line ;
                found = true;
            }
        }
        file.close();
    }
    else
    {
        cout << "ไม่สามารถเปิดไฟล์ได้" << endl;
    }

    if (!found)
    {
        cout << "ไม่พบข้อมูล" << endl;
    }
    return target ;
}

float Train::CalculatePrice(string num,string PPC)
{
    float fare = 0 ;
    string km = maintrain->currentDist;
    if (PPC == "*") PPC = "1.0";
    if (PPC == "**") PPC = "1.5";
    if (PPC == "***") PPC = "2.0";
    if (PPC == "****") PPC = "2.5";
    if (PPC == "*****") PPC = "3.0";
    if(Rapid.count(num))
    {
        maintrain->fareRate = 0.5;
        if(stoi(maintrain ->currentDist) >= 200)
        {
            if(PPC == "1.0") {fare = 90  ; PPC = "0.2" ;}
            if(PPC == "1.5") {fare = 160 ; PPC = "0.3" ;}
            if(PPC == "2.0") {fare = 170 ; PPC = "0.4" ;}
            if(PPC == "2.5") {fare = 230 ; PPC = "0.6" ;}
        }
    }
    else if(Express.count(num))
    {
        maintrain->fareRate = 1.0;
        if(stoi(maintrain ->currentDist) >= 200)
        {
            if(PPC == "1.0") {fare = 160 ; PPC = "0.2" ;}
            if(PPC == "1.5") {fare = 250 ; PPC = "0.3" ;}
            if(PPC == "2.5") {fare = 380 ; PPC = "0.6" ;}
            if(PPC == "3.0") {fare = 450 ; PPC = "0.9" ;}
        }
    }
    else if(Extra_Express.count(num))
    {
        maintrain->fareRate = 1.5;
        if(stoi(maintrain ->currentDist) >= 200)
        {
            if(PPC == "1.0") {fare = 260 ; PPC = "0.2" ;}
            if(PPC == "1.5") {fare = 370 ; PPC = "0.3" ;}
            if(PPC == "2.5") {fare = 490 ; PPC = "0.6" ;}
            if(PPC == "3.0") {fare = 600 ; PPC = "0.9" ;}
        }
    }
    return fare + (maintrain->fareRate*stof(km)*stof(PPC)) ;
}

void Train::saveticket(string a, string b, string c, string d, float x , string e)
{
    Ticket* newticket = new Ticket(a,b,c,d,x,e);
    ticketList.add_node(newticket);
}
