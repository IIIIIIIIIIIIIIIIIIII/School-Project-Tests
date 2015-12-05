#include "triangles.h"
#include <iostream>
using std::cout;

int main(void) {
	// TODO: write some code to test out your program.
	// This won't be graded- it is just for your benefit
	// and to aid your testing / debugging.
	
	vector<triangle> test;
	unsigned long l = 1, h = 25;
	test = findRightTriangles(l, h);
	for( unsigned int i = 0; i < test.size(); i++){
		cout << "[" << test[i].s1 << "," << test[i].s2 << "," << test[i].s3 << "]" << std::endl; 
	}
	return 0;
}
