#include "Card.h"
#include "Output.h"
#include <iostream>
using namespace std;
#include <iomanip>
#include <string>
#include <fstream>




Card::Card()
{
}

Card::Card(const CellPosition& pos) : GameObject(pos) // sets the cell position of the GameObject
{
	position = pos;//
}

void Card::SetCardNumber(int cnum)
{
	if (cnum > 0 && cnum <= 14)//
		cardNumber = cnum;// needs validation

}

int Card::GetCardNumber()
{
	return cardNumber;
}

void Card::Draw(Output* pOut) const
{

	pOut->DrawCell(position, cardNumber);//
	///TODO: call the appropriate Ouput function that draws a cell containing the "cardNumber" in "position"


}

void Card::ReadCardParameters(Grid* pGrid)
{
	//....................(pGrid)
	// we should not make it pure virtual because some Cards doesn't have parameters
	// and if we make it pure virtual, that will make those Cards abstract classes
}

void Card::Apply(Grid* pGrid, Player* pPlayer)
{
	// As written below the "Roll Dice" action in the document ==> Check the Project Document
	// "If a player reaches a card of any other type", the following message should be printed then wait mouse click

	pGrid->PrintErrorMessage("You have reached card " + to_string(cardNumber) + ". Click to continue ...");
}


void Card::Save(ofstream& OutFile, TYPE CARD)
{
	OutFile << cardNumber << "\t" << GameObject::position.GetCellNum() << "\t";
}

//void Card::Read(ifstream& Infile)
//{
//
//}

bool Card::Validate() {
	return true;
}

void Card::Edit(Grid* pGrid)
{
	pGrid->PrintErrorMessage(" This card cannot be edited");
}

void Card::CopyCard(Grid* pGrid)
{
	pGrid->PrintErrorMessage(" Card cannot be copied");
}

void Card::CutCard(Grid* pGrid)
{
	pGrid->PrintErrorMessage("Card cannot be cut");
}

void Card::PasteCard(Grid* pGrid)
{
	pGrid->PrintErrorMessage("Card cannot be pasted");
}

Card::~Card()
{
}
