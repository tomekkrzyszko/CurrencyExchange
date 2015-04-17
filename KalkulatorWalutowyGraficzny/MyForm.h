#pragma once
#include "Date.h"
#include "Currency.h"
#include "File.h"
#include <map>
#include <shellapi.h>

namespace KalkulatorWalutowyGraficzny {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{

			InitializeComponent();

			InitializeData();

			otwarciePliku2("C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\kurs1.txt");
			otwarciePliku3("C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\dir.txt");

			InitializeListView();
			InitializeToolTips();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				closeFiles();;
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  download_button;
	protected:

	protected:

	private: System::Windows::Forms::TextBox^  ilosc1_Box;
	private: System::Windows::Forms::TextBox^  ilosc2_Box;
	private: System::Windows::Forms::ComboBox^  waluta1_Box;
	private: System::Windows::Forms::ComboBox^  waluta2_Box;
	private: System::Windows::Forms::Button^  exchange_button;




	private: System::Windows::Forms::DateTimePicker^  dateTimePicker2;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  pLIKToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pOMOCToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  uMLToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  userGuideToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  oAUTORZEToolStripMenuItem;
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;



	public: 	Currency * waluta1 = new Currency();
	public:		Currency * waluta2 = new Currency();
	public:	Date * data1 = new Date();
	public:	Date * data0 = new Date();
	public: Date * data2 = new Date();
	private: System::Windows::Forms::ToolStripMenuItem^  pobierzToolStripMenuItem;
	public:
	private: System::Windows::Forms::ToolStripMenuItem^  aktualnyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dlaKonkretnejDatyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  zPlikuToolStripMenuItem;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::ToolStripMenuItem^  wczorajToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  dzisiajToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  jutroToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::ToolStripMenuItem^  zamknijPlikiToolStripMenuItem;





	public: int trybPracy = 1;

	private: System::Windows::Forms::ListBox^  przelicznik;

	public:

