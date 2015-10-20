//File:ice.cpp
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "ice.h"
using namespace std;
//SYNARTHSEIS IceSkater//
    //---------------------------------------------------------------------------------//
	IceSkater::IceSkater(int taxythta,int time,int timepassed,int tautothta,typos level,Node* csq):speed(taxythta),deadline(time),passedtime(timepassed),id(tautothta),skater(level),currentsquare(csq)
	{
		//constructing an IceSkater//
	}
	//IceSkater copy constructor
	IceSkater::IceSkater(const IceSkater &is):speed(is.speed),deadline(is.deadline),passedtime(is.passedtime),id(is.id),skater(is.skater),currentsquare(is.currentsquare)
	{
		//constructing an IceSkater//
	}
	//---------------------------------------------------------------------------------//
	IceSkater::~IceSkater()
	{
		//Destructing an IceSkater//
	}
	//-----------------------------------------------------------------------------//
	//return a random speed at an IceSkater//
	 int IceSkater::randspeed(int x,int y)
	{
		int i,k;
		if(x>=y)i=y+1; //Epelekse thn mikroterh 
		else i=x+1;    //syntetagmenh ws max ths speed
		if (i==1)
		{
			return 1;
		}
		k=rand()%(i);  //epelekse mia tyxaia speed
		return k;
	}
	//----------------------------------------------------------------------------//
	//return a random deadline at an IceSkater type//
	int IceSkater::randdeadline(int xronos)
	{
			int i=0;
			while(i==0) //oso to deadline einai mhden epelekse allo
			i=rand()%xronos; //epelekse tyxaia deadline
			return i;
	}
	//-----------------------------------------------------------------------------------//
	//return a random passedtime at a IceSkater type//
	int IceSkater::randompassedtime()
	{
		int i;
		i=rand()%deadline;//epelekse ena tyxaia xrono pou exei perasei me max to deadline
		return i;
	}
	//-------------------------------------------------------------------------------//
	//return a random id at an IceSkater type//
	int IceSkater::random_id(int x,int y,Node*** grid)
	{
		int flag=0,k=rand();//flag=0 == to id k den einai monadiko 
		while (flag==0)
		{
			flag=1;
			k=rand();
			for(int i=0;i<=x;i++)
				for(int j=0;j<=y;j++)
					if (((*(*(grid[i][j])).getpagodromos()).getid())==k)
							flag=0;
		}
		return k;
	}
	//------------------------------------------------------------------------------//
	//return the speed of the IceSkater//
	int IceSkater::getspeed()
	{
		if (this==NULL) return -1;
		return speed;
	}
	//----------------------------------------------------------------------------------------//
	//return the id of the IceSkater//
	int IceSkater::getid()
	{
		if (this==NULL) return -1;
		return id;
	}
	//---------------------------------------------------------------------------------------//
	//return passedtime from the IceSkater//
	int IceSkater::getpassedtime()
	{
		if (this==NULL) return -1;
		return passedtime;
	}
	//-------------------------------------------------------------------------------------------//
	//return the skatertype//
	typos IceSkater::getskatertype()
	{
		if (this==NULL) return nothing;
		return skater;
	}
	//-------------------------------------------------------------------------------------------//
	//return the deadline of an IceSkater//
	int IceSkater::getdeadline()
	{
		if (this==NULL) return -1;
		return deadline;
	}
	//-------------------------------------------------------------------------------------------------//
	//Move an IceSkater from a position to another on a grid o Nodes//
	 int IceSkater::move (movement motion,Node*** thegrid,int tylength,int txlength,IceSkater ****help)
	{	
		int x=(*currentsquare).getxposition();
		int y=(*currentsquare).getyposition();
		int i;
		if (motion==panw)//kinhsh pros ta panw
		{
			if ((speed+y)<=tylength)//an speed+twrinh thesh den ksepernaei ta oria toy pinaka
			{
				int flag=0;//flag==0 ==kamia sygkroush ola kala
				for(i=0;i<=speed;i++)//to i metraei ta bhmata pros ta panw pou tha ginoun
				{
					if ((*help)[x][y+i]!=NULL)//an o boithitikos pinakas einai mh kenos sto shmeio enos bhmatos ths synolikhs diadromhs twrinh thesh->twrinh thesh+speed
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)//to m metraei tis theseis se ayth thn synetagmenh x
						{
							if ((thegrid[x][m]->getpagodromos())!=NULL)
							{	
								if ((((*help)[x][y+i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==speed))
								//an h tautothta autou pou einai sthn thesh [x][y+i] tou bohthitikou pinaka yparxei kapou se ayth thn sygkekrimenh x gia ola ta y h yparxei pagodromos sto teliko shmeio pou tha teleiwsei auth h kinhsh (speed+y)
								{
									flag2=1;//kane alithis thn sygkroush
									break;
								}
							}
						}
						if (flag2==1)//an exei ginei sygkroush
						{
							(*help)[x][y+i-1]=(*(thegrid[x][y])).getpagodromos();//an ginei sygkroush baltwn mia thesh prin thn sygkroush
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)//an den exei ginei opoiadhpote sygkroush kai olla pane kala
				{
					(*help)[x][y+speed]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else//an speed kai twrinh thesh ksepernaei ta oria tou pinaka
			{
				//ta analoga sxolia me parapanw isxoyn kai edw
				int flag=0;
				for(i=0;i<=(tylength-y);i++)
				{
					if ((*help)[x][y+i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if ((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y+i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==tylength-y))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y+i-1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][tylength]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		else if(motion==katw)
		{
			//analoga sxolia me parapanw efarmozontai kai edw
				if ((y-speed)>=0)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if ((*help)[x][y-i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if ((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y-i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y-i+1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y-speed]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=y;i++)
				{
					if ((*help)[x][y-i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if ((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y-i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==y))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y-i+1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][0]=(*(thegrid[x][y])).getpagodromos();
				}
			}	
		}
		else if(motion==aristera)
		{
			if ((x-speed)>=0)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if ((*help)[x-i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if ((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x-i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x-i+1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x-speed][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=x;i++)
				{
					if ((*help)[x-i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if ((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x-i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==x))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x-i+1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[0][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		else if(motion==deksia)
		{
			if ((speed+x)<=txlength)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if ((*help)[x+i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x+i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x+i-1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x+speed][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=(txlength-x);i++)
				{
					if ((*help)[x+i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x+i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==(txlength-x)))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x+i-1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[txlength][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		
	}
	//--------------------------------------------------------------------------------//
	//return the  truth condition if the IceSkater have to go//
	 bool IceSkater::bye()
	{
		if (deadline==passedtime)return true;
		else return false;
	}
	//------------------------------------------------------------------------------------//
	//Select the position in the grid of an IceSkater from the type of IceSkater//
	Node * IceSkater::give_csq(Ice pagos)
	{
		int m,t,flag=0;
		int x=0;
		int y=0;
		while (flag==0)
		{
			if (skater==beginner)
			{
				int k=10*pagos.getylength()/100;
				int j=10*pagos.getxlength()/100;
				if(k==0)k=1;
				if(j==0)j=1;
				t=rand()%2;
				if (t)//analoga me thn timh tou t  kai tou m epilegoume an o pagodromos tha einai sto panw aristera kommati sto katw deksia kommati sto panw deksia h sto katw aristera
				{
					y=rand()%k;
					x=rand()%j;
					m=rand()%2;
					if(m) y=rand()%(pagos.getylength()+1);
					else if(!m)x=rand()%(pagos.getxlength()+1);
				}
				else if(!t)
				{
					y=pagos.getylength()-rand()%k;
					x=pagos.getxlength()-rand()%j;
					m=rand()%2;
					if(m) y=rand()%(pagos.getylength()+1);
					else if(!m)x=rand()%(pagos.getxlength()+1);
				}
			}
			if (skater==average)
			{
				int k=30*pagos.getylength()/100;
				int j=30*pagos.getxlength()/100;
				if(k==0)k=1;
				if(j==0)j=1;
				t=rand()%2;
				if (t)
				{
					y=rand()%k;
					x=rand()%j;
					m=rand()%2;
					if(m) y=rand()%(pagos.getylength()+1);
					else if(!m)x=rand()%(pagos.getxlength()+1);
				}
				else if(!t)
				{
					y=pagos.getylength()-rand()%k;
					x=pagos.getxlength()-rand()%j;
					m=rand()%2;
					if(m) y=rand()%(pagos.getylength()+1);
					else if(!m)x=rand()%(pagos.getxlength()+1);
				}
			}
			else if (skater==pro)
			{
				y=rand()%(pagos.getylength()+1);
				x=rand()%(pagos.getxlength()+1);
			}
			if ((*(pagos.thegrid()[x][y])).getpagodromos()!=NULL)
			{
				flag=0;
			}
		}
		return pagos.thegrid()[x][y];
	}
	//---------------------------------------------------------------------//
	//return the position at the grid//
	Node * IceSkater::gcsq()
	{
		return currentsquare;
	}
	//---------------------------------------------------------------------------------------------//
	//Increase passed time by 1//
	void IceSkater::passedtimepp()
	{
		passedtime++;
	}
	//-------------------------------------------------------------------------------------------//
	//Synarthseis Average//
	//----------------------------------------------------------------------------------------------------//
	//Construct an Average IceSkater type//
	Average::Average(int taxythta,int time,int timepassed,int tautothta,typos level,Node* csq):IceSkater(taxythta,time,timepassed,tautothta,level,csq)
	{
	}
	//------------------------------------------------------------------------------------------------//
		//Average copy constructor
	Average::Average(const Average &av):IceSkater(av)
	{
		//constructing an Average//
	}
	//Destruct an Average type IceSkater//
	Average::~Average()
	{
	}
	//---------------------------------------------------------------------------------------------------//
	//Do nothing//
	int Average::rand_margin_of_falls()
	{
		return 0;
	}
	//--------------------------------------------------------------------------------------------------------//
	//Move an Average type IceSkater on the grid depending on movement colisions and borders//
	int Average::move(movement motion,Node*** thegrid,int tylength,int txlength,IceSkater ****help)
	{
		//H skepsh me thn move twn average einai idia me ayth twn IceSKATER diaferoun mono sto shmeio oti den mporoun na kinhthoun epanw se pro tmhmata toy plagmatos
		int x=(*currentsquare).getxposition();
		int y=(*currentsquare).getyposition();
		int i;
		if (motion==panw)
		{
			if ((speed+y)<=tylength)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x][y+i])).getdapedo()==pro)
					{
						i--;
						break;
					}
					if ((*help)[x][y+i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y+i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y+i-1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y+i]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=(tylength-y);i++)
				{	
					if((*(thegrid[x][y+i])).getdapedo()==pro)
					{
						i--;
						break;
					}
					if ((*help)[x][y+i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y+i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==(tylength-y)))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y+i-1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y+i]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		else if(motion==katw)
		{
				if ((y-speed)>=0)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x][y-i])).getdapedo()==pro)
					{
						i--;
						break;
					}
					if ((*help)[x][y-i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y-i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y-i+1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y-i]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=y;i++)
				{
					if((*(thegrid[x][y-i])).getdapedo()==pro)
					{
						i--;
						break;
					}
					if ((*help)[x][y-i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y-i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==y))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y-i+1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y-i]=(*(thegrid[x][y])).getpagodromos();
				}
			}	
		}
		else if(motion==aristera)
		{
			if ((x-speed)>=0)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x-i][y])).getdapedo()==pro)
					{
						i--;
						break;
					}
					if ((*help)[x-i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x-i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x-i+1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x-i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=x;i++)
				{
						if((*(thegrid[x-i][y])).getdapedo()==pro)
					{
						i--;
						break;
					}
					if ((*help)[x-i][y]!=NULL)
					{	
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x-i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==x))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x-i+1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x-i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		else if(motion==deksia)
		{
			if ((speed+x)<=txlength)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x+i][y])).getdapedo()==pro)
					{
						i--;
						break;
					}
					if ((*help)[x+i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x+i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x+i-1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x+i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=(txlength-x);i++)
				{
					if((*(thegrid[x+i][y])).getdapedo()==pro)
					{
						i--;
						break;
					}
					if ((*help)[x+i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x+i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==(txlength-x)))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x+i-1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x+i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		
	}
	//---------------------------------------------------------------------------------------------//
	//select average as IceSKATER type//
	typos Average::randomtypos()
	{
		return average;
	}
	//--------------------------------------------------------------------------------------------//
	//print type Average of the Average type IceSkater//
	void Average::couttype()
	{
		cout<<"Average type";
	}
	//-----------------------------------------------------------------------------------------------//
	//Synarthseis Pro//
	//------------------------------------------------------------------------------------------------//
	//Construct a Pro IceSkater type//
	Pro::Pro(int taxythta,int time,int timepassed,int tautothta,typos level,Node* csq):IceSkater(taxythta,time,timepassed,tautothta,level,csq)
	{
	}
	//-------------------------------------------------------------------------------------------------//
	//Pro copy constructor
	Pro::Pro(const Pro &pr):IceSkater(pr)
	{
		//constructing an Pro//
	}
	//Destruct a Pro IceSkater//
	Pro::~Pro()
	{
	}
	//--------------------------------------------------------------------------------------------------------//
	//Do nothinng//
	int Pro::rand_margin_of_falls()
	{
		return 0;
	}
	//---------------------------------------------------------------------------------------------------------//
	//Move a Pro IceSkater through the grid depending on the movement and the borders//
	int Pro::move (movement motion,Node*** thegrid,int tylength,int txlength,IceSkater ****help)
	{
		//Toskeptiko ths kinhseis twn pro iceskater einai to idio me ton iceskater apla den ypaxoyn ptwseis
		int x=(*currentsquare).getxposition();
		int y=(*currentsquare).getyposition();
		int i;
		if (motion==panw)
		{
			if ((speed+y)<=tylength)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if ((*help)[x][y+i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if ((((*help)[x][y+i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==speed))
							{
								flag2=1;
								break;
							}
						}
						if (flag2==1)
						{
							if(i==speed)
							(*help)[x][y+i-1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"I had overacame the colision"<<endl;
							flag=1;
							break;
						} 	
					}
				}
				if (flag==0)
				{
					(*help)[x][y+speed]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=(tylength-y);i++)
				{
					if ((*help)[x][y+i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if ((((*help)[x][y+i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==(tylength-y)))
							{
								flag2=1;
								break;
							}
						}
						if (flag2==1)
						{
							if(i==(tylength-y))
							(*help)[x][y+i-1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"I had overacame the colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][tylength]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		else if(motion==katw)
		{
				if ((y-speed)>=0)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if ((*help)[x][y-i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if ((((*help)[x][y-i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==speed))
							{
								flag2=1;
								break;
							}
						}
						if (flag2==1)
						{
							if(i==speed)
							(*help)[x][y-i+1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"I had overacame the colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y-speed]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=y;i++)
				{
					if ((*help)[x][y-i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if ((((*help)[x][y-i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==y))
							{
								flag2=1;
								break;
							}
						}
						if (flag2==1)
						{
							if(i==y)
							(*help)[x][y-i+1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"I had overacame the colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][0]=(*(thegrid[x][y])).getpagodromos();
				}
			}	
		}
		else if(motion==aristera)
		{
			if ((x-speed)>=0)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if ((*help)[x-i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if ((((*help)[x-i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==speed))
							{
								flag2=1;
								break;
							}
						}
						if (flag2==1)
						{
							if(i==speed)
							(*help)[x-i+1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"I had overacame the colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x-speed][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=x;i++)
				{
					if ((*help)[x-i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if ((((*help)[x-i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==x))
							{
								flag2=1;
								break;
							}
						}
						if (flag2==1)
						{
							if(i==x)
							(*help)[x-i+1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"I had overacame the colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[0][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		else if(motion==deksia)
		{
			if ((speed+x)<=txlength)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if ((*help)[x+i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if ((((*help)[x+i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==speed))
							{
								flag2=1;
								break;
							}
						}
						if (flag2==1)
						{
							if(i==speed)
							(*help)[x+i-1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"I had overacame the colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x+speed][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=(txlength-x);i++)
				{
					if ((*help)[x+i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if ((((*help)[x+i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==(txlength-x)))
							{
								flag2=1;
								break;
							}
						}
						if (flag2==1)
						{
							if(i==(txlength-x))
							(*help)[x+i-1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"I had overacame the colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[txlength][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		
	}
	//--------------------------------------------------------------------------------------------------------//
	//select pro type and return it//
	typos Pro::randomtypos()
	{
		return pro;
	}
	//--------------------------------------------------------------------------------------------------------//
	//print pro type //
	void Pro::couttype()
	{
		cout<<"Pro type";
	}
	//------------------------------------------------------------------------------------------------------------//
	//Synarthseis Beginner//
	//-------------------------------------------------------------------------------------------------------------//
	//Construct a beginner IceSkater type//
	Beginner::Beginner(int taxythta,int time,int timepassed,int tautothta,typos level,Node* csq):IceSkater(taxythta,time,timepassed,tautothta,level,csq)
	{
	}
	//-------------------------------------------------------------------------------------------------------------//
	//Beginner copy constructor
	Beginner::Beginner(const Beginner & beg):IceSkater(beg)
	{
	//constructing an Beginner//
	}
	//Destruct a Beginner type IceSkater//
	Beginner::~Beginner()
	{
	}
	//------------------------------------------------------------------------------------------------------------------//
	//Do Nothing//
	int Beginner::rand_margin_of_falls()
	{
		return 0;
	}
	//----------------------------------------------------------------------------------------------------------------//
	//Give speed 1 at Beginner type//
	int Beginner::randspeed(int x,int y)
	{
		return 1;
	}
	//----------------------------------------------------------------------------------------------------------------//
	//Select Beginner type as type of the IceSkater//
	typos Beginner::randomtypos()
	{
		return beginner;
	}
	//---------------------------------------------------------------------------------------------------------------//
	//Move Beginner IceSkater type on the grid depending on the movement the colosion and the real and type borders//
	int Beginner::move(movement motion,Node*** thegrid,int tylength,int txlength,IceSkater ****help)
	{
		//To skeptiko ths move gia begginer einai pali to idio mono pou den mporoune oi pagodromoi na pane se average kai pro kommatia
		int x=(*currentsquare).getxposition();
		int y=(*currentsquare).getyposition();
		int i;
		if (motion==panw)
		{
			if ((speed+y)<=tylength)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x][y+i])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x][y+i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y+i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y+i-1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y+i]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=(tylength-y);i++)
				{	
					if((*(thegrid[x][y+i])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x][y+i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y+i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==(tylength-y)))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y+i-1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y+i]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		else if(motion==katw)
		{
				if ((y-speed)>=0)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x][y-i])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x][y-i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y-i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y-i+1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y-i]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=y;i++)
				{
					if((*(thegrid[x][y-i])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x][y-i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y-i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==y))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y-i+1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y-i]=(*(thegrid[x][y])).getpagodromos();
				}
			}	
		}
		else if(motion==aristera)
		{
			if ((x-speed)>=0)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x-i][y])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x-i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x-i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x-i+1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x-i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=x;i++)
				{
						if((*(thegrid[x-i][y])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x-i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x-i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==x))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x-i+1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x-i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		else if(motion==deksia)
		{
			if ((speed+x)<=txlength)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x+i][y])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x+i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x+i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x+i-1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x+i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=(txlength-x);i++)
				{
					if((*(thegrid[x+i][y])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x+i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x+i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==(txlength-x)))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x+i-1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x+i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		
	}
	//----------------------------------------------------------------------------------------------------//
	//Print Begginer for Beginner IceSkater type//
	void Beginner::couttype()
	{
		cout<<"Beginner type";
	}
	//-------------------------------------------------------------------------------------------------------------//
	//Synarthseis Kid//
	//----------------------------------------------------------------------------------------------------------------//
	//Construct a Kid Beginner type//
	Kid::Kid(int taxythta,int time ,int timepassed,int tautothta,typos level,Node* csq,int ptwseis):Beginner(taxythta,time,timepassed,tautothta,level,csq),falls(ptwseis)
	{
	}
	//--------------------------------------------------------------------------------------------------------------------------//
	//Average copy constructor
	Kid::Kid(const Kid & kd):Beginner(kd),falls(kd.falls)
	{
		//constructing an Kid//
	}
	//Destruct a Kid Beginner type//
	Kid::~Kid()
	{
	}
	//--------------------------------------------------------------------------------------------------------------------------//
	//return falls of the kid//
	int Kid::get_falls()
	{
		return falls;
	}
	//----------------------------------------------------------------------------------------------------------------------------//
	//Define the margin of falls//
	int Kid::rand_margin_of_falls()
	{
		return rand()%8+3;
	}
	//------------------------------------------------------------------------------------------------------------------------------//
	//Check if the the Kid have to go and return the condition//
	bool Kid::bye()
	{
		if (deadline==passedtime)return true;
		if (falls==0)return true;
		else return false;
	}
	//-------------------------------------------------------------------------------------------//
	//Move the Kid type on the grid depending on the movement,colisions and borders,imaginary or real and increase the falls at colisions//
	int Kid::move(movement motion,Node*** thegrid,int tylength,int txlength,IceSkater ****help)
	{
		//To skeptiko ths move gia kid einai pali to idio mono pou den mporoune oi pagodromoi na pane se average kai pro kommatia kai  anaibainei to plithos twn ptwsewn
		int x=(*currentsquare).getxposition();
		int y=(*currentsquare).getyposition();
		int i;
		if (motion==panw)
		{
			if ((speed+y)<=tylength)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x][y+i])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x][y+i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if ((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y+i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y+i-1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							falls--;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y+i]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=(tylength-y);i++)
				{	
					if((*(thegrid[x][y+i])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x][y+i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y+i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==(tylength-y)))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y+i-1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							falls--;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y+i]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		else if(motion==katw)
		{
				if ((y-speed)>=0)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x][y-i])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x][y-i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y-i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y-i+1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							falls--;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y-i]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=y;i++)
				{
					if((*(thegrid[x][y-i])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x][y-i]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=tylength;m++)
						{
							if((thegrid[x][m]->getpagodromos())!=NULL)
							{
								if ((((*help)[x][y-i]->getid())==((thegrid[x][m]->getpagodromos())->getid()))||(i==y))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x][y-i+1]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							falls--;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x][y-i]=(*(thegrid[x][y])).getpagodromos();
				}
			}	
		}
		else if(motion==aristera)
		{
			if ((x-speed)>=0)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x-i][y])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x-i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x-i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x-i+1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							falls--;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x-i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=x;i++)
				{
						if((*(thegrid[x-i][y])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x-i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x-i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==x))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x-i+1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							falls--;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x-i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		else if(motion==deksia)
		{
			if ((speed+x)<=txlength)
			{
				int flag=0;
				for(i=0;i<=speed;i++)
				{
					if((*(thegrid[x+i][y])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x+i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x+i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==speed))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x+i-1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							falls--;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x+i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
			else
			{
				int flag=0;
				for(i=0;i<=(txlength-x);i++)
				{
					if((*(thegrid[x+i][y])).getdapedo()!=skater)
					{
						i--;
						break;
					}
					if ((*help)[x+i][y]!=NULL)
					{
						int m;
						int flag2=0;
						for(m=0;m<=txlength;m++)
						{
							if((thegrid[m][y]->getpagodromos())!=NULL)
							{
								if ((((*help)[x+i][y]->getid())==((thegrid[m][y]->getpagodromos())->getid()))||(i==(txlength-x)))
								{
									flag2=1;
									break;
								}
							}
						}
						if (flag2==1)
						{
							(*help)[x+i-1][y]=(*(thegrid[x][y])).getpagodromos();
							cout<<"colision"<<endl;
							falls--;
							flag=1;
							break;
						}
					}
				}
				if (flag==0)
				{
					(*help)[x+i][y]=(*(thegrid[x][y])).getpagodromos();
				}
			}
		}
		
	}
	//---------------------------------------------------------------------------------------------------//
	//Print Kid for kid type//
	void Kid::couttype()
	{
		cout<<"Kid type";
	}
	//-------------------------------------------------------------------------------------------------------//
	//Synarthseis NODE//
	//--------------------------------------------------------------------------------------------------------//
	//Construct a Node //
	Node::Node(IceSkater* skater,typos patwma,int x,int y):pagodromos(skater),dapedo(patwma),xposition(x),yposition(y)
	{
	}
	//----------------------------------------------------------------------------------------------------------------//
	//Destruct a Node//
	Node::~Node()
	{
	}
	//-----------------------------------------------------------------------------------------------------------------------//
	//Return tha adress of the IceSkater at this Node//
	IceSkater* Node::getpagodromos()
	{
		return pagodromos;
	}
	//--------------------------------------------------------------------------------------------------------------------------//
	//Return x axis position//
	int Node::getxposition()
	{
		return xposition;
	}
	//--------------------------------------------------------------------------------------------------------------------------------//
	//Return y axis position//
	int Node::getyposition()
	{
		return yposition;
	}
	//---------------------------------------------------------------------------------------------------------------------------------//
	//Change IceSkater at this position of the grid,namely at Node//
	void Node::changepagodromos(IceSkater* temp)
	{
		pagodromos=temp;
	}
	//-------------------------------------------------------------------------------------------------------------------------------------//
	//Give the acceptable IceSkater types on every Node depending on the distance of the real borders//
	typos Node::chosedapedo(int x,int y,int txlength,int tylength)
	{
				int k=10*tylength/100;
				int j=10*txlength/100;
				int l=30*tylength/100;
				int m=30*txlength/100;
				if (((x<=(0+j))&&(y<=tylength))||((x>=txlength-j)&&(y<=tylength))||((x<=txlength)&&(y<=(0+k)))||((x<=txlength)&&(y>=(tylength-k))))
				{
					return beginner;
				}
				else if (((x<=(0+m))&&(y<=tylength))||((x>=txlength-m)&&(y<=tylength))||((x<=txlength)&&(y<=(0+l)))||((x<=txlength)&&(y>=(tylength-l))))
				{
					return average;
				}
				else
				{
					return pro;
				}
				
	}
	//---------------------------------------------------------------------------------------------------------------------------------------//
	//Return the type of the Current Node//
	typos Node::getdapedo()
	{
		return dapedo;
	}
	//----------------------------------------------------------------------------------------------------------------------------------------//
	//Synarthseis Ice//
	//---------------------------------------------------------------------------------------------------------------------------------------//
	//Construct an Ice//
	Ice::Ice(int x,int y, int n,int time):xlength(x),ylength(y),arithmos_pagodromwn(n),xronos(time)
	{
		int i,j;
		grid=new Node**[x];
		for ( i=0;i<=x;i++)
		{
			grid[i]=new Node*[y];
			for( j=0;j<=y;j++)
			{
				Node * ptr=new Node(NULL,ptr->chosedapedo(i,j,xlength,ylength),i,j);
				grid[i][j]=ptr;//initialize grid
			}
		}
		i=0;
		j=0;
		//gemise to plegma me n tyxaious pagodromous se tyxaies theseis
		while((n!=0)&&(i<=x)&&(j<=y))
		{
			i=0;
			while((n!=0)&&(i<=x)&&(j<=y))
			{
				if((rand()%n)>=(rand()%(i+j+1)))//oso pio konta eimaste sthn arxh tou pinaka toso auksanetai h pithanothta na mpei kapoios pagodromos se ena shmeio
				{
					IceSkater* pt;
					if(((*grid[i][j]).getdapedo())==beginner)
					{
						 int k=rand()%2;
						 if(k)
						 {
						 	Beginner be(be.randspeed(xlength,ylength),be.randdeadline(time),be.randompassedtime(),be.random_id(xlength,ylength,grid),be.randomtypos(),grid[i][j]);
						 	Beginner * beginner=new Beginner(be);
						 	pt=beginner;
						 }
						 else if (!k)
						 {
						 	Kid kd(kd.randspeed(xlength,ylength),kd.randdeadline(time),kd.randompassedtime(),kd.random_id(xlength,ylength,grid),kd.randomtypos(),grid[i][j],kd.rand_margin_of_falls());
						 	Kid * kid=new Kid(kd);
							pt=kid;
						 }
						
					}
					else if((grid[i][j]->getdapedo())==average)
					{
						Average av(av.randspeed(xlength,ylength),av.randdeadline(time),av.randompassedtime(),av.random_id(xlength,ylength,grid),av.randomtypos(),grid[i][j]);
						Average * average=new Average(av);
						pt=average;         
					}
					else
					{
						Pro pr(pr.randspeed(xlength,ylength),pr.randdeadline(time),pr.randompassedtime(),pr.random_id(xlength,ylength,grid),pr.randomtypos(),grid[i][j]);
						Pro * pro=new Pro(pr);
						pt=pro;	
					}
					grid[i][j]->changepagodromos(pt);
					n--;
				}
				i++;
			}
			j++;
		}
	}
	//--------------------------------------------------------------------------------------------------------------------------------------//
	//Destructing an Ice//
	Ice::~Ice()
	{
		int i,j;
		for (i=0; i<=xlength; i++)
		{	
        	for (j=0; j<=ylength; j++)
        	{
                delete[] grid[i][j];
            }
            delete[] grid[i];
        }
        delete[]grid;
	}
	//----------------------------------------------------------------------------------------------------------------------------------------//
	//Return Ice x length//
	int Ice::getxlength()
	{
		return xlength;
	}
	//-----------------------------------------------------------------------------------------------//
	//Return Ice y length//
	int Ice::getylength()
	{
		return ylength;
	}
	//--------------------------------------------------------------------------------------------//
	//Return xronos//
	int Ice::getxronos()
	{
		return xronos;
	}
	//-----------------------------------------------------------------------------------------//
	// Return Arithmos pagodromwn//
	int Ice::getar_pagodromwn()
	{
		return arithmos_pagodromwn;
	}
	//----------------------------------------------------------------------------------------//
	//Return the grid//
	Node *** Ice::thegrid()
	{
		return grid;
	}
	//-------------------------------------------------------------------------------------//
	//Make a move for all the IceSkaters in the grid//
	void Ice::moveall()
	{
		int i,j;
		IceSkater ***temp;
		temp=new IceSkater**[xlength];
		for ( i=0;i<=xlength;i++)
		{
			temp[i]=new IceSkater*[ylength];
			for( j=0;j<=ylength;j++)
			{
				IceSkater * ptr=NULL;//initialize temp
				temp[i][j]=ptr;
			}
		}
		
		for(i=0;i<=xlength;i++)
		{
			for(j=0;j<=ylength;j++)
			{
				//kinhsh analoga thn thesh pou eisai kai thn tyxaia metablhth k
				if ((grid[i][j]->getpagodromos())!=NULL)
				{
					if (j<((ylength+1)/2))
					{
							if(i<((xlength+1)/2))
							{
								int k=rand()%2;
								if(k==0)
								{
									(grid[i][j]->getpagodromos())->move(panw,grid,ylength,xlength,&temp);
									(grid[i][j]->getpagodromos())->passedtimepp();
								}
								else if (k==1)
								{
									(grid[i][j]->getpagodromos())->move(aristera,grid,ylength,xlength,&temp);
									(grid[i][j]->getpagodromos())->passedtimepp();
								}
							}
							else if(i>=((xlength+1)/2))
							{
								int k=rand()%2;
								if(k==0)
								{
									(grid[i][j]->getpagodromos())->move(katw,grid,ylength,xlength,&temp);
									(grid[i][j]->getpagodromos())->passedtimepp();
								}
								else if (k==1)
								{
									(grid[i][j]->getpagodromos())->move(aristera,grid,ylength,xlength,&temp);
									(grid[i][j]->getpagodromos())->passedtimepp();
								}
							}
						}
						else if(j>=((ylength+1)/2))
						{
							if(i<((xlength+1)/2))
							{
								int k=rand()%2;
								if(k==0)
								{
									(grid[i][j]->getpagodromos())->move(panw,grid,ylength,xlength,&temp);
									(grid[i][j]->getpagodromos())->passedtimepp();
								}
								else if (k==1)
								{
									(grid[i][j]->getpagodromos())->move(deksia,grid,ylength,xlength,&temp);
									(grid[i][j]->getpagodromos())->passedtimepp();
								}
							}
							else if(i>=((xlength+1)/2))
							{
								int k=rand()%2;
								if(k==0)
								{
									(grid[i][j]->getpagodromos())->move(katw,grid,ylength,xlength,&temp);
									(grid[i][j]->getpagodromos())->passedtimepp();
								}
								else if (k==1)
								{
									(grid[i][j]->getpagodromos())->move(deksia,grid,ylength,xlength,&temp);
									(grid[i][j]->getpagodromos())->passedtimepp();
								}
							}	
						}
					
						
					
				}
			}
		}
		for(i=0;i<=xlength;i++)
		for(j=0;j<=ylength;j++)
		grid[i][j]->changepagodromos(temp[i][j]);
		xronos--;
	}
	//----------------------------------------------------------------------------------------------------------------------//
	//Delete the IceSkaters that have to go//
	void Ice::trushthedead()
	{
		int i,j;
		for(i=0;i<=xlength;i++)
		for(j=0;j<=ylength;j++)
		if((grid[i][j]->getpagodromos())->bye())
		{
			delete (grid[i][j]->getpagodromos());
			grid[i][j]->changepagodromos(NULL);
		}
	}
	//---------------------------------------------------------------------------------------------------------------------//
	//Print the positions of the IceSkaters at one moment of time//
	void Ice::stigmiotypo()
	{
		int i,j;
		for(j=ylength;j>=0;j--)
		{	
			cout<<"["<<j<<"]"<<"||";
			for(i=0;i<=xlength;i++)
			{
				if(grid[i][j]->getpagodromos()==NULL)
				cout<<"[ ]";
				else 
				cout<<"[*]";
			}
			cout<<endl;
		}
		cout<<"     ";
		for(i=0;i<=xlength;i++)
		{
			cout<<"===";
		}
		cout<<endl;
		cout<<"     ";
		for(i=0;i<=xlength;i++)
		{
			cout<<"["<<i<<"]";
		}
		for(i=0;i<=xlength;i++)
		{
			for(j=0;j<=ylength;j++)
			{
				if ((grid[i][j]->getpagodromos())!=NULL)
				{
					cout<<endl;
					cout<<"<====================================================>"<<endl;
					cout<<"IceSkater with id :"<<(grid[i][j]->getpagodromos())->getid()<<" is on the block:["<<i<<"]["<<j<<"]"<<endl;
					cout<<"IceSkater with id :"<<(grid[i][j]->getpagodromos())->getid()<<" is " ;
					(grid[i][j]->getpagodromos())->couttype();
					cout<<"."<<endl;
					cout<<"IceSkater with id :"<<(grid[i][j]->getpagodromos())->getid()<<"has "<<(grid[i][j]->getpagodromos())->getspeed()<<" speed"<<endl;
					cout<<"<====================================================>"<<endl;
				}
			}
		}
	}
	//--------------------------------------------------------------------------------------------------------------------------------------//
	//Make all moves while there is enough time//
	void Ice::performance()
	{
		while(xronos>0)
		{
			moveall();
			stigmiotypo();
			trushthedead();
		}
	}
	//-------------------------------------------------------------------------------------------------------------------------------------//
