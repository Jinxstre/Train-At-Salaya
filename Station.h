#include <cctype>

#include "Call_train.h"

using namespace std;

string trim(const string& str) ;
void start_program();
void station_list() ;
string GET_info(int,int) ;
bool isDigitsOnly(const string& str) ;

void start_program()
{
    clearScreen();
    string level ;
    string name ;
    string input ;
    station_list() ;
    int n ;
    do
    {
        cout << "โปรดเลือกสถานีที่อยากไป (พิมพ์ x เพื่อกลับหน้าหลัก) : ";
        cin >> input;
        if(input == "x" || input == "X") return ;
        if(input == "3") cout << "\n\033[1;31mx-------------------คุณอยู่สถานีศาลายาอยู่แล้ว-------------------x\033[0m\n\n" ;
        if (!isDigitsOnly(input)) 
        {
            cout << "\n\033[1;31mx-------------------โปรดพิมพ์เลขที่สอดคล้องกับสถานี-------------------x\033[0m\n\n";
            continue;
        }
        if(input.length()>6) 
        {
            cout << "\n\033[1;31mx-------------------คุณใส่ค่ามากเกินไปแล้ว-------------------x\033[0m\n\n";
            continue;
        }

        else n = stoi(input);  // แปลง string เป็น int หลังจากที่มั่นใจว่ามีแต่ตัวเลข
        
        if ((n > 73 || n < 1)) 
        {
            cout << endl << "\033[1;31mx-------------------โปรดพิมพ์เลขที่สอดคล้องกับสถานี-------------------x\033[0m\n\n";
            continue;
        }
    } while (n > 73 || n < 1 || n == 3);
    level = GET_info(n,2) ;
    name = GET_info(n,4) ; maintrain->setTarget(name);
    string km = GET_info(n,1); maintrain->setDist(km);
    clearScreen();
    Trainlist() ;
    cout << "----------------------------------------------------" << endl ;
    cout << "The station's name : " << name << endl ;
    call_train(level , trim(name)) ;
}

string GET_info(int n,int m)
{
    string level ;
    fstream file("Station.txt") ;
    string line ;
    int lineNumber = 0 ;
    int targetLine[] = {(5 * n) - m} ;
    int targetCount = sizeof(targetLine) / sizeof(targetLine[0]) ;

    if(file.is_open())
    {
        while (getline(file , line))
        {
            lineNumber++ ;
            for(int i = 0 ; i < targetCount ; ++i)
            {
                if(lineNumber == targetLine[i])
                {
                    level = line ;
                }
            }
        }
        file.close() ;
    }
    else
    {
        cout << "ไม่สามารถเปิดไฟล์ได้" << endl ;
    }

    return level ;
}

string trim(const string& str) 
{
    size_t first = str.find_first_not_of(" \t\r\n");
    size_t last  = str.find_last_not_of(" \t\r\n");
    if (first == string::npos) return "";
    return str.substr(first, (last - first + 1));
}

