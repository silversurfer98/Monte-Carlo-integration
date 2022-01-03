#include "include.h"
#include <SQLAPI.h>

/*  add libmysql in %PATH variable or else put libmysql.dll in programs directory to run
* 
* before that .................
*  project --> properties --> VC++ directories --> include directories --> edit --> D:\c++_databse_connect\include
* 
* then
*  project --> properties --> linker --> input --> additional dependencies --> edit  --> D:\c++_databse_connect\vs2019\lib\sqlapi.lib
* 
* then run the project
*/


inline float test_func(float x)
{
    return x * x * x + 2 * x * x + 1;
}

int main()
{
    std::cout << "enter no. of random numbers to be generated : ";
    size_t size;
    std::cin >> size;
    std::cout << "enter range a : ";
    float sd, a, b;
    std::cin >> a;
    std::cout << "enter range b : ";
    std::cin >> b;
    std::cout << "enter standard deviation : ";
    std::cin >> sd;

    std::ofstream file2;
    file2.open("gauss.txt");

    float* ans = gauss_random(size, a, b, sd, 17);
    /*for (size_t i = 0; i < size; i++)
        file2 << *(ans + i)<<"\n";*/

    SAConnection con;
    //std::cout << "omale";
    con.Connect(_TSA("192.168.1.98@test"), _TSA("developer"), _TSA("1998"), SA_MySQL_Client);
    printf("We are connected!\n");

    
    for (size_t i = 0; i < size; i++)
    {
        SACommand insert(&con, _TSA("INSERT INTO x_data (data) VALUES (:1)"));
        insert << _TSA(*(ans + i));
        insert.Execute();
    }
    


    return 0;
}