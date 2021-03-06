#pragma once
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct Cell
{
	char mine;
	int nums;
	int reveal;
	char flag;
}Cell;
const int size = 20;
Cell board[size][size];
int bx = 0, by = 0, bNums = 0;
int numMines = 10;


void clearBoard(void)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			board[i][j].nums = 0;
			board[i][j].reveal = 0;
			board[i][j].mine = ' ';
			board[i][j].flag = ' ';
		}
	}
}
void deployMines(void)
{
	int x = 0, y = 0, i = 0;

	for(i = 0; i < numMines; i++)
	{
		do{
		x = rand() % size;
		y = rand() % size;
		}while(board[x][y].mine == '*');
		board[x][y].mine = '*';
		//board[x][y].reveal = 1;
	}
}
void setBoard(void)
{
	int i = 0, j = 0;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if((board[i][j+1].mine == '*')&&(j<size-1)){board[i][j].nums++;}
			if((board[i][j-1].mine == '*')&&(j>0)){board[i][j].nums++;}
			if((board[i+1][j].mine == '*')&&(i<size-1)){board[i][j].nums++;}
			if((board[i-1][j].mine == '*')&&(i>0)){board[i][j].nums++;}
			if((board[i+1][j+1].mine == '*')&&(i<size-1)&&(j<size-1)){board[i][j].nums++;}
			if((board[i-1][j-1].mine == '*')&&(i>0)&&(j>0)){board[i][j].nums++;}
			if((board[i+1][j-1].mine == '*')&&(i<size-1)&&(j>0)){board[i][j].nums++;}
			if((board[i-1][j+1].mine == '*')&&(i>0)&&(j<size-1)){board[i][j].nums++;}
		}
	}
}

int solved(void)
{
	int i = 0, j = 0, solve = 1;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if((board[i][j].mine == '*')&&(board[i][j].reveal == 1))
			{
				solve = 2;
				//printf("Loss\n");
				return solve;
			}
			if((board[i][j].mine != '*')&&(board[i][j].reveal == 0)&&(board[i][j].flag != '!'))
			{
				solve = 0;
			}
		}
	}
	return solve;
}
void showZeros(void)
{
	int i = 0, j = 0;
	for(i = 0; i < size; i++)
	{
		for(j = 0; j < size; j++)
		{
			if((board[i][j].reveal == 1)&&(board[i][j].nums == 0))
			{
				if((board[i][j+1].nums < 2)&&(j<size-1)){board[i][j+1].reveal = 1;}
				if((board[i+1][j].nums < 2)&&(i<size-1)){board[i+1][j].reveal = 1;}
				if((board[i-1][j].nums < 2)&&(i>0)){board[i-1][j].reveal = 1;}
				if((board[i][j-1].nums < 2)&&(j>0)){board[i][j-1].reveal = 1;}
				//if((board[i+1][j+1].nums < 2)&&(i<size-1)&&(j<size-1)){board[i+1][j+1].reveal = 1;}
				//if((board[i-1][j-1].nums < 2)&&(i>0)&&(j>0)){board[i-1][j-1].reveal = 1;}
				//if((board[i-1][j+1].nums < 2)&&(i>0)&&(j<size-1)){board[i-1][j+1].reveal = 1;}
				//if((board[i+1][j-1].nums < 2)&&(i<size-1)&&(j>0)){board[i+1][j-1].reveal = 1;}
			}
		}
	}
	for(i = size-1; i > 0; i--)
	{
		for(j = size-1; j > 0; j--)
		{
			if((board[i][j].reveal == 1)&&(board[i][j].nums == 0))
			{
				if((board[i][j+1].nums < 2)&&(j<size-1)){board[i][j+1].reveal = 1;}
				if((board[i+1][j].nums < 2)&&(i<size-1)){board[i+1][j].reveal = 1;}
				if((board[i-1][j].nums < 2)&&(i>0)){board[i-1][j].reveal = 1;}
				if((board[i][j-1].nums < 2)&&(j>0)){board[i][j-1].reveal = 1;}
				//if((board[i+1][j+1].nums < 2)&&(i<size-1)&&(j<size-1)){board[i+1][j+1].reveal = 1;}
				//if((board[i-1][j-1].nums < 2)&&(i>0)&&(j>0)){board[i-1][j-1].reveal = 1;}
				//if((board[i-1][j+1].nums < 2)&&(i>0)&&(j<size-1)){board[i-1][j+1].reveal = 1;}
				//if((board[i+1][j-1].nums < 2)&&(i<size-1)&&(j>0)){board[i+1][j-1].reveal = 1;}
			}
		}
	}
}



