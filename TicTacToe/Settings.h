#pragma once
#include "Game.h"

namespace TicTacToe {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Settings
	/// </summary>
	public ref class Settings : public System::Windows::Forms::Form
	{
	public:
		Settings(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Settings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ NrOfPlayers;
	private: System::Windows::Forms::ComboBox^ Difficulty;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->NrOfPlayers = (gcnew System::Windows::Forms::ComboBox());
			this->Difficulty = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(76, 162);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 30);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Start Game";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Settings::button1_Click);
			// 
			// NrOfPlayers
			// 
			this->NrOfPlayers->FormattingEnabled = true;
			this->NrOfPlayers->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1 (AI)", L"2" });
			this->NrOfPlayers->Location = System::Drawing::Point(37, 43);
			this->NrOfPlayers->Name = L"NrOfPlayers";
			this->NrOfPlayers->Size = System::Drawing::Size(164, 24);
			this->NrOfPlayers->TabIndex = 1;
			this->NrOfPlayers->SelectedIndexChanged += gcnew System::EventHandler(this, &Settings::NrOfPlayers_SelectedIndexChanged);
			// 
			// Difficulty
			// 
			this->Difficulty->FormattingEnabled = true;
			this->Difficulty->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Easy", L"Medium", L"Hard" });
			this->Difficulty->Location = System::Drawing::Point(37, 112);
			this->Difficulty->Name = L"Difficulty";
			this->Difficulty->Size = System::Drawing::Size(164, 24);
			this->Difficulty->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(37, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 16);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Number of players";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(37, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"AI Difficulty";
			// 
			// Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(239, 204);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Difficulty);
			this->Controls->Add(this->NrOfPlayers);
			this->Controls->Add(this->button1);
			this->Name = L"Settings";
			this->Text = L"Settings";
			this->Load += gcnew System::EventHandler(this, &Settings::Settings_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Settings_Load(System::Object^ sender, System::EventArgs^ e) {
		NrOfPlayers->SelectedIndex = 0;
		Difficulty->SelectedIndex = 0;

	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	Form^ gForm = gcnew Game(NrOfPlayers->SelectedIndex,Difficulty->SelectedIndex);
	gForm->Show();
	this->Hide();

}
private: System::Void NrOfPlayers_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (NrOfPlayers->SelectedIndex == 1)
	{
		Difficulty->Visible = false;
		label2->Visible = false;
	}
	else {
		Difficulty->Visible = true;
		label2->Visible = true;
	}
		
}
};
}
