/*
 * CSc103 Project 2: prime numbers.
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: Used wikihow: http://www.wikihow.com/Check-if-a-Number-Is-Prime
 *
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <cmath>

int main()

{
	unsigned long n;

	while(cin >> n) {

		int z = sqrt(n), y = 3;
		
		if (n == 1)
			cout <<"0" << endl;

		else if (n%2 == 0 && n != 2)
				cout << "0" << endl;
		
		else if (n == 2 || n == 3) // Makes sure that 2 and 3 does not print out 0
				cout << "1" << endl;	
		else{
			while(y <= z){

				if (n%y == 0){
					cout <<"0"<< endl;
					break;
				}
				else
					y += 2;
		}
			if (n%y == 0);

			else 
				cout << "1" << endl;
		}

    }
	
	return 0;
}
