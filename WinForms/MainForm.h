#pragma once
#include "Profile.h"
#include "DatabaseDirectory.h"
#include "ProfileEditing.h"
#include <Windows.h>
#include <vector>

namespace WinForms 
{
#pragma region Init
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			SetStartWindowVisibility(true);
			SetAccessSelectionWindowVisibility(false);
			SetProfileSelectionWindowVisibility(false);
			SetEditProfileWindowVisibility(false);
			SetViewProfileWindowVisibility(false);
		}
#pragma endregion
#pragma region Dest&Items

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ ViewForms;
	protected:
	private: System::Windows::Forms::Button^ EditForms;
	private: System::Windows::Forms::Button^ AddForms;
	private: System::Windows::Forms::Button^ CreateNewDB;
	private: System::Windows::Forms::Button^ OpenDB;
	private: System::Windows::Forms::ListBox^ ProfilesListBox;
	private: System::Windows::Forms::Label^ FirstNameLabel;
	private: System::Windows::Forms::Label^ LastNameLabel;
	private: System::Windows::Forms::Label^ AgeLabel;
	private: System::Windows::Forms::TextBox^ FirstNameEditTextBox;
	private: System::Windows::Forms::TextBox^ LastNameEditTextBox;
	private: System::Windows::Forms::TextBox^ AgeEditTextBox;
	private: System::Windows::Forms::Button^ BackButton;
	private: System::Windows::Forms::Button^ SaveButton;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma endregion
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->ViewForms = (gcnew System::Windows::Forms::Button());
			this->EditForms = (gcnew System::Windows::Forms::Button());
			this->AddForms = (gcnew System::Windows::Forms::Button());
			this->CreateNewDB = (gcnew System::Windows::Forms::Button());
			this->OpenDB = (gcnew System::Windows::Forms::Button());
			this->ProfilesListBox = (gcnew System::Windows::Forms::ListBox());
			this->FirstNameLabel = (gcnew System::Windows::Forms::Label());
			this->LastNameLabel = (gcnew System::Windows::Forms::Label());
			this->AgeLabel = (gcnew System::Windows::Forms::Label());
			this->FirstNameEditTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LastNameEditTextBox = (gcnew System::Windows::Forms::TextBox());
			this->AgeEditTextBox = (gcnew System::Windows::Forms::TextBox());
			this->BackButton = (gcnew System::Windows::Forms::Button());
			this->SaveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ViewForms
			// 
			this->ViewForms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ViewForms->Location = System::Drawing::Point(100, 100);
			this->ViewForms->Name = L"ViewForms";
			this->ViewForms->Size = System::Drawing::Size(194, 184);
			this->ViewForms->TabIndex = 0;
			this->ViewForms->Text = L"View";
			this->ViewForms->UseVisualStyleBackColor = true;
			this->ViewForms->Click += gcnew System::EventHandler(this, &MainForm::ViewForms_Click);
			// 
			// EditForms
			// 
			this->EditForms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->EditForms->Location = System::Drawing::Point(300, 100);
			this->EditForms->Name = L"EditForms";
			this->EditForms->Size = System::Drawing::Size(194, 184);
			this->EditForms->TabIndex = 1;
			this->EditForms->Text = L"Edit";
			this->EditForms->UseVisualStyleBackColor = true;
			this->EditForms->Click += gcnew System::EventHandler(this, &MainForm::EditForms_Click);
			// 
			// AddForms
			// 
			this->AddForms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AddForms->Location = System::Drawing::Point(500, 100);
			this->AddForms->Name = L"AddForms";
			this->AddForms->Size = System::Drawing::Size(194, 184);
			this->AddForms->TabIndex = 2;
			this->AddForms->Text = L"Add";
			this->AddForms->UseVisualStyleBackColor = true;
			this->AddForms->Click += gcnew System::EventHandler(this, &MainForm::AddForms_Click);
			// 
			// CreateNewDB
			// 
			this->CreateNewDB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->CreateNewDB->Location = System::Drawing::Point(183, 72);
			this->CreateNewDB->Name = L"CreateNewDB";
			this->CreateNewDB->Size = System::Drawing::Size(437, 123);
			this->CreateNewDB->TabIndex = 3;
			this->CreateNewDB->Text = L"CreateNewDB";
			this->CreateNewDB->UseVisualStyleBackColor = true;
			this->CreateNewDB->Click += gcnew System::EventHandler(this, &MainForm::CreateNewDB_Click);
			// 
			// OpenDB
			// 
			this->OpenDB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->OpenDB->Location = System::Drawing::Point(183, 201);
			this->OpenDB->Name = L"OpenDB";
			this->OpenDB->Size = System::Drawing::Size(437, 123);
			this->OpenDB->TabIndex = 4;
			this->OpenDB->Text = L"OpenDB";
			this->OpenDB->UseVisualStyleBackColor = true;
			this->OpenDB->Click += gcnew System::EventHandler(this, &MainForm::OpenDB_Click);
			// 
			// ProfilesListBox
			// 
			this->ProfilesListBox->BackColor = System::Drawing::SystemColors::Menu;
			this->ProfilesListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ProfilesListBox->FormattingEnabled = true;
			this->ProfilesListBox->ItemHeight = 42;
			this->ProfilesListBox->Location = System::Drawing::Point(253, 34);
			this->ProfilesListBox->Name = L"ProfilesListBox";
			this->ProfilesListBox->Size = System::Drawing::Size(295, 340);
			this->ProfilesListBox->TabIndex = 5;
			this->ProfilesListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ProfilesListBox_SelectedIndexChanged);
			// 
			// FirstNameLabel
			// 
			this->FirstNameLabel->AutoSize = true;
			this->FirstNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FirstNameLabel->Location = System::Drawing::Point(166, 103);
			this->FirstNameLabel->Name = L"FirstNameLabel";
			this->FirstNameLabel->Size = System::Drawing::Size(199, 42);
			this->FirstNameLabel->TabIndex = 6;
			this->FirstNameLabel->Text = L"FirstName:";
			// 
			// LastNameLabel
			// 
			this->LastNameLabel->AutoSize = true;
			this->LastNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LastNameLabel->Location = System::Drawing::Point(167, 158);
			this->LastNameLabel->Name = L"LastNameLabel";
			this->LastNameLabel->Size = System::Drawing::Size(198, 42);
			this->LastNameLabel->TabIndex = 7;
			this->LastNameLabel->Text = L"LastName:";
			// 
			// AgeLabel
			// 
			this->AgeLabel->AutoSize = true;
			this->AgeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AgeLabel->Location = System::Drawing::Point(270, 213);
			this->AgeLabel->Name = L"AgeLabel";
			this->AgeLabel->Size = System::Drawing::Size(95, 42);
			this->AgeLabel->TabIndex = 8;
			this->AgeLabel->Text = L"Age:";
			// 
			// FirstNameEditTextBox
			// 
			this->FirstNameEditTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->FirstNameEditTextBox->Location = System::Drawing::Point(371, 100);
			this->FirstNameEditTextBox->Name = L"FirstNameEditTextBox";
			this->FirstNameEditTextBox->Size = System::Drawing::Size(323, 49);
			this->FirstNameEditTextBox->TabIndex = 9;
			// 
			// LastNameEditTextBox
			// 
			this->LastNameEditTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->LastNameEditTextBox->Location = System::Drawing::Point(371, 155);
			this->LastNameEditTextBox->Name = L"LastNameEditTextBox";
			this->LastNameEditTextBox->Size = System::Drawing::Size(323, 49);
			this->LastNameEditTextBox->TabIndex = 10;
			// 
			// AgeEditTextBox
			// 
			this->AgeEditTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->AgeEditTextBox->Location = System::Drawing::Point(371, 210);
			this->AgeEditTextBox->Name = L"AgeEditTextBox";
			this->AgeEditTextBox->Size = System::Drawing::Size(323, 49);
			this->AgeEditTextBox->TabIndex = 11;
			// 
			// BackButton
			// 
			this->BackButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BackButton->Location = System::Drawing::Point(404, 320);
			this->BackButton->Name = L"BackButton";
			this->BackButton->Size = System::Drawing::Size(184, 54);
			this->BackButton->TabIndex = 12;
			this->BackButton->Text = L"Back";
			this->BackButton->UseVisualStyleBackColor = true;
			this->BackButton->Click += gcnew System::EventHandler(this, &MainForm::BackButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SaveButton->Location = System::Drawing::Point(213, 320);
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(185, 54);
			this->SaveButton->TabIndex = 13;
			this->SaveButton->Text = L"Save";
			this->SaveButton->UseVisualStyleBackColor = true;
			this->SaveButton->Click += gcnew System::EventHandler(this, &MainForm::SaveButton_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(800, 400);
			this->Controls->Add(this->SaveButton);
			this->Controls->Add(this->BackButton);
			this->Controls->Add(this->AgeEditTextBox);
			this->Controls->Add(this->LastNameEditTextBox);
			this->Controls->Add(this->FirstNameEditTextBox);
			this->Controls->Add(this->AgeLabel);
			this->Controls->Add(this->LastNameLabel);
			this->Controls->Add(this->FirstNameLabel);
			this->Controls->Add(this->ProfilesListBox);
			this->Controls->Add(this->OpenDB);
			this->Controls->Add(this->CreateNewDB);
			this->Controls->Add(this->AddForms);
			this->Controls->Add(this->EditForms);
			this->Controls->Add(this->ViewForms);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Profiles";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
#pragma region StartWindow
		Void CreateNewDB_Click(Object^ sender, EventArgs^ e) 
		{
			if (IsDatabaseExists())
			{
				MessageBox::Show("Database already exists", "Information");
			}
			else
			{
				//..createdb
				MessageBox::Show("Database successfully created", "Information");
				SetStartWindowVisibility(false);
				SetAccessSelectionWindowVisibility(true);
			}
		}
		Void OpenDB_Click(Object^ sender, EventArgs^ e) 
		{
			if (IsDatabaseExists())
			{
				MessageBox::Show("Opening database", "Information");
				SetStartWindowVisibility(false);
				SetAccessSelectionWindowVisibility(true);
			}
			else
			{
				MessageBox::Show("Database not found", "Information");
			}
		}
		Void SetStartWindowVisibility(Boolean visibility) 
		{
			this->CreateNewDB->Visible = visibility;
			this->OpenDB->Visible = visibility;
		}
#pragma endregion
#pragma region AccessSelection
		Void EditForms_Click(Object^ sender, EventArgs^ e) 
		{
			SetCurrentAccess(1);
			SetAccessSelectionWindowVisibility(false);
			SetProfileSelectionWindowVisibility(true);
		}
		Void ViewForms_Click(Object^ sender, EventArgs^ e) 
		{
			SetCurrentAccess(0);
			SetAccessSelectionWindowVisibility(false);
			SetProfileSelectionWindowVisibility(true);
		}
		Void AddForms_Click(Object^ sender, EventArgs^ e) 
		{
			SetCurrentAccess(1);
			SetAccessSelectionWindowVisibility(false);
			SetEditProfileWindowVisibility(true);
		}
		Void SetAccessSelectionWindowVisibility(Boolean visibility) 
		{
			this->ViewForms->Visible = visibility;
			this->EditForms->Visible = visibility;
			this->AddForms->Visible = visibility;
		}
#pragma endregion
#pragma region ProfileSelection
		Void ProfilesListBox_SelectedIndexChanged(Object^ sender, EventArgs^ e) 
		{
			SetProfileSelectionWindowVisibility(false);
		}
		Void SetProfileSelectionWindowVisibility(Boolean visibility) 
		{
			this->ProfilesListBox->Visible = visibility;
		}
#pragma endregion
#pragma region View&EditProfile
		Void BackButton_Click(Object^ sender, EventArgs^ e) 
		{
			SetViewProfileWindowVisibility(false);
			SetEditProfileWindowVisibility(false);
			SetAccessSelectionWindowVisibility(true);
		}
		Void SaveButton_Click(Object^ sender, EventArgs^ e) 
		{
			SetEditProfileWindowVisibility(false);
			SetAccessSelectionWindowVisibility(true);
		}
		Void SetEditAndViewProfileVisibility(Boolean visibility) 
		{
			this->FirstNameEditTextBox->Visible = visibility;
			this->FirstNameLabel->Visible = visibility;
			this->LastNameEditTextBox->Visible = visibility;
			this->LastNameLabel->Visible = visibility;
			this->AgeEditTextBox->Visible = visibility;
			this->AgeLabel->Visible = visibility;
			this->BackButton->Visible = visibility;
		}
		Void SetEditProfileWindowVisibility(Boolean visibility) 
		{
			SetEditAndViewProfileVisibility(visibility);
			this->SaveButton->Visible = visibility;
			this->FirstNameEditTextBox->ReadOnly = visibility;
			this->LastNameEditTextBox->ReadOnly = visibility;
			this->AgeEditTextBox->ReadOnly = visibility;
		}
		Void SetViewProfileWindowVisibility(Boolean visibility) 
		{
			SetEditAndViewProfileVisibility(visibility);
		}
#pragma endregion
};
}
