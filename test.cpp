//g++ -c test.cpp && g++ -o test.exe test.o && del test.o
#include<iostream>
int main()
{
    size_t x;
    std::cin>>x;
    float *hi = new float[x];
    for(size_t i=0;i<x;i++)
        hi[i]=(float)i;
    
    float *t;
    std::cout<<sizeof(float)<<"\n";
    std::cout<<hi<<"\n";
    std::cout<<*hi<<"\n";
    std::cout<<*(hi+2)<<"\n";

    std::cout<<"----------------------\n";

    for(size_t i=0;i<x/2;i++)
        std::cout<<*(hi+(i*2))<<"\n";




    // for(t = hi; t < hi + x * sizeof(float); t++)
        //std::cout<<*(hi += 2*sizeof(float))<<"\n";
        //std::cout<<*(hi + i*sizeof(float))<<"\n";
        //std::cout<<hi[i]<<"\n";

    return 0;
}