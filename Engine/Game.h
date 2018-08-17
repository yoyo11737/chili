/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawBox(int x, int y, int r, int g, int b);
	bool OverLapTest(int movx, int movy);
	int xborder(int x);
	int yborder(int y);
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	//colors
	bool colorChange = false;
	//Static color
	int red = 255;
	int green = 255;
	int blue = 255;
	//Moving collor
	int movRed = 255;
	int movGreen = 255;
	int movBlue = 255;

	bool colliding = false;
	int movx = 400;
	int movy = 300;
	int x0 = 250;
	int y0 = 200;
	int x1 = 350;
	int y1 = 200;
	int x2 = 450;
	int y2 = 200;
	//int vx = 0;
	//int vy = 0;
	//bool slowLeft = false;
	//bool slowRight = false;
	//bool slowUp = false;
	//bool slowDown = false;
	
	
	/********************************/
};