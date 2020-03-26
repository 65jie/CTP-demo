#include "ThostFtdcMdApi.h"
#include "ThostFtdcTraderApi.h"
#include "MdSpi.h"
#include "TdSpi.h"
#include <iostream>

#pragma comment(lib,"thostmduserapi_se.lib")
#pragma comment(lib,"thosttraderapi_se.lib")

FILE *logfile;

int main(int argc, char *argv[]){

	//CThostFtdcMdApi *mdapi = CThostFtdcMdApi::CreateFtdcMdApi("./md_file/");
	//MdSpi *mdspi = new MdSpi(mdapi);
	////注册事件处理对象
	//mdapi->RegisterSpi(mdspi);
	////和前置机连接
	//mdapi->RegisterFront("tcp://180.168.146.187:10131");	//模拟 行情
	//std::cout << "1\n";
	//mdapi->Init();
	//std::cout << "2\n";
	//mdapi->Join();
	//std::cout << "3\n";
	//mdapi->Release();
	//std::cout << "4\n";
	//system("pause");

	auto tdapi = CThostFtdcTraderApi::CreateFtdcTraderApi("./trader_file/");
	TdSpi *tdspi = new TdSpi(tdapi);
	//注册事件处理对象
	tdapi->RegisterSpi(tdspi);
	//订阅共有流和私有流
	tdapi->SubscribePublicTopic(THOST_TERT_RESTART);
	tdapi->SubscribePrivateTopic(THOST_TERT_RESTART);
	//注册前置机
	//tdapi->RegisterFront("tcp://180.169.75.19:41205");	//实盘270338
	tdapi->RegisterFront("tcp://180.168.146.187:10130");	//模拟 交易
	std::cout << "1\n";
	//和前置机连接
	tdapi->Init();
	std::cout << "2\n";
	tdapi->Join();
	std::cout << "3\n";
	tdapi->Release();
	std::cout << "4\n";
	system("pause");

	return 0;
}
