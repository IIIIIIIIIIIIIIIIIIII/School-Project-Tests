/*
 * CSc103 Project 4: Triangles
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 *
 *
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: 
 */

#include "triangles.h" // import the prototypes for our triangle class.
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

// note the "triangle::" part.  We need to specify the function's
// FULL name to avoid confusion.  Else, the compiler will think we
// are just defining a new function called "perimeter"
unsigned long triangle::perimeter() {
	return s1+s2+s3;
}

unsigned long triangle::area() {
	// TODO: write this function.
	// Note: why is it okay to return an integer here?  Recall that
	// all of our triangles have integer sides, and are right triangles...

	/*if(s1 > s2 && s1 > s3)
		return (s2*s3)/3;
	else if(s2 > s1 && s2 > s3)
		return (s1*s3)/3;
	else if(s3 > s1 && s3 > s2)
		return (s1*s2)/3;
	else 
		return 0;*/

	unsigned long sides[3] = {s1,s2,s3};
	sort(sides,sides+3);
	return (sides[0]*sides[1])/2;
}

void triangle::print() {
	cout << "[" << s1 << "," << s2 << "," << s3 << "]";
}

bool congruent(triangle t1, triangle t2) {
	// TODO: write this function.

	/*	if(t1.perimeter() != t2.perimeter())
		return false;
	else if((t1.s1 == t2.s1 || t1.s1 == t2.s2 || t1.s1 == t2.s1) &&
			(t1.s2 == t2.s1 || t1.s2 == t2.s2 || t1.s2 == t2.s1) &&
			(t1.s3 == t2.s3 || t1.s3 == t2.s2 || t1.s3 == t2.s1))
				return true;
	else
		return false;*/
		unsigned long sides1[3] = {t1.s1,t1.s2,t1.s3}, sides2[3] = {t2.s1,t2.s2,t2.s3};
		sort(sides1,sides1+3);
		sort(sides2,sides2+3);
		return (sides1[0] == sides2[0] && sides1[1] == sides2[1] && sides1[2] == sides2[2]);
		//	return true;
		//else
		//	return false;
		}

bool similar(triangle t1, triangle t2) {
	// TODO: write this function.
	/*if (t1.s1/t2.s1 == t1.s2/t2.s2 && t1.s2/t2.s2 == t1.s3/t2.s3)
		return true;
	else
		return false;*/
	unsigned long sides1[3] = {t1.s1,t1.s2,t1.s3}, sides2[3] = {t2.s1,t2.s2,t2.s3};
		sort(sides1,sides1+3);
		sort(sides2,sides2+3);
		return (sides1[0]/sides2[0] == sides1[1]/sides2[1] && sides1[0]/sides2[0] == sides1[2]/sides2[2]);
			//return true;
		//else
		//	return false;
}

//NOTE: FIX CODE RIGHT TRIANGLES REPEATS FIX THE VECTOR
vector<triangle> findRightTriangles(unsigned long l, unsigned long h) {
	// TODO: find all the right triangles with integer sides,
	// subject to the perimeter bigger than l and less than h
	vector<triangle> retval; // storage for return value.
	triangle temp;

	unsigned int c;
	
	 for(unsigned int i = 3; i < h; i++){
	 	temp.s1 = i;

	 	for(unsigned int i = 4; i < h; i++){
			temp.s2 = i;
			c = (temp.s1*temp.s1) + (temp.s2*temp.s2);

			for(unsigned int i = 5; i < h; i++){
	 			if((double) c/(i*i) == 1){
					temp.s3 = i;		
					if(temp.perimeter() <= h && temp.perimeter() >= l)
						retval.push_back(temp);
				}	
			 }
		}
	 }	 
	return retval;
}


