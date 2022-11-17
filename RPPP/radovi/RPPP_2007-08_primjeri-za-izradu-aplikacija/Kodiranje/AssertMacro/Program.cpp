#pragma once

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						
#define ASSERT( condition, message ) {	if ( !condition ) { printf(message); } }
#include <stdio.h>
#include <tchar.h>


//#define ASSERT( condition, message ) {
//   if ( !(condition) ) {
//      LogError( "Assertion failed: ", #condition, message );
//      exit( EXIT_FAILURE );
//   } 
//}


int _tmain(int argc, _TCHAR* argv[])
{
	int x = 0;
	ASSERT( x != 0 , "Neocekivano : x = 0." );
	char c;
	scanf(&c);
	return 0;
}