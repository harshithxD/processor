
class Dialog{

	double w = 800, h = 600, rln=50; int irln=rln; // size and resolution
	Rectangle * rptr[200];
	int rpr=0;

	float wd=3*w/4; float hd=2*h/3;
	
	int i=0,j=0,k=0,m=0; //pointers to the graphic objects created
	
   Circle* c[10];
   
   Line* l[10];
   
   Text* t[10];
   
   Rectangle* r[100]; 
   
   Rectangle Paint, TextPr, PolyPr;

   Circle exitb;   
   bool readytostay=true;

public:

	Dialog(double l, double m);
	void click();
   void rectAlloc(Rectangle rec);
   void circAlloc(Circle cir);
   void lineAlloc(Line lin);
   void textAlloc(Text txt);
   ~Dialog();
};
