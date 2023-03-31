#include <iostream>
#include <unordered_set>
#pragma once

class Observer {
public:
	virtual void update(const std::string question) = 0;
};

class Observable {
private:
	std::unordered_set<Observer*> observers;

public:
	void addObserver(Observer* obj) {
		if (observers.find(obj) == observers.end()) {
			observers.insert(obj);
		}
	}
	void delObserver(Observer* obj) {
		auto pos = observers.find(obj);
		if (pos != observers.end()) {
			observers.erase(pos);
		}
	}
	void notifyObserver(const std::string& question) {
		for (auto obs : observers) {
			obs->update(question);
		}
	}
};
