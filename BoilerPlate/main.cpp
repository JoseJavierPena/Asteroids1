#if _MSC_VER && _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

// C++ STL
#include <cassert>
#include <iostream>

// 
#include "App.hpp"
#include "utilities.hpp"
#include "ship.h"

const int WIDTH = 1136;
const int HEIGHT = 640;

using namespace std;

int main(int argc, char* argv[])
{
	
#if _MSC_VER && _DEBUG
	// https://msdn.microsoft.com/en-us/library/x98tx3cf.aspx
	// This will help you detect leaks when using Visual C++
	// Uncomment this line to start getting reports!
	assert(_CrtCheckMemory());
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	// Create Game Object
	//
	Engine::App* app = new Engine::App("Boiler Plate!", WIDTH, HEIGHT);

	// Initialize game
	//
	if(!app->Init())
	{
		std::cout << "App Init error!\n";
		return -1;
	}

	// Execute game
	//
	app->Execute();

	// Delete game object
	//
	delete app;

	return 0;
}