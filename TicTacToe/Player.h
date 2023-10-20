#pragma once
#include <vcclr.h>
using namespace System;

public ref class Player {

public:
	bool isX;
	virtual void Move() {};
	bool Turn;

};
