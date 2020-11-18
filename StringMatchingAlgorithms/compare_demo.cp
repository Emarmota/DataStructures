// David Touretzky
// Sean Bufano, maintainer


#include <stdlib.h>
#include <string>
#include <iostream.h>
#include <iomanip>


void  search_all(string const& text, string const& pat);




int main(void)  {

	string the_text = "panamanian banana fanatics can manage anacondas";
	string the_pattern = "ana";
	search_all(the_text, the_pattern);

	return  EXIT_SUCCESS;
}




void  search_all(string const& text, string const& pat)  {

	int const  pat_size(pat.size());
	int const  endpos(text.size() - pat_size + 1);
	int num=0;
	int result;
	for (int  pos(0); pos < endpos; ++pos)  {

		result = text.compare(pat, pos, pat_size);
		num++;
		cout << setw(2) << pos << " |" << text[pos] <<
		        text[pos+1] << text[pos+2] << "| " << setw(2) << result;
		if (result == 0)  {
			cout << "  <---- match!";
		}
		cout << "comparaciones "<<num<<endl;
	}
}