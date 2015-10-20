//File:class.h
 enum color{nothing=-1,black=0,white};
 enum skill{spin=0,jump};
class List;
class Lake;
//CLASS ICESKATER//
class IceSkater
{
private:
        int id;
        int distance;
        int position;
        color xrwma;
        skill _deksiothta;
public:
        IceSkater(int dista ,color xrwma_ ,skill deks,int identification);
        IceSkater( const IceSkater& skater);
        ~IceSkater();
        skill deksiotita();
        int skate(int dist);
        int getPosition();
        int getTautothta();
        color getColour();
	color  random_colour();
	skill random_skill();
        int  random_distance(Lake limnoutza);
        int random_id(List* listaK,List* listaB);
};

//CLASS NODE//
class Node
{
public:
	IceSkater& pagodromos;
	Node* next;
	Node(IceSkater& skater,Node*n);
	~Node();
};

//CLASS LIST//
class List
{
private:
	Node* start;
	Node* last;
	int size;
	int m_pagodromoi;
	int a_pagodromoi;
public:
	List();
	~List();
	Node* getStart();
	Node* getLast();
	int getSize();
	int getM_pagodromoi();
	int getA_pagodromoi();
	void pushFront(IceSkater& skate);
	bool popBack();
	bool popFront();
	IceSkater* at(int pos);
};

//CLASS LAKE//
class Lake
{
private:
	int length;
	List k_a_stoiba_;
	List k_d_stoiba_;
	List p_d_stoiba_;
	List p_a_stoiba_;
public:
	Lake(int l);
	~Lake();
	int getLength();
	List * k_a_stoiba();
	List * k_d_stoiba();
	List * p_a_stoiba();
	List * p_d_stoiba();
};
//CLASS Scence//
class Scence
{
private:
	Lake limni;
	List kyria_oura;
	List bohthitiki_oura;
	int ar_pagodromwn;
public:
	Scence(int l,int num);
	~Scence();
	int getAr_pagodromwn();
	void fullK_oura(int n);
	void plot();
	void full_stoibes();
        void performance();

};
