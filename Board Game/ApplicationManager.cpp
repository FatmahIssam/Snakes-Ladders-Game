#include "ApplicationManager.h"

#include "Grid.h"
#include "AddLadderAction.h"
#include "AddSnakeAction.h"
#include "AddCardAction.h"
#include "EditCardAction.h"
#include "CopyCardAction.h"
#include "CutCardAction.h"
#include "PasteCardAction.h"
#include "DeleteAction.h"
#include "NewGame.h"
#include "SaveAction.h"
#include "OpenAction.h"
#include "DiceValue.h"
#include "RollDiceAction.h"

///TODO: Add #include for all action types

ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pIn, pOut);
}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

void ApplicationManager::UpdateInterface() const
{
	pGrid->UpdateInterface();
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	// Ask the input to get the action from the user.
	return pIn->GetUserAction();
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_LADDER:
		pAct = new AddLadderAction(this);
		break;
	
	case ADD_SNAKE:
		pAct = new AddSnakeAction(this);
		break;

	case ADD_CARD:
		// create an object of AddCardAction here
		pAct = new AddCardAction(this);
		break;

	case COPY_CARD:
		// create an object of AddCardAction here
		pAct = new CopyCardAction(this);
		break;

	case CUT_CARD:
		// create an object of AddCardAction here
		pAct = new CutCardAction(this);
		break;

	case PASTE_CARD:
		// create an object of AddCardAction here
		pAct = new PasteCardAction(this);
		break;

	case EDIT_CARD:
		// create an object of AddCardAction here
		pAct = new EditCardAction(this);
		break;
	
	case DELETE_OBJECT:
		// create an object of AddCardAction here
		pAct = new DeleteAction(this);
		break;
		
	case SAVE_GRID:
		// create an object of AddCardAction here
		pAct = new SaveAction(this);
		break;
		
	case OPEN_GRID:
		// create an object of AddCardAction here
		pAct = new OpenAction(this);
		break;

	case EXIT:
		break;

	case TO_PLAY_MODE:
		pOut->CreatePlayModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

	case ROLL_DICE:
		// create an object of RollDiceAction here
		pAct = new RollDiceAction(this);
		break;

	case DICE_VALUE:
		pAct = new DiceValue(this);
		break;

	case NEW_GAME:
		pAct = new NewGame(this);
		break;

	case TO_DESIGN_MODE:
		pOut->CreateDesignModeToolBar(); // temporary till you made its action class (CHANGE THIS LATTER)
		break;

		

		///TODO: Add a case for EACH Action type in the Design mode or Play mode



	case STATUS:	// a click on the status bar ==> no action
		return;
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing ==> delete it
		pAct = NULL;
	}
}
