#pragma once

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
	private: System::Windows::Forms::ToolStripMenuItem^  îáíîâèòüÎêíîToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  îÏğîãğàììåToolStripMenuItem;

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
			this->îÏğîãğàììåToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->îáíîâèòüÎêíîToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->ôàéëToolStripMenuItem, 
				this->îáíîâèòüÎêíîToolStripMenuItem, this->îÏğîãğàììåToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(634, 24);
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
			// 
			// âûõîäToolStripMenuItem
			// 
			this->âûõîäToolStripMenuItem->Name = L"âûõîäToolStripMenuItem";
			this->âûõîäToolStripMenuItem->Size = System::Drawing::Size(154, 22);
			this->âûõîäToolStripMenuItem->Text = L"Âûõîä";
			// 
			// îÏğîãğàììåToolStripMenuItem
			// 
			this->îÏğîãğàììåToolStripMenuItem->Name = L"îÏğîãğàììåToolStripMenuItem";
			this->îÏğîãğàììåToolStripMenuItem->Size = System::Drawing::Size(94, 20);
			this->îÏğîãğàììåToolStripMenuItem->Text = L"Î ïğîãğàììå";
			// 
			// îáíîâèòüÎêíîToolStripMenuItem
			// 
			this->îáíîâèòüÎêíîToolStripMenuItem->Name = L"îáíîâèòüÎêíîToolStripMenuItem";
			this->îáíîâèòüÎêíîToolStripMenuItem->Size = System::Drawing::Size(103, 20);
			this->îáíîâèòüÎêíîToolStripMenuItem->Text = L"Îáíîâèòü îêíî";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(634, 362);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Virtual CD-ROM";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