	public:
	public: int wartoscPrzelicznika = 1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->download_button = (gcnew System::Windows::Forms::Button());
			this->ilosc1_Box = (gcnew System::Windows::Forms::TextBox());
			this->ilosc2_Box = (gcnew System::Windows::Forms::TextBox());
			this->waluta1_Box = (gcnew System::Windows::Forms::ComboBox());
			this->waluta2_Box = (gcnew System::Windows::Forms::ComboBox());
			this->exchange_button = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->pLIKToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pobierzToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aktualnyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dlaKonkretnejDatyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zPlikuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->wczorajToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dzisiajToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->jutroToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->zamknijPlikiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pOMOCToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->uMLToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->userGuideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->oAUTORZEToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->przelicznik = (gcnew System::Windows::Forms::ListBox());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// download_button
			// 
			this->download_button->BackColor = System::Drawing::SystemColors::Control;
			this->download_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"download_button.BackgroundImage")));
			this->download_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->download_button->ForeColor = System::Drawing::SystemColors::ControlText;
			this->download_button->Location = System::Drawing::Point(433, 60);
			this->download_button->Name = L"download_button";
			this->download_button->Size = System::Drawing::Size(203, 44);
			this->download_button->TabIndex = 0;
			this->download_button->UseVisualStyleBackColor = false;
			this->download_button->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// ilosc1_Box
			// 
			this->ilosc1_Box->BackColor = System::Drawing::SystemColors::HotTrack;
			this->ilosc1_Box->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->ilosc1_Box->Location = System::Drawing::Point(288, 335);
			this->ilosc1_Box->Name = L"ilosc1_Box";
			this->ilosc1_Box->Size = System::Drawing::Size(150, 20);
			this->ilosc1_Box->TabIndex = 2;
			this->ilosc1_Box->TextChanged += gcnew System::EventHandler(this, &MyForm::ilosc1_Box_TextChanged);
			// 
			// ilosc2_Box
			// 
			this->ilosc2_Box->BackColor = System::Drawing::SystemColors::HotTrack;
			this->ilosc2_Box->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->ilosc2_Box->Location = System::Drawing::Point(617, 335);
			this->ilosc2_Box->Name = L"ilosc2_Box";
			this->ilosc2_Box->ReadOnly = true;
			this->ilosc2_Box->Size = System::Drawing::Size(150, 20);
			this->ilosc2_Box->TabIndex = 3;
			// 
			// waluta1_Box
			// 
			this->waluta1_Box->BackColor = System::Drawing::SystemColors::HotTrack;
			this->waluta1_Box->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->waluta1_Box->FormattingEnabled = true;
			this->waluta1_Box->IntegralHeight = false;
			this->waluta1_Box->Location = System::Drawing::Point(288, 196);
			this->waluta1_Box->Name = L"waluta1_Box";
			this->waluta1_Box->Size = System::Drawing::Size(202, 21);
			this->waluta1_Box->TabIndex = 4;
			this->waluta1_Box->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::waluta1_Box_SelectedIndexChanged);
			// 
			// waluta2_Box
			// 
			this->waluta2_Box->BackColor = System::Drawing::SystemColors::HotTrack;
			this->waluta2_Box->Cursor = System::Windows::Forms::Cursors::Default;
			this->waluta2_Box->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->waluta2_Box->FormattingEnabled = true;
			this->waluta2_Box->Location = System::Drawing::Point(565, 196);
			this->waluta2_Box->Name = L"waluta2_Box";
			this->waluta2_Box->Size = System::Drawing::Size(202, 21);
			this->waluta2_Box->TabIndex = 5;
			this->waluta2_Box->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::waluta2_Box_SelectedIndexChanged);
			// 
			// exchange_button
			// 
			this->exchange_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exchange_button.BackgroundImage")));
			this->exchange_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->exchange_button->Location = System::Drawing::Point(489, 310);
			this->exchange_button->Name = L"exchange_button";
			this->exchange_button->Size = System::Drawing::Size(77, 68);
			this->exchange_button->TabIndex = 6;
			this->exchange_button->UseVisualStyleBackColor = true;
			this->exchange_button->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker2->Location = System::Drawing::Point(618, 0);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(173, 20);
			this->dateTimePicker2->TabIndex = 9;
			this->dateTimePicker2->ValueChanged += gcnew System::EventHandler(this, &MyForm::dateTimePicker2_ValueChanged);
			// 
			// listView1
			// 
			this->listView1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3
			});
			this->listView1->Dock = System::Windows::Forms::DockStyle::Left;
			this->listView1->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->listView1->Location = System::Drawing::Point(0, 24);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(246, 486);
			this->listView1->TabIndex = 10;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Kod";
			this->columnHeader1->Width = 80;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Sell";
			this->columnHeader2->Width = 80;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Buy";
			this->columnHeader3->Width = 80;
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->pLIKToolStripMenuItem,
					this->pOMOCToolStripMenuItem, this->oAUTORZEToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(792, 24);
			this->menuStrip1->TabIndex = 11;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// pLIKToolStripMenuItem
			// 
			this->pLIKToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->pobierzToolStripMenuItem });
			this->pLIKToolStripMenuItem->Name = L"pLIKToolStripMenuItem";
			this->pLIKToolStripMenuItem->Size = System::Drawing::Size(42, 20);
			this->pLIKToolStripMenuItem->Text = L"PLIK";
			this->pLIKToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::pLIKToolStripMenuItem_Click);
			// 
			// pobierzToolStripMenuItem
			// 
			this->pobierzToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->aktualnyToolStripMenuItem,
					this->dlaKonkretnejDatyToolStripMenuItem, this->zPlikuToolStripMenuItem
			});
			this->pobierzToolStripMenuItem->Name = L"pobierzToolStripMenuItem";
			this->pobierzToolStripMenuItem->Size = System::Drawing::Size(113, 22);
			this->pobierzToolStripMenuItem->Text = L"Pobierz";
			// 
			// aktualnyToolStripMenuItem
			// 
			this->aktualnyToolStripMenuItem->Name = L"aktualnyToolStripMenuItem";
			this->aktualnyToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->aktualnyToolStripMenuItem->Text = L"Aktualny";
			this->aktualnyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aktualnyToolStripMenuItem_Click);
			// 
			// dlaKonkretnejDatyToolStripMenuItem
			// 
			this->dlaKonkretnejDatyToolStripMenuItem->Name = L"dlaKonkretnejDatyToolStripMenuItem";
			this->dlaKonkretnejDatyToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->dlaKonkretnejDatyToolStripMenuItem->Text = L"Dla konkretnej daty";
			this->dlaKonkretnejDatyToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::dlaKonkretnejDatyToolStripMenuItem_Click);
			// 
			// zPlikuToolStripMenuItem
			// 
			this->zPlikuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->wczorajToolStripMenuItem,
					this->dzisiajToolStripMenuItem, this->jutroToolStripMenuItem, this->zamknijPlikiToolStripMenuItem
			});
			this->zPlikuToolStripMenuItem->Name = L"zPlikuToolStripMenuItem";
			this->zPlikuToolStripMenuItem->Size = System::Drawing::Size(176, 22);
			this->zPlikuToolStripMenuItem->Text = L"Z pliku";
			this->zPlikuToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::zPlikuToolStripMenuItem_Click);
			// 
			// wczorajToolStripMenuItem
			// 
			this->wczorajToolStripMenuItem->Name = L"wczorajToolStripMenuItem";
			this->wczorajToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->wczorajToolStripMenuItem->Text = L"Wczoraj";
			this->wczorajToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::wczorajToolStripMenuItem_Click);
			// 
			// dzisiajToolStripMenuItem
			// 
			this->dzisiajToolStripMenuItem->Name = L"dzisiajToolStripMenuItem";
			this->dzisiajToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->dzisiajToolStripMenuItem->Text = L"Dzisiaj";
			this->dzisiajToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::dzisiajToolStripMenuItem_Click);
			// 
			// jutroToolStripMenuItem
			// 
			this->jutroToolStripMenuItem->Name = L"jutroToolStripMenuItem";
			this->jutroToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->jutroToolStripMenuItem->Text = L"Jutro";
			this->jutroToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::jutroToolStripMenuItem_Click);
			// 
			// zamknijPlikiToolStripMenuItem
			// 
			this->zamknijPlikiToolStripMenuItem->Name = L"zamknijPlikiToolStripMenuItem";
			this->zamknijPlikiToolStripMenuItem->Size = System::Drawing::Size(142, 22);
			this->zamknijPlikiToolStripMenuItem->Text = L"Zamknij pliki";
			this->zamknijPlikiToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::zamknijPlikiToolStripMenuItem_Click);
			// 
			// pOMOCToolStripMenuItem
			// 
			this->pOMOCToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->uMLToolStripMenuItem,
					this->userGuideToolStripMenuItem
			});
			this->pOMOCToolStripMenuItem->Name = L"pOMOCToolStripMenuItem";
			this->pOMOCToolStripMenuItem->Size = System::Drawing::Size(63, 20);
			this->pOMOCToolStripMenuItem->Text = L"POMOC";
			this->pOMOCToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::pOMOCToolStripMenuItem_Click);
			// 
			// uMLToolStripMenuItem
			// 
			this->uMLToolStripMenuItem->Name = L"uMLToolStripMenuItem";
			this->uMLToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->uMLToolStripMenuItem->Text = L"UML";
			this->uMLToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::uMLToolStripMenuItem_Click);
			// 
			// userGuideToolStripMenuItem
			// 
			this->userGuideToolStripMenuItem->Name = L"userGuideToolStripMenuItem";
			this->userGuideToolStripMenuItem->Size = System::Drawing::Size(131, 22);
			this->userGuideToolStripMenuItem->Text = L"User Guide";
			this->userGuideToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::userGuideToolStripMenuItem_Click);
			// 
			// oAUTORZEToolStripMenuItem
			// 
			this->oAUTORZEToolStripMenuItem->Name = L"oAUTORZEToolStripMenuItem";
			this->oAUTORZEToolStripMenuItem->Size = System::Drawing::Size(83, 20);
			this->oAUTORZEToolStripMenuItem->Text = L"O AUTORZE";
			this->oAUTORZEToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::oAUTORZEToolStripMenuItem_Click);
			// 
			// toolTip1
			// 
			this->toolTip1->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &MyForm::toolTip1_Popup);
			// 
			// przelicznik
			// 
			this->przelicznik->BackColor = System::Drawing::SystemColors::HotTrack;
			this->przelicznik->ForeColor = System::Drawing::SystemColors::HighlightText;
			this->przelicznik->FormattingEnabled = true;
			this->przelicznik->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"x1", L"x10", L"x100", L"x1000", L"x10000" });
			this->przelicznik->Location = System::Drawing::Point(288, 361);
			this->przelicznik->Name = L"przelicznik";
			this->przelicznik->Size = System::Drawing::Size(45, 69);
			this->przelicznik->TabIndex = 14;
			this->przelicznik->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(792, 510);
			this->Controls->Add(this->przelicznik);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->exchange_button);
			this->Controls->Add(this->waluta2_Box);
			this->Controls->Add(this->waluta1_Box);
			this->Controls->Add(this->ilosc2_Box);
			this->Controls->Add(this->ilosc1_Box);
			this->Controls->Add(this->download_button);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Tag = L"MyForm";
			this->Text = L"Kalkulator Walutowy";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


		void InitializeData(void){
			data1->setSystemData();
			data0->setSystemData(); 
			data2->setSystemData();
			string save = "C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\dir.txt";
			string adres = "http://www.nbp.pl/kursy/xml/dir.txt ";
			if (URLDownloadToFileA(NULL, adres.c_str(), save.c_str(), 0, NULL) == S_OK)
				cout << adres << " done. " << '\n';

			else
				cout << adres << " fail. " << '\n';

			data0->setPreviousDay();
			data2->setNextDay();

			string nazwaPliku1 = "C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\" + data1->getDate() + ".txt";
			string nazwaPliku0 = "C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\" + data0->getDate() + ".txt";
			string nazwaPliku2 = "C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\" + data2->getDate() + ".txt";
			rename("C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\kurs2.txt", nazwaPliku1.c_str());
			rename("C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\kurs3.txt", nazwaPliku0.c_str());
			rename("C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\kurs4.txt", nazwaPliku2.c_str());
		}


		void InitializeListView(void){
			int i = 0;
			while (i != 35){
				array<String^>^ subItems = gcnew array<String^>(3);
				String^ e = ToSysString(getKodyWalut());
				subItems[0] = e;
				subItems[1] = "0";
				subItems[2] = "0";
				ListViewItem^ itm = gcnew ListViewItem(subItems);
				listView1->Items->Add(itm);
				waluta1_Box->Items->Add(e);
				waluta2_Box->Items->Add(e);
				if (e == "XDR")
					i = 35;
			}
			setPointerInFile();
		}

		void RefreshListView(void){
			listView1->Items->Clear();
			int i = 0;
			while (i != 35){
				array<String^>^ subItems = gcnew array<String^>(3);
				String^ e = ToSysString(getWaluty());
				double price = atof(getWaluty().c_str());
				double sell = 1.2*price;
				double buy = 0.7*price;
				String^ f = Convert::ToString(sell);
				String^ g = Convert::ToString(buy);
				subItems[0] = e;
				subItems[1] =f;
				subItems[2] = g;
				ListViewItem^ itm = gcnew ListViewItem(subItems);	
				listView1->Items->Add(itm);
				waluta1_Box->Items->Add(e);
				waluta2_Box->Items->Add(e);
				if (e == "XDR")
					i = 35;
				//i++;
			}
			setPointerInFile();
		}

		void InitializeToolTips(void){
			toolTip1->SetToolTip(download_button, "Pobierz");
			toolTip1->SetToolTip(exchange_button, "Przelicz");
			toolTip1->SetToolTip(ilosc1_Box, "Podaj kwote do zamiany");
			toolTip1->SetToolTip(waluta1_Box, "Wybierz walute do zamiany");
			toolTip1->SetToolTip(waluta2_Box, "Wybierz walute na jak¹ chcesz wymieniæ");
			toolTip1->SetToolTip(dateTimePicker2, "Wybierz date");
			toolTip1->SetToolTip(przelicznik, "Wybierz przelicznik dla waluty");
		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		this->download_button->Enabled = true;
		string dataDoPobrania = pobierzKonkretnyPlik(data1->getDate());
		if (dataDoPobrania == "error"){
			MessageBox::Show("Nie ma kursy dla tej daty. \nWybierz inna.","Error");
		}
		else{
			pobierzKurs(dataDoPobrania);
			zamienPrzecinekNaKropke();
			RefreshListView();
			
		}
		setPointerInFile();
		if (trybPracy == 0)
			trybPracy = 1;
	}


