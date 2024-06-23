#include"Actions/Action.h"
#include"DeleteAction.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"CCircle.h"
#include"CHexagon.h"
#include "CRectangle.h"
#include"CSquare.h"
#include"CTriangle.h"

DeleteAction::DeleteAction(ApplicationManager* pApp):Action(pApp)
{
	StoreSelected = pManager->GetSelected();
}
void DeleteAction::ReadActionParameters()
{

}
void DeleteAction::Undoaction()
{
	pManager->AddFigure(StoreSelected);
	pManager->UpdateInterface();
}
void DeleteAction::Redoaction()
{
	pManager->DeleteFigure(SelectedPtr);
	pManager->UpdateInterface();
}
void DeleteAction::Execute()
{
	ReadActionParameters();

	//get the selected figure and store it in SelectedPtr
	SelectedPtr = pManager->GetSelected();
	//delete the selected figure
	pManager->DeleteFigure(SelectedPtr);
}
