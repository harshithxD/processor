class polynomial{
   
   int n;
   double *a;
   

public:
   polynomial(){
     
   }
   void read();
   void print();
   polynomial operator+(const polynomial &b);
   polynomial operator/(const polynomial &b);
   polynomial operator%(const polynomial &b);
   polynomial operator*(const polynomial &b);
   polynomial operator-(const polynomial &b);
   polynomial & operator=(const polynomial &rhs); 
   polynomial diff();
   polynomial integrate();
   long double valueAt(const double &x);
   void plot(const double &xl,const double &xr, Rectangle r);
}; 