private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	waluta2->setIlosc(waluta1->przeliczKurs(waluta2));
	ilosc2_Box->Text = Convert::ToString(waluta2->getIlosc());	
}	
private: System::Void ilosc1_Box_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	waluta1->setIlosc(wartoscPrzelicznika*Convert::ToDouble(ilosc1_Box->Text));

}
private: System::Void waluta1_Box_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	waluta1->setNazwa(ToStdString(waluta1_Box->Text));
	waluta1->setKursSredni(wartoscKursu(waluta1->getNazwa(), trybPracy));
	waluta1->setCeny();
}
private: System::Void waluta2_Box_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	waluta2->setNazwa(ToStdString(waluta2_Box->Text));
	waluta2->setKursSredni(wartoscKursu(waluta2->getNazwa(), trybPracy));
	waluta2->setCeny();
}

private: System::Void dateTimePicker2_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
		data1->changeFormat(ToStdString(dateTimePicker2->Text));
}
private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pLIKToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pOMOCToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void uMLToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void userGuideToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	openPDF();
}
private: System::Void oAUTORZEToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	MessageBox::Show("Tomasz Krzyszkowski", "Autor");
}

private: System::Void aktualnyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	pobierzKurs("http://www.nbp.pl/kursy/xml/LastA.xml");
	zamienPrzecinekNaKropke();
}
private: System::Void dlaKonkretnejDatyToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	pobierzKurs(pobierzKonkretnyPlik(data1->getDate()));
	zamienPrzecinekNaKropke();
}
private: System::Void zPlikuToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	this->download_button->Enabled = false;

}
	private: System::Void toolTip1_Popup(System::Object^  sender, System::Windows::Forms::PopupEventArgs^  e) {
		
	}
