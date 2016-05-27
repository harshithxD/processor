
void paint::rectAlloc(Rectangle rec){
   r[m] = new Rectangle;
   *r[m] = rec;
   m++;
}

void paint::textAlloc(Text txt){
   t[k] = new Text;
   *t[k] = txt;
   k++;
}

void paint::circAlloc(Circle cir){
   c[i] = new Circle;
   *c[i] = cir;
   i++;   
}
void paint::lineAlloc(Line lin){
   l[j] = new Line;
   *l[j] = lin;
   j++;  
}

paint::paint(){ //paint layout
   w = 800,h = 600,n = 3; b=true;
   
   //app bounds
   double wp = (7*w)/8,hp = (5*h)/6;
   rm.init(w/2,h/2,(7*w)/8,(5*h)/6); Rectangle rmoutl(w/2,h/2,(7*w)/8,(5*h)/6);
   rm.setColor(COLOR(230,228,227));rm.setFill();
   rectAlloc(rm); rectAlloc(rmoutl);
   
   //app task bar
   int it=25;
   Rectangle tk[2*it];
   double t=it, ht=h/16;
 
   for(int i=0; i<t; i++){
      tk[i+it].init(w/2,((5*h)/96)+(ht/(2*t))/2+(ht/(2*t))*i,(7*w)/8,ht/(2*t));
      tk[i+it].setColor(COLOR(0,0,0));
      tk[i+it].setFill(true);
      
      tk[i].init(w/2,((5*h)/96)-(ht/(2*t))/2-(ht/(2*t))*i,(7*w)/8,ht/(2*t));
      tk[i].setColor(COLOR(65+(60.0/t)*i,65+(60.0/t)*i,65+(60.0/t)*i));
      tk[i].setFill(true);
      
      rectAlloc(tk[i]); rectAlloc(tk[i+it]);
   }
   
   //canvasBounds
   double wc = wp - 20,hc = hp - 50;
   rc.init(w/2,h/2 + 8,wc,hc); rc.setColor(COLOR("white")); rc.setFill();
   rectAlloc(rc);
   
   //exitButton
    float rad = h/20; // setting r to the size of exitui button
 
    exitui.init(w-rad-10,rad+10,rad); exitui.setColor(COLOR(243,81,79)); exitui.setFill();
    Circle olexitui(w-rad-10,rad+10,rad); circAlloc(exitui); circAlloc(olexitui);
         
	
   //LineButton 
   r1.init(w/16 + 10 + (wc)/(n+1)+24/2,h/12 + 10 +textHeight()/2,24+4,textHeight()+3); r1.setColor(COLOR(255,255,255)); r1.setFill();
   Text t1(w/16 + 10 + (wc)/(n+1)+24/2,h/12 + 10 +textHeight()/2,"Line");
   rectAlloc(r1); textAlloc(t1);
   
   //CircleButton
   r2.init(w/16 + 10 + 2*(wc)/(n+1)+36/2,h/12 + 10 +textHeight()/2,36+4,textHeight()+3); r2.setColor(COLOR(255,255,255)); r2.setFill();
   Text t2(w/16 + 10 + 2*(wc)/(n+1)+36/2,h/12 + 10 +textHeight()/2,"Circle");
   rectAlloc(r2); textAlloc(t2);
   
   //RectangleButton
   r3.init(w/16 + 10 + 3*(wc)/(n+1)+56/2,h/12 + 10 +textHeight()/2,56+4,textHeight()+3); r3.setColor(COLOR(255,255,255)); r3.setFill();
   Text t3(w/16 + 10 + 3*(wc)/(n+1)+56/2,h/12 + 10 +textHeight()/2,"Rectangle");  
   rectAlloc(r3); textAlloc(t3);

   cout << "Welcome to Paint." << endl;
   while(b){
   	Point p; int a;
   	a = drawHelp(p);
    
       if(a == 4){
         b = false;
      }
      paintHelp(a);
   }
}


int paint::drawLine(){
   while(true) { 
      cout << "Line Command Active." << endl;
      Point p,q; int a;
      a = drawHelp(p);
      if(a != 0){
         return a;
         break;
      }
      a = drawHelp(q);
      if(a != 0){
        return a;
        break;
      }
      Line l1(p.getX(),p.getY(),q.getX(),q.getY());
      lineAlloc(l1);

   }     
}
int paint::drawRectangle(){
   
      cout << "Rectangle Command Active." << endl;
      Point p,q; int a;
      a = drawHelp(p);
      if(a != 0){
         return a;
      }
      a = drawHelp(q);
      if(a != 0){
        return a;
      }
      Rectangle r4((p.getX()+q.getX())/2,(p.getY()+q.getY())/2,abs(p.getX()-q.getX()),abs(p.getY()-q.getY()));
      rectAlloc(r4); 
      return 5;
 
}
int paint::drawCircle(){
	
      cout << "Circle Command Active." << endl;
		Point p,q; int a;
      a = drawHelp(p);
      if(a != 0){
         return a;
      }
      a = drawHelp(q);
      if(a != 0){
         return a;
      }
      Circle c1(p.getX(),p.getY(),p.dist(q));
      circAlloc(c1); 
      return 5;
}
paint::~paint(){
   cout << "Closing Paint." << endl;

   for(int x = 0;x<m;x++) 
      delete r[x]; 
   for(int x = 0;x<i;x++)
      delete c[x];
   for(int x = 0;x<j;x++)
      delete l[x];
   for(int x = 0;x<k;x++)
      delete t[x];
}

int paint::drawHelp(Point &p){
	p.read();
   
   if(p.inRect(r1)){
      
      return 1;
   }
   else if(p.inRect(r2)){
      
      return 2;
   }
   else if(p.inRect(r3)){
      
      return 3;
   }
   else if(p.inCircle(exitui)){
      
      return 4;
   }
   else if(p.inRect(rc)){
      
      return 0;
   }
   else return drawHelp(p);
}

int paint::paintHelp(int a){
      if(a == 4){
         b = false;
         return 5;
      }
      else if(a == 1){
         return(paintHelp(drawLine()));
      }
      else if(a == 2){
         return(paintHelp(drawCircle()));
      }
      else if(a == 3){
         return(paintHelp(drawRectangle()));
      }
      else return 5;
}





