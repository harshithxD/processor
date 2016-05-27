void polyui::rectAlloc(Rectangle rec){
   r[m] = new Rectangle;
   *r[m] = rec;
   m++;
}

void polyui::textAlloc(Text txt){
   t[k] = new Text;
   *t[k] = txt;
   k++;
}

void polyui::circAlloc(Circle cir){
   c[i] = new Circle;
   *c[i] = cir;
   i++;   
}
void polyui::lineAlloc(Line lin){
   l[j] = new Line;
   *l[j] = lin;
   j++;  
}

polyui::polyui(){ // poly ui Layout
   w = 800,h = 600;
   
   //AppBounds 
   double wp = (7*w)/8,hp = (5*h)/6;
   rm.init(w/2,h/2,(7*w)/8,(5*h)/6); Rectangle rmoutl(w/2,h/2,(7*w)/8,(5*h)/6);
   rm.setColor(COLOR(230,228,227));rm.setFill();
   // rectAlloc(rm); rectAlloc(rmoutl);
   
   //AppTaskBar
   int it=25;  // Task bar
   Rectangle tk[2*it];
   double t=it, ht=h/16;
 
   for(int i=0; i<t; i++){
      tk[i+it].init(w/2,((5*h)/96)+(ht/(2*t))/2+(ht/(2*t))*i,(7*w)/8,ht/(2*t));
      tk[i+it].setColor(COLOR(0,0,0));
      tk[i+it].setFill(true);
      
      tk[i].init(w/2,((5*h)/96)-(ht/(2*t))/2-(ht/(2*t))*i,(7*w)/8,ht/(2*t));
      tk[i].setColor(COLOR(65+(60.0/t)*i,65+(60.0/t)*i,65+(60.0/t)*i));
      tk[i].setFill(true);
      
      //rectAlloc(tk[i]); rectAlloc(tk[i+it]);
   }
   
   //canvasBounds
   double wc = wp - 20,hc = hp - 80;
   rc.init(w/2,h/2 + 30,wc,hc); rc.setColor(COLOR("white")); rc.setFill();
   rectAlloc(rc);
   
   //exitButton
    float rad = h/20; // setting r to the size of exitui button
 
    exitui.init(w-rad-10,rad+10,rad); exitui.setColor(COLOR(243,81,79)); exitui.setFill();
    Circle olexitui(w-rad-10,rad+10,rad); circAlloc(exitui); circAlloc(olexitui);
         
	// control panel of the polynomial
   // left half // wdb = width of buttons on the left
   
   double wdb=(wc/2-50)/5, htb=20;

   ppolyread.init(w/2-wc/2+wdb/2,h/2-hp/2+10+htb/2, wdb, htb); ppolyread.setColor(COLOR(255,255,255));
   ppolyread.setFill();
   Text ppolyreadtext(w/2-wc/2+wdb/2,h/2-hp/2+10+htb/2, "P");

   qpolyread.init(w/2-wc/2+wdb/2,h/2-hp/2+10+htb/2 + htb + 10, wdb, htb); qpolyread.setColor(COLOR(255,255,255));
   qpolyread.setFill(); // below ppolyread
   Text qpolyreadtext(w/2-wc/2+wdb/2,h/2-hp/2+10+htb/2 + htb + 10, "Q");

   pqswap.init(w/2-wc/2+wdb/2 + (wdb + 10),h/2-hp/2+10+htb/2 + htb/2 + 5, wdb, htb); pqswap.setColor(COLOR(255,255,255));
   pqswap.setFill();
   Text pqswaptext(w/2-wc/2+wdb/2 + (wdb + 10),h/2-hp/2+10+htb/2 + htb/2 + 5, "Swap");

   add.init(w/2-wc/2+wdb/2 + 2*(wdb + 10),h/2-hp/2+10+htb/2, wdb, htb); add.setColor(COLOR(255,255,255));
   add.setFill();
   Text addtext(w/2-wc/2+wdb/2 + 2*(wdb + 10),h/2-hp/2+10+htb/2, "+");

   minus.init(w/2-wc/2+wdb/2 + 3*(wdb + 10),h/2-hp/2+10+htb/2, wdb, htb); minus.setColor(COLOR(255,255,255));
   minus.setFill();
   Text minustext(w/2-wc/2+wdb/2 + 3*(wdb + 10),h/2-hp/2+10+htb/2, "-");

   remain.init(w/2-wc/2+wdb/2 + 4*(wdb + 10),h/2-hp/2+10+htb/2, wdb, htb); remain.setColor(COLOR(255,255,255));
   remain.setFill();
   Text remaintext(w/2-wc/2+wdb/2 + 4*(wdb + 10),h/2-hp/2+10+htb/2, "%"); // top row till here

   multiply.init(w/2-wc/2+wdb/2 + 2*(wdb + 10) + (5+wdb/2) ,h/2-hp/2+10+htb/2 + htb + 10, wdb, htb); multiply.setColor(COLOR(255,255,255));
   multiply.setFill();
   Text multiplytext(w/2-wc/2+wdb/2 + 2*(wdb + 10) + (5+wdb/2) ,h/2-hp/2+10+htb/2 + htb + 10, "x");

   divide.init(w/2-wc/2+wdb/2 + 3*(wdb + 10) + (5+wdb/2) ,h/2-hp/2+10+htb/2 + htb + 10, wdb, htb); divide.setColor(COLOR(255,255,255));
   divide.setFill();
   Text dividetext(w/2-wc/2+wdb/2 + 3*(wdb + 10) + (5+wdb/2) ,h/2-hp/2+10+htb/2 + htb + 10, "/");
   

   // control panel
   // right half // wrb = width of buttons on the right

   double wrb = wc/6-10;

   plotp.init(w/2 + wrb/2, h/2-hp/2+10+htb/2, wrb, htb ); plotp.setColor(COLOR(255,255,255));
   plotp.setFill();
   Text plotptext(w/2 + wrb/2, h/2-hp/2+10+htb/2, "Plot P");

   plotq.init(w/2 + wrb/2, h/2-hp/2+10+htb/2 + htb + 10, wrb, htb ); plotq.setColor(COLOR(255,255,255));
   plotq.setFill();
   Text plotqtext(w/2 + wrb/2, h/2-hp/2+10+htb/2 + htb + 10, "Plot Q");

   diffp.init(w/2 + wrb/2 + (wrb+15), h/2-hp/2+10+htb/2, wrb, htb ); diffp.setColor(COLOR(255,255,255));
   diffp.setFill();
   Text diffptext(w/2 + wrb/2 + (wrb+15), h/2-hp/2+10+htb/2, "Differentiate P");

   diffq.init(w/2 + wrb/2 + (wrb+15), h/2-hp/2+10+htb/2 + htb + 10, wrb, htb ); diffq.setColor(COLOR(255,255,255));
   diffq.setFill();
   Text diffqtext(w/2 + wrb/2 + (wrb+15), h/2-hp/2+10+htb/2 + htb + 10, "Differentiate Q");

   integp.init(w/2 + wrb/2 + 2*(wrb+15), h/2-hp/2+10+htb/2, wrb, htb ); integp.setColor(COLOR(255,255,255));
   integp.setFill();
   Text integptext(w/2 + wrb/2 + 2*(wrb+15), h/2-hp/2+10+htb/2, "Integrate P");

   integq.init(w/2 + wrb/2 + 2*(wrb+15), h/2-hp/2+10+htb/2 + htb + 10, wrb, htb ); integq.setColor(COLOR(255,255,255));
   integq.setFill();
   Text integqtext(w/2 + wrb/2 + 2*(wrb+15), h/2-hp/2+10+htb/2 + htb + 10, "Integrate Q");

   /*
   // allocations rectangles
   rectAlloc(ppolyread); rectAlloc(qpolyread); rectAlloc(pqswap);
   rectAlloc(add); rectAlloc(minus); rectAlloc(remain);
   rectAlloc(multiply); rectAlloc(divide);

   rectAlloc(plotp); rectAlloc(plotq);
   rectAlloc(diffp); rectAlloc(diffq);
   rectAlloc(integp); rectAlloc(integq);

   // allocations text
   textAlloc(ppolyreadtext); textAlloc(qpolyreadtext); textAlloc(pqswaptext);
   textAlloc(addtext); textAlloc(minustext); textAlloc(remaintext);
   textAlloc(multiplytext);  textAlloc(dividetext);

   textAlloc(plotptext); textAlloc(plotqtext);
   textAlloc(diffptext); textAlloc(diffqtext);
   textAlloc(integptext); textAlloc(integqtext);
   */

   cout << "Welcome to Polynomial Processor." << endl;
   cout << "Please read the Polynomials P, Q before proceeding to use operations on them." << endl;

   while(readytostay){
      click();      
   }

}

