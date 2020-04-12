#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

#define INF 1e12
#define EPS 1e-6

using namespace std;

enum
{
	NOT_SOLVED = (size_t)(-1),
	NOBODY = -1
};

map <string, string> get_distribution(const map <string, int>&, const map <string, vector <string>>&, unsigned);

template <class first_T>
vector <int> map_to_vector(const map <first_T, int>&);

template <class sec_T>
map <string, int> get_id(const map <string, sec_T>&);

vector <string> invert_map(const map <string, int>&);
vector <int> apply_mask(const vector <vector <int>>&, const vector <size_t>&);
vector <vector <int>> get_options(const map <string, vector <string> >&, map <string, int>&);
vector <int> count_score(const vector <int>&, unsigned);
map <string, string> translate_result(const vector <int>&, vector <string>&, vector <string>&);
bool limit_exceeded(const vector <int>&, unsigned);
int tot_solved(const vector <int>&);

bool advance_mask(vector <size_t>&, const vector <vector <int> >&);
vector <int> operator + (const vector <int>&, const vector <int>& b);
double count_disp(const vector <int>&);

template <class T>
ostream& operator << (ostream& os, const vector <T>& vec)
{
	for (unsigned pos = 0; pos < vec.size(); pos++)
	{
		os << vec[pos] << " ";
	}
	return os;
}

template <class T>
void print_vector(const vector <T>& row)
{
	for (unsigned pos = 0; pos < row.size(); pos++)
	{
		cout << pos << ": " << row[pos] << "\n";
	}
	cout << "\n";
}

template <class T1, class T2>
void print_map(const map <T1, T2>& table)
{
	for (auto it = table.begin(); it != table.end(); it++)
	{
		cout << it->first << " " << it->second << "\n";
	}
	cout << "\n";
}

template <class T>
istream& operator >> (istream& is, vector <T>& vec)
{
	unsigned size;
	is >> size;
	vec.clear();
	vec.resize(size);
	for (unsigned i = 0; i < size; i++)
	{
		is >> vec[i];
	}
	return is;
}

template <class T1, class T2>
void read_map(map <T1, T2>& table)
{
	unsigned size;
	cin >> size;
	table.clear();
	for (unsigned pos = 0; pos < size; pos++)
	{
		T1 first;
		T2 second;
		cin >> first >> second;
		table.insert(make_pair(first, second));
	}
}