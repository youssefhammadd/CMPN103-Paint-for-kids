#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_RECT,		//Recangle item in menu
	ITM_SQUARE,
	ITM_CIRCLE,
	ITM_TRIANGLE,
	ITM_HEXAGON,

	ITM_SELECT,

	ITM_DRAW_COLOR,
	ITM_FILL_COLOR,

	ITM_RED,
	ITM_ORANGE,
	ITM_YELLOW,
	ITM_GREEN,
	ITM_BLUE,
	ITM_BLACK,

	ITM_DELETE,
	ITM_MOVE,
	ITM_UNDO,
	ITM_REDO,
	ITM_CLEAR_ALL,

	ITM_START_RECORDING,
	ITM_STOP_RECORDING,
	ITM_PLAY_RECORDING,

	ITM_SAVE_GRAPH,
	ITM_LOAD_GRAPH,

	ITM_SWITCH_TO_PLAY,
	

	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};

enum PlayMenuItem //The items of the Play menu (you should add more items)
{
	//Note: Items are **(ordered)** here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	ITM_SELECT_BY_FIGURE,
	ITM_SELECT_BY_COLOR,
	ITM_SELECT_BY_BOTH,

	ITM_RESTART,
	ITM_SWITCH_TO_DRAW,
	ITM_EXIT_PLAY,

	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};





__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	bool isFilled;          //the figure is filled or not
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	color ToolBarColor;     //tool bar color
	int PenWidth;			//width of the pen that draws shapes

	
	
}UI;	//create a global object UI

#endif