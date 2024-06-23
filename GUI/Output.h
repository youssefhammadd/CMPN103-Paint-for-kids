#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();

	window* CreateWind(int, int, int, int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar() const; //clears the too bar

	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;  //Draw a rectangle
	void DrawSquare(Point P1, GfxInfo SquareInfo, bool selected = false)const;//Draw square
	void DrawCirc(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected = false) const; //Draw a circle
	void DrawHexa(Point P1, GfxInfo HexaInfo, bool selected = false)const;//Draw square
	void DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const; //Draw a triangle

	///TODO:Make similar functions for drawing all other figure types.

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor();	//get current drwawing color
	void setCrntDrawColor(color DrawingClr);  //set current drawing color
	color getCrntFillColor();	//get current filling color
	void setCrntFillColor(color FillClr); //set current fill color with the passed color
	int getCrntPenWidth() const;		//get current pen width
	void setisfilled(bool f);          // set the figure status as filled or not
	bool getisfilled();               //check whether the figure is filled
	string color_to_string(color color);          // return the color as string
	color String_to_Color(string string);
	~Output();
};

#endif