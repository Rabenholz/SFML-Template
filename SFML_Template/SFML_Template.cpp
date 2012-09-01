// SFML_Template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SFMLApp.h"

/*
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
   #ifndef DBG_NEW
      #define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
      #define new DBG_NEW
   #endif
#endif  // _DEBUG
   */
#ifdef _WIN32
#ifdef _DEBUG
#include <Windows.h>
#endif
#endif
int main(int argc, _TCHAR* argv[])
{ 
	//_CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
	//_CrtMemState s1, s2, s3;
	//_CrtMemCheckpoint( &s1 );
	//_CrtSetBreakAlloc(164);
	//_CrtSetBreakAlloc(150);
	{
	SFMLApp app;
	app.OnExecute();
	}

	//_CrtMemCheckpoint( &s2 );
//if ( _CrtMemDifference( &s3, &s1, &s2) )
   //_CrtMemDumpStatistics( &s3 );
	//_CrtDumpMemoryLeaks();

	#ifdef _WIN32
#ifdef _DEBUG
	TerminateProcess(GetCurrentProcess(), EXIT_SUCCESS);
#endif
#endif
	return 0;
}

