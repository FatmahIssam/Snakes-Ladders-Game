#include "CardTwo.h"
#include "Grid.h"
#include "ApplicationManager.h"

CardTwo::CardTwo(const CellPosition& pos) : Card(pos)
{
	cardNumber = 2;
}

CardTwo::~CardTwo()
{
}




void CardTwo::ReadCardParameters(Grid* pGrid)
{

	Input* pIn = pGrid->GetInput();//
	Output* pOut = pGrid->GetOutput();//

	pOut->PrintMessage("New CardTwo. Enter its wallet value: ");//
	walletvalue= pIn->GetInteger(pOut);
	pOut->ClearStatusBar();




}

void CardTwo::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);//

	pPlayer->SetWallet(pPlayer->GetWallet()+ walletvalue);//



}
void CardTwo::Edit(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price

	pOut->PrintMessage("Enter the amount of money the player will gain.");
	int twalletAmount = pIn->GetInteger(pOut);
	if(twalletAmount <= 0)
        pGrid->PrintErrorMessage("Invalid Values entered for Card Two .");
    else{

	pOut->ClearStatusBar();
    pGrid->PrintErrorMessage("Card succesfully Edited. Player will now get "+ to_string(twalletAmount) + " coins");
	walletvalue = twalletAmount;
}
}

void CardTwo::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardTwo::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardTwo::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}


bool CardTwo::Validate()
{
	if (walletvalue > 0)
		return true;
	else
		return false;

}

void CardTwo::Save(ofstream& OutFile, TYPE CARD)
{
	Card::Save(OutFile, CARD);

	OutFile << endl;
}

void CardTwo::Read(ifstream& Infile)
{
	int w;
	Infile >> w;
	walletvalue = w;
}