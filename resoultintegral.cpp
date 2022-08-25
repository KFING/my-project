#include "sourcemathoperation.cpp"

#include <iostream>
#include <string>

/*std::string calculateIntegral(std::string func = "0", std::string lower_limit = "0", std::string apper_limit = "0", std::string accuracy = "0")
{
    std::string temp;
    std::string str;
    double dTemp = 0;
    double n = atof(apper_limit.c_str())- atof(lower_limit.c_str());
    double dAccuracy = n * atof(accuracy.c_str());
    int lenghtFunc = func.length();
    double i = atof(lower_limit.c_str());
    while( i <= atof(apper_limit.c_str()) ){
        for(int j = 0; j < lenghtFunc; j++){
            if (func[j] == 'x'){
                func.erase(j, 1);
                func.insert(j, std::to_string(i));
            }
        }
        OPN strP = func;
        //temp = strP.Calculate();
        if (temp == "Input error!"){
            break;
        }//else dTemp = dTemp + atof(temp.c_str());
        i = i + dAccuracy;
    }
    str = std::to_string(dTemp);
    return str;
}*/
