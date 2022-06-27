#include "CardThirteen.h"


int CardThirteen::Price = -1;
int CardThirteen::Fee = -1;
Player* CardThirteen::pPointer = NULL;
CardThirteen::CardThirteen(const CellPosition& pos) :Base10To14(pos)
{
	cardNumber = 13;
	pOwner = NULL;
	cardName = "Thirteen";
	IsBought = false;

}



int CardThirteen::getFee() { return Fee; }
int CardThirteen::getPrice() { return Price; }
void CardThirteen::setFee(int n) { CardThirteen::Fee = n; }
void CardThirteen::setPrice(int n) { CardThirteen::Price = n; }
Player* CardThirteen::getPlayer() { return CardThirteen::pPointer; }
void CardThirteen::setPlayer(Player* p) { CardThirteen::pPointer = p; }
CardThirteen::~CardThirteen(void) {}



void CardThirteen::CopyCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Copying Card " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}




void CardThirteen::CutCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Cutting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}

void CardThirteen::PasteCard(Grid* pGrid)
{
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// to be edited fee and price
	pOut->PrintMessage("Pasting Card  " + to_string(cardNumber));
	CellPosition C1 = pIn->GetCellClicked();
}
