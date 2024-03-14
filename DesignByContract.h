//============================================================================
// Name        : DesignByContract.h
// Author      : Serge Demeyer
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Serge Demeyer - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================

#include <assert.h>

#define REQUIRE(assertion, what) if (!(assertion)) assert (!what)

#define ENSURE(assertion, what) if (!(assertion)) assert (!what)