void polyui::click(){

   Point e; e.read();
   
   if(e.inRect(ppolyread )) ppolyreadfn();
   else if(e.inRect(qpolyread )) qpolyreadfn();
   else if(e.inRect(pqswap )) pqswapfn();
   
   else if(e.inRect(add )) addfn();
   else if(e.inRect(minus )) minusfn();
   else if(e.inRect(remain )) remainfn();

   else if(e.inRect(multiply )) multiplyfn();
   else if(e.inRect(divide )) dividefn();
  
   else if(e.inRect(plotp )) plotpfn();
   else if(e.inRect(plotq )) plotqfn();
   else if(e.inRect(diffp )) diffpfn();
   else if(e.inRect(diffq )) diffqfn();
   else if(e.inRect(integp )) integpfn();
   else if(e.inRect(integq )) integqfn();

   else if( e.inCircle(exitui) ){
      
      readytostay=false;
   } 
}

polyui::~polyui(){

   cout << "Closing Polynomial Processor." << endl;
   
   for(int x = 0;x<m;x++) 
      delete r[x];
   
   for(int x = 0;x<i;x++)
      delete c[x];
   
   for(int x = 0;x<j;x++)
      delete l[x];
   
   for(int x = 0;x<k;x++)
      delete t[x];
   
}


