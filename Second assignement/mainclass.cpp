//File:mainclass.cpp
#include <iostream>
#include "class.h"
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(int argc,char * argv[])
{
	srand(time(NULL));
        int L,N;
	L=atoi(argv[1]);
        N=atoi(argv[2]);
	if(L<=0)
	{
	 	cout<<"Warning:The length of the lake cant be zero or negative"<<endl;
		return 0;
	}
	if (N<=0)
	{
		cout<<"Warning:The number of IceSkaters CANT be zero or negative"<<endl;
	}
        Scence scence(L,N);
        scence.plot();
        return 0;
 }
