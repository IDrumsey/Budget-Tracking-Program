#include "Budget.h"

using namespace std;

int main()
{
	//Initialize systems
	
	vector <IncomeObj> listOfIncomeNodes;
	vector <ExpenseObj> listOfExpenseNodes;

	vector <string> listOfExpenses;
	vector <string> listOfIncome;
	initializeExpenses(listOfExpenses);
	printListOfExpenses(listOfExpenses);

	initializeIncome(listOfIncome);
	printListOfIncome(listOfIncome);

	initializeListsOfNodes(listOfIncomeNodes, listOfExpenseNodes, listOfExpenses, listOfIncome);

	
	int choice;
	while (1)
	{
		cout << "(0)Exit\n(1)Add New Income\n(2)Add to existing Income\n(3)View Income Info\n(4)Add New Expense\n(5)Add to existing Expense\n(6)View Expense Info\n(7)Get Budget Report\nChoice : ";
		cin >> choice;
		cout << "\n";

		switch (choice)
		{
		case 0:
		{
			exit(0);
		}
		case 1:
		{
			addNewIncome(listOfIncome);
			break;
		}
		case 2:
		{
			addExistingIncome(listOfIncome);
			break;
		}
		case 3:
		{
			ViewIncomeInfo(listOfIncome);
			break;
		}
		case 4:
		{
			addNewExpense(listOfExpenses);
			break;
		}
		case 5:
		{
			addExistingExpense(listOfExpenses);
			break;
		}
		case 6:
		{
			ViewExpenseInfo(listOfExpenses);
			break;
		}
		case 7:
		{
			GetBudgetReport(listOfIncomeNodes, listOfExpenseNodes);
			break;
		}
		default:
		{
			cout << "Not a valid choice::Try Again\n";
			break;
		}
		}

		cout << "\n\n";
		system("pause");
		system("cls");
	}

	system("pause");
	return 0;
}