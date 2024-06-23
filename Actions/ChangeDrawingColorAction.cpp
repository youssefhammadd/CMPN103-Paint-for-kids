#include"ChangeDrawingColorAction.h"
#include"CRectangle.h"
#include"CSquare.h"
#include"CTriangle.h"
#include"CHexagon.h"
#include"CCircle.h"
#include"ApplicationManager.h"
#include"SelectOneAction.h"

ChangeDrawingColorAction::ChangeDrawingColorAction(ApplicationManager* pApp) :Action(pApp)
{
	SelectedPtr = NULL;
	PreviousFigure = NULL;

}

void ChangeDrawingColorAction::ReadActionParameters()
{

}
void ChangeDrawingColorAction::Undoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetFigCount() > 0)
	{
		SelectedPtr = pManager->GetSelected();
		if (SelectedPtr->isColorDraw() == false)
		{
			pOut->setisfilled(false);
		}
		else
			SelectedPtr->ChngFillClr(oldColor);

		pManager->UpdateInterface();     // To update the interface after undo
		pOut->PrintMessage("Undo Change Color");
	}
}
void ChangeDrawingColorAction::Redoaction()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->GetActionCount() < MaxUndoCount)
	{
		SelectedPtr = pManager->GetSelected();
		SelectedPtr->ChngFillClr(pOut->getCrntFillColor());

		pManager->UpdateInterface();
		pOut->PrintMessage("Redo Change Color");
	}
	else
	{
		pOut->PrintMessage("No undo action to redo.");
	}
}
void ChangeDrawingColorAction::Execute()
{
	//get a pointer to the input/output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ReadActionParameters();

	if (ClickedColor == CHANGE_TO_RED)
	{
		pOut->setCrntDrawColor(RED);
		
	}
	else if (ClickedColor == CHANGE_TO_ORANGE)
	{
		pOut->setCrntDrawColor(ORANGE);
		
	}
	else if (ClickedColor == CHANGE_TO_YELLOW)
	{
		pOut->setCrntDrawColor(YELLOW);
		
	}
	else if (ClickedColor == CHANGE_TO_GREEN)
	{
		pOut->setCrntDrawColor(GREEN);
		
	}
	else if (ClickedColor == CHANGE_TO_BLUE)
	{
		pOut->setCrntDrawColor(BLUE);
		
	}
	else if (ClickedColor == CHANGE_TO_BLACK)
	{
		pOut->setCrntDrawColor(BLACK);
		
	}
	FigGfxInfo.DrawClr = pOut->getCrntDrawColor();

}