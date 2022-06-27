#include "Player.h"
#include "GameObject.h"

Player::Player(Cell * pCell, int playerNum) : stepCount(0), wallet(100), playerNum(playerNum)
{
	this->pCell = pCell;
	this->turnCount = 0;
	ZeroRoll = false ;

	// Make all the needed initialization or validations
}

// ====== Setters and Getters ======
void Player::SetZeroRoll(bool Val){
	ZeroRoll = Val ;
}
void Player::SetTurnCount(int n )
{
	turnCount = n ;
}
void Player::SetCell(Cell * cell)
{
	pCell = cell;
}

Cell* Player::GetCell() const
{
	return pCell;
}

void Player::SetWallet(int wallet)
{
	if(wallet < 0) return;
	this->wallet = wallet;
	// Make any needed validations
}

int Player::GetWallet() const
{
	return wallet;
}

int Player::GetTurnCount() const
{
	return turnCount;
}



int Player::GetLastRolledDice() const
{
return justRolledDiceNum ;
}
// ====== Drawing Functions ======

void Player::Draw(Output* pOut) const
{
	color playerColor = UI.PlayerColors[playerNum];

	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,playerColor);
	///TODO: use the appropriate output function to draw the player with "playerColor"

}

void Player::ClearDrawing(Output* pOut) const 
{
	color cellColor = pCell->HasCard() ? UI.CellColor_HasCard : UI.CellColor_NoCard;
	pOut->DrawPlayer(pCell->GetCellPosition(),playerNum,cellColor);
	///TODO: use the appropriate output function to draw the player with "cellColor" (to clear it)

}

// ====== Game Functions ======

void Player::Move(Grid * pGrid, int diceNumber) //This might solve the card Thing
{ 

	Output * pOut = pGrid->GetOutput();
	
	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	if(ZeroRoll){
		ZeroRoll = false;
		return;
	}

	// == Here are some guideline steps (numbered below) to implement this function ==

	
	// 1- Increment the turnCount because calling Move() means that the player has rolled the dice once
	
		turnCount++;
	pGrid->PrintErrorMessage("Dice Roll : " + to_string(diceNumber));
	
	
	// 2- Check the turnCount to know if the wallet recharge turn comes (recharge wallet instead of move)
	//    If yes, recharge wallet and reset the turnCount and return from the function (do NOT move)
	if(turnCount % 3 == 0){
		this->SetWallet(this->GetWallet() + (diceNumber * 10) );
		turnCount = 0 ;
		return;
	}
	// 3- Set the justRolledDiceNum with the passed diceNumber
	justRolledDiceNum = diceNumber ;
	// 4- Get the player current cell position, say "pos", and add to it the diceNumber (update the position)
	//    Using the appropriate function of CellPosition class to update "pos"
	if(this->wallet > 0){
	CellPosition pos ;
	pos = this->GetCell()->GetCellPosition();
	pos.AddCellNum(diceNumber);
	// 5- Use pGrid->UpdatePlayerCell() func to Update player's cell POINTER (pCell) with the cell in the passed position, "pos" (the updated one)
	//    the importance of this function is that it Updates the pCell pointer of the player and Draws it in the new position
	
	if(pos.IsValidCell()){ //Checks if the player rolls the right amount to land exactly on 100 tile
	pGrid->UpdatePlayerCell(this ,pos );
	// 6- Apply() the game object of the reached cell (if any)
	if(this->GetCell()->GetGameObject()) this->GetCell()->GetGameObject()->Apply(pGrid,this);
	// 7- Check if the player reached the end cell of the whole game, and if yes, Set end game with true: pGrid->SetEndGame(true)
	if(this->GetCell()->GetCellPosition().GetCellNum()== (NumHorizontalCells * NumVerticalCells)){
		pGrid->SetEndGame(true);
	}
	}
	else pGrid->PrintErrorMessage("Dice Number Larger than tiles left. Click to continue");
	}
	else pGrid->PrintErrorMessage("Player Can't Move While having zero coins in wallet");
}

void Player::SetPlayerToOrigin(Grid * pGrid) {
	CellPosition pos (8, 0);
	pGrid->UpdatePlayerCell(this, pos);
}

void Player::AppendPlayerInfo(string & playersInfo) const
{
	playersInfo += "P" + to_string(playerNum) + "(" ;
	playersInfo += to_string(wallet) + ", ";
	playersInfo += to_string(turnCount) + ")";
}