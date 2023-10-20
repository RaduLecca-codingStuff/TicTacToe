#pragma once
#include "Player.H"
#include <vcclr.h>
using namespace System;

public ref class AIPlayer : public Player {
protected:
	array<int^, 2>^ Reference;

public:
	int SelectedX=0;
	int SelectedY=0;

	void ResetRef(array<int^, 2>^ ref) {
		Reference = ref;
		SelectedX = 0;
		SelectedY = 0;
	}

};