namespace Test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		static array<Label ^>^ labels = gcnew array<Label ^>(size*size);	
	    static array<Button ^>^ buttons = gcnew array<Button ^>(size*size);	
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
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Button^  button1;
    private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RadioButton^  radioButton1;
	private: System::Windows::Forms::RadioButton^  radioButton2;
	private: System::Windows::Forms::RadioButton^  radioButton3;
	private: System::Windows::Forms::RadioButton^  radioButton4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;

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
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(272, 18);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(82, 17);
			this->checkBox1->TabIndex = 0;
			this->checkBox1->Text = L"Flag/Unflag";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->ForeColor = Color::White;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(22, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"New Game";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(130, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Settings";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(130, 101);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Choose Difficulty:";
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(133, 130);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(48, 17);
			this->radioButton1->TabIndex = 7;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Easy";
			this->radioButton1->UseVisualStyleBackColor = true;
			this->radioButton1->ForeColor = Color::White;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(133, 153);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(62, 17);
			this->radioButton2->TabIndex = 8;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Medium";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->ForeColor = Color::White;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(134, 176);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(48, 17);
			this->radioButton3->TabIndex = 9;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Hard";
			this->radioButton3->UseVisualStyleBackColor = true;
			this->radioButton3->ForeColor = Color::White;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(134, 199);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(60, 17);
			this->radioButton4->TabIndex = 9;
			this->radioButton4->TabStop = true;
			this->radioButton4->ForeColor = Color::White;
			this->radioButton4->Text = L"Custom";
			//this->radioButton4->UseVisualStyleBackColor = true;
			this->radioButton4->Click += gcnew System::EventHandler(this, &Form1::radioButton4_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(157, 253);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 10;
			this->textBox1->Visible = false;
			this->textBox1->BackColor = Color::White;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(154, 230);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 13);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Enter Percentage of Mines";
			this->label2->ForeColor = Color::White;
			this->label2->Visible = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(80+(size*26), 80+(size*25));
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->radioButton4);
			this->Controls->Add(this->radioButton3);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->checkBox1);
			this->Name = L"Form1";
			this->Text = L"Minesweeper";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void revealMines(void)
		{
			int x = 0;
			for(int i = 0; i < size; i++)
			{
				for(int j = 0; j < size; j++)
				{
					x = (j*size)+i;
					if(board[i][j].mine == '*')
					{
						this->buttons[x]->Text = "X";
						this->buttons[x]->BackColor = Color::DarkRed;
					}
				}
			}
		}
		void revealZeros(void)
		{
			showZeros();
			showZeros();
			showZeros();
			int x = 0;
			for(int i = 0; i < size; i++)
			{
				for(int j = 0; j < size; j++)
				{
					x = (j*size)+i;
					if((board[i][j].reveal == 1)&&(buttons[x]->Visible == true))
					{
						buttons[x]->Visible = false;
						labels[x]->Visible = true;
						labels[x]->Text = board[i][j].nums.ToString();
						if(board[i][j].nums == 0){labels[x]->Visible = false;}
						if(board[i][j].nums == 1){labels[x]->ForeColor = Color::Blue;}
						if(board[i][j].nums == 2){labels[x]->ForeColor = Color::DarkGreen;}
						if(board[i][j].nums == 3){labels[x]->ForeColor = Color::Red;}
						if(board[i][j].nums == 4){labels[x]->ForeColor = Color::Red;}
						if(board[i][j].nums >= 5){labels[x]->ForeColor = Color::DarkRed;}
						
					}
				}
			}
		}
		void createButtons(void)
		{			
			for(int i = 0; i < size*size; i++)
			{	//y = 0;	
				if(!this->Controls->Contains(buttons[i]))
				{
				bx = i % size;
				if(bx == 0){by++;}
				labels[i] = (gcnew System::Windows::Forms::Label());
				labels[i]->AutoSize = true;
				labels[i]->Visible = false;
				labels[i]->Name = (bNums+3).ToString();
				labels[i]->Size = System::Drawing::Size(27, 25);
				labels[i]->TabIndex = bNums;
				buttons[i] = (gcnew System::Windows::Forms::Button());
				buttons[i]->Location = System::Drawing::Point(30+(bx*27), 30+(by*25));
				labels[i]->Location = System::Drawing::Point(36+(bx*27), 35+(by*25));
				buttons[i]->Name = (bNums+3).ToString();
				buttons[i]->Size = System::Drawing::Size(27, 25);
				buttons[i]->TabIndex = bNums;
				buttons[i]->Text = " ";
				buttons[i]->Visible = true;
				buttons[i]->Enabled = true;
				buttons[i]->FlatStyle = FlatStyle::Popup;
				buttons[i]->BackColor = Color::DarkBlue;
				
				buttons[i]->UseVisualStyleBackColor = true;
				
				bNums++;
				buttons[i]->Click += gcnew EventHandler(this, &Form1::ButtonsClick);
				

				
				this->Controls->Add(buttons[i]);
				this->Controls->Add(labels[i]);
				}
				if(this->Controls->Contains(buttons[i]))
				{
					buttons[i]->Text = " ";
					buttons[i]->Enabled = true;
					buttons[i]->Visible = true;
					buttons[i]->UseVisualStyleBackColor = true;
					labels[i]->Text = " ";
					labels[i]->Visible = false;
					buttons[i]->BackColor = Color::DarkBlue;
				}
			}
		}

		void ButtonsClick(System::Object ^sender, System::EventArgs ^e)
        {
			Button ^b = (Button^)sender;
			int i = b->TabIndex;
			int j = 0, tmp = i;
			if(i > size){i %= size;}
			while(tmp > size)
			{
				tmp -= size;
				j++;
			}
			if(board[i][j].flag == '!'){labels[b->TabIndex]->Text = "X";}
			if(board[i][j].flag != '!'){labels[b->TabIndex]->Text = board[i][j].nums.ToString();}
			
			if((checkBox1->Checked == true)&&(b->Text != "!"))
			{
				b->Text = "!";
				b->Font->Bold;
				b->BackColor = Color::Red;
				//checkBox1->Checked = false;
				board[i][j].flag = '!';
			}
			else if((b->Text == "!")&&(checkBox1->Checked == true))
			{
				b->Text = " ";
				//checkBox1->Checked = false;
				board[i][j].flag = ' ';
			}
			if(b->Text != "!")
			{
				if(board[i][j].mine == '*')
				{
					b->Text = "X";
					b->BackColor = Color::DarkRed;
					//board[i][j].reveal = 1;
					MessageBox::Show("You Lose!");
					revealMines();
					b->Visible = true;
				}
				else
				{
					b->Text = board[i][j].nums.ToString();
					b->Visible = false;
				
					labels[b->TabIndex]->Text = board[i][j].nums.ToString();
					if(board[i][j].nums > 8){labels[b->TabIndex]->Text = "1";}
					labels[b->TabIndex]->Visible = true;
					
					
					if(board[i][j].nums == 0){labels[b->TabIndex]->Visible = false;}
					if(board[i][j].nums == 1){labels[b->TabIndex]->ForeColor = Color::Blue;}
					if(board[i][j].nums == 2){labels[b->TabIndex]->ForeColor = Color::DarkGreen;}
					if(board[i][j].nums == 3){labels[b->TabIndex]->ForeColor = Color::Red;}
					if(board[i][j].nums == 4){labels[b->TabIndex]->ForeColor = Color::Red;}
					if(board[i][j].nums >= 5){labels[b->TabIndex]->ForeColor = Color::DarkRed;}
					board[i][j].reveal = 1;
				}
			}
			
			if(buttonSolved() == 1)
			{
				MessageBox::Show("You Win!");
			}
			revealZeros();		
		
        }
		int buttonSolved(void)
		{
			int solved = 1;
			for(int i = 0; i < size*size; i++)
			{
				if((buttons[i]->Visible == true)&&(buttons[i]->Text != "!"))
				{
					solved = 0;
				}
				if((labels[i]->Text == "X")&&(buttons[i]->Text != "!"))
				{
					solved = 0;
				}
			}
			return solved;
		}
		void settings(void)
		{
			if(radioButton1->Checked == true)
			{
				numMines = (size*size)/20;

			}
			if(radioButton2->Checked == true)
			{				
				numMines = (size*size)/10;
			}
			if(radioButton3->Checked == true)
			{				
				numMines = (size*size)/5;
			}
			if(radioButton4->Checked == true)
			{
				int p = System::Convert::ToInt32(textBox1->Text);
				numMines = (size*size*p)/100;
			}
			label1->Visible = false;
			radioButton1->Visible = false;
			radioButton2->Visible = false;
			radioButton3->Visible = false;
			radioButton4->Visible = false;
			label2->Visible = false;
			textBox1->Visible = false;
		}
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			
				bx = 0;
				by = 0;
				bNums = 0;
				settings();				
				createButtons();
				clearBoard();
				deployMines();
				setBoard();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				for(int i = 0; i < size*size; i++)
				{
					if(this->Controls->Contains(buttons[i]))
					{
						this->buttons[i]->Visible = false;
					}
					if(this->Controls->Contains(labels[i]))
					{
						this->labels[i]->Visible = false;
					}
				}
				label1->Visible = true;
				radioButton1->Visible = true;
				radioButton2->Visible = true;
				radioButton3->Visible = true;
				radioButton4->Visible = true;
			 }
private: System::Void radioButton4_Click(System::Object^  sender, System::EventArgs^  e) {
				this->label2->Visible = true;
				this->textBox1->Visible = true;
		 }
};
}