void station_list()
{
    Stationlist() ;
    cout << "1.  กรุงเทพอภิวัฒน์                                                    ." << endl ;
    cout << "2.  บางบำหรุ                                                         ." << endl ;
    cout << "3.  ศาลายา                                                      . ;." << endl ;
    cout << "4.  นครปฐม                                                        .;" << endl ;
    cout << "5.  บ้านโป่ง                                                       ;;." << endl ;
    cout << "6.  โพธาราม                                                     ;.;;" << endl ;
    cout << "7.  ราชบุรี                                                      ;;;;." << endl ;
    cout << "8.  ปากท่อ                                                      ;;;;;" << endl ;
    cout << "9.  เพชรบุรี                                                     ;;;;;" << endl ;
    cout << "10. ชะอำ                                                        ;;;;;" << endl ;
    cout << "11. หัวหิน                                                      ;;;;;" << endl ;
    cout << "12. วังก์พง                                                       ;;;;;" << endl ;
    cout << "13. ปราณบุรี                                                     ;;;;;" << endl ;
    cout << "14. กุยบุรี                                                      ;;;;;" << endl ;
    cout << "15. ประจวบคีรีขันธ์                                                 ;;;;;" << endl ;
    cout << "16. ทับสะแก                                                     ;;;;;" << endl ;
    cout << "17. บ้านกรูด                                                      ;;;;;" << endl ;
    cout << "18. บางสะพานใหญ่                                                 ;;;;;" << endl ;
    cout << "19. บางสะพานน้อย                                                 ;;;;;" << endl ;
    cout << "20. มาบอำมฤต                                                    ;;;;;" << endl ;
    cout << "21. ปะทิว                                                        ;;;;;" << endl ;
    cout << "22. ชุมพร                                                        ;;;;;" << endl ;
    cout << "23. สวี                                                          ;;;;;" << endl ;
    cout << "24. ปากตะโก                                                     ;;;;;" << endl ;
    cout << "25. หลังสวน                                                      ;;;;;" << endl ;
    cout << "26. ละแม                                                        ;;;;;" << endl ;
    cout << "27. ท่าชนะ                                                       ;;;;;" << endl ;
    cout << "28. ไชยา                                                        ;;;;;" << endl ;
    cout << "29. ท่าฉาง                                                       ;;;;;" << endl ;
    cout << "30. สุราษฎร์ธานี                                                   ;;;;;" << endl ;
    cout << "31. บ้านนา                                                       ;;;;;" << endl ;
    cout << "32. นาสาร                                                       ;;;;;" << endl ;
    cout << "33. บ้านส้อง                                                      ;;;;;" << endl ;
    cout << "34. ห้วยปริก                                                      ;;;;;" << endl ;
    cout << "35. กระเบียด                                                     ;;;;;" << endl ;
    cout << "36. ทานพอ                                                       ;;;;;" << endl ;
    cout << "37. ฉวาง                                                        ;;;;;" << endl ;
    cout << "38. คลองจันดี                                                     ;;;;;" << endl ;
    cout << "39. นาบอน                                                       ;;;;;" << endl ;
    cout << "40. คลองจัง                                                      ;;;;;" << endl ;
    cout << "41. ชุมทางทุ่งสง                                                   ;;;;;" << endl ;
    cout << "42. ที่วัง                                                         ;;;;;" << endl ;
    cout << "43. กะปาง                                                       ;;;;;" << endl ;
    cout << "44. ห้วยยอด                                                      ;;;;;" << endl ;
    cout << "45. ตรัง                                                         ;;;;;" << endl ;
    cout << "46. กันตัง                                                        ;;;;;" << endl ;
    cout << "47. ชุมทางเขาชุมทอง                                               ;;;;;" << endl ;
    cout << "48. ชะอวด                                                       ;;;;;" << endl ;
    cout << "49. บ้านขอนหาด                                                   ;;;;;" << endl ;
    cout << "50. แหลมโตนด                                                    ;;;;;" << endl ;
    cout << "51. ปากคลอง                                                     ;;;;;" << endl ;
    cout << "52. พัทลุง" << endl ;
    cout << "53. เขาชัยสน       " << "                        ___=================================================.  ==---_______" << endl ;
    cout << "54. บางแก้ว        " << "                      /   \\___||___||___||___||___||___||___||___||___||__| ======------------" << endl ;
    cout << "55. หารเทา        " << "                     |    ___      ___      ___      ___      ___      ___|  ==______________________" << endl ;
    cout << "56. ควนเนียง       " << "                   [_|__/ o \\____/ o \\____/ o \\____/ o \\____/ o \\____/ o \\__  ==============" << endl ;
    cout << "57. ชุมทางหาดใหญ่   " << "                 <___/__________________________________________________/=  ________________" << endl ;
    cout << "58. จะนะ          " << "                    (O)            (O)            (O)            (O)      ----==============_____" << endl ;
    cout << "59. เทพา          " << "              |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||" << endl ;
    cout << "60. ปัตตานี         " << endl ;
    cout << "61. นาประดู่                                                      ;;;;;" << endl ;
    cout << "62. วัดช้างให้                                                     ;;;;;" << endl ;
    cout << "63. ยะลา                                                        ;;;;;" <<endl ;
    cout << "64. รามัน                                                        ;;;;;" <<endl ;
    cout << "65. รือเสาะ                                                      ;;;;;"  <<endl ;
    cout << "66. มะรือโบ                                                      ;;;;;"  <<endl ;
    cout << "67. ตันหยงมัส                                                     ;;;;;" <<endl ;
    cout << "68. เจาะไอร้อง                                                 ..;;;;;.." <<endl ;
    cout << "69. สุไหงปาดี                                                    ':::::'" << endl ;
    cout << "70. สุไหงโก-ลก                                                    ':`" << endl ;
    cout << "71. บ้านทุ่งหล่อ" << endl ;
    cout << "72. โคกคราม" << endl ;
    cout << "73. นครศรีธรรมราช" << endl ;
    cout << "----------------------------------------------------" << endl ;
}

bool isDigitsOnly(const string& str) 
{
    if (str.empty()) return false;
    for (char c : str) 
    {
        if (!isdigit(c)) return false;
    }
    return true;
}