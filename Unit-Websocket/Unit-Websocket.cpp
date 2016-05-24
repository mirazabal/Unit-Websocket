// Unit-Websocket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "..\include\gtest\gtest.h"
#include "..\websocket_endpoint\websocket_endpoint.h"

#include <future>


TEST(Test_Websocket, Connect_Websocket)
{
	mirazabal::sio::websocket_endpoint endpoint;
	endpoint.connect("http://localhost:3000") ;

}

TEST(Test_Websocket, Emit_Websocket)
{
	mirazabal::sio::websocket_endpoint endpoint;
	auto conn_val = endpoint.connect("http://localhost:3000");

	for (int i = 0; i < 10; i++)
	{
		endpoint.emit("new message", "Unit Websocket Writting " + std::to_string(i));
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}


}

int _tmain(int argc, _TCHAR* argv[])
{
	testing::InitGoogleTest(&argc, argv);

	RUN_ALL_TESTS();

    return 0;
}

