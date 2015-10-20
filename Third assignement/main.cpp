#include <iostream>
#include "ice.h"
#include <time.h>
#include <stdio.h>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
 {
 	int x=*argv[1],y=*argv[2],n=*argv[3],t=*argv[4];
 	srand (time(NULL));
 	Ice* pagos=new Ice(x,y,n,t);
 	pagos->performance();
	return 0;
}
