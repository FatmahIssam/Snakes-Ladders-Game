#include "Grid.h"

#include "Cell.h"
#include "Ladder.h"
#include "Card.h"
#include "Snake.h"
#include "Player.h"


Grid::Grid(Input * pIn, Output * pOut) : pIn(pIn), pOut(pOut) // Initializing pIn, pOut
{
	// Allocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) // to allocate cells from bottom up
	{
		for (int j = 0; j < NumHorizontalCells; j++) // to allocate cells from left to right
		{
			CellList[i][j] = new Cell(i, j);
		}
	}

	// Allocate thePlayer Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		PlayerList[i] = new Player(CellList[NumVerticalCells-1][0], i); // first cell
		PlayerList[i]->Draw(pOut); // initially draw players in the first cell
	}

	// Initialize currPlayerNumber with 0 (first player)
	currPlayerNumber = 0; // start with the first player

	// Initialize Clipboard with NULL
	Clipboard = NULL;

	// Initialize endGame with false
	endGame = false;
}


// ========= Adding or Removing GameObjects to Cells =========


bool Grid::AddObjectToCell(GameObject * pNewObject)  // think if any validation is needed
{
	// Get the cell position of pNewObject
	CellPosition pos = pNewObject->GetPosition() ;
	if (pos.IsValidCell()) // Check if valid position
	{
		// Get the previous GameObject of the Cell
		GameObject * pPrevObject = CellList[pos.VCell()][pos.HCell()]->GetGameObject();
		if( pPrevObject)  // the cell already contains a game object
			return false; // do NOT add and return false

		// Set the game object of the Cell with the new game object
		CellList[pos.VCell()][pos.HCell()]->SetGameObject(pNewObject);
		return true; // indicating that addition is done
	}
	
	return false; // if not a valid position
}

void Grid::RemoveObjectFromCell(const CellPosition & pos)
{
	if (pos.IsValidCell()) // Check if valid position
	{
		// Note: you can deallocate the object here before setting the pointer to null if it is needed
		CellList[pos.VCell()][pos.HCell()]->DeleteGameObject();
	}
}

void Grid::CLEARCellList()
{
	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasLadder() || CellList[i][j]->HasSnake() || CellList[i][j]->HasCard())
			{
				Grid::RemoveObjectFromCell(CellList[i][j]->GetCellPosition());
			}
		}
	}
}

void Grid::UpdatePlayerCell(Player * player, const CellPosition & newPosition)
{
	// Clear the player's circle from the old cell position
	player->ClearDrawing(pOut);

	// Set the player's CELL with the new position
	Cell * newCell = CellList[newPosition.VCell()][newPosition.HCell()];
	player->SetCell(newCell);	

	// Draw the player's circle on the new cell position
	player->Draw(pOut);
}


// ========= Setters and Getters Functions =========


Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

void Grid::SetClipboard(Card * pCard) // to be used in copy/cut
{
	// you may update slightly in implementation if you want (but without breaking responsibilities)
	Clipboard = pCard;
}

Card * Grid::GetClipboard() const // to be used in paste
{
	return Clipboard;
}

void Grid::SetEndGame(bool endGame)
{
	this->endGame = endGame;
}

bool Grid::GetEndGame() const
{
	return endGame;
}

void Grid::AdvanceCurrentPlayer()
{
	currPlayerNumber = (currPlayerNumber + 1) % MaxPlayerCount; // this generates value from 0 to MaxPlayerCount - 1
}

// ========= Other Getters =========


Player * Grid::GetCurrentPlayer() const
{
	return PlayerList[currPlayerNumber];
}

void Grid::StartNewGame() {
	for (int i = 0; i < MaxPlayerCount; i++) {
		PlayerList[i]->SetPlayerToOrigin(this);
		PlayerList[i]->SetWallet(100);
		PlayerList[i]->SetTurnCount(0);
	}
	currPlayerNumber = 0;
}

