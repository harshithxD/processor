
void Point::read(){

	int p=getClick();
	int xi=p/65536; int yi=p%65536;
	x=xi; y=yi;

}

Point::Point(){}

Point::Point(double a,double b){
   x = a; y = b;
}

Point::Point(const Point &a){

	x=a.x; y=a.y;

}

double Point::dist(Point a){

	return sqrt( (x-a.x)*(x-a.x)+(y-a.y)*(y-a.y) );

}

bool Point::inRect(Rectangle a){

	double cx=a.getX(), cy=a.getY(), w=a.getWidth(), h=a.getHeight();

	if( cx-w/2 < x and x < cx+w/2 and cy-h/2 < y and y < cy+h/2 ) return true;
	else return false;

}

bool Point::inCircle(Circle a){

	Point cc;
	cc.x=a.getX(); cc.y=a.getY();
	
	if ( dist(cc) < a.getRadius() ) return true;
	else return false;

}

double Point::getX(){
   return x;
}

double Point::getY(){
   return y;
}
