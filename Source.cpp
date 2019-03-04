#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
operations of the following  types:
1. append - Append string W to the end of S.
2. delete - Delete the last k characters of S.
3. print - Print the kth character of S.
4. undo - Undo the last (not previously undone) operation of type 1 or 2 ,
reverting S to the state it was in prior to that operation.
First column is action second column is string
*/

/*
	sample input:			Sample Output:
					8						c
					1 abc					y
					3 3						a
					2 3
					1 xy
					3 2
					4
					4
					3 1
*/

void append(string w);
void deletek(string k);
void print(string k);
void undo();

string mainstring = "";
string previousstring = "";
vector <string> previousstate;
int main() {
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	int numberofinputs;
	cin >> numberofinputs;
	vector<int> inputtype(numberofinputs);
	vector<string> inputstring(numberofinputs);
	int in;
	string str;
	for (int i = 0; i < numberofinputs; i++) {
		// grab the inputs;
		cin >> inputtype[i];
		if (inputtype[i] == 4) {
			inputstring[i] = "0";
			continue;
		}
		cin >> inputstring[i];
	}
	for (int i = 0; i < numberofinputs; i++) {
		if (inputtype[i] == 1) {
			append(inputstring[i]);
		}
		else if (inputtype[i] == 2) {
			deletek(inputstring[i]);
		}
		else if (inputtype[i] == 3) {
			print(inputstring[i]);
		}
		else {
			undo();
		}
	}
	return 0;
}

void append(string w) {
	previousstate.push_back(mainstring);
	mainstring.append(w);

}
void deletek(string k) {
	previousstate.push_back(mainstring);
	mainstring.resize(mainstring.length() - stoi(k));
}
void print(string k) {
	int i = stoi(k);
	cout << mainstring[i - 1] << endl;
}
void undo() {
	mainstring = previousstate.back();
	previousstate.pop_back();
}
