#include <algorithm>
#include <fstream>
#include <iostream>
#pragma once
using namespace std;

class Input {
public:
	virtual void read(const string& file_name, string& out) = 0;
};

class FileReader : public Input {
public:
	void read(const string& file_name, string& out) {
		ifstream infile;
		infile.open(file_name, ios::in);
		if (!infile.is_open()) {
			cout << "fail read file: " << file_name << endl;
			return;
		}

		string temp;
		while (getline(infile, temp)) {
			out += temp;
			temp.clear();
		}
		cout << "FileReader Result: " << out << endl;
		infile.close();
	}
};

class Decorator : public Input {
public:
	Input* obj;
	Decorator(Input* filereader) { obj = filereader; }

	void read(const string& file_name, string& out) {
		cout << "Base Decorator use read, wrong!" << endl;
	}
};

class SmallReader : public Decorator {
public:
	using Decorator::Decorator;
	void read(const string& file_name, string& out) {
		obj->read(file_name, out);
		transform(out.begin(), out.end(), out.begin(), ::tolower);
		cout << "SmallReader Result: " << out << endl;
	}
};
