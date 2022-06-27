#include "Snake.h"



Snake::Snake()
{
}

Snake::Snake(const CellPosition & startCellPos, const CellPosition & endCellPos) : GameObject(startCellPos)
{
	this->endCellPos = endCellPos;
	StartCell= startCellPos;

}

void Snake::Draw(Output * pOut) const
{
	pOut->DrawSnake(position, endCellPos);
}

void Snake::Apply(Grid * pGrid, Player * pPlayer)
{
	Output* pOut = pGrid->GetOutput();

	pOut->PrintMessage("You have reached a Snake . Click to continue ...");



		pGrid->UpdatePlayerCell(pPlayer, endCellPos);
	
}

void Snake::Save(ofstream & OutFile, TYPE SNAKE)
{
	OutFile << GameObject::position.GetCellNum() << "\t" << endCellPos.GetCellNum() << endl;
}

void Snake::Read(ifstream & Infile)
{
	int start, end;
	CellPosition s, e;
	Infile >> start >> end;
	GameObject::position = s.GetCellPositionFromNum(start);
	endCellPos = e.GetCellPositionFromNum(end);
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

CellPosition Snake::GetStartPosition() const
{
	return StartCell;
}

Snake::~Snake()
{
}
