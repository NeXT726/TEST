#include "factory.h"

int main() {
	HatPikachu pika;
	pika.create_clothing("t-shirt");
	pika.self_introduction();
	pika.create_clothing("sweater");
	pika.self_introduction();
	pika.create_clothing("long-sleeved shirt");
	pika.self_introduction();
}