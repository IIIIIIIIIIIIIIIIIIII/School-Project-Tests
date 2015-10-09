/*
 * CSc103 Project 3: wordcount++
 * See readme.html for details.
 * Please list all references you made use of in order to complete the
 * assignment: your classmates, websites, etc.  Aside from the lecture notes
 * and the book, please list everything.  And remember- citing a source does
 * NOT mean it is okay to COPY THAT SOURCE.  What you submit here **MUST BE
 * YOUR OWN WORK**.
 * References: 
 * http://stackoverflow.com/questions/1954718/how-to-get-the-elements-in-a-set-in-c
 * http://web.stanford.edu/class/cs106l/course-reader/full_course_reader.pdf
 * https://web.stanford.edu/class/cs106x/handouts/05-C++-Strings.pdf -- TA gave, link dosen't work anymore but I was able to download the pdf before it was down
 * cplusplus.com -- references on set insert function
 * http://stackoverflow.com/questions/9235296/how-to-detect-empty-lines-while-reading-from-istream-object-in-c -- to read blank lines
 * Finally, please indicate approximately how many hours you spent on this:
 * #hours: ~8-9 hrs --(O.O)/
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <set>
using std::set;
#include <cstdio>

// write this function to help you out with the computation.

unsigned long countWords(const string& s, set<string>& unqw){ //count # of words and create a set of unique words
	string word, scopy = s, str;
	
	unsigned long pos = 0, spacepos, wrds = 0, pos2 = 0, tpos; //pos = position
	long length = 0;
	tpos = scopy.find('\t'); // Finds if the code have any tabs and return either a long or string::npos
		if( tpos != string::npos){
				while(tpos < scopy.length()){
					scopy[tpos] = ' ';
					pos2 = scopy.find('\t', tpos+1);
					tpos = pos2;
				}
			}
				
	//	cout << scopy << endl;
		while(pos < scopy.length()){
		if(pos == 0)
			spacepos = scopy.find(' ',pos);
		else{
			spacepos = scopy.find(' ',pos+1);
			pos++;}
		
			length = spacepos - pos;
		if(length == 0) //prevent an infinite loop if there are spaces in the beginning of a line
			pos++;
		else{
			word = scopy.substr(pos,length);
			if(word != ""){ //make sures that an empty word will not add to the set and word counter
			unqw.insert(word);
			wrds++;
			pos = spacepos;	}}
		}
			return wrds; 
}

unsigned long countlines(const string& s, set<string>& unql){ //count # of lines and create a set of unique lines
	string sentence;
	unsigned long pos = 0, nlpos, nlength = 0, newlines = 0 ;
	
		if(s.empty()){ // check if a line is empty
			newlines++;
			unql.insert("");}

		while(pos < s.length()){
			if(pos == 0)
			nlpos = s.find('\n',pos);
		else{
			nlpos = s.find('\n',pos+1);
			pos++;}
			
			nlength = nlpos - pos;
			sentence = s.substr(pos,nlength);
			unql.insert(sentence);
			newlines++;
			pos = nlpos;}
	
		return newlines;
}

unsigned long countchar(const string& s){ //counts characters in a string
	long count = s.length();
	return count;
}

int main(){

	string line;
	set<string> unqw;
	set<string> unql;

	unsigned long chars = 0, newlines = 0, wrds = 0, unqwrds = 0, unqlines = 0;

	 while( getline(cin, line)){

		wrds += countWords(line, unqw);
		newlines += countlines(line, unql);
		chars += countchar(line);
		unqwrds = unqw.size();
		unqlines = unql.size();
	}
	 chars += newlines;
	
	printf("%li\t%li\t%li\t%li\t%li\t\n", newlines, wrds, chars, unqlines, unqwrds); // trying out printf
//	cout << newlines << "\t" << wrds << "\t" << chars << "\t" << unqlines << "\t" << unqwrds << endl;

	//Test if set is working correctly
//	int counter = 0;
//	set<string>::iterator it; 
//	for(it = unqw.begin(); it != unqw.end();it++){
//		cout << *it << ++counter << endl;}
	
	return 0;
}

//First draft of code
#if 0 
	string s;
	set<string> unqw;
	set<string> unql;

	string newstr, word, sentence; //newstr2;
	unsigned int pos = 0, spacepos, length = 0, pos2 = 0, nlpos, nlength = 0; // variable use to get seperate the strings
	unsigned int chars = 0, newlines = 0, wrds = 0, unqwrds = 0, unqlines = 0; // counters

	string s = "Hello I don't like oranges \nI also don't like apricot";
	//string s = "this is a test";

	while(pos < s.length()){
		if(pos == 0)
			spacepos = s.find(' ',pos);
		else{
			spacepos = s.find(' ',pos+1);
			pos++;}
			
		//	cout << pos << " " << spacepos << endl;
			length = spacepos - pos;
			word = s.substr(pos,length);
		//	newstr += word;
		//	cout << newstr << endl;
			unqw.insert(word);
			wrds += 1;
			pos += length;	

			}	

	while(pos2 < s.length()){
			if(pos2 == 0)
			nlpos = s.find("\n",pos2);
		else{
			nlpos = s.find("\n",pos2+1);
			pos2++;}
			
		//	cout << pos2 << " " << nlpos << endl;
			nlength = nlpos - pos2;
			sentence = s.substr(pos2,nlength);
		//	newstr2 += sentence;
		//	cout << newstr2 << endl;
			unql.insert(sentence);
			newlines++;
			pos2 += nlength;
	}

		
		chars = s.length()+ newlines;
		unqwrds = unqw.size();
		unqlines = unql.size();
		
		
		cout << newlines << "\t" << wrds << "\t" << chars << "\t" << unqlines << "\t" << unqwrds << endl;

	//	set<string>::iterator it; 
	//for(it = unqw.begin(); it != unqw.end();it++){
	//	cout << *it << endl;}
 
	//for(it = unql.begin(); it != unql.end();it++){
	//	cout << *it << endl;}

   }
  // cout << newlines << "\t" << wrds << "\t" << chars << "\t" << unqlines << "\t" << unqwrds << endl;

# endif
