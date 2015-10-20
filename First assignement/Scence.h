//File:Scence.h

class Mountains
{
      public:
             Mountains();
             ~Mountains();
};
class Trees
{
      public:
             Trees();
             ~Trees();
};
class Little_House
{
      public:
             Little_House();
             ~Little_House();
};

class Background
{
      private:
              Mountains bouna;
              Trees dentra;
              Little_House spiti;
      public: 
              Background();
              ~Background();
};
class IceSkater
{
      private:
              int distance;
              int position;
      public:
              IceSkater(int Dist);
              ~IceSkater();
              void start();
              void skate(int d);
              void rotate();
              void jump();
};
class Lake
{
      private:
              int length;
              bool dark;
      public :
             Lake(int L);
             ~Lake();
             void light_up();
             void darken();
             void rotate();
	     int get_length();
};
class Scence
{
      private:
              Background topio;
              Lake limni;
              IceSkater pagodromos;
      public: 
              Scence(int L,int Dist);
              ~Scence();
              void plot();
};
