

//File:main.cpp
#include <iostream>
#include "Scence.h"
#include <cstdlib>
using namespace std;

int main(int argc,char * argv[])
{
        int L,Dist;
	L=atoi(argv[1]);
        Dist=atoi(argv[2]);
        Scence scence(L,Dist);
        scence.plot();
        return 0;
 }
