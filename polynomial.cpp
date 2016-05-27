
void polynomial::read(){
   int m;
   cin >> m;
   double coeff[m];
   int expo[m];
   for(int i = 0;i < m;i++){
      cin >> expo[i];
      cin >> coeff[i];
   }
   int mexpo = expo[0];
   for(int i = 1;i < m;i++){
      mexpo = max(mexpo,expo[i]);
   }
   n = mexpo;
   a = new double[mexpo + 1];
   for(int i = 0;i <= mexpo;i++){
      a[i] = 0;
   }
   for(int i = 0;i < m;i++){
      a[expo[i]] += coeff[i];
   }
}

void polynomial::print(){

  int nzro=0;
  while(a[nzro]==0){
   nzro++;
  }
   
   for(int i=0; i<n+1; i++){
        if(n==0){
            cout << a[0] << endl;
        }
        else{
            if(a[i]==0){
                continue;
            }
            else{
               if(nzro==0){
                   if(a[i]>0){
                     if(i==0) cout << a[i];
                     if(i==1) cout  << " + " << abs(a[i]) << "x";
                     if(i>1 and i!=n) cout << " + " << abs(a[i]) << "x^" << i;
                     if(i==n) cout << " + " << abs(a[n]) << "x^" << n << endl;
                     }
                   else{
                     if(i==0) cout << a[i];
                     if(i==1) cout  << " - " << abs(a[i]) << "x";
                     if(i>1 and i!=n) cout << " - " << abs(a[i]) << "x^" << i;
                     if(i==n) cout << " - " << abs(a[n]) << "x^" << n << endl;
                     }
               
               }
               else{
                  if(a[i]>0){
                     
                     if(i==nzro) cout  << (a[i]) << "x";
                     if(i>nzro and i!=n) cout << " + " << abs(a[i]) << "x^" << i;
                     if(i==n) cout << " + " << abs(a[n]) << "x^" << n << endl;
                     }
                   else{
                     if(i==nzro) cout  << (a[i]) << "x" << endl;
                     if(i>nzro and i!=n) cout << " - " << abs(a[i]) << "x^" << i;
                     if(i==n) cout << " - " << abs(a[n]) << "x^" << n << endl;
                     }
               }
            }
        }
   }

}

polynomial polynomial::operator+(const polynomial &b){

   int x = max(n,b.n);
   int y = min(n,b.n);
   polynomial c;
   c.n = x;
   c.a = new double[x+1];
   for(int i = 0; i < x+1; i++)
      if(i<y+1)
         c.a[i] = a[i] + b.a[i];
      else if(n > b.n)
         c.a[i] = a[i];
         else
            c.a[i] = b.a[i];

   return c;
}

polynomial polynomial::operator-(const polynomial &b){
   int x = max(n,b.n);
   int y = min(n,b.n);
   polynomial c;
   c.n = x;
   c.a = new double[x+1];
   for(int i = 0; i < x+1; i++)
      if(i<y+1)
         c.a[i] = a[i] - b.a[i];
      else if(n > b.n)
         c.a[i] = a[i];
         else
            c.a[i] = - b.a[i];

   return c;
}

polynomial & polynomial::operator=(const polynomial &rhs){
   for(int i = rhs.n;i >=0;i--){
      if(rhs.a[i] != 0){
         n = i;
         break;
      }
   }
   a = new double[n+1];
   for(int i =0 ;i<n+1;i++)
      a[i] = rhs.a[i];
   return *this;
}

polynomial polynomial::operator*(const polynomial &b){
   polynomial c;
   c.n = n + b.n;
   c.a = new double[c.n+1];
   for(int i = 0;i < c.n + 1;i++){
      c.a[i] = 0;
   }
   for(int i = 0;i<n+1;i++){
      for(int j = 0;j<b.n+1;j++){
         c.a[i+j] += a[i] * b.a[j];
      }
   }
   return c;
}

polynomial polynomial::operator/(const polynomial &b){
   polynomial c;
   if(b.n <= n){
      polynomial x,y;
      x.n = n - 1;
      y.n = n - b.n;
      y.a = new double[y.n+1];
      for(int i = 0;i<y.n;i++){
         y.a[i] = 0;
      }
      y.a[y.n] = a[n]/b.a[b.n];
      c = y * b;
      polynomial * g = this;
      x = *g - c;
      polynomial z = x / b;
      return y + z;
   }
   else {
      polynomial z;
      z.n = 0;
      z.a = new double[1];
      z.a[0] = 0;
      return z;
   }
}

polynomial polynomial::operator%(const polynomial &b){
     
      polynomial * x = this;

      polynomial z = *x / b;
      polynomial c = z * b;

      return (*x - c);
}

polynomial polynomial::diff(){
   polynomial x;
   x.n = n -1;
   x.a = new double[n];
   for(int i = 1;i<n+1;i++){
      x.a[i-1] = i * a[i];
   }
   return x;
}

polynomial polynomial::integrate(){
   polynomial x;
   x.n = n + 1;
   x.a = new double[n+2];
   x.a[0] = 0;
   for(int i = 1;i<n+2;i++){
      x.a[i] = a[i-1]/i;
   }
   return x;
}

long double polynomial::valueAt(const double &x){
   long double value = a[0];
   for(int i =1;i<n+1;i++){
      value += a[i]*(pow(x,i));
   }
   return value;
}

void polynomial::plot(const double &xl,const double &xr,Rectangle r){
   polynomial * ptr = this;
   Line *lptr;
   repaint();
   double w = r.getWidth() - 10,h = r.getHeight() - 10,cx = r.getX(),cy = r.getY();
   Line l1(cx - w/2 - 5,cy,cx + w/2 + 5,cy);
   if(true){
      long double fy,fx = w/(xr-xl);
      long double dx = 0.009,mx = ptr->valueAt(xl),mn = ptr->valueAt(xl);
      for(long double x = xl ; x <= xr ; x += dx){
         mx = max(mx,ptr->valueAt(x));
         mn = min(mn,ptr->valueAt(x));
      }
      long double xm = max(abs(mx),abs(mn));
      
      fy = h/(xm*2);
      int nlines = (xr - xl)/dx;
      lptr = new Line[nlines + 3];
      long double yl = ptr->valueAt(xl),yr;
      int i =0;
      for(long double x = xl ; x <= xr;x += dx){
        yr = ptr->valueAt(x + dx);
         Line l2((cx - (w/2))+((x - xl)*fx),cy + ((-yl)*fy),(cx - (w/2)) + (x + dx - xl)*fx,cy + ((-yr)*fy));
               lptr[i] = l2; i++;
                 yl = yr;
               }
   }

   cout << "Click to clear." << endl;
   getClick();
   delete[] lptr;
}

