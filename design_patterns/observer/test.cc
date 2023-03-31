#include "questioner.h"
#include "respondent.h"

int main() {
	Questioner q;
	GoodMan gm(&q);
	BadMan bm(&q);
	std::cout << "what do you want to ask" << std::endl;
	std::string s;
	while (1) {
		getline(std::cin, s);
		if (s != "quit")
			q.set_question(s);
		else {
			break;
		}
	}
}