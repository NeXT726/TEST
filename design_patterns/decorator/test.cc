#include "input.h"

int main() {
	string out;

	FileReader* fr = new FileReader();
	SmallReader* sr = new SmallReader(fr);
	sr->read("djl.txt", out);
}