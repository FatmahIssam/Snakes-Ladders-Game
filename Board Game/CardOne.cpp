#include "CardOne.h"
#include "Grid.h"
#include "ApplicationManager.h"

CardOne::CardOne(const CellPosition & pos) : Card(pos) // set the cell position of the card
{
	cardNumber = 1; // set the inherited cardNumber data member with the card number (1 here)
}

CardOne::~CardOne(void)
{
}

void CardOne::ReadCardParameters(Grid * pGrid)
{

    Input*pIn=pGrid->GetInput();//
	Output*pOut=pGrid->GetOutput();//

	pOut->PrintMessage("New CardOne. Enter its wallet amount: ");//
	walletAmount=pIn->GetInteger(pOut);//
	pIn->GetCellClicked();//
	pOut->ClearStatusBar();//



	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==


	// 1- Get a Pointer to the Input / Output Interfaces from the Grid

	// 2- Read an Integer from the user using the Input class and set the walletAmount parameter with it
	//    Don't forget to first print to a descriptive message to the user like:"New CardOne: Enter its wallet amount ..."


	// [ Note ]:
	// In CardOne, the only parameter of CardOne is the "walletAmount" value to decrease from player
	// Card parameters are the inputs you need to take from the user in the time of adding the Card in the grid
	// to be able to perform his Apply() action

	// 3- Clear the status bar

}

void CardOne::Apply(Grid* pGrid, Player* pPlayer)
{

	Card::Apply(pGrid, pPlayer);//
	pPlayer->SetWallet(pPlayer->GetWallet()-walletAmount);//
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below


	// == Here are some guideline steps (numbered below) (numbered below) to implement this function ==

	// 1- Call Apply() of the base class Card to print the message that you reached this card number

	// 2- Decrement the wallet of pPlayer by the walletAmount data member of CardOne

}

void CardOne::Edit(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price

	pOut->PrintMessage("Enter the amount of money the player will lose.");
	int twalletAmount = pIn->GetInteger(pOut);
	if(twalletAmount <= 0)
        pGrid->PrintErrorMessage("Invalid Values entered for Card One .");
    else{

	pOut->ClearStatusBar();
    pGrid->PrintErrorMessage("Card succesfully Edited. Player will now lose "+ to_string(twalletAmount)+" coins.");
	walletAmount = twalletAmount;
}
}

void CardOne::CopyCard(Grid* pGrid)
{
}

void CardOne::CutCard(Grid* pGrid)
{
}

void CardOne::PasteCard(Grid* pGrid)
{
}

bool CardOne::Validate()
{
	if (walletAmount > 0)
		return true;
	else
		return false;
}

void CardOne::Save(ofstream& OutFile, TYPE CARD)
{
	Card::Save(OutFile, CARD);
	OutFile << endl;
}

void CardOne::Read(ifstream& Infile)
{
	int w;
	Infile >> w;
	walletAmount = w;
}