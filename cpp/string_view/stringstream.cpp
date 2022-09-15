// 如何使用 stringstream 
// 对象生成格式化的 string
 
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
 
int main()
{
	cout << "\n Welcome to the StringStream Demo program.\n";
 
	// 构建一些将在string中出现的数据变量
	// PI 精确到小数点后15位
	double pi = 3.141592653589793;
	float dollar = 1.00;
	int dozen = 12;
 
	string text;
 
	// 我们希望tring 的格式如下:
	// dozen适12,dollar是$1.00
	// 精确到小数点后10为pi是3.141592653589793
 
	// 生成stringstream 对象
	stringstream ss;
	
	// 现在像使用cout一样使用ss
 
	ss << " A dozen is "<< dozen << ", a dollar is $ ";
	ss.setf(ios::fixed);
	ss.precision(2);
	ss << dollar << " and \n the value of pi to 10 places is ";
	ss.precision(10);
	ss << pi << ".";
 
	// 现在将ss中的内容赋给一个string对象
	// 使用str()函数
 
	text = ss.str();
	cout << "\nHere is our formatted text string:\n" << text << endl;
	// 再加入一些信息
	ss << "\ There are 2 \"+\" in C++.";
	text = ss.str();
	cout<< "\nHere is the final string:\n" << text << endl;
	return 0;
}