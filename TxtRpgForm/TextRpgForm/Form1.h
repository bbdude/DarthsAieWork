#pragma once

namespace TextRpgForm {
	#include "Player.h"
	using namespace System;
	using namespace System::Text;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(0, 519);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(958, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::getC);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(964, 519);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			this->richTextBox1->Enter += gcnew System::EventHandler(this, &Form1::richTextBox1_Enter);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(959, 537);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//randomInt
		//drawBar
	private: System::Void write(String^ word) 
	{
		richTextBox1->Text += word;
	}
	private: System::Void writel(String^ word)
	{
		richTextBox1->Text += word;
		richTextBox1->Text += "\n";
	}
	private: System::Void writecl(String^ word)
	{
		richTextBox1->Text = word;
	}
	private: System::Void drawBar()
	{
		writel("-----------------------------------------------------------------------------------------------------------------------");
	}
	private: System::Void richTextBox1_Enter(System::Object^  sender, System::EventArgs^  e) 
	{
	}
	private: System::Void getC(System::Object^  sender, System::EventArgs^  e) {
		if (textBox1->TextLength > 0)
		{
			//write();
			textBox1->Text = "";
		}
	}
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
	{
	}
};
}

