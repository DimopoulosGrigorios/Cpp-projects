//File:Scence.cpp
#include <iostream>
#include "Scence.h"

using namespace std;

Scence::Scence(int L,int Dist):pagodromos(Dist),limni(L)
{
              cout<<"Scence was just created"<<endl; 
}
Scence::~Scence()
{
                 cout<<"Scence is about to destroyed"<<endl;
}
void Scence::plot()
{
     int k;
     limni.light_up();
     pagodromos.start();
     k=limni.get_length();
     pagodromos.skate(k/2);
     pagodromos.rotate();
     pagodromos.jump();
     pagodromos.skate(k);
     limni.rotate();
     limni.darken();
}
Background::Background()
{
     cout<<"Background was just created"<<endl;
}
Background::~Background()
{
  cout<<"Background is about to destroyed"<<endl;                       
}
Mountains::Mountains()
{
  cout<<"Mountains were just created"<<endl;
}
Mountains::~Mountains()
{
   cout<<"Mountains are about to destroyed"<<endl;
}
Trees::Trees()
{
   cout<<"Trees were just created"<<endl;
}
Trees::~Trees()
{
    cout<<"Trees were about to destroyed"<<endl;
}
Little_House::Little_House()
{
   cout<<"A little house was just created"<<endl;
}
Little_House::~Little_House()
{
   cout<<"A little house is about to be destroyed"<<endl;
}
IceSkater::IceSkater(int Dist)
{
   this->distance=Dist;
   this->position=0;
   cout<<"An IceSkater participates"<<endl;
}
IceSkater::~IceSkater()
{
   cout<<"An IceSkater will be destroyed"<<endl;
}
void IceSkater::start()
{
     cout<<"Here I am"<<endl;
}
void IceSkater::skate(int d)
{
     int sum=0;
     int temp;
     this->position=d;
     temp=this->position;
     while(temp>0)
     {
                   temp=temp-(this->distance);
                   sum++;
     }
     cout<<"An IceSkater skates "<<sum<<endl;
}
void IceSkater::rotate()
{
     cout<<"An IceSkater spins on position "<<(this->position)<<endl;
}
void IceSkater::jump()
{
     cout<<"An IceSkater jumps on position "<<(this->position)<<endl;
}
Lake::Lake(int L)
{
                this->length=L;
                this->dark=true;
                cout<<"A lake appears"<<endl;
}
Lake::~Lake()
{
                cout<<"A lake will  dissappear"<<endl;
}
void Lake::light_up()
{
     this->dark=false;
     cout<<"Lights on"<<endl;
}
void Lake::darken()
{
     this->dark=true;
     cout<<"Lights off"<<'\n'<<endl;
}
void Lake::rotate()
{
     cout<<"Lake rotated"<<endl;
}
int Lake::get_length()
{
	return length;
}
