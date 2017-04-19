#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Point {
	float x;
	float y;

	Point(float xIn, float yIn) : x(xIn), y(yIn) { } 
};

Point p0 = Point(0,0);

int orient(Point a, Point b, Point c){
	int d = (c.x - a.x)*(b.y -a.y) - (b.x - a.x)*(c.y - a.y);
	if(d==0)return 0;
	if(d>0)return 2;
	else return 1;
}


int distSq(Point a, Point b)
{
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

int compare(Point a, Point b)
{
 
   // Find orientation
   int d = orient(p0, a ,b);
   if (d == 0)
     return (distSq(p0, b) >= distSq(p0, a))? -1 : 1;
 
   return (d == 2)? -1: 1;
}

//This function is copied from internet to generate random points
vector<Point> randomPoints() {
	vector<Point> v;
	
	const float lo = -100.0;
	const float hi = 100.0;

	for (int i = 0; i < 100; ++i) {
		float x = lo + 
			static_cast<float>(
				rand()) / static_cast<float>(RAND_MAX / (hi - lo));

		float y = lo + 
			static_cast<float>(
				rand()) / static_cast<float>(RAND_MAX / (hi - lo));

		v.push_back(Point(x, y));
	}

	return v;
}

Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}

void GrahamScan(vector<Point> points) {
	int n = points.size();
	//find bottom most point and put in front of the list
	int min = 0;
	for(int i=1;i<n;i++){
		if(points[i].y < points[min].y || (points[i].y == points[min].y && points[i].x < points[min].x)){
			min = i;
		}
	}
	p0 = points[min];
	swap(points[min], points[0]);
	
	//sort the program based on the orientation or polar angle w.r.t the min point
	//sort(points.begin(), points.end(), compare);\
		
	int t = 1;
	for(int i=1;i<n;i++){
		while(i<n-1 && orient(p0, points[i], points[i+1])==0) i++;
		points[t] = points[i];
		t++;
	}
	
	if(t<3){
		cout<<"hull does not exist because of too many points lie on straight line and no hull fomation"<<endl;
		return;
	}
	stack<Point> S;
	S.push(points[0]);
	S.push(points[1]);
	S.push(points[2]);
	
	cout<<"i pass .5"<<endl;
	
	for (int i = 3; i < t; i++)
   {
      while (orient(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
	cout<<"The convex hull contains "<<S.size()<<" points on it"<<endl;
	while(!S.empty()){
		cout<<"( "<<S.top().x<<", "<<S.top().y<<")"<<endl;
		S.pop();
	}
	return;
}

int main(){
	// generating random points
	vector<Point> myvec = randomPoints();
	cout<<"Total number of points = "<<myvec.size()<<endl;
	GrahamScan(myvec);
	cout<<"End of program"<<endl;
	return 0;
}
