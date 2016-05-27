
class paint{
   
   float h,w,n;
   int i=0,j=0,k=0,m=0; // pointers to the graphical objects created

   Circle* c[20];
   Line* l[40];
   Text* t[10];
   Rectangle* r[120];

   Rectangle rm,rc,r1,r2,r3;  
   Circle exitui;
   
   bool b;
   public :
   paint();
   ~paint();
   int drawLine();
   int drawCircle();
   int drawRectangle();
   void rectAlloc(Rectangle rec);
   void circAlloc(Circle cir);
   void lineAlloc(Line lin);
   void textAlloc(Text txt);
   int drawHelp(Point &p);
   int paintHelp(int a);
};
