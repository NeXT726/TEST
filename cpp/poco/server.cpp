//https://blog.csdn.net/fengyishang/article/details/45220823?spm=1001.2101.3001.6650.3&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-3.pc_relevant_aa&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7ECTRLIST%7Edefault-3.pc_relevant_aa&utm_relevant_index=6
//MacOS编译Poco代码需要选项-lPocoUtil -lPocoXML -lPocoJSON -lPocoNet -lPocoFoundation

#include <Poco/Net/ServerSocket.h>
#include <Poco/Net/HTTPServer.h>
#include <Poco/Net/HTTPRequestHandler.h>
#include <Poco/Net/HTTPRequestHandlerFactory.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/HTTPServerRequest.h>
#include <Poco/Net/HTTPServerResponse.h>
#include <Poco/Util/ServerApplication.h>
 
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
using namespace Poco::Net;
using namespace Poco::Util;
 
class MyRequestHandler : public HTTPRequestHandler
{
public:
	virtual void handleRequest(HTTPServerRequest &req, HTTPServerResponse &resp)
	{
		resp.setStatus(HTTPResponse::HTTP_OK);
		resp.setContentType("text/html");
 
		ostream & out = resp.send();
 
		out << "<h1>Hello World!</h1>";
	}
};
 
class MyRequestHandlerFactory : public HTTPRequestHandlerFactory
{
public:
	virtual HTTPRequestHandler* createRequestHandler(const HTTPServerRequest &)
	{
		return new MyRequestHandler;
	}
};
 
class MyServerApp :public ServerApplication
{
protected:
	int main(const vector<string> &)
	{
		HTTPServer s(new MyRequestHandlerFactory, ServerSocket(8080), new HTTPServerParams);
 
		s.start();
		cout << endl << "Server started" << endl;
 
		waitForTerminationRequest();  // wait for CTRL-C or kill
 
		cout << endl << "Shutting down..." << endl;
 
		s.stop();
 
		return Application::EXIT_OK;
	}
};
 
int main(int argc, char **argv)
{
	MyServerApp app;
 
	return app.run(argc, argv);
}