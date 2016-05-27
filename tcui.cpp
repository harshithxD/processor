
void tcui::rectAlloc(Rectangle rec){
   r[m] = new Rectangle;
   *r[m] = rec;
   m++;
}

void tcui::textAlloc(Text txt){
   t[k] = new Text;
   *t[k] = txt;
   k++;
}

void tcui::circAlloc(Circle cir){
   c[i] = new Circle;
   *c[i] = cir;
   i++;   
}
void tcui::lineAlloc(Line lin){
   l[j] = new Line;
   *l[j] = lin;
   j++;  
}

void tcui::click(){

   Point e; e.read();
   
   if(e.inRect(comp)){
       cout << "Compressor is active." << endl;
       tstring a;
       a.compress();
   }
   else if(e.inRect(decomp)){
       cout << "Decompressor is active." << endl;
       tstring b;
       b.decompress();
   }
   else if(e.inRect(analyse)){
    cout << "Analysis." << endl;
    tstring c;
    c.analyse();
   }   
      
   else if( e.inCircle(exitui) ){      
      readytostay=false;
   } 

}

tcui::tcui(){ //tcui layout
   w = 800,h = 600;
   
   //AppBounds
   double wp = (6*w)/8,hp = (4*h)/6;
   rm.init(w/2,h/2,wp,hp); Rectangle rmoutl(w/2,h/2,wp,hp);
   rm.setColor(COLOR(230,228,227));rm.setFill();
   rectAlloc(rm); rectAlloc(rmoutl);
   
   //AppTaskBar
   int it=25;  // Task bar
   Rectangle tk[2*it];
   double t=it, ht=h/16; double pdown=0;
 
   for(int i=0; i<t; i++){
      tk[i+it].init(w/2,(h/2) - (hp/2 )- (ht/2)+(ht/(2*t))*i + (pdown),wp,ht/(2*t));
      tk[i+it].setColor(COLOR(0,0,0));
      tk[i+it].setFill(true);
      
      tk[i].init(w/2,(h/2) - (hp/2 )- (ht/2)-(ht/(2*t))*i + (pdown),wp,ht/(2*t));
      tk[i].setColor(COLOR(65+(60.0/t)*i,65+(60.0/t)*i,65+(60.0/t)*i));
      tk[i].setFill(true);
      
      rectAlloc(tk[i]); rectAlloc(tk[i+it]);
   }
   
   //exitButton
    float rad = h/20; // setting r to the size of exitui button
 
    exitui.init(w-rad-10,rad+10,rad); exitui.setColor(COLOR(243,81,79)); exitui.setFill();
    Circle olexitui(w-rad-10,rad+10,rad); circAlloc(exitui); circAlloc(olexitui);
         
   // links

   comp.init( w/2, h/2-hp/3, wp, hp/3); 
   Text comptxt( w/2, h/2-hp/3 , "Compress");// the dimensions of the dialog box
   //textAlloc(painttxt);

   decomp.init(w/2, h/2, wp, hp/3);
   Text decomptxt( w/2, h/2 , "Decompress");  
   //textAlloc(polytxt);

   analyse.init(w/2, h/2+hp/3, wp, hp/3); 
   Text analysetxt(w/2, h/2+hp/3, "Analysis");
   //textAlloc(textprtxt);

   Line compdecomp(w/2-wp/2+20,h/2-hp/6, w/2+wp/2-20, h/2-hp/6);
   Line decompanalyse(w/2-wp/2+20,h/2+hp/6, w/2+wp/2-20, h/2+hp/6);
   //rectAlloc(Paint); rectAlloc(PolyPr); rectAlloc(TextPr); // allocations

   cout << "The files under analysis in this processor should be of txt type." << endl;
   cout << "The text should be written in one paragraph with none of the lines having an empty line between them." << endl;
   cout << "The files analysed, created or read should and will be in the same directory as the Application." << endl; 
   
   while(readytostay){
      click();      
   }
}

tcui::~tcui(){

  cout << "Closing Text Processor." << endl;

   for(int x = 0;x<m;x++) 
      delete r[x]; 
   for(int x = 0;x<i;x++)
      delete c[x];
   for(int x = 0;x<j;x++)
      delete l[x];
   for(int x = 0;x<k;x++)
      delete t[x];
}




