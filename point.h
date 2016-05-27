
class Point{
	double x, y;

public:
   Point();
   Point(double a,double b);
	void read();
	Point(const Point &a);
	double dist(Point a);
	bool inRect(Rectangle a);
	bool inCircle(Circle a);
   double getX();
   double getY();	
};
