//File:class.cpp
#include <iostream>
#include "class.h"
#include <cstdlib>
using namespace std;
//Synarthseis Node//
Node::Node(IceSkater& skater,Node*n=NULL):pagodromos(skater),next(n){}
Node::~Node(){}
//Synarthseis List//
List::List():start(NULL),last(NULL),size(0),m_pagodromoi(0),a_pagodromoi(0){}
List::~List(){}
Node * List::getStart(){return start;}
Node * List::getLast(){return last;}
int List::getSize(){return size;}
int List::getM_pagodromoi(){return m_pagodromoi;}
int List:: getA_pagodromoi(){return a_pagodromoi;}
void List::pushFront(IceSkater& skate)
{
	if ((start==NULL)&&(last==NULL))
	{
		start= new Node(skate,start);
		last=start;
        	size++;
		if  (skate.getColour()==black)
		{
			m_pagodromoi++;
		}
		else
		{
			a_pagodromoi++;
		}
	}
	else
	{	
		start= new Node(skate,start);
		size++;
		if  (skate.getColour()==black)
                {
                        m_pagodromoi++;
                }
                else  
                {
                        a_pagodromoi++;
                }

	}
}
bool  List::popBack()
{
	if((start==NULL)&&(last==NULL))
	{
		return false;
	}
	Node* t;
	int i;
	t=start;
	for(i=1;i<size-1;i++)
	{
		 t=t->next;
	}	
	if (((last->pagodromos).getColour())==black)
        {
               m_pagodromoi--;
        }
        else  
        {
               a_pagodromoi--;
        }
	delete last;
	if (size==1)
	{
		last=NULL;
		start=NULL;
	}
	else
	{
		last=t;
	}
	size--;
	return true;
}
bool List:: popFront()
{	
	Node * t=start;
	if((last==NULL)&&(start==NULL))return false;
	if  (((start->pagodromos).getColour())==black)
        {
               m_pagodromoi--;
        }
        else  
        {
               a_pagodromoi--;
        }
	start=start->next;
	delete t;
	size--;
	return true;
}
IceSkater* List::at(int pos)
{
	int i;
	if ( pos < 0 || pos >= size ) return NULL;
	Node* t = start;
	for (i = 0 ; i < pos ; i++) t = t->next;
	return &(t->pagodromos);
}
//Synarthseis Lake//
Lake::Lake(int l):length(l){}
Lake::~Lake(){}
int Lake::getLength(){return length;}
List * Lake::k_a_stoiba(){return &k_a_stoiba_;}
List * Lake::k_d_stoiba(){return &k_d_stoiba_;}
List * Lake::p_a_stoiba(){return &p_a_stoiba_;}
List * Lake::p_d_stoiba(){return &p_d_stoiba_;}
//Synarthseis IceSkater//
IceSkater::IceSkater(int dista,color xrwma_ ,skill deks,int identification):id(identification),distance(dista),_deksiothta(deks),xrwma(xrwma_)
{
	position=0;
}
IceSkater::IceSkater(const IceSkater& skater) : id(skater.id),distance(skater.distance),position(skater.position),xrwma(skater.xrwma),_deksiothta(skater._deksiothta)
{
}
IceSkater::~IceSkater(){}
skill IceSkater::deksiotita()
{
	return _deksiothta;
}
int IceSkater::skate(int dist)
{
	position=dist;
	if ((dist%distance)==0)
	{
		return (dist/distance);	
	}
	else
	{
		return ((dist/distance)+1);
	}
}
int IceSkater::getPosition()
{
	return position;
}
int IceSkater::getTautothta()
{
	return id;
}
color IceSkater::getColour()
{
	return xrwma;
}
//////////////////////////////////////////////////
//epilegw gia tyxaio id analoga me thn seira gennhshs tou pagodromou p.x o prwtos pernei 0 h 1 o deyteros 2 h 3	kai outo kathe ekseis.H epilogh tou id einai kai  pali tyxaia me isopithano //
//endexomeno gia 0 h 1  me 1/2 sto kathena (sthn periptwsh tou prwtou pagodromou pou genatai(me paromoio tropo kai stis alles))//
int IceSkater::random_id(List* listaK,List* listaB)
{
	int random23;
	random23=rand()%2+(2*((*listaK).getSize()+(*listaB).getSize())); 
	return random23;
}
///////////////////////////////////////////////
int IceSkater::random_distance(Lake limnoutza)
{
	int i;
	if(limnoutza.getLength()==1)
	return 1;
	i=rand()%(limnoutza.getLength());
	while(i==0)i=rand()%(limnoutza.getLength());
	return i;	
}
color IceSkater::random_colour()
{
	if( (rand()%2)==1)
	{
		return black;
	}
	else
	{
		return white;
	}
}
skill IceSkater::random_skill()
{
	if( (rand()%2)==1)
        {
                return jump;
        }
        else
        {
                return spin;
        }

}
//Synarthseis Scence//
Scence::Scence(int l,int num=0):limni(l),ar_pagodromwn(num){}
Scence::~Scence(){}
int Scence::getAr_pagodromwn()
{
	return ar_pagodromwn;
}
void Scence::fullK_oura(int n)
{
	int narxiko=0,i=0,m_p_k_ou=0,m_p_b_ou=0,a_p_b_ou=0,a_p_k_ou=0;
	IceSkater *ska,*temp,*t_m_p;
	color previous=nothing,xrwma_b_ouras=nothing;
	////////////////////////
	//An o arithmos twn pagodromn einai peritos meiwse ton kata ena kai katwn zygo//
	if (n%2==1)
	{
		narxiko=n-1;
	}	
	//////////////////////
	else if(n%2==0)
	{
		narxiko=n;
	}
	while(i<narxiko)
	{
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//Elenxos gia to an tha eisaxthei stoixeio apo thn bohthitikh oura//
		if ((bohthitiki_oura.getSize())&&(previous!=xrwma_b_ouras))
		{
			temp=(bohthitiki_oura.at(bohthitiki_oura.getSize()-1));
			t_m_p=new IceSkater(*temp);
			kyria_oura.pushFront(*t_m_p);
			cout<<"Adding IceSkater with id:"<<(*t_m_p).getTautothta()<<" to the MainQueue"<<endl;
			previous=(*t_m_p).getColour();
			cout<<"Deleting IceSkater with id:"<<(*temp).getTautothta()<<" from the HelpQueue"<<endl;
			bohthitiki_oura.popBack();
			if((*t_m_p).getColour()==black)
				cout<<"IceSkater with id:"<<(*temp).getTautothta() <<" has black colour"<<endl;
			else if((*t_m_p).getColour()==white)
                        	cout<<"IceSkater with id:"<<(*temp).getTautothta() <<" has white colour"<<endl;
			else
				cout<<"IceSkater with id:"<<(*temp).getTautothta() <<" going through an ERROR"<<endl;
			if (bohthitiki_oura.getSize()==0)
				xrwma_b_ouras=nothing;
			else
				xrwma_b_ouras=(*(bohthitiki_oura.at(bohthitiki_oura.getSize()-1))).getColour();
		}
		////////////////////////////////////////////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////////////////////////////////////////
		//Dhmiourgeia pagodromou kai eisxwrish tou sthn kyria h sthn  bohthitikh oura//
		else
		{
			a_p_k_ou=kyria_oura.getA_pagodromoi();
			a_p_b_ou=bohthitiki_oura.getA_pagodromoi();
			m_p_k_ou=kyria_oura.getM_pagodromoi();
			m_p_b_ou=bohthitiki_oura.getM_pagodromoi();
			if((a_p_k_ou+a_p_b_ou)==narxiko/2)//Asproi pagodromoi ftasan sto megisto tous  ara eksanagkasmenh mayrh genesi//
				ska=new IceSkater((*ska).random_distance(limni),black,(*ska).random_skill(),(*ska).random_id(&kyria_oura,&bohthitiki_oura));
			else if((m_p_k_ou+m_p_b_ou)==narxiko/2)//Mauroi pagodromoi ftasan sto megisto tous  ara eksanagkasmenh asprh genesi//
				ska=new IceSkater((*ska).random_distance(limni),white,(*ska).random_skill(),(*ska).random_id(&kyria_oura,&bohthitiki_oura));
			else
				ska=new IceSkater((*ska).random_distance(limni),(*ska).random_colour(),(*ska).random_skill(),(*ska).random_id(&kyria_oura,&bohthitiki_oura));
			if((*ska).getColour()==previous)//An to xrwma tou pagodromou pou gennithike twra einai idio me tou prohgoumenou sthn main balto sthn help//
			{
				bohthitiki_oura.pushFront((*ska));
				xrwma_b_ouras=(*ska).getColour();
				cout<<"Adding IceSkater with id:"<<(*ska).getTautothta()<<" to the HelpQueue"<<endl;
				if((*ska).getColour()==black)
                        		cout<<"IceSkater with id:"<<(*ska).getTautothta() <<" has black colour"<<endl;
                        	else if((*ska).getColour()==white)
                       	 		cout<<"IceSkater with id:"<<(*ska).getTautothta() <<" has white colour"<<endl;
                        	else
                        		cout<<"IceSkater with id:"<<(*ska).getTautothta() <<" going through an ERROR"<<endl;
			}
			else//alliws baltw sthn main//
			{
				kyria_oura.pushFront((*ska));
				previous=(*ska).getColour();
				cout<<"Adding IceSkater with id:"<<(*ska).getTautothta()<<" to the MainQueue"<<endl;	
				if((*ska).getColour()==black)
                                        cout<<"IceSkater with id:"<<(*ska).getTautothta() <<" has black colour"<<endl;
                                else if((*ska).getColour()==white)
                                        cout<<"IceSkater with id:"<<(*ska).getTautothta() <<" has white colour"<<endl;
                                else
                                        cout<<"IceSkater with id:"<<(*ska).getTautothta() <<" going through an ERROR"<<endl;
			}
			i++;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		cout<<endl;
		cout<<"/-----------------------------------------------------------------------------/"<<endl;
	}
	//////////////////////////////////////////////////////////////////////////////////////////
	//Eksagwgh kai tou teleutaiou stoixeiou an yparxei sthn bohthitikh oura//
	if(bohthitiki_oura.getSize())
	{
		 temp=(bohthitiki_oura.at(bohthitiki_oura.getSize()-1));
                 t_m_p=new IceSkater(*temp);
                 kyria_oura.pushFront(*t_m_p);
                 cout<<"Adding IceSkater with id:"<<(*t_m_p).getTautothta()<<" to the MainQueue"<<endl;
                 previous=(*t_m_p).getColour();
                 cout<<"Deleting IceSkater with id:"<<(*temp).getTautothta()<<" from the HelpQueue"<<endl;
                 bohthitiki_oura.popBack();
		 if((*t_m_p).getColour()==black)
                       	cout<<"IceSkater with id:"<<(*temp).getTautothta() <<" has black colour"<<endl;
                 else if((*t_m_p).getColour()==white)
                       	cout<<"IceSkater with id:"<<(*temp).getTautothta() <<" has white colour"<<endl;
                 else
                       	cout<<"IceSkater with id:"<<(*temp).getTautothta() <<" going through an ERROR"<<endl;
                 if (bohthitiki_oura.getSize()==0)
              	 	xrwma_b_ouras=nothing;
                 else
                 	xrwma_b_ouras=(*(bohthitiki_oura.at(bohthitiki_oura.getSize()-1))).getColour();
		cout<<endl;
                cout<<"/-----------------------------------------------------------------------------/"<<endl;
	}
	////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////
	//An o arithmos twn pagodromwn einai peritos arithmos tote prosthese kai thn teleutaia pagodromo wste na mhn parabiazei ton kanona xrwmatwn//
	if (n%2==1)
	{
		cout<<"bazinga"<<endl;
		if(n==1)
		ska=new IceSkater((*ska).random_distance(limni),(*ska).random_colour(),(*ska).random_skill(),(*ska).random_id(&kyria_oura,&bohthitiki_oura));
		else
		{
			color prwto=((kyria_oura.getLast())->pagodromos).getColour();
			ska=new IceSkater((*ska).random_distance(limni),prwto,(*ska).random_skill(),(*ska).random_id(&kyria_oura,&bohthitiki_oura));
		}
		kyria_oura.pushFront(*ska);
		cout<<"Adding IceSkater with id:"<<(*ska).getTautothta()<<" to the MainQueue"<<endl;
		 if((*ska).getColour()==black)
                        cout<<"IceSkater with id:"<<(*ska).getTautothta() <<" has black colour"<<endl;
               	else if((*ska).getColour()==white)
                     	cout<<"IceSkater with id:"<<(*ska).getTautothta() <<" has white colour"<<endl;
                else
                       	cout<<"IceSkater with id:"<<(*ska).getTautothta() <<" going through an ERROR"<<endl;

		cout<<endl;
                cout<<"/-----------------------------------------------------------------------------/"<<endl;
	}
	//////////////////////////////////////////////////////////////////////////////////

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//H parakatw synarthsh xrhsimopoiei thn idea oti h oyra pou exei dhmiourgithei tha  periexei pagodromous me enallaks diaforetika xrwmata//
//Ara ayto shmainei oti arxizontaw apo katw aristera kai kinoumenoi antitheta apo thn fora ton deiktwn toy rologioy oi stoibes tha gemizoun opws perigrafetai pio katw//
//To j me traei tous kyklous pou kanoume  eno to i symbolizei tis theseis pou eimaste,otan to j ==i+1+nonskipper  tote den bazoume se ayth thn stoiba stoixeio alla kanoume ena alma //
//kai to bazoume sthn epomenh stoiba gia na ikanopoeitai o kanonas oti den prepei 2 pagodromoi tou idiou xrwmatos na mpoun diadoxika sthn idia stoiba//
//to nonskipper antiprosopeuei ton pio prosfato kyklo(dhladh j) pou den egine  alma //
void Scence::full_stoibes()
{
	IceSkater   *temp ,*t_m_p;
	int flag,i,j=0;
	int nonskipper=0;
	while((kyria_oura.getSize())!=0)
	{	
		i=-1;
		flag=0;
		while(((kyria_oura.getSize())!=0)&&(i<3))
		{
			i++;
			if (j==i+1+nonskipper)
			{
				flag=1;
				continue;
			}
			temp=(kyria_oura.at((kyria_oura.getSize())-1));
			t_m_p=new IceSkater(*temp);
			if (i==0)
			{
				(*(limni.k_a_stoiba())).pushFront((*t_m_p));
				cout<<"Adding Iceskater with id:"<<(*t_m_p).getTautothta()<<" to the down left Stack"<<endl;
				cout<<endl;
			        cout<<"<=================================================================================>"<<endl;
				cout<<endl;
			}
			else if (i==1)
			{
				(*(limni.k_d_stoiba())).pushFront((*t_m_p));
				cout<<"Adding Iceskater with id:"<<(*t_m_p).getTautothta()<<" to the down right Stack"<<endl;
				cout<<endl;
                                cout<<"<=================================================================================>"<<endl;
                                cout<<endl;
			}
			else if (i==2)
			{
				(*(limni.p_d_stoiba())).pushFront((*t_m_p));
				cout<<"Adding Iceskater with id:"<<(*t_m_p).getTautothta()<<" to the upper right Stack"<<endl;
				cout<<endl;
                                cout<<"<=================================================================================>"<<endl;
                                cout<<endl;
			}
			else if (i==3)
			{
				(*(limni.p_a_stoiba())).pushFront((*t_m_p));
				cout<<"Adding Iceskater with id:"<<(*t_m_p).getTautothta()<<" to the upper left Stack"<<endl;
				cout<<endl;
                                cout<<"<=================================================================================>"<<endl;
                                cout<<endl;
			}			
			cout<<"Deleting Iceskater with id:"<<(*temp).getTautothta()<<" from Main Queue"<<endl;
			cout<<endl;
                        cout<<"<=================================================================================>"<<endl;
                        cout<<endl;
                        kyria_oura.popBack();
		}
		if (flag==0)
		{
			nonskipper=j;
		}
		j++;

	}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Se ayth thn synarthsh pali kyklika  antistrofa me thn fora twn deiktwn toy rologiou kai ksekinwntas apo thn katw aristera stoiba eksagoume pagodromous apo tis koryfes twn stoibwn //
//kai afoy kanoyn to performance tous(typwma twn xarakthristikwn toys) olisthainoun ws thn eksodo opou diagrafontai//
void Scence::performance()
{
	IceSkater *temp;
	while((*(limni.k_a_stoiba())).getSize()+(*(limni.k_d_stoiba())).getSize()+(*(limni.p_d_stoiba())).getSize()+(*(limni.p_a_stoiba())).getSize()!=0)
	{
		/////////////////////////////////////////
		if ((*(limni.k_a_stoiba())).getSize()!=0)
		{
			cout<<endl;
                        cout<<"<=================================================================================>"<<endl;
                        cout<<endl;
			temp=(*(limni.k_a_stoiba())).at(0);
			if ((*temp).deksiotita()==jump)
			{
				cout<<"My skill is jump"<<endl;
			}
			else
			{
				cout<<"My skill is  spin"<<endl;
			}
			cout<<"I had make "<<(*temp).skate(limni.getLength())<<" skates"<<endl;
			cout<<"My ID is "<<(*temp).getTautothta()<<endl;
			if((*temp).getColour()==black)
			cout<<"My colour is black"<<endl;
			else cout<<"My colour is white"<<endl;
			cout<<"Deleting Iceskater with id:"<<(*temp).getTautothta()<<" from down left Stack"<<endl;
			(*(limni.k_a_stoiba())).popFront();

		}
		///////////////////////////////////////
		 if ((*(limni.k_d_stoiba())).getSize()!=0)
                {
       	                cout<<endl;
                        cout<<"<=================================================================================>"<<endl;
                        cout<<endl;
			temp=(*(limni.k_d_stoiba())).at(0);
                	if ((*temp).deksiotita()==jump)
                	{
                        	cout<<"My skill is jump"<<endl;
                	}
                	else
                	{
                        	cout<<"My skill is  spin"<<endl;
                	}
                	cout<<"I had make "<<(*temp).skate(limni.getLength())<<" skates"<<endl;
                	cout<<"My ID is "<<(*temp).getTautothta()<<endl;
                	if((*temp).getColour()==black)
               	 	cout<<"My colour is black"<<endl;
                	else cout<<"My colour is white"<<endl;
			cout<<"Deleting Iceskater with id:"<<(*temp).getTautothta()<<" from down right Stack"<<endl;
			(*(limni.k_d_stoiba())).popFront();

		}
		/////////////////////////////////////////
		 if ((*(limni.p_d_stoiba())).getSize()!=0)
                 {
		        cout<<endl;
                        cout<<"<=================================================================================>"<<endl;
                        cout<<endl;
			temp=(*(limni.p_d_stoiba())).at(0);
                	if ((*temp).deksiotita()==jump)
                	{
                        	cout<<"My skill is jump"<<endl;
                	}
                	else
                	{
                        	cout<<"My skill is  spin"<<endl;
                	}
                	cout<<"I had make "<<(*temp).skate(limni.getLength())<<" skates"<<endl;
                	cout<<"My ID is "<<(*temp).getTautothta()<<endl;
                	if((*temp).getColour()==black)
                	cout<<"My colour is black"<<endl;
                	else cout<<"My colour is white"<<endl;
			cout<<"Deleting Iceskater with id:"<<(*temp).getTautothta()<<" from upper right Stack"<<endl;
                	(*(limni.p_d_stoiba())).popFront();
		}
		//////////////////////////////////////////////
		 if ((*(limni.p_a_stoiba())).getSize()!=0)
                {
			 cout<<endl;
                        cout<<"<=================================================================================>"<<endl;
                        cout<<endl;
			temp=(*(limni.p_a_stoiba())).at(0);
                	if ((*temp).deksiotita()==jump)
                	{
                        	cout<<"My skill is jump"<<endl;
                	}
                	else
                	{
                        	cout<<"My skill is  spin"<<endl;
                	}
                	cout<<"I had make "<<(*temp).skate(limni.getLength())<<" skates"<<endl;
                	cout<<"My ID is "<<(*temp).getTautothta()<<endl;
                	if((*temp).getColour()==black)
                	cout<<"My colour is black"<<endl;
                	else cout<<"My colour is white"<<endl;
			cout<<"Deleting Iceskater with id:"<<(*temp).getTautothta()<<" from upper left Stack"<<endl;
                	(*(limni.p_a_stoiba())).popFront();

		}
		////////////////////////////////
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Scence::plot()
{
	if (ar_pagodromwn!=0)
	{
		fullK_oura(ar_pagodromwn);
		full_stoibes();
		performance();
	}
	else
	{
		cout<<"WARNING:The amount of IceSkaters cants be zero"<<endl;
	}
}
