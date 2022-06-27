#include "OpenAction.h"



OpenAction::OpenAction(ApplicationManager*pApp) :Action(pApp)
{
}


void OpenAction::ReadActionParameters()
{
	// Get a Pointer to the Input / Output Interfaces
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();
	pOut->PrintMessage("Enter File Name to Load:");
	Name = pIn->GetSrting(pOut) + ".txt";    // user enter name to open 
	pOut->ClearStatusBar();

}

void OpenAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pOut = pGrid->GetOutput();
	ifstream InFile(Name, ios::in);
	if (InFile.is_open())
	{
		pGrid->CLEARCellList();
		pOut->ClearGridArea();
		pOut->PrintMessage(Name + " is opened");
		int L, S, C;

		InFile >> L;
		for (int i = 0; i < L; i++)
		{

			OBJ = new Ladder();
			OBJ->Read(InFile);
			pGrid->AddObjectToCell(OBJ);
			OBJ->Draw(pOut);

		}
		InFile >> S;
		for (int i = 0; i < S; i++)
		{

			OBJ = new Snake();
			OBJ->Read(InFile);
			pGrid->AddObjectToCell(OBJ);
			OBJ->Draw(pOut);

		}
		InFile >> C;
		for (int i = 0; i < C; i++)
		{
			int type, pos;
			InFile >> type >> pos;
			switch (type)
			{
			case 1:
				OBJ = new CardOne(pos);
				OBJ->Read(InFile);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 2:
				OBJ = new CardTwo(pos);
				OBJ->Read(InFile);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 3:
				OBJ = new CardThree(pos);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 4:
				OBJ = new CardFour(pos);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 5:
				OBJ = new CardFive(pos);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 6:
				OBJ = new CardSix(pos);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 7:
				OBJ = new CardSeven(pos);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 8:
				OBJ = new CardEight(pos);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 9:
				OBJ = new CardNine(pos);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 10:
				OBJ = new CardTen(pos);
				OBJ->Read(InFile);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 11:
				OBJ = new CardEleven(pos);
				OBJ->Read(InFile);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 12:
				OBJ = new CardTwelve(pos);
				OBJ->Read(InFile);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 13:
				OBJ = new CardThirteen(pos);
				OBJ->Read(InFile);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			case 14:
				OBJ = new CardFourteen(pos);
				OBJ->Read(InFile);
				pGrid->AddObjectToCell(OBJ);
				OBJ->Draw(pOut);
				break;
			}
		}
		pGrid->UpdateInterface();
	}
}

OpenAction::~OpenAction()
{
}

