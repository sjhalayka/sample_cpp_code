// Q: How do I use the regular expressions
//    capabilities of C++ to parse strings?

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;
using std::getline;

#include <vector>
using std::vector;

// Regular expressions
// We use this to tokenize a string
#include <regex>
using std::regex;
using std::sregex_token_iterator;



// Chop the string up into tokens
void std_strtok(const string& s, const string& regex_s, vector<string>& tokens)
{
	tokens.clear();

	regex r(regex_s);
	sregex_token_iterator iter(s.begin(), s.end(), r, -1);
	sregex_token_iterator end;

	while (iter != end)
	{
		tokens.push_back(*iter);
		iter++;
	}
}



int main(void)
{
	string line = "first_cell,second_cell,third_cell";
	vector<string> output_tokens;

	// For example, when using comma-separated values
	std_strtok(line, "[,]", output_tokens);

	cout << "Generated " << output_tokens.size() << " tokens" << endl;

	for (size_t i = 0; i < output_tokens.size(); i++)
		cout << output_tokens[i] << ' ' << endl;

	return 0;
}