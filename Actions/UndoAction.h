#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class UndoAction:public Action
{
public:
	UndoAction(ApplicationManager *pApp);
	~UndoAction();
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void Undoaction();
	virtual void Redoaction();
};

