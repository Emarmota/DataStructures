// David Touretzky
// Sean Bufano, maintainer


#include <stdlib.h>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


void  search_all(string const& text, string const& pat, int &cont); //Brute Force String Matching Algorithm




int main(void) {
	int* cont = new int(0);
	string the_text = "qwertyuiopasdfghjklzqwertyuiopasdfghjklzqwertyu";
	string the_pattern = "qwe";
	search_all2(the_text, the_pattern, *cont);

	cout << "cont " << *cont;

	return  EXIT_SUCCESS;
}



void  search_all(string const& text, string const& pat, int& cont) {
	//Description: This method find all occurrences of string pattern whitin string text
	//Input:
	//Output:
	int const  pat_size(pat.size());
	int const  endpos(text.size() - pat_size + 1);
	int num = 0;
	int result;
	for (int pos(0); pos < endpos; ++pos) {
		result = text.compare( pos, pat_size, pat);
		cont++;
		num++;
		cout << setw(2) << pos << " |" << text[pos] <<
			text[pos + 1] << text[pos + 2] << text[pos + 3] << "| " << setw(2) << result;
		if (result == 0) {
			cout << "  <---- match!";
		}
		cout << "comparaciones " << num << endl<<endl;
	}
	cout << "text is of lenght : " << text.size() << endl;
	cout << "pat is of lenght: " << pat_size<< endl;
	cout << "compare() was called " << cont << " times" << endl;

}


void  search_all2(string const& text, string const& pat, int& cont) {
	//Description: This method find all occurrences of string pattern whitin string text
	//Input:
	//Output:
	int const  pat_size(pat.size());
	int const  endpos(text.size() - pat_size + 1);
	int num = 0;
	int result;
	for (auto it = text.cbegin(); it!= text.cend; ++it) {
		result = text.compare(*it, pat_size, pat);
		cont++;
		num++;
		cout << setw(2) << 0 << " |" << *it <<
			*it  << *it << *it << "| " << setw(2) << result;
		if (result == 0) {
			cout << "  <---- match!";
		}
		cout << "comparaciones " << num << endl << endl;
	}
	cout << "text is of lenght : " << text.size() << endl;
	cout << "pat is of lenght: " << pat_size << endl;
	cout << "compare() was called " << cont << " times" << endl;
	
}