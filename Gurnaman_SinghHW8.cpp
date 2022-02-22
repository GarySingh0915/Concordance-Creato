//Gurnaman Singh
// HW8
//New update
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <cctype>
#include <thread>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <array>
#include <iterator>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <Windows.h>
#include <functional>
#include <set>
#include <stdio.h>

using namespace std;

int linecount = 0;
vector<string> load_words(string filename);
map<string, int> get_word_count(const vector<string>& words);


vector<int> get_line_number(string filename, string word);
ofstream output_file;
ofstream pop_file;
string filename;

int main() {
	
	cout << "The Word Counter program\n\n";

	cout << "1	-	TheRaven.txt"							//File options for concordance.
		<< "\n2	-	ModestProposal.txt"
		<< "\n3	-	OccurrenceAtOwlCreekBridge.txt"
		<< "\n4	-	Apology_W.txt";

	string fileNum;
	
	cout << "\n\nPLEASE ENTER THE INDEX FROM ABOVE FOR THE FILE FOR CONCORDANCE: ";
	cin >> fileNum;
	
	if (fileNum == "1") {
		filename = "TheRaven.txt";
		output_file.open("TheRaven_concordance.txt", ios::out | ios::trunc);			//creates a file named TheRaven_concordance.txt
		pop_file.open("TheRaven_popular.txt", ios::out | ios::trunc);			//creates a file named TheRaven_popular.txt
	}
	else if (fileNum == "2") {
		filename = "ModestProposal.txt";
		output_file.open("ModestProposal_concordance.txt", ios::out | ios::trunc);			//creates a file named ModestProposal_concordance.txt
		pop_file.open("ModestProposal_popular.txt", ios::out | ios::trunc);			//creates a file named ModestProposal_popular.txt
	}
	else if (fileNum == "3") {
		filename = "OccurrenceAtOwlCreekBridge.txt";
		output_file.open("OccurrenceAtOwlCreekBridge_concordance.txt", ios::out | ios::trunc);			//creates a file named OccurrenceAtOwlCreekBridge_concordance.txt
		pop_file.open("OccurrenceAtOwlCreekBridge_popular.txt", ios::out | ios::trunc);			//creates a file named OccurrenceAtOwlCreekBridge_popular.txt
	}
	else if (fileNum == "4") {
		filename = "Apology_W.txt";
		output_file.open("Apology_W_concordance.txt", ios::out | ios::trunc);			//creates a file named resultsApology_W_concordancetxt
		pop_file.open("Apology_W_popular.txt", ios::out | ios::trunc);			//creates a file named Apology_W_popular.txt
	}
	cout << "\nPLEASE WAIT 30 SECONDS WHILE CONTENT IS WRITTEN ON THE FILES OR THERE WILL BE MISSING DATA. REOPEN FILE IF DATA IS MISSING.";
	auto words = load_words(filename);

	output_file << "\nTHERE ARE A TOTAL OF " << words.size() << " WORDS.";
	
	output_file << endl << endl;

	auto word_count = get_word_count(words);

	output_file << "\nTHERE ARE " << word_count.size() << " UNIQUE WORDS.";
	
	output_file << endl << endl;

	output_file << "COUNT PER WORD: ";
	for (auto pair : word_count) {
		output_file << left << setw(15) << pair.first << "==>     " << left << pair.second << setw(10) << " Number of Times ";
		output_file << "(Line Number: ";

		auto number = get_line_number(filename, pair.first);
		for (int i = 0; i < number.size(); i++) {
			output_file << number.at(i) << ", ";
		}
		output_file << ") \n";
	
	}
	cout << "\n\nCOMPLETED. THANKS FOR YOUR PATIENCE...\n\n\n";
}

map<string, int> get_word_count(const vector<string>& words) {
	map<string, int> word_count{};

	for (string word : words) {
		auto search = word_count.find(word);
		if (search == word_count.end()) {
			word_count[word] = 1;					// not found - add word with count of 1
		}
		else {
			word_count[word] += 1;					// found - increment count for word
		}
	}
	typedef std::pair<std::string, int> pair;
	// create an empty vector of pairs
	std::vector<pair> vec;

	// copy key-value pairs from the map to the vector
	std::copy(word_count.begin(), word_count.end(), std::back_inserter<std::vector<pair>>(vec));

	// sort the vector by increasing order of its pair's second value
	// if second value are equal, order by the pair's first value
	std::sort(vec.begin(), vec.end(),
		[](const pair& l, const pair& r) {
			if (l.second != r.second)
				return l.second > r.second;

			return l.first > r.first;
		});

	// print the vector
	int i = 0;
	for (auto const& pair : vec) {
		pop_file << left << setw(15) << pair.first << "==>     " << left << pair.second << setw(10) << " Number of Times ";
		pop_file << "(Line Number: ";

		auto number = get_line_number(filename, pair.first);
		for (int i = 0; i < number.size(); i++) {
			pop_file << number.at(i) << ", ";
		}
		pop_file << ") \n";
		if (i == 99) {
			break;
		}
		i++;
	}


	return word_count;
}

vector<string> load_words(string filename) {
	vector<string> words;
	ifstream infile(filename);

	if (infile) {
		string word;
		while (infile >> word) {
			string new_word = "";

			//for (char c : word) {
			//	if (c == '\n') {
			//		linecount++;
			//	}
			//	else if (ispunct(c) || isdigit(c)) {					//remove punctuation
			//		continue;
			//	}
			//	else if (isupper(c)) {				// convert to lowercase
			//		new_word += tolower(c);
			//	}
			//	else {
			//		new_word += c;					// add word
			//	}
			string str = word;


			for (int i = 0, len = str.size(); i < len; i++)
			{
				if (ispunct(str[i]))	// If it contains punctuation.
				{

					if (i != 0 && i != str.size() - 1 && str[i] != '(' && str[i] != ')' && str[i] != ';')
					{
						continue;
					}
					else
					{
						str.erase(i--, 1);
						len = str.size();
					}


				}

			}
			int letters = 0;

			for (int p = 0, len = str.size(); p < len; p++)
			{

				if (letters == len - 1 && str[p] == '.' || str[p] == '\"')
				{
					str.erase(letters--, 1);
					len = str.size();
				}
				letters++;
			}
			new_word = str;

			transform(new_word.begin(), new_word.end(), new_word.begin(), tolower);	// Change string from upper to lower case.
			words.push_back(new_word);
		}
		
	}
	infile.close();
	return words;
	}
	

vector<int> get_line_number(string filename, string word) {
	vector<int> numbers;
	ifstream file(filename);
	int line_counter = 0;
	string line;
	while (getline(file, line)) {
		line_counter++;
		transform(line.begin(), line.end(), line.begin(), tolower);
		if (line.find(word) != string::npos) {
			numbers.push_back(line_counter);
		}
	}
	return numbers;
}
