
#include "pch.h"

using namespace std;
using namespace std::chrono;


string substring(const string &str) {
	auto res = str.substr(4);
	return str;
}

string_view substring_view(string_view str) {
	str.remove_prefix(4);
	return str;
}

string_view substring_view_const(const string_view str) {
	return str;
}

template <typename in, typename out > void functor(in arg, out(*fun)(in)) {
	auto start = high_resolution_clock::now();

	for (auto i = 0; i <= 100000; i++)
		auto res = (out)(*fun)(arg);
	
	auto milli = duration_cast<microseconds>(high_resolution_clock::now() - start).count();
	
	cout << "Time taken by function: " << milli << " microseconds \t " << milli / 1000 << " milli" << endl;
}

int main()
{
	string str = "Hello World!\n";

	functor<const string&,string>(str,substring);

	functor<string_view, string_view>(str, substring_view);

	functor<string_view, string_view>(str, substring_view_const);
}