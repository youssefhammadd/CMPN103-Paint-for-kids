#include"ChangeFillColorAction.h"
#include"CRectangle.h"
#include"CSquare.h"
#include"CTriangle.h"
#include"CHexagon.h"
#include"CCircle.h"
#include"ApplicationManager.h"
#include"SelectOneAction.h"

ChangeFillColorAction::ChangeFillColorAction(ApplicationManager*pApp):Action(pApp)
{ 
	SelectedPtr = NULL;
}
void ChangeFillColorAction::Undoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() > 0)
	{
		SelectedPtr = pManager->GetSelected();
		if (SelectedPtr->isColorFilled() == false)
		{
			pOut->setisfilled(false);
		}
		else
			SelectedPtr->ChngFillClr(oldColor);

		pManager->UpdateInterface();     // To update the interface after undo
		pOut->PrintMessage("Undo Change Color");
	}
}
void ChangeFillColorAction::Redoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetActionCount() < MaxUndoCount)
	{
		SelectedPtr = pManager->GetSelected();
		SelectedPtr->ChngFillClr(pOut->getCrntFillColor());

		pManager->UpdateInterface();
		pManager->GetOutput()->PrintMessage("Redo Change Color");
	}
	else
	{
		pOut->PrintMessage("No undo action to redo.");
	}
}
void ChangeFillColorAction::ReadActionParameters()
{
	//get the selected figure and store it in SelectedPtr
	SelectedPtr = pManager->GetSelected();

}
void ChangeFillColorAction::Execute()
{
	//get a pointer to the input/output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();


	//get the new color
	ClickedColor = pIn->GetUserAction();

	if (ClickedColor == CHANGE_TO_RED)
	{
		pOut->setCrntFillColor(RED);
		
	}
	else if (ClickedColor == CHANGE_TO_ORANGE)
	{
		pOut->setCrntFillColor(ORANGE);
		
	}
	else if (ClickedColor == CHANGE_TO_YELLOW)
	{
		pOut->setCrntFillColor(YELLOW);
		
	}
	else if (ClickedColor == CHANGE_TO_GREEN)
	{
		pOut->setCrntFillColor(GREEN);
		
	}
	else if (ClickedColor == CHANGE_TO_BLUE)
	{
		pOut->setCrntFillColor(BLUE);
		
	}
	else if (ClickedColor == CHANGE_TO_BLACK)
	{
		pOut->setCrntFillColor(BLACK);
		
	}
	SelectedPtr->ChngFillClr(pOut->getCrntFillColor());
	pOut->setisfilled(true);
	FigGfxInfo.FillClr = pOut->getCrntFillColor();
}