void Dialog::rectAlloc(Rectangle rec){
   r[m] = new Rectangle;
   *r[m] = rec;
   m++;
}

void Dialog::textAlloc(Text txt){
   t[k] = new Text;
   *t[k] = txt;
   k++;
}

void Dialog::circAlloc(Circle cir){
   c[i] = new Circle;
   *c[i] = cir;
   i++;   
}
void Dialog::lineAlloc(Line lin){
   l[j] = new Line;
   *l[j] = lin;
   j++;  
}

void Dialog::click(){

	Point e; e.read();
   
	if(e.inRect(Paint)){
		 cout << "Opening Paint" << endl;// ob correspoinding to app
		 paint xyz;
	}
	else if(e.inRect(PolyPr)){
		 cout << "Opening PolyProcessor" << endl;// ob correspoinding to app
		 polyui pui;
	}
	else if(e.inRect(TextPr)){
		cout << "Opening TextProcessor" << endl;// ob correspoinding to app
		tcui tpx;
	}
	
		
	else if( e.inCircle(exitb) ){
		
		readytostay=false;
	} 

}

Dialog::Dialog(double l,double m){
   
	w = l;	h = m;

	float wd=3*w/4; float hd=2*h/3; // window dimensions

	for(int i=0; i<rln; i++){ // animation

		Rectangle d( w/8 + wd/2 , h + ( hd/2-5*h/6 )*(i/rln), (i/rln)*wd, (i/rln)*hd );

		d.setColor(COLOR(230,228,227)); d.setFill();
		
		Rectangle doutline( w/8 + wd/2 , h + ( hd/2-5*h/6 )*(i/rln), (i/rln)*wd, (i/rln)*hd );

		rptr[rpr] = new Rectangle; rptr[rpr+irln] = new Rectangle;
		*rptr[rpr] = d; *rptr[rpr+irln] = doutline; rpr++; // rpr-1 points to the last rectangle

		if(i!=rln-1){
			delete rptr[i];
			delete rptr[i+irln];
		}

		//wait(1.0/rln);		

	}

	double r=h/20; // radius of exit button

	exitb.init(w-r-10,r+10,r); exitb.setColor(COLOR(243,81,79)); exitb.setFill(); // Exit from dialog
	circAlloc(exitb);
	
	// links to apps

	Paint.init( w/2, h/2-hd/3+10 , wd-20, hd/3-10);
	Text painttxt( w/2, h/2-hd/3+10 , "Paint");
	
	PolyPr.init( w/2, h/2 , wd-20, hd/3-10);
	Text polytxt( w/2, h/2 , "Polynomial Processor");  
	
	TextPr.init( w/2, h/2+hd/3-10, wd-20, hd/3-10); 
	Text textprtxt(w/2, h/2+hd/3-10 , "Text Processor");
	
	Line paintpoly(w/2-wd/2+20,h/2-hd/6, w/2+wd/2-20, h/2-hd/6);
	Line polytext(w/2-wd/2+20,h/2+hd/6, w/2+wd/2-20, h/2+hd/6);
		
	cout << "Opening Dialog Box." << endl;
	
	while(readytostay){
		click();		
	}
}

Dialog::~Dialog(){

	cout << "Closing Dialog Box." << endl;
   for(int x = 0;x<m;x++) 
      delete r[x]; 
   for(int x = 0;x<i;x++)
      delete c[x];
   for(int x = 0;x<j;x++)
      delete l[x];
   for(int x = 0;x<k;x++)
      delete t[x];

 	delete rptr[rpr-1];
	delete rptr[rpr+irln-1];

}
