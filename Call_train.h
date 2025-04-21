#include <vector>
#include <map>
#include <algorithm>

#include "Train.h"
#include "Graffiti.h"

void Choose_train(const string& , const string&) ;
void Choose_class(string) ;
void Show_class(string num) ;

void call_train(const string& level , string& name) ;

map<string, vector<string>> levelToTrains = 
{
    {"1", {"167" , "169" , "171" , "83" , "85" , "31" , "37"}},
    {"11", {"168" , "170" , "172" , "84", "86", "32", "38"}},
    {"111", {"31" ,"37" , "169" , "171"}},
    {"2", {"167", "169"}},
    {"3", {"169", "171"}},
    {"4", {"171", "167"}},
    {"5", {"85", "169"}},
    {"6", {"85", "167"}},
    {"7", {"85", "171"}},
    {"10", {"167" , "169" , "171" , "83" , "85"}},
    {"100", {"167" , "169" , "171"}},
    {"167", {"167"}},
    {"169", {"169"}},
    {"171", {"171"}},
    {"337", {"37" , "169" , "171"}} ,
    {"83" , {"83" , "167"}},
    {"85" , {"85"}} ,
    {"985" , {"37" , "171"}}
};

void call_train(const string& level, const string& name)
{

    auto it = levelToTrains.find(level);
    if (it != levelToTrains.end()) 
    {
        Train train ;
        cout << "----------------------------------------------------" << endl ;
        for (const string& level : it->second)
        {
            train.SearchTrain(level , name);
        }
    } 
    else 
    {
        cout << "ไม่พบระดับ: " << level << endl;
    }

    Choose_train(level , name) ;
}

void Choose_train(const string& level , const string& name)
{
    Train train ;
    string train_num ;
    auto it = levelToTrains.find(level);
    bool valid = false;
    do
    {
        if (it != levelToTrains.end()) 
        {
            cout << "โปรดเลือกขบวนที่ต้องการจะไป(พิมพ์ x เพื่อกลับหน้าหลัก) : " ;
            cin >> train_num ;
            if((train_num)=="x") return ;
            if (find(it->second.begin(), it->second.end(), train_num) != it->second.end()) 
            {
                valid = true;
            }
            else
            {
                cerr << endl << "\033[1;31mx-----------------ไม่พบขบวนที่คุณเลือก กรุณาลองใหม่-----------------x\033[0m" << endl  << endl;
            }
        }
        else 
        {
            cout << "ไม่พบระดับ: " << level << endl;
        }
    }while(!valid) ;

    maintrain->setNum(train_num);
    maintrain->setTotalseat(train_num);
    if(ticketList.countticket(train_num)>=maintrain->totalseat){
        cout << endl << "ขออภัย ขบวนรถนี้เต็มแล้ว" << endl;
        cout << endl << "กดปุ่มอะไรก็ได้เพื่อกลับหน้าหลัก" << endl ;
        pause() ;
        return;
    }
    Show_class(train_num) ;
}


void Show_class(string num)
{
    clearScreen();
    cout << "----------------------------------------------------" << endl ;
    clearScreen();
    
    Primary P(1 , 1 , 1 , 1 , 1 , 0 , 1) ;
    Secondary_AC SAC(0 , 1 , 1 , 1 , 1 , 0 , 1) ;
    Secondary_Lay SL(0 , 0 , 1 , 0 , 1 , 1 , 1) ;
    Secondary_Sit S(0 , 0 , 0 , 0 , 0 , 1 , 1) ;
    Normal N(0 , 0 , 0 , 0 , 0 , 1 , 1) ;

    if (Rapid.count(num)) 
    {
        class_available() ;
        cout << "-----------------------------------------------------------------------------------" << endl ;
        upboarder() ;
        SAC.show_benefit() ;
        SL.show_benefit() ;
        S.show_benefit() ;
        N.show_benefit() ;
        Choose_class(num) ;
        
    } 
    else if (Express.count(num)) 
    {
        class_available() ;
        cout << "-----------------------------------------------------------------------------------" << endl ;
        upboarder() ;
        P.show_benefit() ;
        SAC.show_benefit() ;
        S.show_benefit() ;
        N.show_benefit() ;
        Choose_class(num) ;
        
    } 
    else if (Extra_Express.count(num)) 
    {
        class_available() ;
        cout << "-----------------------------------------------------------------------------------" << endl ;
        upboarder() ;
        P.show_benefit() ;
        SAC.show_benefit() ;
        S.show_benefit() ;
        N.show_benefit() ;
        Choose_class(num) ;
    }
}

