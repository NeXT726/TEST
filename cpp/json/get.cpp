// json.get<map<string, string> 可以将json文件以string - string的map形式保存
// 甚至json.get可以直接保存string_view，并且将file close之后也不会出现错误？

#include<iostream>
#include<nlohmann/json.hpp>
#include<fstream>
#include<string_view>
using json = nlohmann::json;//此处是别名，方便使用

using ContextObject = std::map<std::string_view, std::string_view>;
using ContextObjectList = std::vector<ContextObject>;

int main()
{
    json jTest;
    std::ifstream jfile("test.json");
    jfile >> jTest;
    
    jfile.close();
    for(auto i = 0; i < 3; i++){
        std::cout << jTest[i] << std::endl;
    }
    // jTest[0] = "{\"credits\":\"199999\",\"name\":\"Judd Trump\",\"ranking\":\"1\"}";
    auto ctx = jTest.get<ContextObjectList>();
    for(auto i : {0, 1, 2}) {
        std::cout << ctx[i]["credits"] << std::endl;
    };
}



bool ReadAllFile(const std::string& strFileName, std::string& strFileData)
{
	std::ifstream in(strFileName, std::ios::in | std::ios::binary);
	if (!in.is_open())
	{
		return false;
	}
	std::istreambuf_iterator<char> beg(in), end;
	strFileData = std::string(beg, end);
	in.seekg(0, std::ios::end);//移动的文件尾部
	int strFileSize = in.tellg();//获取文件的整体大小
	in.close();
	return true;
}


int main_zhihu()
{
	/*第一种方式读取文件并解析*/
	json jMessage;
	std::string wifiPassword;
	std::string wifiName;
	std::ifstream jfile("test.json");
	if (!jfile.is_open())
	{
		std::cout << "open test.json failed" << std::endl;
		return -1;
	}
	try
	{
		jfile >> jMessage;//json类支持文件流输入进行解析。
		if (jMessage.is_discarded())
		{
			std::cout << "parse json data failed" << std::endl;
			return -1;
		}

		wifiName = jMessage["wifi_Name"].get<std::string>();//函数模板的显示实例化
		jMessage.at("wifi_Password").get_to(wifiPassword);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;

	}
	std::cout << wifiName << ' ' << wifiPassword << std::endl;
	jMessage.clear();
	wifiName.clear();
	wifiPassword.clear();
	/*第二种方式读取文件并解析*/
	std::string fileData;
	std::string fileName = "test.json";
	if (!ReadAllFile(fileName, fileData))
	{
		std::cout << "open test.json failed" << std::endl;
		return -1;
	}
	try
	{
		jMessage = json::parse(fileData.c_str(), nullptr, false);
		if (jMessage.is_discarded())
		{
			std::cout << "parse json data failed" << std::endl;
			return -1;
		}

		wifiName = jMessage["wifi_Name"].get<std::string>();//函数模板的显示实例化
		jMessage.at("wifi_Password").get_to(wifiPassword);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << wifiName << ' ' << wifiPassword << std::endl;

	return 0;
}