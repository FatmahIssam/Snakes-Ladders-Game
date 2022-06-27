#include "CardEleven.h"


int CardEleven::Price = -1;
int CardEleven::Fee = -1;
Player* CardEleven::pPointer = NULL;
CardEleven::CardEleven(const CellPosition& pos) :Base10To14(pos)
{
	cardNumber = 11;
	pOwner = NULL;
	cardName = "Eleven";
	IsBought = false;

}


int CardEleven::getFee() { return CardEleven::Fee; }
int CardEleven::getPrice() { return CardEleven::Price; }
void CardEleven::setFee(int n) { CardEleven::Fee = n; }
void CardEleven::setPrice(int n) { CardEleven::Price = n; }
Player* CardEleven::getPlayer() { return CardEleven::pPointer; }
void CardEleven::setPlayer(Player* p) { CardEleven::pPointer = p; }
void CardEleven::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardEleven::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardEleven::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}


CardEleven::~CardEleven(void)
{
}
