#include "CardNine.h"

CardNine::CardNine(const CellPosition& pos):Card(pos)
{

	cardNumber = 9;
}

void CardNine::ReadCardParameters(Grid* pGrid)
{
	
}


void CardNine::Apply(Grid* pGrid, Player* pPlayer)
{
	Card::Apply(pGrid, pPlayer);
	pGrid->PrintErrorMessage("Player will move to cell "+ to_string(MoveToCell.GetCellNum()) );
	pGrid->UpdatePlayerCell(pPlayer, MoveToCell);
}

bool CardNine::Validate(){
return MoveToCell.IsValidCell();

}

void CardNine::Edit(Grid * pGrid){
	pGrid->GetOutput()->PrintMessage("Click on the new cell you want the player to move to.");
	CellPosition C1 =pGrid->GetInput()->GetCellClicked();
	if(C1.IsValidCell()){
            MoveToCell = C1 ; pGrid->PrintErrorMessage("Player will now move to " + to_string(MoveToCell.GetCellNum()) + " if he lands on card 9 . ");
	}else {
		pGrid->PrintErrorMessage("Invalid Entry for Cell .Cell will remain "+to_string(MoveToCell.GetCellNum()));
	}
    }

void CardNine::Save(ofstream& OutFile, TYPE CARD)
{
	OutFile << endl;
}

void CardNine::Read(ifstream& Infile)
{
	int type, position;
	CellPosition p;
	Infile >> type >> position;
	Card::SetCardNumber(type);
	GameObject::position = p.GetCellPositionFromNum(position);
}


CardNine:: ~CardNine()
{
}
