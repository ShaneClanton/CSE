#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string s = "";
	vector<string> v;
	ifstream in( "code.cpp" );
	string line;
	
	while( getline( in, line ) ) {// getline returns true if read successfully
		v.push_back( line ); // add the line to the end of v
		s+= line;
		//cout << s;
	}
	// add line numbers:
	for( int i = 0; i < v.size(); i++ )
		cout << i << ": " << v[i] << endl;
	cout << endl;
	
	// Problem 5:
	for( int i = 0; i < v.size(); i++ )
		cout << 15-i << ": " << v[i] << endl;
	cout << endl;

	// Problem 6:
	cout << "\nProblem 6:\n\n" << "da order:\n\n " << s << endl;
	cout << endl;
}