Ladder * Grid::GetNextLadder(const CellPosition & position)
{
	
	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if (CellList[i][j]->HasLadder())
			{
				return CellList[i][j]->HasLadder();
				
			}


			///TODO: Check if CellList[i][j] has a ladder, if yes return it
			

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

Snake* Grid::GetNextSnake(const CellPosition& position)
{

	int startH = position.HCell(); // represents the start hCell in the current row to search for the ladder in
	for (int i = position.VCell(); i >= 0; i--) // searching from position.vCell and ABOVE
	{
		for (int j = startH; j < NumHorizontalCells; j++) // searching from startH and RIGHT
		{
			if (CellList[i][j]->HasSnake())
			{
				return CellList[i][j]->HasSnake();
				
			}

			///TODO: Check if CellList[i][j] has a ladder, if yes return it

		}
		startH = 0; // because in the next above rows, we will search from the first left cell (hCell = 0) to the right
	}
	return NULL; // not found
}

GameObject* Grid::GetGameObject(const CellPosition& position)const 
{



	return CellList[position.VCell()][position.HCell()]->GetGameObject();


}


// ========= User Interface Functions =========


void Grid::UpdateInterface() const
{
	if (UI.InterfaceMode == MODE_DESIGN)
	{
		// 1- Draw cells with or without cards 
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawCellOrCard(pOut);
			}
		}

		// 2- Draw other cell objects (ladders, snakes)
		for (int i = NumVerticalCells-1; i >= 0 ; i--) // bottom up
		{
			for (int j = 0; j < NumHorizontalCells; j++) // left to right
			{
				CellList[i][j]->DrawLadderOrSnake(pOut);
			}
		}

		// 3- Draw players
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->Draw(pOut);
		}
	}
	else // In PLAY Mode
	{
		// 1- Print Player's Info
		string playersInfo = "";
		for (int i = 0; i < MaxPlayerCount; i++)
		{
			PlayerList[i]->AppendPlayerInfo(playersInfo); // passed by reference
			if (i < MaxPlayerCount-1) // except the last player
				playersInfo += ", ";
		}
		playersInfo += " | Curr = " + to_string(currPlayerNumber);

		pOut->PrintPlayersInfo(playersInfo);

		// Note: UpdatePlayerCell() function --> already update drawing players in Play Mode
		//       so we do NOT need draw all players again in UpdateInterface() of the Play mode
		// In addition, cards/snakes/ladders do NOT change positions in Play Mode, so need to draw them here too
	}
}

void Grid::PrintErrorMessage(string msg)
{
	pOut->PrintMessage(msg);
	int x, y;
	pIn->GetPointClicked(x, y);
	pOut->ClearStatusBar();
}



bool Grid::ValidateLadder(CellPosition start, CellPosition end)
{
	

	if (!start.IsValidCell())
	{
		pOut->PrintMessage("Check ladder specification ...");
		return false;
	}
	else if (start.VCell() == 0)
	{
		pOut->PrintMessage("Check ladder specification ...");
		return false;
	}
	else if (!end.IsValidCell())
	{
		pOut->PrintMessage("Check ladder specification ...");
		return false;

	}
	else if (end.VCell() > start.VCell())
	{
		pOut->PrintMessage("End cell cannot be greater than start cell");
		return false;

	}
	else if (start.HCell() != end.HCell())
	{
		pOut->PrintMessage("End cell and start cell are not in the same column");
		return false;

	}

	Cell* c1 = CellList[end.VCell()][end.HCell()];
	Cell* c2 = CellList[start.VCell()][start.HCell()];

	if (c1->HasSnake() || c2->HasSnake() || c1->HasLadder() || c2->HasLadder())
	{
		pOut->PrintMessage("End cell cannot be a start of another ladder or snake");
		return false;
	}
	for (int i = 0; i < NumVerticalCells; i++)
	{
		Cell* x = CellList[i][end.HCell()];
		if (x->HasLadder()) {
			Ladder* l = x->HasLadder();
			CellPosition ladderStartPos = l->GetStartPosition();
			CellPosition ladderEndPos = l->GetEndPosition();
			if ((end.VCell() < ladderStartPos.VCell() && end.VCell() > ladderEndPos.VCell()) || (start.VCell() < ladderStartPos.VCell() && start.VCell() > ladderEndPos.VCell()))
			{
				pOut->PrintMessage("Two ladders cannot overlap");
				return false;
			}
			else if (end.VCell() < ladderEndPos.VCell() || start.VCell() > ladderStartPos.VCell()) {
				pOut->PrintMessage("Two ladders cannot overlap");
				return false;
			}
			else if (start.VCell() == ladderEndPos.VCell()) {
				pOut->PrintMessage("End cell cannot be a start of another ladder or snake");
				return false;
			}
			else if (end.VCell() == ladderStartPos.VCell() && end.HCell() == ladderStartPos.HCell())
			{
				pOut->PrintMessage("Two ladders cannot overlap");
				return false;
			}
		}
	}
	return true;

}

