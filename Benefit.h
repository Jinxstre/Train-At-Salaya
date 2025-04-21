#include <iostream>


using namespace std ;

class Benefit
{
public:
    int B1 , B2 , B3 , B4 , B5 , B6 , B7 ;
    
    Benefit() {}
    void Set_Benefit(int , int , int , int , int , int , int) ;
    ~Benefit() {}
    virtual void show_benefit();
};

void Benefit::Set_Benefit(int BF1 , int BF2 , int BF3 , int BF4 , int BF5 , int BF6 , int BF7)
{
    B1 = BF1 ;  
    B2 = BF2 ; 
    B3 = BF3 ; 
    B4 = BF4 ; 
    B5 = BF5 ; 
    B6 = BF6 ;
    B7 = BF7 ;
}

void Benefit::show_benefit()
{
    if (B1 == 1) cout << "    |   - อ่างล้างหน้า                          |." << endl;
    if (B2 == 1) cout << "    |   - ปลั๊กไฟ                              |." << endl;
    if (B3 == 1) cout << "    |   - ที่เก็บสัมภาระบริเวณที่นั่ง                 |." << endl;
    if (B4 == 1) cout << "    |   - ระบบปรับอากาศ                       |." << endl;
    if (B5 == 1) cout << "    |   - ไฟส่องสว่างที่หัวนอน                    |." << endl;
    if (B6 == 1) cout << "    |   - พัดลม                               |." << endl;
    if (B7 == 1) cout << "    |   - ห้องน้ำ                              |." << endl << "    |                                        |." << endl ;
}