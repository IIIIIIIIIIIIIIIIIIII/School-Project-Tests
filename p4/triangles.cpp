
/*
 * CSc103 Project 4: Triangles
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References:
 * Friend Laisa
 * http://images.tutorvista.com/cms/images/67/triangle.png
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: ~3 hours
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

	unsigned long sides[3] = {s1,s2,s3};                                                  //Sorts the triangle sides
	sort(sides,sides+3);
	return (sides[0]*sides[1])/2;                                                         //return the area using formula b*h*1/2
}

void triangle::print() {
	cout << "[" << s1 << "," << s2 << "," << s3 << "]";
}

bool congruent(triangle t1, triangle t2) {                                                     
	// TODO: write this function.

		unsigned long sides1[3] = {t1.s1,t1.s2,t1.s3}, sides2[3] = {t2.s1,t2.s2,t2.s3};       //Sorts the triangles sides
		sort(sides1,sides1+3);
		sort(sides2,sides2+3);
		return (sides1[0] == sides2[0] && sides1[1] == sides2[1] && sides1[2] == sides2[2]);  //Return true if both triangle 1 and 2 have same sides

		}

bool similar(triangle t1, triangle t2) {
	// TODO: write this function.

	unsigned long sides1[3] = {t1.s1,t1.s2,t1.s3}, sides2[3] = {t2.s1,t2.s2,t2.s3};    //sorts the triangles sides
		sort(sides1,sides1+3);
		sort(sides2,sides2+3);
		return ((double)sides1[0]/sides2[0] == (double)sides1[1]/sides2[1] && (double)sides1[0]/sides2[0] ==(double) sides1[2]/sides2[2]); //Return true if the ratio of all sides are the same

}

vector<triangle> findRightTriangles(unsigned long l, unsigned long h) {
	// TODO: find all the right triangles with integer sides,
	// subject to the perimeter bigger than l and less than h
	vector<triangle> retval; // storage for return value.
	triangle temp;                                                           // create a temporary triangle that stores right traingle

	unsigned int c;
	
	 for(unsigned int a = 3; a < h; a++){                                    // loop for the lowest side of the triangle s1
	 	temp.s1 = a;

	 	for(unsigned int b = a+1; b < h; b++){                               // loop for the lowest side of the triangle s2
			temp.s2 = b;
			c = (temp.s1*temp.s1) + (temp.s2*temp.s2);

			for(unsigned int i = 5; i < h; i++){                             // loop for the lowest side of the triangle s3
	 			if((double) c/(i*i) == 1){                                   // tests if the third side is equal to sqrt((a*a)+(b*b)) = c
					temp.s3 = i;		
					if(temp.perimeter() <= h && temp.perimeter() >= l)       // test if the perimeter of is l <= p <= h
						retval.push_back(temp);                              // adds the temporary triangle to retval triangle
				}	
			 }
		}
	 }	 
	return retval;
}



