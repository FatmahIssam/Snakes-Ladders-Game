#pragma once
#include "Action.h"
#include"Card.h"
#include"CellPosition.h"
class CopyCardAction :public Action
{
	Card* CC;
	Cell* pCell;
public:
	CopyCardAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~CopyCardAction();






};