bool Grid::ValidateSnake(CellPosition start, CellPosition end)
{
	if (!start.IsValidCell())
	{
		pOut->PrintMessage("Check Snake specification ...");
		return false;
	}
	else if (start.VCell() == 8)
	{
		pOut->PrintMessage("Check Snake specification ...");
		return false;

	}
	else if (!end.IsValidCell())
	{
		pOut->PrintMessage("Check Snake specification ...");
		return false;

	}
	else if (end.VCell() < start.VCell())
	{
		pOut->PrintMessage("End cell cannot be less than start cell");
		return false;

	}
	else if (start.HCell() != end.HCell())
	{
		pOut->PrintMessage("End cell and start cell are not in the same column");
		return false;
	}
	Cell* c1 = CellList[end.VCell()][end.HCell()];
	Cell* c2 = CellList[start.VCell()][start.HCell()];

	if (c1->HasLadder() || c2->HasLadder() || c1->HasSnake() || c2->HasSnake())
	{
		pOut->PrintMessage("End cell cannot be a start of another ladder or snake");
		return false;
	}
	for (int i = 0; i < NumVerticalCells; i++)
	{
		Cell* x = CellList[i][end.HCell()];
		if (x->HasSnake()) {
			Snake* s = x->HasSnake();
			CellPosition SnakeStartPos = s->GetStartPosition();
			CellPosition SnakeEndPos = s->GetEndPosition();
			if ((end.VCell() > SnakeStartPos.VCell() && end.VCell() < SnakeEndPos.VCell()) || (start.VCell() > SnakeStartPos.VCell() && start.VCell() < SnakeEndPos.VCell()))
			{
				pOut->PrintMessage("Two snakes cannot overlap ");
				return false;
			}
			else if (end.VCell() > SnakeEndPos.VCell() || start.VCell() < SnakeStartPos.VCell()) {
				pOut->PrintMessage("Two snakes cannot overlap ");
				return false;
			}
			else if (start.VCell() == SnakeEndPos.VCell()) {
				pOut->PrintMessage("End cell cannot be a start of another ladder or snake");
				return false;
			}
			else if (end.VCell() == SnakeStartPos.VCell() && end.HCell() == SnakeStartPos.HCell())
			{
				pOut->PrintMessage("Two snakes cannot overlap ");
				return false;
			}

		}
	}
	return true;
}


void Grid::SaveAll(ofstream & OutFile, TYPE a)
{
	GameObject * OBJ;
	if (a == LADDER)
	{ 
		OutFile << LC << endl;
		for (int i = NumVerticalCells - 1; i >= 0; i--) 
		{
			for (int j = 0; j < NumHorizontalCells; j++) 
			{
				if (CellList[i][j]->HasLadder())
				{
					
					OBJ = CellList[i][j]->GetGameObject();
					OBJ->Save(OutFile, a);
				}
			}
		}
	}
	else if (a == SNAKE)
	{
		OutFile << SC << endl;
		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				if (CellList[i][j]->HasSnake())
				{

					OBJ = CellList[i][j]->GetGameObject();
					OBJ->Save(OutFile, a);
				}
			}
		}
	}
	else if (a == CARD)
	{
		OutFile << CC << endl;
		for (int i = NumVerticalCells - 1; i >= 0; i--)
		{
			for (int j = 0; j < NumHorizontalCells; j++)
			{
				if (CellList[i][j]->HasCard())
				{

					OBJ = CellList[i][j]->GetGameObject();
					OBJ->Save(OutFile, a);
				}
			}
		}
	}
}


void Grid::CountNumber()
{
	LC = 0;
	SC = 0;
	CC = 0;

	for (int i = NumVerticalCells - 1; i >= 0; i--)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (CellList[i][j]->HasLadder())
			{
				LC++;
			}
			else if (CellList[i][j]->HasSnake())
			{
				SC++;
			}
			else if (CellList[i][j]->HasCard())
			{
				CC++;
			}
		}
	}
}




Grid::~Grid()
{
	delete pIn;
	delete pOut;

	// Deallocate the Cell Objects of the CellList
	for (int i = NumVerticalCells-1; i >= 0 ; i--) 
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			delete CellList[i][j];
		}
	}

	// Deallocate the Player Objects of the PlayerList
	for (int i = 0; i < MaxPlayerCount; i++) 
	{
		delete PlayerList[i];
	}
}