void Choose_class(string num)
{
    downboarder( ) ;
    string Ans ;
    do
    {
        cout << endl << "คำตอบของคุณ(ตอบเป็น (*) หรือ พิมพ์ x เพื่อกลับหน้าหลัก) : " ;

        if(Extra_Express.count(num))
            do
            {
                cin >> Ans ;
                if((Ans)=="x" || (Ans)=="X") return ;
                if (Ans!="*" && Ans!="**" && Ans!="****" && Ans!="*****")
                {
                    cerr << endl << "\033[1;31mx-------โปรดเลือกให้ถูกต้องหรือเลือกแค่ชั้นที่มีเท่านั้น-------x\033[0m" << endl << endl ;
                    cout << "คำตอบของคุณ(*) หรือ พิมพ์ x เพื่อกลับหน้าหลัก) : " ;
                }
                
            } while (Ans!="*" && Ans!="**" && Ans!="****" && Ans!="*****");
        else if(Express.count(num))
            do
            {
                cin >> Ans ;
                if((Ans)=="x" || (Ans)=="X") return ;
                if (Ans!="*" && Ans!="**" && Ans!="****" && Ans!="*****")
                {
                    cout << endl << "\033[1;31mx-------โปรดเลือกให้ถูกต้องหรือเลือกแค่ชั้นที่มีเ่ทานั้น-------x\033[0m" << endl << endl ;
                    cout << "คำตอบของคุณ(*) หรือ พิมพ์ x เพื่อกลับหน้าหลัก) : " ;
                }
                
            } while (Ans!="*" && Ans!="**" && Ans!="****" && Ans!="*****");
        else if(Rapid.count(num))
            do
            {
                cin >> Ans ;
                if((Ans)=="x" || (Ans)=="X") return ;
                if (Ans!="*" && Ans!="**" && Ans!="****" && Ans!="***")
                {
                    cout << endl << "\033[1;31mx-------โปรดเลือกให้ถูกต้องหรือเลือกแค่ชั้นที่มีเท่านั้น-------x\033[0m" << endl << endl ;
                    cout << "คำตอบของคุณ(*) : " ;
                }
            } while (Ans!="*" && Ans!="**" && Ans!="****" && Ans!="***");
    } while (Ans!="*" && Ans!="**" && Ans!="***" && Ans!="****" && Ans!="*****");


    maintrain->setClass(Ans); //นำค่าที่ได้จากการ input ไปแปลงเป็นชั้นที่นั่ง ที่แสดงบนตั๋ว
    if(ticketList.countclass(Ans,maintrain->currentNum))
    {
        cout << endl << "ขออภัย ชั้นที่นั่งนี้เต็มแล้ว" << endl;
        cout << endl << "กดปุ่มอะไรก็ได้เพื่อกลับไปเลือกใหม่" << endl ;
        pause() ;
        return;
    }


    float price = maintrain->CalculatePrice(num,Ans); //คำนวณราคา
    maintrain->setPrice(price); //นำราคาที่คำนวณไปเก็บในคลาส Train


    string temp = maintrain->TrainTime(num , maintrain->target_station) ; //กำหนดให้รับข้อมูลเวลาถึงสถานีที่จะไปมาใส่
    string initial = maintrain->TrainTime(num , "ศาลายา") ; //กำหนดให้รับข้อมูลเวลาถึงสถานีศาลายามาใส่
    maintrain->setTarget(initial) ; //นำเวลาถึงสถานีศาลายาใส่ใน class Train
    maintrain->settime(temp); //นำเวลาถึงสถานีที่จะไปใส่ใน class Train


    maintrain->saveticket(maintrain -> target_station , maintrain -> currentNum , maintrain -> currentClass , maintrain -> currentDist , maintrain -> currentPrice , maintrain->ReachTime) ;
    //Save ข้อมูลทั้งหมดไว้ใน class Ticket
    clearScreen();
    ticketList.show_lastest(); //โชว์ตั๋วใบล่าสุดที่เราพึ่งจอง

    
    cout << "กดปุ่มอะไรก็ได้เพื่อกลับหน้าหลัก" << endl ;
    pause() ;
}