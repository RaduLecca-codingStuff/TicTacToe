#pragma once
#include "AIPlayer.h"
#include <random> 


public ref class EasyAI :public AIPlayer
{
public:
	EasyAI() {
		srand(time(0));
	}
	EasyAI( array<int^, 2>^ ref) {
		Reference = ref;
		srand(time(0));
	}
	void Move()override
	{
		RandomChoice();
	}
	void RandomChoice() {
		//srand((unsigned int)time(NULL));
		
		int nrofFreeSpaces = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				if (Reference[i, j]->Equals(0)) 
				{
					nrofFreeSpaces++;
				}
					
			}
		}

		int X = rand() % 10;
		int Y = rand() % 10;

		X= (X % 2 == 0) ? 0 : (X % 3 == 0) ? 1 : 2;
		Y = (Y % 2 == 0) ? 0 : (Y % 3 == 0) ? 1 : 2;
		
		if ((Reference[X, Y]->Equals(0)))
		{
			SelectedX = X;
			SelectedY = Y;
		}
		else if(nrofFreeSpaces>0){
			RandomChoice();
		}


	
	}
	void SetReference(array<int^, 2>^ ref) {
		Reference = ref;
	}

};

public ref class MediumAI :public EasyAI
{
public:
	MediumAI() {
		srand(time(0));
	}
	MediumAI(array<int^, 2>^ ref) {
		Reference = ref;
		srand(time(0));
	}
	void Move ()override
	{
		if (Reference != nullptr)
		LookAtBoard();
	}
	void LookAtBoard() {
		for (int i = 0; i < 3; i++) {

			//horizontal check
			if (Reference[i, 0]->Equals(Reference[i, 1]) && !Reference[i, 1]->Equals(0) && Reference[i, 2]->Equals(0))
			{
				SelectedX = i;
				SelectedY = 2;
				break;
			}
			else if (Reference[i, 0]->Equals(Reference[i, 2]) && !Reference[i, 0]->Equals(0) && Reference[i, 1]->Equals(0))
			{
				SelectedX = i;
				SelectedY = 1;
				break;
			}
			else if (Reference[i, 1]->Equals(Reference[i, 2]) && !Reference[i, 1]->Equals(0) && Reference[i, 0]->Equals(0))
			{
				SelectedX = i;
				SelectedY = 0;
				break;
			}
			//Vertical check
			else if (Reference[0, i]->Equals(Reference[1, i]) && !Reference[1, i]->Equals(0) && Reference[2,i]->Equals(0))
			{
				SelectedX = 2;
				SelectedY = i;
				break;
			}
			else if (Reference[1, i]->Equals(Reference[2, i]) && !Reference[1, i]->Equals(0) && Reference[0, i]->Equals(0))
			{
				SelectedX = 0;
				SelectedY = i;
				break;
			}
			else if (Reference[0, i]->Equals(Reference[2, i]) && !Reference[0, i]->Equals(0) && Reference[1, i]->Equals(0))
			{
				SelectedX = 1;
				SelectedY = i;
				break;
			}
			else {
				RandomChoice();
				break;
			}

		}
	}
};

public ref class HardAI :public MediumAI
{
private:
	int steps=0;
public:
	HardAI() {
		srand(time(0));
	};
	HardAI(array<int^, 2>^ ref) {
		Reference = ref;
		srand(time(0));
	}
	void Move ()override
	{
		if (Reference != nullptr)
		CornerStrategy();
	}
	void CornerStrategy() {

		if (Reference[0, 0]->Equals(0))
		{
			SelectedX = 0;
			SelectedY = 0;
			steps++;
		}
		else if (Reference[2, 2]->Equals(0))
		{
			SelectedX = 2;
			SelectedY = 2;
			steps++;
		}
		else if (Reference[2, 0]->Equals(0))
		{
			SelectedX = 2;
			SelectedY = 0;
			steps++;
		}
		else if (Reference[0, 2]->Equals(0))
		{
			SelectedX = 0;
			SelectedY = 2;
			steps++;
		}
		if (steps >= 3) {
				LookAtBoard();
		}
		else {
			LookAtBoard();
		}

	}
};

public ref class RealPlayer :public Player
{
public:
	void Move() override
	{

	}
};
