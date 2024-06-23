#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
#define MaxUndoCount 5
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,		  //Draw Rectangle
	DRAW_SQUARE,      //Draw Square
	DRAW_CIRCLE,      //Draw Cicle
	DRAW_TRIANGLE,    //Draw Triangle
	DRAW_HEXAGON,     //Draw Hexagon
	SELECT,           //Select Figure
	CHANGE_DRAWING_COLOR, //Change figure drawing color
	CHANGE_FILL_COLOR,    //Change figure fill color
	CHANGE_TO_RED,    //Change figure color to Red
	CHANGE_TO_ORANGE, //Change figure color to Orange
	CHANGE_TO_YELLOW, //Change figure color to Yellow
	CHANGE_TO_GREEN,  //Change figure color to Green
	CHANGE_TO_BLUE,   //Change figure color to Blue
	CHANGE_TO_BLACK,  //Change figure color to Black
	DELETE_FIGURE,    //Delete Figure
	MOVE_FIGURE,      //Move Figure to another coordinate
	UNDO,             //Undo previous action
	REDO,             //Redo previous action
	CLEAR_ALL,        //Clear Drawing Area
	START_RECORDING,  //Start action Recording
	STOP_RECORDING,   //Stop action Recording
	PLAY_RECORDING,   //Play action Recording
	SAVE_GRAPH,       //Save Graph
	LOAD_GRAPH,       //Load Graph
	SELECT_BY_FIGURE_TYPE,            //Select figures By Figure Type
	SELECT_BY_COLOR,                  //Select figures By Color
	SELECT_BY_FIGURE_TYPE_AND_COLOR,  //Select figures By Figure Type and Color
	RESTART,        //Restart
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	STATUS			//A click on the status bar


};


struct Point	//To be used for figures points
{
	int x, y;
};

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif