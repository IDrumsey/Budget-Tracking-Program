#include "Budget.h"
#include <iostream>

using namespace std;

void initializeExpenses(vector<string>& listOfExpenses)
{
	ifstream ExpensesFile("..//BudgetTracking//Expenses.txt");
	if (ExpensesFile.fail())
	{
		cout << "Expense File failed to open\n";
	}
	else
	{
		string temp;

		while (!ExpensesFile.eof())
		{
				getline(ExpensesFile, temp);
				if (temp != "")
				{
					listOfExpenses.push_back(temp);
				}
		}

	}
}

void addNewExpense(vector<string>& listOfExpenses)
{
	ofstream NewExpense;
	string ExpenseName;
	cout << "Name of Expense : ";
	cin.ignore();
	getline(cin, ExpenseName);

	listOfExpenses.push_back(ExpenseName);
	NewExpense.open("..//BudgetTracking//Expenses//" + ExpenseName + ".txt");
	if (NewExpense.fail())
	{
		cout << "Failed to create new Expense file\n";
		return;
	}
	else NewExpense.close();



	NewExpense.open("..//BudgetTracking//Expenses.txt", std::ios_base::app);
	if (NewExpense.fail())
	{
		cout << "Failed to open Expenses File #1001\n";
		return;
	}
	else
	{
		NewExpense << ExpenseName << endl;
	}
	NewExpense.close();
}

void printListOfExpenses(vector<string>listOfExpenses)
{
	if (listOfExpenses.empty() == 1)
	{
		cout << "You currently have no Expenses!\n";
	}
	else
	{
		cout << "Expenses : ";
		for (int i = 0; i < listOfExpenses.size(); i++)
		{
			if (i < listOfExpenses.size() - 1)
			{
				cout << listOfExpenses[i] << ", ";
			}
			else
			{
				cout << listOfExpenses[i] << endl;
			}
		}
	}
}

void addExistingExpense(vector<string>listOfExpenses)
{
	string choice;
	for (int i = 0; i < listOfExpenses.size(); i++)
	{
		cout << listOfExpenses[i] << endl;
	}

	cout << "\nIn which category would you like to add a value? : ";
	cin >> choice;

	printSingleExpenseFile(choice);

	string date, item;
	float cost;

	

	ofstream Expense("..//BudgetTracking//Expenses//" + choice + ".txt",  std::ios_base::app);
	bool fileExists = 0;
	string temp;
	for (int i = 0; i < listOfExpenses.size(); i++)
	{
		temp = listOfExpenses[i];
		if (temp == choice)
		{
			fileExists = 1;
		}
	}
	if (fileExists == 0)
	{
		cout << "Invalid Expense!\n";
	}
	else
	{
		cout << "Date: ";
		cin.ignore();
		getline(cin, date);

		cout << "Item: ";
		getline(cin, item);

		cout << "Cost: ";
		cin >> cost;
		Expense << "Date: " << date << endl;
		Expense << "Item: " << item << endl;
		Expense << "Cost: " << cost << endl << endl;
	}
	Expense.close();
}

void printSingleExpenseFile(string nameOfExpense)
{
	ifstream file("..//BudgetTracking//Expenses//" + nameOfExpense + ".txt");
	string temp;
	if (file.fail())
	{
		cout << "Failed to open an Expense file!\n";
		return;
	}
	else
	{
		cout << "\n---------- " << nameOfExpense << " Expenses ----------" << "\n";
		while (!file.eof())
		{
			getline(file, temp);
			cout << temp << endl;
		}
	}
}

//KEEP FOR NOW JUST IN CASE
string loadTextFromFile(string path)
{
	string fileContents = "";
	ifstream loadContentsfromFile(path + ".txt");

	if (loadContentsfromFile.fail())
	{
		cout << "Failed to open file to read from\n";
	}
	else
	{
		string temp = "";
		while (!loadContentsfromFile.eof())
		{
			cout << "check\n";//DEBUG
			getline(loadContentsfromFile, temp);
			fileContents += temp;
			cout << "fileContents : " << fileContents << endl;//DEBUG
		}
	}

	return fileContents;
}

