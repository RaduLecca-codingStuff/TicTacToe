#pragma once
#include "Player.h"
#include "AIPlayer.h"
#include "Difficulties.h"  
//#include "Settings.h"

namespace TicTacToe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Game
	/// </summary>
	public ref class Game : public System::Windows::Forms::Form
	{
	public:
		Game(int nrpl, int dif)
		{
			InitializeComponent();

			nrOfPlayers = nrpl;
			difficulty = dif;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Game()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ bkg;
	private: System::Windows::Forms::PictureBox^ Slot1;
	private: System::Windows::Forms::PictureBox^ Slot2;
	private: System::Windows::Forms::PictureBox^ Slot3;
	private: System::Windows::Forms::PictureBox^ Slot4;
	private: System::Windows::Forms::PictureBox^ Slot5;
	private: System::Windows::Forms::PictureBox^ Slot6;
	private: System::Windows::Forms::PictureBox^ Slot7;
	private: System::Windows::Forms::PictureBox^ Slot8;
	private: System::Windows::Forms::PictureBox^ Slot9;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ pLabel1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ mLabel1;
	private: System::Windows::Forms::Label^ mLabel2;
	private: System::Windows::Forms::Label^ score1;
	private: System::Windows::Forms::Label^ score2;
	private: System::Windows::Forms::Label^ WinMessage;
	private: System::Windows::Forms::Button^ NextMatch;
	public: array<Int32^, 2>^ BoxValues;
	public: array<PictureBox^, 2>^ BoxVisuals;
	private: bool IsGameOVer;
	private:int nrOfPlayers;
	private:int difficulty;
	private:Player^ p1;
	private:AIPlayer^ p2;
	private: int p1score;
	private:int p2score;
	private:int nrOfMatches;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->bkg = (gcnew System::Windows::Forms::PictureBox());
			this->Slot1 = (gcnew System::Windows::Forms::PictureBox());
			this->Slot2 = (gcnew System::Windows::Forms::PictureBox());
			this->Slot3 = (gcnew System::Windows::Forms::PictureBox());
			this->Slot4 = (gcnew System::Windows::Forms::PictureBox());
			this->Slot5 = (gcnew System::Windows::Forms::PictureBox());
			this->Slot6 = (gcnew System::Windows::Forms::PictureBox());
			this->Slot7 = (gcnew System::Windows::Forms::PictureBox());
			this->Slot8 = (gcnew System::Windows::Forms::PictureBox());
			this->Slot9 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pLabel1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->mLabel1 = (gcnew System::Windows::Forms::Label());
			this->mLabel2 = (gcnew System::Windows::Forms::Label());
			this->score1 = (gcnew System::Windows::Forms::Label());
			this->score2 = (gcnew System::Windows::Forms::Label());
			this->WinMessage = (gcnew System::Windows::Forms::Label());
			this->NextMatch = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bkg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot9))->BeginInit();
			this->SuspendLayout();
			// 
			// bkg
			// 
			this->bkg->BackColor = System::Drawing::Color::Black;
			this->bkg->Location = System::Drawing::Point(62, 91);
			this->bkg->Name = L"bkg";
			this->bkg->Size = System::Drawing::Size(287, 288);
			this->bkg->TabIndex = 0;
			this->bkg->TabStop = false;
			// 
			// Slot1
			// 
			this->Slot1->Location = System::Drawing::Point(48, 79);
			this->Slot1->Name = L"Slot1";
			this->Slot1->Size = System::Drawing::Size(100, 100);
			this->Slot1->TabIndex = 1;
			this->Slot1->TabStop = false;
			this->Slot1->Click += gcnew System::EventHandler(this, &Game::Slot1_Click);
			// 
			// Slot2
			// 
			this->Slot2->Location = System::Drawing::Point(154, 79);
			this->Slot2->Name = L"Slot2";
			this->Slot2->Size = System::Drawing::Size(100, 100);
			this->Slot2->TabIndex = 2;
			this->Slot2->TabStop = false;
			this->Slot2->Click += gcnew System::EventHandler(this, &Game::Slot2_Click);
			// 
			// Slot3
			// 
			this->Slot3->Location = System::Drawing::Point(260, 79);
			this->Slot3->Name = L"Slot3";
			this->Slot3->Size = System::Drawing::Size(100, 100);
			this->Slot3->TabIndex = 3;
			this->Slot3->TabStop = false;
			this->Slot3->Click += gcnew System::EventHandler(this, &Game::Slot3_Click);
			// 
			// Slot4
			// 
			this->Slot4->Location = System::Drawing::Point(48, 185);
			this->Slot4->Name = L"Slot4";
			this->Slot4->Size = System::Drawing::Size(100, 100);
			this->Slot4->TabIndex = 4;
			this->Slot4->TabStop = false;
			this->Slot4->Click += gcnew System::EventHandler(this, &Game::Slot4_Click);
			// 
			// Slot5
			// 
			this->Slot5->Location = System::Drawing::Point(154, 185);
			this->Slot5->Name = L"Slot5";
			this->Slot5->Size = System::Drawing::Size(100, 100);
			this->Slot5->TabIndex = 5;
			this->Slot5->TabStop = false;
			this->Slot5->Click += gcnew System::EventHandler(this, &Game::Slot5_Click);
			// 
			// Slot6
			// 
			this->Slot6->Location = System::Drawing::Point(260, 185);
			this->Slot6->Name = L"Slot6";
			this->Slot6->Size = System::Drawing::Size(100, 100);
			this->Slot6->TabIndex = 6;
			this->Slot6->TabStop = false;
			this->Slot6->Click += gcnew System::EventHandler(this, &Game::Slot6_Click);
			// 
			// Slot7
			// 
			this->Slot7->Location = System::Drawing::Point(48, 291);
			this->Slot7->Name = L"Slot7";
			this->Slot7->Size = System::Drawing::Size(100, 100);
			this->Slot7->TabIndex = 7;
			this->Slot7->TabStop = false;
			this->Slot7->Click += gcnew System::EventHandler(this, &Game::Slot7_Click);
			// 
			// Slot8
			// 
			this->Slot8->Location = System::Drawing::Point(154, 291);
			this->Slot8->Name = L"Slot8";
			this->Slot8->Size = System::Drawing::Size(100, 100);
			this->Slot8->TabIndex = 8;
			this->Slot8->TabStop = false;
			this->Slot8->Click += gcnew System::EventHandler(this, &Game::Slot8_Click);
			// 
			// Slot9
			// 
			this->Slot9->Location = System::Drawing::Point(260, 291);
			this->Slot9->Name = L"Slot9";
			this->Slot9->Size = System::Drawing::Size(100, 100);
			this->Slot9->TabIndex = 9;
			this->Slot9->TabStop = false;
			this->Slot9->Click += gcnew System::EventHandler(this, &Game::Slot9_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(181, 418);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(44, 16);
			this->label1->TabIndex = 10;
			this->label1->Text = L"label1";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pLabel1
			// 
			this->pLabel1->AutoSize = true;
			this->pLabel1->Location = System::Drawing::Point(12, 9);
			this->pLabel1->Name = L"pLabel1";
			this->pLabel1->Size = System::Drawing::Size(65, 16);
			this->pLabel1->TabIndex = 11;
			this->pLabel1->Text = L"Player 1 : ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(336, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(65, 16);
			this->label2->TabIndex = 12;
			this->label2->Text = L"Player 2 : ";
			// 
			// mLabel1
			// 
			this->mLabel1->AutoSize = true;
			this->mLabel1->Location = System::Drawing::Point(74, 9);
			this->mLabel1->Name = L"mLabel1";
			this->mLabel1->Size = System::Drawing::Size(15, 16);
			this->mLabel1->TabIndex = 13;
			this->mLabel1->Text = L"a";
			// 
			// mLabel2
			// 
			this->mLabel2->AutoSize = true;
			this->mLabel2->Location = System::Drawing::Point(397, 9);
			this->mLabel2->Name = L"mLabel2";
			this->mLabel2->Size = System::Drawing::Size(15, 16);
			this->mLabel2->TabIndex = 14;
			this->mLabel2->Text = L"a";
			// 
			// score1
			// 
			this->score1->AutoSize = true;
			this->score1->Location = System::Drawing::Point(45, 41);
			this->score1->Name = L"score1";
			this->score1->Size = System::Drawing::Size(14, 16);
			this->score1->TabIndex = 15;
			this->score1->Text = L"0";
			this->score1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// score2
			// 
			this->score2->AutoSize = true;
			this->score2->Location = System::Drawing::Point(371, 41);
			this->score2->Name = L"score2";
			this->score2->Size = System::Drawing::Size(14, 16);
			this->score2->TabIndex = 16;
			this->score2->Text = L"0";
			this->score2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// WinMessage
			// 
			this->WinMessage->AutoSize = true;
			this->WinMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			this->WinMessage->Location = System::Drawing::Point(117, 26);
			this->WinMessage->Name = L"WinMessage";
			this->WinMessage->Size = System::Drawing::Size(0, 31);
			this->WinMessage->TabIndex = 17;
			this->WinMessage->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// NextMatch
			// 
			this->NextMatch->Location = System::Drawing::Point(154, 456);
			this->NextMatch->Name = L"NextMatch";
			this->NextMatch->Size = System::Drawing::Size(100, 31);
			this->NextMatch->TabIndex = 19;
			this->NextMatch->Text = L"Next Match";
			this->NextMatch->UseVisualStyleBackColor = true;
			this->NextMatch->Click += gcnew System::EventHandler(this, &Game::NextMatch_Click);
			// 
			// Game
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(413, 511);
			this->Controls->Add(this->NextMatch);
			this->Controls->Add(this->WinMessage);
			this->Controls->Add(this->score2);
			this->Controls->Add(this->score1);
			this->Controls->Add(this->mLabel2);
			this->Controls->Add(this->mLabel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pLabel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Slot9);
			this->Controls->Add(this->Slot8);
			this->Controls->Add(this->Slot7);
			this->Controls->Add(this->Slot6);
			this->Controls->Add(this->Slot5);
			this->Controls->Add(this->Slot4);
			this->Controls->Add(this->Slot3);
			this->Controls->Add(this->Slot2);
			this->Controls->Add(this->Slot1);
			this->Controls->Add(this->bkg);
			this->Name = L"Game";
			this->Text = L"Game";
			this->Load += gcnew System::EventHandler(this, &Game::Game_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bkg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Slot9))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:System::Void MarkSpot(Int32 X, Int32 Y, Int32 val) {
		
		if (IsGameOVer==false) {
 
				if (val == 1) {
					BoxVisuals[(X >= 0) ? (X <= 2) ? X : 2 : 0, (Y >= 0) ? (Y <= 2) ? Y : 2 : 0]->Image = Image::FromFile("x.png");
				}
				else if (val >= 2) {
					BoxVisuals[(X >= 0) ? (X <= 2) ? X : 2 : 0, (Y >= 0) ? (Y <= 2) ? Y : 2 : 0]->Image = Image::FromFile("o.png");
				}
				else
					BoxVisuals[(X >= 0) ? (X <= 2) ? X : 2 : 0, (Y >= 0) ? (Y <= 2) ? Y : 2 : 0]->Image = nullptr;
				BoxValues[(X >= 0) ? (X <= 2) ? X : 2 : 0, (Y >= 0) ? (Y <= 2) ? Y : 2 : 0] = (val >= 0) ? (val <= 2) ? val : 2 : 0;
				CheckIfWon();
		}
		
	}
	protected:System::Void CheckIfWon() {
		if ( ( (BoxValues[0, 0]->Equals(BoxValues[1, 1]))&& (BoxValues[1, 1]->Equals(BoxValues[2, 2]) )&& !(BoxValues[1, 1]->Equals(0))||
			((BoxValues[0, 2]->Equals(BoxValues[1, 1])) && (BoxValues[1, 1]->Equals(BoxValues[2, 0])) && !(BoxValues[1, 1]->Equals(0))) ))
		{
			IsGameOVer = true;
			if (BoxValues[1, 1]->Equals(1)) {
				DisplayWinner("X");
				return;
			}
			else if (BoxValues[1, 1]->Equals(2)) {
				DisplayWinner("O");
				return;
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)
			{
				if ((BoxValues[i, 0]->Equals(BoxValues[i, 1]))&& (BoxValues[i, 1]->Equals(BoxValues[i, 2])) &&!(BoxValues[i, 1]->Equals(0))) {
					IsGameOVer = true;
					if (BoxValues[i, 1]->Equals(1)) {
						DisplayWinner("X");
						return;
					}
					else if (BoxValues[i, 1]->Equals(2)) {
						DisplayWinner("O");
						return;
					}
				}
				else if ((BoxValues[0, i]->Equals(BoxValues[1,i])) && (BoxValues[1,i]->Equals(BoxValues[2,i])) && !(BoxValues[1,i]->Equals(0))) {
					IsGameOVer = true;
					if (BoxValues[1, i]->Equals(1)) {
						DisplayWinner("X");
						return;
					}
					else if (BoxValues[1, i]->Equals(2)) {
						DisplayWinner("O");
						return;
					}	
				}
			}
		}
		bool isFull = true;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (BoxValues[i, j]->Equals(0))
					isFull = false;
			}
		}
		if(isFull)
			DisplayWinner("");
	}
	private:System::Void DisplayWinner(String^ s) {

		nrOfMatches++;
		NextMatch->Visible = true;
		if (s->Equals("X"))
		{
			label1->Text = "X won";
			if (p1->isX)
			{
				p1score++;
				if(p1score >= 2 && p1score > p2score) {
					WinMessage->Text = "Player 1 Won!";
					NextMatch->Visible = false;
				}
			}
			else if (p2->isX)
			{
				p2score++;
				if (p2score >= 2 && p2score > p1score) {
					WinMessage->Text = "Player 2 Won!";
					NextMatch->Visible = false;
				}
			}
				
			return;
		}
		else if (s->Equals("O"))
		{
			label1->Text = "O won";
			if (!p1->isX)
			{
				p1score++;
				if (p1score >= 2 && p1score > p2score) {
					WinMessage->Text = "Player 1 Won!";
					NextMatch->Visible = false;
				}
			}
			else if (!p2->isX)
			{
				p2score++;
				if (p2score >= 2 && p2score > p1score) {
					WinMessage->Text = "Player 2 Won!";
					NextMatch->Visible = false;
				}
			}
			return;
		}
		else if (s->Equals(""))
		{
			label1->Text = " Draw";
			return;
		}

		if (nrOfMatches >= 3 && p1score==p2score) {

			WinMessage->Text = " It's a draw!";
			NextMatch->Visible = false;
		}
		
	}
	private:System::Void ResetBoard() {
		BoxValues = gcnew array<Int32^, 2>{{0, 0, 0}, { 0,0,0 }, { 0,0,0 }};
		for (int i = 0; i < 3;i++)
		{
			for (int j = 0; j < 3; j++)
			{
				BoxVisuals[i, j]->Image = nullptr;
			}
		}
		IsGameOVer = false;
		NextMatch->Visible = false;
	}
	private: System::Void Slot1_Click(System::Object^ sender, System::EventArgs^ e) {
		Step(0, 0);
	}
	private: System::Void Slot2_Click(System::Object^ sender, System::EventArgs^ e) {
		Step(0,1);
	}
	private: System::Void Slot3_Click(System::Object^ sender, System::EventArgs^ e) {
		Step(0, 2);
	}
	private: System::Void Slot4_Click(System::Object^ sender, System::EventArgs^ e) {
		Step(1, 0);
	}
	private: System::Void Slot5_Click(System::Object^ sender, System::EventArgs^ e) {
		Step(1, 1);
	}
	private: System::Void Slot6_Click(System::Object^ sender, System::EventArgs^ e) {
		Step(1, 2);
	}
	private: System::Void Slot7_Click(System::Object^ sender, System::EventArgs^ e) {
		Step(2, 0);
	}
	private: System::Void Slot8_Click(System::Object^ sender, System::EventArgs^ e) {
		Step(2, 1);
	}
	private: System::Void Slot9_Click(System::Object^ sender, System::EventArgs^ e) {
		Step(2, 2);
	}
	private: System::Void Game_Load(System::Object^ sender, System::EventArgs^ e) {
		BoxValues = gcnew array<Int32^, 2>{{0, 0, 0}, { 0,0,0 }, { 0,0,0 }};
		BoxVisuals = gcnew array<PictureBox^, 2>{{Slot1, Slot2, Slot3}, { Slot4,Slot5,Slot6 }, { Slot7,Slot8,Slot9 }};
		nrOfMatches = 0;
		srand(time(0));
		NextMatch->Visible = false;

		bool p1X = (rand() % 2 == 0) ? true : false;

		p1 = gcnew Player();
		switch (difficulty) {
		case 0:
			p2 = gcnew EasyAI(BoxValues);
			label1->Text = "Easy";
			break;
		case 1:
			p2 = gcnew MediumAI(BoxValues);
			label1->Text = "Medium";
			break;
		case 2:
			p2 = gcnew HardAI(BoxValues);
			label1->Text = "Hard";
			break;
		default:
			label1->Text = "";
			break;
		}

		if (!p1X) 
		{
			p1->isX = false;
			p2->isX = true;
			mLabel1->Text = "O";
			mLabel2->Text = "X";
			if (nrOfPlayers != 1) {
				p2->Move();
				MarkSpot(p2->SelectedX, p2->SelectedY, 1);
			}
			
		}
		else {
			p1->isX = true;
			p2->isX = false;
			mLabel1->Text = "X";
			mLabel2->Text = "O";
		}
		
		if (nrOfPlayers == 1) {
			if (p1->isX)
			{
				p2->Turn = false;
				p1->Turn = true;
			}
			else 
			{
				p1->Turn = false;
				p2->Turn = true;
			}
		}

	}
	private:System::Void Step(int x, int y) {

		if (BoxValues[x, y]->Equals(0))
		{
			if (nrOfPlayers == 1) {
				//two players
				if (p1->Turn)
				{
					if (p1->isX)
					{
						MarkSpot(x, y, 1);
					}
					else {
						MarkSpot(x, y, 2);
					}
					p1->Turn = false;
					p2->Turn = true;
				}
				else if (p2->Turn)
				{
					if (p2->isX)
					{
						MarkSpot(x, y, 1);
					}
					else {
						MarkSpot(x, y, 2);
					}
					p2->Turn = false;
					p1->Turn = true;
				}

			}
			else {
				//AI Singleplayer
				if (p1->isX)
				{
					MarkSpot(x, y, 1);
					p2->Move();
					MarkSpot(p2->SelectedX, p2->SelectedY, 2);
				}
				else
				{
					MarkSpot(x, y, 2);
					p2->Move();
					MarkSpot(p2->SelectedX, p2->SelectedY, 1);
				}
			}
		}
	}
	private: System::Void NextMatch_Click(System::Object^ sender, System::EventArgs^ e) {
		ResetBoard();
		p2->ResetRef(BoxValues);
		score1->Text = p1score.ToString();
		score2->Text = p2score.ToString();
		label1->Text = "";
	}
};
}
