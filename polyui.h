
class polyui{
   
   float h,w;
   polynomial p,q;
   
   int i=0,j=0,k=0,m=0; //pointers
   Circle* c[20];
   Line* l[20];
   Text* t[10];
   Rectangle* r[100]; 
   Rectangle rm,rc,r1,r2,r3;  
   bool readytostay=true;
   Circle exitui;

   bool pread=false, qread=false;
   
   Rectangle ppolyread;
   Rectangle qpolyread;
   Rectangle pqswap;
  
   Rectangle add;
   Rectangle minus;
   Rectangle remain;

   Rectangle multiply;
   Rectangle divide;

   Rectangle diffp;
   Rectangle diffq;
   Rectangle integp;
   Rectangle integq;
   Rectangle plotp;
   Rectangle plotq;
   
   public:

   polyui();
   ~polyui();
   void click();
   
   void ppolyreadfn();
   void qpolyreadfn();
   void pqswapfn();

   void addfn();
   void minusfn();
   void remainfn();

   void multiplyfn();
   void dividefn();
   
   void plotpfn();
   void plotqfn();

   void diffpfn();
   void diffqfn();

   void integpfn();
   void integqfn();
   
   void textAlloc(Text tex);   
   void rectAlloc(Rectangle rec);   
   void circAlloc(Circle cir);   
   void lineAlloc(Line lin);

};