void ViewExpenseInfo(vector<string> listOfExpenses)
{
	int choice;
	cout << "(1)View all Expense info\n(2)View Single Expense info\nChoice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		for (int i = 0; i < listOfExpenses.size(); i++)
		{
			printSingleExpenseFile(listOfExpenses[i]);
		}
		break;
	}
	case 2:
	{
		string ExpenseName;
		for (int i = 0; i < listOfExpenses.size(); i++)
		{
			cout << listOfExpenses[i] << endl;
		}

		cout << "\nIn which category would you like to add a value? : ";
		cin >> ExpenseName;

		printSingleExpenseFile(ExpenseName);
		break;
	}
	default:
		cout << "Not a valid choice\n";
		break;
	}
}

void initializeIncome(std::vector<std::string>& listOfIncome)
{
	ifstream IncomeFile("..//BudgetTracking//Income.txt");
	if (IncomeFile.fail())
	{
		cout << "Expense File failed to open\n";
	}
	else
	{
		string temp;

		while (!IncomeFile.eof())
		{
			getline(IncomeFile, temp);
			if (temp != "")
			{
				listOfIncome.push_back(temp);
			}
		}

	}
}

void printListOfIncome(vector<string> listOfIncome)
{
	if (listOfIncome.empty() == 1)
	{
		cout << "You currently have no Income!\n";
	}
	else
	{
		cout << "Income : ";
		for (int i = 0; i < listOfIncome.size(); i++)
		{
			if (i < listOfIncome.size() - 1)
			{
				cout << listOfIncome[i] << ", ";
			}
			else
			{
				cout << listOfIncome[i] << endl;
			}
		}
	}
}

void addNewIncome(vector<string>& listOfIncome)
{
	ofstream NewIncome;
	string IncomeName;
	cout << "Name of Income : ";
	cin.ignore();
	getline(cin, IncomeName);

	listOfIncome.push_back(IncomeName);
	NewIncome.open("..//BudgetTracking//Income//" + IncomeName + ".txt");
	if (NewIncome.fail())
	{
		cout << "Failed to create new Income file\n";
		return;
	}
	else NewIncome.close();


	NewIncome.open("..//BudgetTracking//Income.txt", std::ios_base::app);
	if (NewIncome.fail())
	{
		cout << "Failed to open Expenses File #1001\n";
		return;
	}
	else
	{
		NewIncome << IncomeName << endl;
	}
	NewIncome.close();
}

void addExistingIncome(vector<string> listOfIncome)
{
	string choice;
	for (int i = 0; i < listOfIncome.size(); i++)
	{
		cout << listOfIncome[i] << endl;
	}

	cout << "\nIn which category would you like to add a value? : ";
	cin >> choice;

	printSingleIncomeFile(choice);

	float amount;
	string date;


	ofstream Income("..//BudgetTracking//Income//" + choice + ".txt", std::ios_base::app);
	bool fileExists = 0;
	string temp;
	for (int i = 0; i < listOfIncome.size(); i++)
	{
		temp = listOfIncome[i];
		if (temp == choice)
		{
			fileExists = 1;
		}
	}
	if (fileExists == 0)
	{
		cout << "Invalid Income!\n";
	}
	else
	{
		cout << "Date: ";
		cin.ignore();
		getline(cin, date);
		cout << "Amount: ";
		cin >> amount;
		Income << "Date: " << date << endl;
		Income << "Amount: " << amount << endl << endl;
	}
	Income.close();
}

void printSingleIncomeFile(string nameOfIncome)
{
	ifstream file("..//BudgetTracking//Income//" + nameOfIncome + ".txt");
	string temp;
	if (file.fail())
	{
		cout << "Failed to open an Income file!\n";
		return;
	}
	else
	{
		cout << "\n---------- " << nameOfIncome << " Income ----------" << "\n";
		while (!file.eof())
		{
			getline(file, temp);
			cout << temp << endl;
		}
	}
}

void ViewIncomeInfo(vector<string> listOfIncome)
{
	int choice;
	cout << "(1)View all Income info\n(2)View Single Income info\nChoice : ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		for (int i = 0; i < listOfIncome.size(); i++)
		{
			printSingleIncomeFile(listOfIncome[i]);
		}
		break;
	}
	case 2:
	{
		string IncomeName;
		for (int i = 0; i < listOfIncome.size(); i++)
		{
			cout << listOfIncome[i] << endl;
		}

		cout << "\nIn which category would you like to add a value? : ";
		cin >> IncomeName;

		printSingleIncomeFile(IncomeName);
		break;
	}
	default:
		cout << "Not a valid choice\n";
		break;
	}
}

