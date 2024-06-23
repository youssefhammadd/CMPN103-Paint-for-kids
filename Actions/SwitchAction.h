#pragma once
#include"Actions/Action.h"
#include"ApplicationManager.h"
class SwitchAction:public Action
{
public:
	SwitchAction(ApplicationManager* pApp);
	~SwitchAction();
	virtual void ReadActionParameters() ;

	virtual void Execute() ;
	virtual void Undoaction();
	virtual void Redoaction();
};

