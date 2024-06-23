#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;

	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;


	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 40;

	UI.DrawColor = BLUE;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.ToolBarColor = WHITE;
	UI.PenWidth = 3;	//width of the figures frames


	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");

	CreateDrawToolBar();
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	//clear tool bar by creating a filled white rectangle
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar() const
{
	UI.InterfaceMode = MODE_DRAW;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\Menu_Rect.jpg";
	MenuItemImages[ITM_SQUARE] = "images\\MenuItems\\Menu_Square.jpg";
	MenuItemImages[ITM_CIRCLE] = "images\\MenuItems\\Menu_Circ.jpg";
	MenuItemImages[ITM_TRIANGLE] = "images\\MenuItems\\Menu_Triangle.jpg";
	MenuItemImages[ITM_HEXAGON] = "images\\MenuItems\\Menu_Hexagon.jpg";

	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\Menu_Select.jpg";

	MenuItemImages[ITM_DRAW_COLOR] = "images\\MenuItems\\Menu_Drawing_Color.jpg";
	MenuItemImages[ITM_FILL_COLOR] = "images\\MenuItems\\Menu_Fill_Color.jpg";

	MenuItemImages[ITM_RED] = "images\\MenuItems\\Menu_Red.jpg";
	MenuItemImages[ITM_ORANGE] = "images\\MenuItems\\Menu_Orange.jpg";
	MenuItemImages[ITM_YELLOW] = "images\\MenuItems\\Menu_Yellow.jpg";
	MenuItemImages[ITM_GREEN] = "images\\MenuItems\\Menu_Green.jpg";
	MenuItemImages[ITM_BLUE] = "images\\MenuItems\\Menu_Blue.jpg";
	MenuItemImages[ITM_BLACK] = "images\\MenuItems\\Menu_Black.jpg";

	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Menu_Delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\MenuItems\\Menu_Move_Figure.jpg";
	MenuItemImages[ITM_UNDO] = "images\\MenuItems\\Menu_Undo.jpg";
	MenuItemImages[ITM_REDO] = "images\\MenuItems\\Menu_Redo.jpg";
	MenuItemImages[ITM_CLEAR_ALL] = "images\\MenuItems\\Menu_Clear_All.jpg";

	MenuItemImages[ITM_START_RECORDING] = "images\\MenuItems\\Menu_Start_Recording.jpg";
	MenuItemImages[ITM_STOP_RECORDING] = "images\\MenuItems\\Menu_Stop_Recording.jpg";
	MenuItemImages[ITM_PLAY_RECORDING] = "images\\MenuItems\\Menu_Play_Recording.jpg";

	MenuItemImages[ITM_SAVE_GRAPH] = "images\\MenuItems\\Menu_Save_Graph.jpg";
	MenuItemImages[ITM_LOAD_GRAPH] = "images\\MenuItems\\Menu_Load_Graph.jpg";

	MenuItemImages[ITM_SWITCH_TO_PLAY] = "images\\MenuItems\\Menu_Switch.jpg";

	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";



	//Draw menu item one image at a time
	for (int i = 0; i < DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;
	/// create Play mode menu
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_SELECT_BY_FIGURE] = "images\\MenuItems\\Menu_Select_By_Figure.jpg";
	MenuItemImages[ITM_SELECT_BY_COLOR] = "images\\MenuItems\\Menu_Select_By_Color.jpg";
	MenuItemImages[ITM_SELECT_BY_BOTH] = "images\\MenuItems\\Menu_Select_By_Figure_And_Color.jpg";

	MenuItemImages[ITM_RESTART] = "images\\MenuItems\\Menu_Restart.jpg";
	MenuItemImages[ITM_SWITCH_TO_DRAW] = "images\\MenuItems\\Menu_Switch.jpg";
	MenuItemImages[ITM_EXIT_PLAY] = "images\\MenuItems\\Menu_Exit.jpg";

	for (int i = 0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::setCrntDrawColor(color DrawingClr)  //set current drawing color
{
	UI.HighlightColor = DrawingClr;

}
/////////////////////////////////////////////////////////////////////////////////////////
void Output::setCrntFillColor(color FillClr)  //set currnet fill color
{
	UI.FillColor = FillClr;
}
/////////////////////////////////////////////////////////////////////////////////////////
color Output::getCrntDrawColor() 	//get current drawing color
{
	return UI.DrawColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() 	//get current filling color
{
	return UI.FillColor;
}
//////////////////////////////////////////////////////////////////////////////////////////

int Output::getCrntPenWidth() const		//get current pen width
{
	return UI.PenWidth;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::setisfilled(bool f)        //check the figure status as filled or not
{
	UI.isFilled = f;
}
bool Output::getisfilled()              //check if the figure is filled 
{
	return UI.isFilled;
}
//////////////////////////////////////////////////////////////////////////////////////////
//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawSquare(Point P1, GfxInfo SquareGfxInfo, bool selected) const
{
	Point P3, P4;
	int x = 75;
	P3.x = P1.x - x;
	P3.y = P1.y - x;
	P4.x = P1.x + x;
	P4.y = P1.y + x;
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = SquareGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (SquareGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(SquareGfxInfo.FillClr);
	}
	else
		style = FRAME;

	pWind->DrawRectangle(P3.x, P3.y, P4.x, P4.y, style);

}

void Output::DrawTri(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected) const
{
	int Arrx[3];
	Arrx[0] = P1.x;
	Arrx[1] = P2.x;
	Arrx[2] = P3.x;
	int Arry[3];
	Arry[0] = P1.y;
	Arry[1] = P2.y;
	Arry[2] = P3.y;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = TriGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (TriGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(TriGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(Arrx, Arry, 3, style);

}
void Output::DrawCirc(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	int R;
	R = sqrt(pow((P2.x - P1.x), 2) + pow((P2.y - P1.y), 2));
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawCircle(P1.x, P1.y, R, style);
}

void Output::DrawHexa(Point P, GfxInfo HexaGfxInfo, bool selected) const
{
	int x1 = 60, y1 = 80, x2 = sqrt(pow(x1, 2) + pow(y1, 2));
	int Arrx[6];
	Arrx[0] = P.x + x1;
	Arrx[1] = P.x + x2;
	Arrx[2] = P.x + x1;
	Arrx[3] = P.x - x1;
	Arrx[4] = P.x - x2;
	Arrx[5] = P.x - x1;

	int Arry[6];
	Arry[0] = P.y + y1;
	Arry[1] = P.y;
	Arry[2] = P.y - y1;
	Arry[3] = P.y - y1;
	Arry[4] = P.y;
	Arry[5] = P.y + y1;

	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = HexaGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, 1);
	drawstyle style;
	if (HexaGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(HexaGfxInfo.FillClr);
	}
	else
		style = FRAME;


	pWind->DrawPolygon(Arrx, Arry, 6, style);

}
string Output::color_to_string(color color) // Change Color into a string
{
	if (color == RED)
		return "RED";
	else if (color == BLACK)
		return "BLACK";
	else if (color == BLUE)
		return "BLUE";
	else if (color == GREEN)
		return "GREEN";
	else if (color == YELLOW)
		return "YELLOW";
	else if (color == ORANGE)
		return "ORANGE";
	else
		return "NO_FILL";
}
color Output::String_to_Color(string string) // Change String of color name into a string
{
	if (string == "RED")
		return RED;
	else if (string == "BLACK")
		return BLACK;
	else if (string == "BLUE")
		return BLUE;
	else if (string == "GREEN")
		return GREEN;
	else if (string == "YELLOW")
		return YELLOW;
	else if (string == "ORANGE")
		return ORANGE;
	else if (string == "NO_FILL") //Returns the color of the background
		return UI.BkGrndColor;
}


//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