void initializeListsOfNodes(vector<IncomeObj>& listOfIncomeNodes, vector<ExpenseObj>& listOfExpenseNodes, vector <string>& listOfExpenses, vector <string>& listOfIncome)
{
	ifstream CurrentFile;
	int counter;
	string temp;
	int temp_amount;
	bool readDate = 0;
	bool readAmount = 0;
	IncomeObj* newIncome = new IncomeObj();

	for (counter = 0; counter < listOfIncome.size(); counter++)
	{
		CurrentFile.open("..//BudgetTracking//Income//" + listOfIncome[counter] + ".txt");//Opening Income File
		if (CurrentFile.fail())
		{
			cout << "Could not open..//BudgetTracking//Income//" << listOfIncome[counter] << ".txt\n";
		}
		else
		{
			while (CurrentFile >> temp)
			{			
				if (readAmount)
				{
					readAmount = 0;
					newIncome->amountRecieved = atof(temp.c_str());
					newIncome->Source = listOfIncome[counter];
					listOfIncomeNodes.push_back(*newIncome);
				}
				else if (readDate)
				{
					readDate = 0;
					newIncome->dateRecieved = temp;
				}
				if (temp == "Date:") readDate = 1;
				else if (temp == "Amount:")readAmount = 1;
			}
		}
		CurrentFile.close();
	}
	delete newIncome;



	ExpenseObj* newExpense = new ExpenseObj();
	for (counter = 0; counter < listOfExpenses.size(); counter++)
	{
				CurrentFile.open("..//BudgetTracking//Expenses//" + listOfExpenses[counter] + ".txt");//Opening Income File
				if (CurrentFile.fail())
				{
					cout << "Could not open..//BudgetTracking//Expenses//" << listOfExpenses[counter] << ".txt\n";
				}
				else
				{
					while (CurrentFile >> temp)
					{
						


						if (readAmount)
						{
							readAmount = 0;
							newExpense->amountOfPurchase = atof(temp.c_str());
							newExpense->Source = listOfExpenses[counter];
							listOfExpenseNodes.push_back(*newExpense);
						}
						else if (readDate)
						{
							readDate = 0;
							newExpense->dateOfPurchase = temp;
						}
						if (temp == "Date:") readDate = 1;
						else if (temp == "Cost:")readAmount = 1;

					}
				}
				CurrentFile.close();
	}
	
}

void GetBudgetReport(vector<IncomeObj> listOfIncomeNodes, vector<ExpenseObj> listOfExpenseNodes)
{
	system("cls");
	cout << "Budget Report\n";
	
	float totalIncome = findTotalIncome(listOfIncomeNodes);
	float totalExpense = findTotalExpenses(listOfExpenseNodes);

	cout << "Total Income   : " << totalIncome << endl;
	cout << "Total Expenses : " << totalExpense << "\n\n";

	cout << "Avg Income : " << findAvgIncome(totalIncome, listOfIncomeNodes.size()) << endl;
	cout << "Avg Expenses : " << findAvgExpense(totalExpense, listOfExpenseNodes.size()) << "\n\n";

	cout << "Case Flow :" << totalIncome - totalExpense << "\n\n";
	cout << "Expense Ratio : " << totalExpense / totalIncome << "\n\n";
	
}

float findTotalExpenses(vector<ExpenseObj> listOfExpenseNodes)
{
	float total = 0;
	for (int i = 0; i < listOfExpenseNodes.size(); i++)
	{
		total += listOfExpenseNodes[i].amountOfPurchase;
	}

	return total;
}

float findTotalIncome(vector<IncomeObj> listOfIncomeNodes)
{
	float total = 0;
	for (int i = 0; i < listOfIncomeNodes.size(); i++)
	{
		cout << "DEBUG : " << listOfIncomeNodes[i].amountRecieved << endl;
		total += listOfIncomeNodes[i].amountRecieved;
	}

	return total;
}

float findAvgIncome(float total, int numOfNodes)
{
	return total / numOfNodes;
}

float findAvgExpense(float total, int numOfNodes)
{
	return total / numOfNodes;
}

void cleanVector(vector<IncomeObj>& listOfIncomeNodes, vector<ExpenseObj>& listOfExpenseNodes)
{
	listOfIncomeNodes.clear();
	listOfExpenseNodes.clear();
}



