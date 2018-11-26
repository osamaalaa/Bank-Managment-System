#include "Account.h"

using std::cerr;                   // bta3t l error 
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::fstream;
using std::getline;
using std::ios;
using std::vector;
using std::ws;
const char* fileName = "Employee.txt";
void clearScreen();
void displayTitle();
void pauseScreen();
char quit();
lint_t findRecord(vector<Account*>*& pv_pca, const field_t ssn);
bool verifyDuplicateEntries(vector<Account*>*& pv_pca, accNum_t accNum);
bool find_rec(vector<Employee*>*&,int);

void mainMenu(vector<Account*>*& pv_pca,vector<Employee*>*& pv_pca2)
{
	char myChoice = (' ');

	do
	{
		clearScreen();
		displayTitle();

		cout << '\n'
			<< CREATE_NEW_ACCOUNT << '\n'
			<< CREATE_EMPLOYEE_ACCOUNT << '\n'
			<< DEPOSIT_INTO_ACCOUNT << '\n'
			<< WITHDRAWAL_FROM_ACCOUNT << '\n'
			<< ADD_LOAN << '\n'
			<< PAY_LOAN << '\n'
			<< VIEW_LOANS<<'\n'
			<< VIEW_ACCOUNT << '\n'
			<<"                        "<<'\n'
			<< LOAD_FILE << '\n'
			<< ERASE_ACCOUNT << '\n'
			<< SAVE_ACCOUNT <<'\n'
			<< FIND_EMPLOYEE<<'\n'
			<< EXIT_PROGRAM << '\n'
			<< endl;

		cout << ENTER_CHOICE;
		cin >> myChoice;

		myChoice = toupper(myChoice);

		if (myChoice == EXIT_CODE)
		{
			if (quit() == TRUE) { break; }
			else
			{
				myChoice = ' ';

				continue;
			}
		}

		switch (myChoice)
		{
		case(CREATE_CODE):
		{
			accountType_t acc = (' ');
			bool isGoBack = (false);

			do
			{
				clearScreen();
				displayTitle();

				cout << '\n' << WHAT_TYPE_OF_ACC;
				cin >> acc;

				acc = toupper(acc);

				if (acc != CHECKING_CODE && acc != SAVING_CODE && acc != GO_BACK_CODE)
				{
					cerr << '\n' << ERROR << '\n' << endl;

					pauseScreen();

					continue;
				}
				else if (acc == GO_BACK_CODE)
				{
					isGoBack = (true);
				}

				if (!isGoBack)
					(acc == CHECKING_CODE)
					? pv_pca->push_back(new checkingRecord_t()) : pv_pca->push_back(new savingRecord_t());     // de msln zy (a>b ? a:b)  de m3naha l lchecking code 2t3ml h y pushback feha l checking otherwise  saving  
					

			} while (acc != CHECKING_CODE && acc != SAVING_CODE && acc != GO_BACK_CODE);

			if (!isGoBack)
			{
				pv_pca->back()->insertAccNum(accNum_t(pv_pca->size()));
				pv_pca->back()->createAccount();
			}

			break;
		}
		case(DEPOSIT_CODE):
		{
			if (pv_pca->empty())
			{
				cerr << '\n' << ERROR<< '\n' << endl;

				pauseScreen();

				continue;
			}

			field_t ssn;

			cout << '\n' << ENTER_SSN;
			cin >> ws;
			getline(cin, ssn);

			if (ssn == "-1")
			{
				; // don't do anything if the user takes the action of going back
			}
			else
			{
				uint_t elemNum_;

				elemNum_ = findRecord(pv_pca, ssn);

				if (elemNum_ == RECORD_NOT_FOUND)
				{
					cerr << '\n' << ERROR << '\n' << endl;

					pauseScreen();

					continue;
				}
				else
				{
					pv_pca->at(elemNum_)->depositMoney();
				}
			}

			break;
		}
		case(WITHDRAWAL_CODE):
		{
			if (pv_pca->empty())
			{
				cerr << '\n' << ERROR << '\n' << endl;

				
				pauseScreen();
				continue;                    // lw mfe4 Continue hy3ml l fuunction 3ady b3d l error 
			}

			field_t ssn;

			cout << '\n' << ENTER_SSN;
			cin >> ws;
			getline(cin, ssn);

			if (ssn == "-1")
			{
				cout << "WELCOME TO Main Menu" ; // don't do anything if the user takes the action of going back
			}
			else
			{
				uint_t elemNum_;

				elemNum_ = findRecord(pv_pca, ssn);

				if (elemNum_ == RECORD_NOT_FOUND)
				{
					cerr << '\n' << ERROR << '\n' << endl;

					pauseScreen();

					continue;
				}
				else
				{
					pv_pca->at(elemNum_)->withdrawMoney();
				}
			}

			break;
		}
		case(VIEW_CODE):
		{
			if (pv_pca->empty())
			{
				cerr << '\n' << ERROR << '\n' << endl;

				pauseScreen();

				continue;
			}

			field_t ssn;

			cout << '\n' << ENTER_SSN;
			cin >> ws;
			getline(cin, ssn);

			if (ssn == "-1")
			{
				; // don't do anything if the user takes the action of going back
			}
			else
			{
				uint_t elemNum_;

				elemNum_ = findRecord(pv_pca, ssn);

				if (elemNum_ == RECORD_NOT_FOUND)
				{
					cerr << '\n' <<"Error !! OR Maybe Your account is closed"<< '\n' << endl;

					pauseScreen();

					continue;
				}
				else
				{
					
					pv_pca->at(elemNum_)->viewAccount();
					
					
				}
			
			}

			break;
		}
		case(ERASE_CODE):
		{
			if (pv_pca->empty())
			{
				cerr << '\n' << ERROR << '\n' << endl;

				pauseScreen();

				continue;
			}

			field_t ssn;

			cout << '\n' << ENTER_SSN;
			cin >> ws;
			getline(cin, ssn);

			if (ssn == "-1")
			{
				; // don't do anything if the user takes the action of going back
			}
			else
			{
				uint_t elemNum_;

				elemNum_ = findRecord(pv_pca, ssn);

				if (elemNum_ == RECORD_NOT_FOUND)
				{
					cerr << '\n' << ERROR << '\n' << endl;

					pauseScreen();

					continue;
				}
				else
				{
					pv_pca->erase(pv_pca->begin() + elemNum_);

					cout << '\n' << RECORD_ERASED << '\n' << endl;

					pauseScreen();
				}
			}

			break;
		}
		case(Save_CODE):
		{
			if (pv_pca->empty())
			{
				cerr << '\n' << "Sorry No accounts ON The System"<< '\n' << endl;

				pauseScreen();

				continue;
			}

			_mkdir("UserData");

			fstream fout;
			field_t fileName, filePath;

			cout << '\n' << "Enter The FIlE Name ";
			cin >> fileName;

			if (fileName == "-1")
			{
				; // don't do anything if the user takes the action of going back
			}
			else
			{
				filePath = "UserData";
				filePath += "\\";
				filePath += fileName;

				fout.open(filePath.c_str(), ios::out | ios::app);

				if (!fout)
				{
					cerr << '\n' << ERROR<< '\n' << endl;
				}
				else
				{
					for (uint_t i = 0; i < pv_pca->size(); ++i)
					{
						if (pv_pca->at(i)->accountNumber() == 1)
						{
							fout << pv_pca->at(i)->typeOfAccount() << '\n';
						}
						else
						{
							fout << '\n' << pv_pca->at(i)->typeOfAccount() << '\n';
						}

						fout << pv_pca->at(i)->accountNumber() << '\n'
							<< pv_pca->at(i)->customerSocial() << '\n'
							<< pv_pca->at(i)->customerFullName() << '\n'
							<< pv_pca->at(i)->customerAddress() << '\n'
							<< pv_pca->at(i)->customerCity() << '\n'
							<< pv_pca->at(i)->customerHomePhone() << '\n'
							<< pv_pca->at(i)->customerWorkPhone() << '\n'
							<< pv_pca->at(i)->customerPinNumber() << '\n'
							<< pv_pca->at(i)->balance() << '\n'
							<< pv_pca->at(i)->mpay_l() << '\n'
							<< pv_pca->at(i)->mcur_l() << '\n'
							<<pv_pca->at(i)->mloan()<<'\n' <<flush;
					}

					cout << '\n' << SAVE_COMPLETED << '\n' << endl;

					fout.close();
				}

				pauseScreen();
			}

			break;
		}
		case(LOAN):
			{
				if (pv_pca->empty())
			{
				cerr << '\n' << ERROR << '\n' << endl;

				pauseScreen();

				continue;
			}
				field_t ssn;
				cout << '\n' << ENTER_SSN;
			cin >> ws;
			getline(cin, ssn);

			if (ssn == "-1")
			{
				; 
			}
			else
			{
				acc_t *acc;
					acc=pv_pca->at(findRecord(pv_pca,ssn));
					acc->show_message();
					acc->set_Loan(acc);
				char g;
				cin>>g;
				g=toupper(g);
				if(g==TRUE)
				{	
					cout<<GET_EMP<<endl;
					int snn;
					cin>>snn;
					if(find_rec(pv_pca2,snn))
					{
				loan_cp* cp=new loan_cp();
				cp->show_message();
				cp->set_Loan(acc);
					}
					else
					{
						cout<<INV_REC<<endl<<GO_BACK;
					}
			
				}
				else
					cout<<GO_BACK<<endl;				
		     	
			}
			break;
			}
		case(PLOAN):
			{
				if (pv_pca->empty())
			{
				cerr << '\n' << ERROR << '\n' << endl;

				pauseScreen();

				continue;
			}
				field_t ssn;
				cout << '\n' << ENTER_SSN;
			cin >> ws;
			getline(cin, ssn);

			if (ssn == "-1")
			{
				; 
			}
			else
			{
				acc_t *acc;
					acc=pv_pca->at(findRecord(pv_pca,ssn));
					acc->show_message();
					acc->set_PayLoan(acc);
				char g;
				cin>>g;
				g=toupper(g);
				if(g==TRUE)
				{	
					cout<<GET_EMP<<endl;
					int snn;
					cin>>snn;
					if(find_rec(pv_pca2,snn))
					{
				loan_cp* cp=new loan_cp();
				cp->show_message();
				cp->set_PayLoan(acc);
			   cout<<acc->mpay_l()<<endl;
					}
					else
					{
						cout<<INV_REC<<endl<<GO_BACK;
					}	
			   	}
				else
					cout<<GO_BACK<<endl;
			   
			}
			break;
			}
		case(VDLoan):
			{
				
				if (pv_pca->empty())
			{
				cerr << '\n' << ERROR << '\n' << endl;

				pauseScreen();

				continue;
			}
				field_t ssn;
				cout << '\n' << ENTER_SSN;
			cin >> ws;
			getline(cin, ssn);

			if (ssn == "-1")
			{
				; 
			}
			else
			{

				acc_t *acc;
					acc=pv_pca->at(findRecord(pv_pca,ssn));
					acc->show_message();
					acc->view_loan(acc);
				char g;
				cin>>g;
				g=toupper(g);
				if(g==TRUE)
				{	
					cout<<GET_EMP<<endl;
					int snn;
					cin>>snn;
				if(find_rec(pv_pca2,snn))
					{
				loan_cp* cp=new loan_cp();
				cp->show_message();
				cp->view_loan(acc);
					}
					else
					{
						cout<<INV_REC<<endl<<GO_BACK;
					}	
					
				
				}
				else
					cout<<GO_BACK<<endl;
			
			}
			break;
			}
		case (EMPLOYEE_CODE):
		{
			Employee emp;
			Employee  e;
			fstream file;
			file.open(fileName, ios::ate | ios::in | ios::out | ios::binary);
			bool isGoBack = (false);
			int  isFound;
			emp.ReadData();
			file.seekg(0, ios::beg);
			isFound = 0;
			file.read((char*)&e, sizeof(e));
			while (!file.eof())
			{
				if (e.GetID() == emp.GetID())
				{
					cout << "This ID already exist…Try for another ID";
					isFound = 1;
					break;
				}
				file.read((char*)&e, sizeof(e));
			}
			if (isFound == 1)
				break;
			file.clear();
			file.seekp(0, ios::end);
			file.write((char*)&emp, sizeof(emp));
			cout << endl << "New record has been added successfully…";
			break;



			

		}
		case(LOAD_FILE_CODE):
		{
			fstream fin;
			field_t fileName;

			accountType_t	typeOfAccount;
			accNum_t		accountNumber,
				            m_cur_l; 
			field_t			customerSocial,
				customerFullName,
				customerAddress,
				customerCity,
				customerHomePhone,
				customerWorkPhone,
				customerPinNumber;
			currency_t		balance,
				            m_loan;            		      
            pay_l           m_pay_l;  
			cout << '\n' << INPUT_FILENAME;
			cin >> fileName;

			if (fileName == "-1")
			{
				; // don't do anything if the user takes the action of going back
			}
			else
			{
				field_t filePath;

				filePath = DATA_DIRECTORY;
				filePath += "\\";
				filePath += fileName;

				fin.open(filePath.c_str(), ios::in);

				if (!fin)
				{
					cerr << '\n' << ERROR<< '\n' << endl;
				}
				else
				{
					while (!fin.eof())
					{
						fin >> typeOfAccount;
						fin >> accountNumber;
						(fin >> ws), getline(fin, customerSocial);
						(fin >> ws), getline(fin, customerFullName);
						(fin >> ws), getline(fin, customerAddress);
						(fin >> ws), getline(fin, customerCity);
						(fin >> ws), getline(fin, customerHomePhone);
						(fin >> ws), getline(fin, customerWorkPhone);
						(fin >> ws), getline(fin, customerPinNumber);
						fin >> balance;
						fin >> m_loan;
						fin >> m_pay_l;
						fin >> m_cur_l;

						// check for duplicate accountNumbers - if duplicate is found, it is excluded
						if (verifyDuplicateEntries(pv_pca, accountNumber) == false)
						{
							if (typeOfAccount == CHECKING_CODE)
							{
								pv_pca->push_back(new CheckingAccount(accountNumber,
									customerSocial, customerFullName, customerAddress,
									customerCity,customerHomePhone, customerWorkPhone, customerPinNumber,
									balance,m_loan,m_pay_l,m_cur_l));
							}
							else
							{
								pv_pca->push_back(new SavingAccount(accountNumber,
									customerSocial, customerFullName, customerAddress,
									customerCity, customerHomePhone, customerWorkPhone, customerPinNumber, balance,m_loan,m_pay_l,m_cur_l));
							}
						}
					}

					cout << '\n' << LOAD_COMPLETED << '\n' << endl;

					fin.close();
				}

				pauseScreen();
			}

			break;
		}
		case (FIND_CODE) : 
		{
			Employee emp, e;
			char option, ch, Dept[50];
			int ID, isFound;
			clearScreen();
			pauseScreen();
			isFound = 0;
			fstream file;
			file.open(fileName, ios::ate | ios::in | ios::out | ios::binary);
			cout << endl << "Enter ID of an employee to be searched : ";
			cin >> ID;
			file.seekg(0, ios::beg);
			file.read((char*)&e, sizeof(e));
			while (!file.eof())
			{
				if (e.GetID() == ID)
				{
					cout << endl << "The record found…."<< endl;
					cout <<  "ID"<<  "Name"  << "Post"  << "Department" << "Salary";
					e.DisplayRecord();
					
					isFound = 1;
					
					break;
				}
				file.read((char*)&e, sizeof(e));
			}
			file.clear();
			if (isFound == 0)
				cout << endl << "Data not found for employee ID#" << ID;
			break;
			
			 }
		default:
		{
			cerr << '\n' << ERROR << '\n' << endl;

			pauseScreen();
		}
		} // end of switch
	} while (myChoice != EXIT_CODE);
}
