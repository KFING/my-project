#include <iostream>
#include <string>
#include <cmath>
#include <limits>


std::string decBin(int n)
{
    int two = 2;
    int counterTwo = 1;
    int temp;
    std::string strBin;
    while (two < n){
        two = two * 2;
        counterTwo++;
    }
    for (int i = 0; i <= counterTwo; i++){
        temp = n - two;
        if(temp < 0){
            strBin.push_back('0');
            two = two / 2;
        }else {
            strBin.push_back('1');
            n = temp;
            two = two / 2;
        }
    }
    return strBin;
}
