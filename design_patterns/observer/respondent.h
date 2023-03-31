#include "observer.h"
#pragma once

class GoodMan : public Observer {
	Observable* ob_;

public:
	GoodMan(Observable* ob) {
		ob_ = ob;
		ob_->addObserver(this);
	}

	void update(const std::string question) {
		std::cout << question << ": my answer is yes" << std::endl;
	}
};

class BadMan : public Observer {
	Observable* ob_;

public:
	BadMan(Observable* ob) {
		ob_ = ob;
		ob_->addObserver(this);
	}

	void update(const std::string question) {
		std::cout << question << ": my answer is no" << std::endl;
	}
};