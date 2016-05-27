
void initGUI(){

	double w=800, h=600;  // resolution and screen size
	initCanvas("XGen",w,h);
	
	int ires=100;  // shaded background
	Rectangle back[2*ires];
	double res=ires;
	
	for(int i=0; i<res; i++){
		back[i+ires].init(w/2,h/2+(h/(2*res))/2+(h/(2*res))*i,w,h/(2*res));
		back[i+ires].setColor(COLOR(162+(93.0/res)*i,220+(35.0/res)*i,255));
		back[i+ires].setFill(true);

		back[i].init(w/2,h/2-(h/(2*res))/2-(h/(2*res))*i,w,h/(2*res));
		back[i].setColor(COLOR(162+(93.0/res)*i,220+(35.0/res)*i,255));
		back[i].setFill(true);
	}

	// x on the background

	const float pi=3.1415; float tilt=pi/6; float lb=300; float hshift = h/20; // position of x from the centre

	Rectangle xb(w/2,h/2 - hshift,lb,10); xb.setColor(COLOR(255,255,255));xb.setFill();
	xb.rotate(tilt);
	Rectangle xc(w/2,h/2 - hshift,lb,10); xc.setColor(COLOR(255,255,255)); xc.setFill();
	xc.rotate(-tilt);

	float bl = w/2 - (lb/2)* cos(pi/6);

	Rectangle xrt( w/2 + w/4 + cos(pi/6)*lb/4  , h/2 - sin(pi/6)*lb/2  - hshift, bl + 5*cos(pi/3) ,10);
	xrt.setColor(COLOR(255,255,255)); xrt.setFill();
	
	Rectangle xrb( w/2 + w/4 + cos(pi/6)*lb/4  , h/2 + sin(pi/6)*lb/2  - hshift, bl + 5*cos(pi/3) ,10);
	xrb.setColor(COLOR(255,255,255)); xrb.setFill();
	
	Rectangle xlt( w/4 - cos(pi/6)*lb/4  , h/2 - sin(pi/6)*lb/2  - hshift, bl + 10*cos(pi/3) ,10);
	xlt.setColor(COLOR(255,255,255)); xlt.setFill();

	Rectangle xlb( w/4 - cos(pi/6)*lb/4 , h/2 + sin(pi/6)*lb/2  - hshift, bl + 10*cos(pi/3) ,10);
	xlb.setColor(COLOR(255,255,255)); xlb.setFill();	
	

	int it=25;  // task bar
	Rectangle tk[2*it];
	double t=it, ht=h/12.5;

	for(int i=0; i<t; i++){
		tk[i+it].init(w/2,h-ht/2+(ht/(2*t))/2+(ht/(2*t))*i,w,ht/(2*t));
		tk[i+it].setColor(COLOR(0,0,0));
		tk[i+it].setFill(true);

		tk[i].init(w/2,h-ht/2-(ht/(2*t))/2-(ht/(2*t))*i,w,ht/(2*t));
		tk[i].setColor(COLOR(65+(60.0/t)*i,65+(60.0/t)*i,65+(60.0/t)*i));
		tk[i].setFill(true);
	}

	// home button on the task bar

	int ic=100;
	Circle home[ic];
	double c=ic, r=h/15;
	int start=35;

	for(int i=0; i<start; i++){
		home[i].init(w/2,h-h/30,r-(r/c)*i);
		home[i].setColor(COLOR(40+(80.0/start)*i,40+(80.0/start)*i,40+(80.0/start)*i));
	}

	for(int i=start; i<c; i++){
		home[i].init(w/2,h-h/30,r-(r/c)*i);
		home[i].setColor(COLOR(170+(240-170)*(i/c),(80/c)*i,(80/c)*i)); home[i].setFill(true);
	}


	// exiting the main ui
	
	r=h/20; // setting r to the size of exitui button

	Circle exitui(w-r-10,r+10,r); exitui.setColor(COLOR(243,81,79)); exitui.setFill();
	Circle olexitui(w-r-10,r+10,r);

	cout << "Welcome to Halcyon." << endl;
	
	while(true){
		
		Point t;
		
		t.read();

		if(t.inCircle(home[0])) { //Dialog Box
			Dialog dg(w,h);
		}

		if(t.inCircle(exitui)) { cout << "Thank You." << endl; break; }
	}

}


