//File:ice.h
enum movement{panw=0,katw=1,aristera=2,deksia=3,panwaristera=4,panwdeksia=5,katwaristera=6,katwdeksia=7};
enum typos{nothing=-1,beginner=0,average=1,pro=2};

class Ice;
class Node;
class IceSkater
{
	protected:
	int speed;
	int passedtime;
	int deadline;
	int id;
	typos skater;
	Node * currentsquare;
	public:
	IceSkater(int taxythta,int time,int timepassed,int tautothta,typos level,Node* csq);
	IceSkater(const IceSkater &is);
	~IceSkater();
	virtual int randspeed(int x,int y);
	int randdeadline(int xronos);
	int randompassedtime();
	int random_id(int x,int y,Node*** grid);
	int getspeed();
	int getid();
	int getpassedtime();
	typos getskatertype();
	int getdeadline();
	virtual int move (movement motion,Node*** thegrid,int tylength,int txlength,IceSkater ****help);
	virtual bool bye();
	Node * give_csq(Ice pagos);
	Node * gcsq();
	void passedtimepp();
	virtual typos randomtypos()=0;
	virtual void couttype()=0;
	virtual int rand_margin_of_falls()=0;
};
class Beginner:public IceSkater
{
	protected:
	public:
	Beginner(int taxythta,int time,int timepassed,int tautothta,typos level,Node* csq);
	Beginner(const Beginner &beg);
	~Beginner();
	int move(movement motion,Node*** thegrid,int tylength,int txlength,IceSkater ****help);
	virtual int randspeed(int x,int y);
	typos randomtypos();
	 void couttype();
	 int rand_margin_of_falls();
};
class Kid:public Beginner
{
	private:
	int falls;
	public:
	Kid(int taxythta,int time ,int timepassed,int tautothta,typos level,Node* csq,int ptwseis);
	Kid(const Kid &kd);
	~Kid();
	int get_falls();
	int rand_margin_of_falls();
	bool bye();
	int move(movement motion,Node*** thegrid,int tylength,int txlength,IceSkater ****help);
	void couttype();
};
class Average:public IceSkater
{
	private:
	public:
	Average(int taxythta,int time,int timepassed,int tautothta,typos level,Node* csq);
	Average(const Average &av);
	~Average();
	int move(movement motion,Node*** thegrid,int tylength,int txlength,IceSkater ****help);
	typos randomtypos();
	void couttype();
	int rand_margin_of_falls();
};
class Pro:public IceSkater
{
	private:
	public:
	Pro(int taxythta,int time,int timepassed,int tautothta,typos level,Node* csq);
	Pro(const Pro &pr);
	~Pro();
	int move (movement motion,Node*** thegrid,int tylength,int txlength,IceSkater ****help);
	typos randomtypos();
	void couttype();
	int rand_margin_of_falls();
};

class Node
{
	private:
	IceSkater* pagodromos;
	typos dapedo;
	int xposition;
	int yposition;
	public:
	Node(IceSkater* skater,typos patwma,int x,int y);
	~Node();
	IceSkater* getpagodromos();
	int getxposition();
	int getyposition();
	void changepagodromos(IceSkater* temp);
	typos chosedapedo(int x,int y,int txlength,int tylength);
	typos getdapedo();
};
class Ice
{
	private:
	int xronos;
	int xlength;
	int ylength;
	Node ***grid;
	int arithmos_pagodromwn;
	public:
	Ice(int x,int y, int n,int time);
	~Ice();
	int getxlength();
	int getylength();
	int getxronos();
	int getar_pagodromwn();
	Node *** thegrid();
	void moveall();
	void trushthedead();
	void stigmiotypo();
	void performance();
};