private: System::Void wczorajToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	trybPracy = 0;
	string nazwaPliku0 = "C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\" + data0->getDate() + ".txt";
	otwarciePliku(nazwaPliku0);
}
private: System::Void dzisiajToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	trybPracy = 0;
	string nazwaPliku1 = "C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\" + data1->getDate() + ".txt";
	otwarciePliku(nazwaPliku1);
}
private: System::Void jutroToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	trybPracy = 0;
	string nazwaPliku2 = "C:\\Users\\Tomek\\C++\\KalkulatorWalutowyGraficzny\\" + data2->getDate() + ".txt";
	otwarciePliku(nazwaPliku2);
}
private: System::Void zamknijPlikiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	closeFile1();
}

private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (przelicznik->Text == "x1")
		wartoscPrzelicznika = 1;
	else if (przelicznik->Text == "x10")
		wartoscPrzelicznika = 10;
	else if (przelicznik->Text == "x100")
		wartoscPrzelicznika = 100;
	else if (przelicznik->Text == "x1000")
		wartoscPrzelicznika = 1000;
	else if (przelicznik->Text == "x10000")
		wartoscPrzelicznika = 10000;
	waluta1->setIlosc(wartoscPrzelicznika*Convert::ToDouble(ilosc1_Box->Text));
}

private: System::Void MyForm_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
	if (MessageBox::Show("Czy na pewno chcesz zamkn¹æ ?", "Kalkulator Walut", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		Application::Exit();
	else
		e->Cancel = true;
}
};
}
