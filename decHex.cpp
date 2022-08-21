#include <string>
#include <cmath>

std::string DecHex(int ch)
{
     using namespace std;
     string s, b;
     int c, d;
     do
        if ((ch != 0) && (fmod(ch,16) != 0))
        {
            c = ch/16; //?????
            d = ch%16; //???????
            switch(d)
            {
               case 0:  b = "0"; break;
               case 1:  b = "1"; break;
               case 2:  b = "2"; break;
               case 3:  b = "3"; break;
               case 4:  b = "4"; break;
               case 5:  b = "5"; break;
               case 6:  b = "6"; break;
               case 7:  b = "7"; break;
               case 8:  b = "8"; break;
               case 9:  b = "9"; break;
               case 10: b = "A"; break;
               case 11: b = "B"; break;
               case 12: b = "C"; break;
               case 13: b = "D"; break;
               case 14: b = "E"; break;
               case 15: b = "F"; break;
            }
            ch = c;
            s = b+s;
        }
        else
        {
          return(s);
        }
     while (true);
}
