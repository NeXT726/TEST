#include "observer.h"
#pragma once

class Questioner : public Observable {
	std::string question_;

public:
	void set_question(std::string& question) {
		question_ = question;
		notifyObserver(question_);
	}
};