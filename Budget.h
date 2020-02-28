#pragma once

#include "IncomeObj.h"

using namespace std;

void initializeExpenses(std::vector<std::string>& listOfExpenses);

void addNewExpense(vector<string>& listOfExpenses);

void printListOfExpenses(vector<string>listOfExpenses);

void addExistingExpense(vector<string>listOfExpenses);

void printSingleExpenseFile(string nameOfExpense);

string loadTextFromFile(string path);//Not being used right now

void ViewExpenseInfo(vector<string>listOfExpenses);

///////////////////////////////////////////////////////////////////////

void initializeIncome(std::vector<std::string>& listOfIncome);

void printListOfIncome(vector<string>listOfIncome);

void addNewIncome(vector<string>& listOfIncome);

void addExistingIncome(vector<string>listOfIncome);

void printSingleIncomeFile(string nameOfIncome);

void ViewIncomeInfo(vector<string>listOfIncome);

/////////////////////////////////////////////////////////////////

void initializeListsOfNodes(vector <IncomeObj>& listOfIncomeNodes, vector <ExpenseObj>& listOfExpenseNodes, vector <string>& listOfExpenses, vector <string>& listOfIncome);

void GetBudgetReport(vector <IncomeObj> listOfIncomeNodes, vector <ExpenseObj> listOfExpenseNodes);


