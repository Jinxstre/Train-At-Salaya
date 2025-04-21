#include <iostream>

#include "Benefit.h"

class Primary : public Benefit
{
public:
    Primary(int , int , int , int , int , int , int);
    ~Primary() {}
    void show_benefit()
    {
        cout << "    |  ***** ชั้น 1 บริการที่มี                    |." << endl ;
        Benefit::show_benefit() ;
    }
};

Primary::Primary(int a , int b , int c , int d , int e , int f , int g)
{
    Benefit::Set_Benefit(a , b , c , d , e , f , g) ;
}

class Secondary_AC : public Benefit //นั่งและนอนปรับอากาศ
{
public:
    Secondary_AC(int , int , int , int , int , int , int);
    ~Secondary_AC() {}
    void show_benefit()
    {
        cout << "    |  **** ชั้น 2 นั่ง/นอน ปรับอากาศ บริการที่มี     |." << endl ;
        Benefit::show_benefit() ;
    }
};

Secondary_AC::Secondary_AC(int a , int b , int c , int d , int e , int f , int g)
{
    Benefit::Set_Benefit(a , b , c , d , e , f , g) ;
}

class Secondary_Lay : public Benefit//ชั้น 2 นั่ง/นอนพัดลม
{
public:
    Secondary_Lay(int , int , int , int , int , int , int);
    ~Secondary_Lay() {}
    void show_benefit()
    {
        cout << "    |  *** ชั้น 2 นั่ง/นอน พัดลม บริการที่มี          |." << endl ;
        Benefit::show_benefit() ;
    }

};

Secondary_Lay::Secondary_Lay(int a , int b , int c , int d , int e , int f , int g)
{
    Benefit::Set_Benefit(a , b , c , d , e , f , g) ;
}

class Secondary_Sit : public Benefit
{
public:
    Secondary_Sit(int , int , int , int , int , int , int);
    ~Secondary_Sit() {} 
    void show_benefit()
    {
        cout << "    |  ** ชั้น 2 นั่งพัดลม บริการที่มี                |." << endl ;
        Benefit::show_benefit() ;
    }
};

Secondary_Sit::Secondary_Sit(int a , int b , int c , int d , int e , int f , int g)
{
    Benefit::Set_Benefit(a , b , c , d , e , f , g) ;
}

class Normal : public Benefit
{
public:
    Normal(int , int , int , int , int , int , int);
    ~Normal() {}
    void show_benefit()
    {
        cout << "    |  * ชั้น 3 นั่งพัดลม บริการที่มี                 |." << endl ;
        Benefit::show_benefit() ;
    }
};

Normal::Normal(int a , int b , int c , int d , int e , int f , int g)
{
    Benefit::Set_Benefit(a , b , c , d , e , f , g) ;
}
