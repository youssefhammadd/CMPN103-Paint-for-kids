#include "Input.h"
#include "Output.h"

Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if(Key == 13 )	//ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction() const
{	
	int x,y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if(UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
	{
		//[1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			//Check whick Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_RECT: return DRAW_RECT;
			case ITM_SQUARE: return DRAW_SQUARE;
			case ITM_CIRCLE: return DRAW_CIRCLE;
			case ITM_TRIANGLE: return DRAW_TRIANGLE;
			case ITM_HEXAGON: return DRAW_HEXAGON;

			case ITM_SELECT: return SELECT;

			case ITM_DRAW_COLOR:return CHANGE_DRAWING_COLOR;
			case ITM_FILL_COLOR:return CHANGE_FILL_COLOR;

			case ITM_RED: return CHANGE_TO_RED;
			case ITM_ORANGE: return CHANGE_TO_ORANGE;
			case ITM_YELLOW: return CHANGE_TO_YELLOW;
			case ITM_GREEN: return CHANGE_TO_GREEN;
			case ITM_BLUE: return CHANGE_TO_BLUE;
			case ITM_BLACK: return CHANGE_TO_BLACK;

			case ITM_DELETE: return DELETE_FIGURE;
			case ITM_MOVE: return MOVE_FIGURE;
			case ITM_UNDO: return UNDO;
			case ITM_REDO: return REDO;
			case ITM_CLEAR_ALL: return CLEAR_ALL;


			case ITM_START_RECORDING: return START_RECORDING;
			case ITM_STOP_RECORDING: return STOP_RECORDING;
			case ITM_PLAY_RECORDING: return PLAY_RECORDING;

			case ITM_SAVE_GRAPH: return SAVE_GRAPH;
			case ITM_LOAD_GRAPH: return LOAD_GRAPH;

			case ITM_SWITCH_TO_PLAY: return TO_PLAY;
			case ITM_EXIT: return EXIT;

			case DRAW_ITM_COUNT: return DRAWING_AREA;

			
			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		//[2] User clicks on the drawing area
		if ( y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;	
		}
		
		//[3] User clicks on the status bar
		return STATUS;
	}
	else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{

			int ClickedItemOrder = (x / UI.MenuItemWidth);

			switch (ClickedItemOrder)
			{
			case ITM_SELECT_BY_FIGURE: return SELECT_BY_FIGURE_TYPE;
			case ITM_SELECT_BY_COLOR: return SELECT_BY_COLOR;
			case ITM_SELECT_BY_BOTH: return SELECT_BY_FIGURE_TYPE_AND_COLOR;

			case ITM_RESTART: return RESTART;
			case ITM_SWITCH_TO_DRAW: return TO_DRAW;
			case ITM_EXIT_PLAY: return EXIT;

			case PLAY_ITM_COUNT: return DRAWING_AREA;

				return TO_PLAY;
			}
		}
		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			return DRAWING_AREA;
		}
		//[3] User clicks on the status bar
		return STATUS;
	}	

}
/////////////////////////////////
	
Input::~Input()
{
}
