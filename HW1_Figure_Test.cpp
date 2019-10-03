#include "HW1_Figure.h"

Figure::Figure(){
	area = 0;
}

Figure::~Figure(){
}

ostream& operator<<(ostream& os, const Figure& fig){
	return fig.print(os);
}

Rectangle::Rectangle(){
	height = 0;
	width = 0;
	point = NULL;
	area = height * width;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2){
	point = new int[4];
	if(x1 < x2){
		point[0] = x1;
		point[2] = x2;
	}else{
		point[0] = x2;
		point[2] = x1;
	}
	if(y1 < y2){
		point[1] = y1;
		point[3] = y2;
	}else{
		point[1] = y2;
		point[3] = y1;
	}
	width = point[2] - point[0];
	height = point[3] - point[1];
	area = width * height;
}

Rectangle::~Rectangle(){
	delete point;
	width = 0;
	height = 0;
}

void Rectangle::shift(int _x, int _y){
	point[0] += _x;
	point[1] += _y;
	point[2] += _x;
	point[3] += _y;
}

ostream& Rectangle::print(ostream& os) const{
	os << "Figure: rectangle" << '\n';
	os << "Width: " << width << ", Height: " << height << " -> Area: " << area << '\n';
	os << "The coordinate od diagonal line: ";
	os << '('<< point[0] << ',' << point[1] << ')' << ", ";
	os << '('<< point[2] << ',' << point[3] << ')' << '\n';
	return os;
}

Circle::Circle(){
	radius=0;
	center=NULL;
}

Circle::Circle(int cx, int cy, int r){
	center = new int[2];
	center[0] = cx;
	center[1] = cy;
	radius = r;
	area = 3.14 * r * r;
}

Circle::~Circle(){
	delete center;
	radius = 0;
}

void Circle::shift(int _x, int _y){
	center[0] += _x;
	center[1] += _y;
}

ostream& Circle::print(ostream& os) const{
	os << "Figure: circle" << '\n';
	os << "Radius: " << radius << " -> Area: " << area << '\n';
	os << "The coordinate of center: (" << center[0] << ", " << center[1] <<')' << '\n';
	return os;
}

int main() {
	Figure* r1 = new Rectangle(0, 0, 5, 4);
	Figure* r2 = new Rectangle(-1, -3, 2, 3);
	Figure* c1 = new Circle(0, 0, 3);
	Figure* c2 = new Circle(1, 3, 9);

	cout << *r1 << *r2 << *c1 << *c2 << endl;

	r1->shift(-1, -1);
	r2->shift(1, 3);
	c1->shift(3, 3);
	c2->shift(-1, -3);

	cout << *r1 << *r2 << *c1 << *c2 << endl;

	delete r1;
	delete r2;
	delete c1;
	delete c2;

	return 0;
}