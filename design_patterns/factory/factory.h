#include <iostream>
#pragma once

using namespace std;

class Pikachu {
public:
	string clothing_;

	void self_introduction() {
		cout << "i'm a pikachu with " << clothing_ << endl;
	}

	virtual void create_clothing(string clothing) = 0;
	// virtual void call_create_clothing(string clothing) {
	// 	create_clothing(clothing);
	// }

	// Pikachu(string clothing) { call_create_clothing(clothing); }
};

class HatPikachu : public Pikachu {
public:
	// using Pikachu::Pikachu;
	void create_clothing(string clothing) {
		if (clothing == "t-shirt") {
			clothing_ = "red " + clothing;
		} else if (clothing == "sweater") {
			clothing_ = "yellow " + clothing + " with hat";
		} else {
			clothing_ = "blue " + clothing;
		}
	}
};