#pragma once
#include "AboutForm.h"
#include "AddForm.h"
#include "ExtendSizeForm.h"

namespace VirtualCDROM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Ñâîäêà äëÿ MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: äîáàâüòå êîä êîíñòğóêòîğà
			//
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ğåñóğñû.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  ôàéëToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  äîáàâèòüÄèñêToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  âûõîäToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  îÏğîãğàììåToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ToolStripMenuItem^  âûáğàííûéToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  èçìåíèòüĞàçìåğToolStripMenuItem;
	private: System::Windows::Forms::Button^  button4;

	private:
		/// <summary>
		/// Òğåáóåòñÿ ïåğåìåííàÿ êîíñòğóêòîğà.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Îáÿçàòåëüíûé ìåòîä äëÿ ïîääåğæêè êîíñòğóêòîğà - íå èçìåíÿéòå
		/// ñîäåğæèìîå äàííîãî ìåòîäà ïğè ïîìîùè ğåäàêòîğà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ôàéëToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->äîáàâèòüÄèñêToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûõîäToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->âûáğàííûéToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->èçìåíèòüĞàçìåğToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->ôàéëToolStripMenuItem, 
				this->âûáğàííûéToolStripMenuItem, this->îÏğîãğàììåToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(384, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ôàéëToolStripMenuItem
			// 
			this->ôàéëToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->äîáàâèòüÄèñêToolStripMenuItem, 
				this->âûõîäToolStripMenuItem});
			this->ôàéëToolStripMenuItem->Name = L"ôàéëToolStripMenuItem";
			this->ôàéëToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->ôàéëToolStripMenuItem->Text = L"Ôàéë";
			// 
			// äîáàâèòüÄèñêToolStripMenuItem
			// 
			this->äîáàâèòüÄèñêToolStripMenuItem->Name = L"äîáàâèòüÄèñêToolStripMenuItem";
			this->äîáàâèòüÄèñêToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->äîáàâèòüÄèñêToolStripMenuItem->Text = L"Äîáàâèòü äèñê";
			this->äîáàâèòüÄèñêToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::äîáàâèòüÄèñêToolStripMenuItem_Click);
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			this->âûõîäToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::âûõîäToolStripMenuItem_Click);
			// 
			// âûáğàííûéToolStripMenuItem
			// 
			this->âûáğàííûéToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->èçìåíèòüĞàçìåğToolStripMenuItem});
			this->âûáğàííûéToolStripMenuItem->Name = L"âûáğàííûéToolStripMenuItem";
			this->âûáğàííûéToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->âûáğàííûéToolStripMenuItem->Text = L"Âûáğàííûé...";
			// 
			// èçìåíèòüĞàçìåğToolStripMenuItem
			// 
			this->èçìåíèòüĞàçìåğToolStripMenuItem->Name = L"èçìåíèòüĞàçìåğToolStripMenuItem";
			this->èçìåíèòüĞàçìåğToolStripMenuItem->Size = System::Drawing::Size(171, 22);
			this->èçìåíèòüĞàçìåğToolStripMenuItem->Text = L"Èçìåíèòü ğàçìåğ";
			this->èçìåíèòüĞàçìåğToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::èçìåíèòüĞàçìåğToolStripMenuItem_Click);
			// 
			// îÏğîãğàììåToolStripMenuItem
			// 
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Î ïğîãğàììå";
			this->îÏğîãğàììåToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::îÏğîãğàììåToolStripMenuItem_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(12, 40);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(360, 150);
			this->dataGridView1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(66, 230);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 30);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Äîáàâèòü äèñê";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(214, 230);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(110, 30);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Óäàëèòü äèñê";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(214, 284);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(110, 30);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Âûõîä";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(66, 284);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(110, 30);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Èçìåíèòü ğàçìåğ";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MainForm::button4_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->ClientSize = System::Drawing::Size(384, 332);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(400, 370);
			this->MinimumSize = System::Drawing::Size(400, 370);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Virtual CD-ROM";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void âûõîäToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
		 }
private: System::Void îÏğîãğàììåToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 AboutForm^ form = gcnew AboutForm;
			 form->Show();
		 }
private: System::Void äîáàâèòüÄèñêToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 AddForm^ form = gcnew AddForm;
			 form->Show();
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 AddForm^ form = gcnew AddForm;
			 form->Show();
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 ExtendSizeForm^ form = gcnew ExtendSizeForm;
			 form->Show();
		 }
private: System::Void èçìåíèòüĞàçìåğToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			 ExtendSizeForm^ form = gcnew ExtendSizeForm;
			 form->Show();
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
