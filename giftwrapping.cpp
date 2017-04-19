#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
struct Point {
	float x;
	float y;

	Point(float xIn, float yIn) : x(xIn), y(yIn) { } 
};

int orient(Point a, Point b, Point c){
	int d = (c.x - a.x)*(b.y -a.y) - (b.x - a.x)*(c.y - a.y);
	if(d==0)return 0;
	if(d>0)return 2;
	else return 1;
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

void convexhull(vector<Point> points){
	int n = points.size();
	vector<Point> hull;
	if(n<3){
		cout<<"every point is on the hull as less than 3 points"<<endl;
		return;
	}
	
	int  p,q,leftmost=0;
	for(int i=0;i<n;i++){
		if(points[i].x < points[p].x) p = i;
	}
	p = leftmost;
	do{
		//cout<<"in the while loop"<<endl;
		hull.pb(points[p]);
		//find q
		q = (p+1)%n;
		for(int r=0;r<n;r++){
			if(orient(points[p],points[q],points[r]) == 2) q = r;
		}
		p = q;
	} while( p!= leftmost);
	
	//printing hull
	cout<<"The convex hull contains "<<hull.size()<<" points on it"<<endl;
	for(int i=0;i<hull.size();i++){
		cout<<"( "<<hull[i].x<<", "<<hull[i].y<<")"<<endl;
	}
	return;
	
}

int main(){
	// generating random points
	vector<Point> myvec = randomPoints();
	cout<<"Total number of points = "<<myvec.size()<<endl;
	convexhull(myvec);
	cout<<"End of program"<<endl;
	return 0;
}
