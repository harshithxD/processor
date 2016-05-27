
class tcui{
   
   float h,w;
   int i=0,j=0,k=0,m=0; //pointers
   Circle* c[20];
   Line* l[20];
   Text* t[10];
   Rectangle* r[100]; 
   Rectangle rm,rc,r1,r2,r3;  

   Circle exitui;
   Rectangle comp, decomp, analyse;
   bool readytostay = true;

   public:

   tcui();
   ~tcui();
   void rectAlloc(Rectangle rec);
   void circAlloc(Circle cir);
   void lineAlloc(Line lin);
   void textAlloc(Text txt);
   void click();
  
};