void polyui::ppolyreadfn(){

   
   cout << "Input Polynomial P." << endl;
   cout << "No of terms; followed by index of the term and the coefficients." << endl;
   p.read();
   cout << "P read successfully." << endl;
   pread=true;

}

void polyui::qpolyreadfn(){

   
   cout << "Input Polynomial Q." << endl;
   cout << "No of terms; followed by index of the term and the coefficients." << endl;
   q.read();
   cout << "Q read successfully." << endl;
   qread=true;

}

void polyui::pqswapfn(){

   if (pread and qread){
      polynomial temp;
      temp=q;
      q=p;
      p=temp;
      cout << "Swapping P and Q." << endl;
   }

   else if(!pread and !qread){ cout << "Enter P and Q and try again." << endl; }
   else if(!pread){ cout << "Enter P and try again." << endl; }
   else if(!qread){ cout << "Enter Q and try again." << endl; }

}

void polyui::addfn(){

   if (pread and qread){
      polynomial r=p+q;
      cout << "Addition:" << endl;
      r.print();
   }   
   else if(!pread and !qread){ cout << "Enter P and Q and try again." << endl; }
   else if(!pread){ cout << "Enter P and try again." << endl; }
   else if(!qread){ cout << "Enter Q and try again." << endl; }
   
}

void polyui::minusfn(){

   if (pread and qread){
      polynomial r=p-q;
      cout << "Sutraction:" << endl;
      r.print();
   }  

   else if(!pread and !qread){ cout << "Enter P and Q and try again." << endl; }
   else if(!pread){ cout << "Enter P and try again." << endl; }
   else if(!qread){ cout << "Enter Q and try again." << endl; }
   
}

void polyui::remainfn(){

   if (pread and qread){
      polynomial r=p%q;
      cout << "Remiander:" << endl;
      r.print();
   }  

   else if(!pread and !qread){ cout << "Enter P and Q and try again." << endl; }
   else if(!pread){ cout << "Enter P and try again." << endl; }
   else if(!qread){ cout << "Enter Q and try again." << endl; }

}

void polyui::multiplyfn(){

   if (pread and qread){
      polynomial r=p*q;
      cout << "Product:" << endl;
      r.print();
   }  

   else if(!pread and !qread){ cout << "Enter P and Q and try again." << endl; }
   else if(!pread){ cout << "Enter P and try again." << endl; }
   else if(!qread){ cout << "Enter Q and try again." << endl; }

}

void polyui::dividefn(){


   if (pread and qread){
      polynomial r=p/q;
      cout << "Quotient:" << endl;
      r.print();
   }  

   else if(!pread and !qread){ cout << "Enter P and Q and try again." << endl; }
   else if(!pread){ cout << "Enter P and try again." << endl; }
   else if(!qread){ cout << "Enter Q and try again." << endl; }
   
}

// next batch of buttons

void polyui::plotpfn(){ 

   if(!pread){ cout << "Enter P and try again." << endl; }
   else{
   cout << "Plotting P." << endl << "Graph between?" << endl;
   long double a,b;
   cin >> a >> b;
   if(a<=b) {}
   else{
      long double temp=b;
      b=a; a=temp;
      cout << "Swapped." << endl;
   }
   cout << "Plotting..." << endl << "Please wait." << endl;
   p.plot(a,b,rc);
   }
}

void polyui::plotqfn(){ 

   if(!qread){ cout << "Enter Q and try again." << endl; }
   else{
   cout << "Plotting Q." << endl << "Graph between?" << endl;
   long double a,b;
   cin >> a >> b;
   if(a<=b) {}
   else{
      long double temp=b;
      b=a; a=temp;
      cout << "Swapped." << endl;
   }
   cout << "Plotting..." << endl << "Please wait." << endl;
   q.plot(a,b,rc);
   }
}

void polyui::diffpfn(){

   if(!pread){ cout << "Enter P and try again." << endl; }
   else{
   polynomial r=p.diff();
   cout << "Derivative of P:" << endl;
   r.print();
   }
}

void polyui::diffqfn(){

   if(!qread){ cout << "Enter Q and try again." << endl; }
   else{
   polynomial r=q.diff();
   cout << "Derivative of Q:" << endl;
   r.print();
   }
}

void polyui::integpfn(){

   if(!pread){ cout << "Enter P and try again." << endl; }
   else{
   polynomial r=p.integrate();
   cout << "Integral of P:" << endl;
   r.print();
   }
}

void polyui::integqfn(){

   if(!qread){ cout << "Enter Q and try again." << endl; }
   else{
   polynomial r=q.integrate();
   cout << "Integral of Q:" << endl;
   r.print();
   }
}
