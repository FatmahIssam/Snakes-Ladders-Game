#include "SaveAction.h"
#include "Output.h"
#include "Input.h"
#include "ApplicationManager.h"
#include "Grid.h"
#include <fstream>
#include "AddSnakeAction.h"


SaveAction::SaveAction(ApplicationManager*pApp) :Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Please enter the file name ");
	FileName = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
}

void SaveAction::Execute()
{
	ReadActionParameters();
	Grid *pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ofstream OutFile(FileName, ios::out);
	if (OutFile.is_open())
	{
		pOut->PrintMessage(FileName + " is saved");
		pGrid->CountNumber();
		pGrid->SaveAll(OutFile, LADDER);
		pGrid->SaveAll(OutFile, SNAKE);
		pGrid->SaveAll(OutFile, CARD);

	}
	else
		pOut->PrintMessage("Error, Cannot open the file");

	OutFile.close();
}

SaveAction::~SaveAction()
{
}

