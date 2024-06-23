#include"SelectOneAction.h"
#include"Actions/Action.h"
#include"ApplicationManager.h"
#include"GUI/Input.h"
#include"GUI/Output.h"
#include"CCircle.h"
#include"CHexagon.h"
#include"CRectangle.h"
#include"CSquare.h"
#include"CTriangle.h"


SelectOneAction::SelectOneAction(ApplicationManager* pApp) :Action(pApp)
{
}
void SelectOneAction::ReadActionParameters() 
{
	//get a pointer to the input/output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//get the point clicked by the user and store it in P
	pIn->GetPointClicked(P.x,P.y);

}
void SelectOneAction::Undoaction()
{

}
void SelectOneAction::Redoaction()
{

}
void SelectOneAction::Execute()
{
	//get a pointer to the input/output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();

	//find the figure to which the clicked point belongs and store it in pointer FigPtr
	FigPtr = pManager->GetFigure(P.x, P.y);

	if (FigPtr!=NULL && FigPtr->IsSelected()==true) 
	{
		FigPtr->SetSelected(false);
		
	}
	else if (FigPtr != NULL && FigPtr->IsSelected() == false )
	{
		pManager->unselectall();
		//select the new figure
		pManager->SetSelectedFigure(FigPtr);
		FigPtr->SetSelected(true);
	}
	else
	{
		pOut->PrintMessage("No Figure was selected");
	}
}