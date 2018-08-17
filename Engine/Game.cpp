/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	//wnd.kbd.KeyIsPressed(VK_LEFT)
	//wnd.kbd.KeyIsPressed(VK_RIGHT)
	//wnd.kbd.KeyIsPressed(VK_UP)
	//wnd.kbd.KeyIsPressed(VK_DOWN)
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		movx -= 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		movx += 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		movy -= 1;
	}
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		movy += 1;
	}

	colliding = OverLapTest(movx, movy);

	//******************Velocity Movement*******************
	/*if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
		if (slowLeft) {

		}
		else {
			vx -= 1;
			slowLeft = true;
		}
		
	}
	else slowLeft = false;
	if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
		if (slowRight) {

		}
		else {
			vx += 1;
			slowRight = true;
		}
		
	}
	else slowRight = false;

	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		if (slowUp) {

		}
		else {
			vy -= 1;
			slowUp = true;
		}
	}
	else slowUp = false;
	if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
		if (slowDown) {

		}
		else {
			vy += 1;
			slowDown = true;
		}
	}
	else slowDown = false;


	x += vx;
	y += vy;
	*/
	//Border Collision = Make a function for this
	
	/*if (movx + 4 >= gfx.ScreenWidth) {
		movx = gfx.ScreenWidth - 5;
		//vx = 0;
	}
	if (movx - 4 < 0) {
		movx = 4;
		//vx = 0;
	}
	if (movy + 4 >= gfx.ScreenHeight) {
		movy = gfx.ScreenHeight - 5;
		//vy = 0;
	}
	if (movy - 4 < 0) {
		movy = 4;
		//vy = 0;
	}
	*/

	movx = xborder(movx);
	movy = yborder(movy);

	/********Color Collision test********/
	/*Cursor color change collision
	if (x > 150 && x < 300) {
		red = 0;
	}
	else {
		red = 255;
	}
	colorChange = wnd.kbd.KeyIsPressed(VK_CONTROL);
	if (colorChange) {
		blue = 0;
	}
	else blue = 255;
	*/
}

void Game::ComposeFrame()
{

	DrawBox(x0, y0, 0,255,0);
	DrawBox(x1, y1, 255, 255, 0);
	DrawBox(x2, y2, 255, 255, 255);
	if (colliding) {
		DrawBox(movx, movy, 255,0,0);
	}
	else {
		DrawBox(movx, movy, 255,255,255);
	}
	

}

void Game::DrawBox(int x, int y, int r, int g, int b) {

	//Moving Reticle
	gfx.PutPixel(x + 1, y, r, g, b);
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);
	gfx.PutPixel(x, y + 1, r, g, b);
	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x, y + 4, r, g, b);
							  
	gfx.PutPixel(x - 1, y, r, g, b);
	gfx.PutPixel(x - 2, y, r, g, b);
	gfx.PutPixel(x - 3, y, r, g, b);
	gfx.PutPixel(x - 4, y, r, g, b);
	gfx.PutPixel(x, y - 1, r, g, b);
	gfx.PutPixel(x, y - 2, r, g, b);
	gfx.PutPixel(x, y - 3, r, g, b);
	gfx.PutPixel(x, y - 4, r, g, b);

}

bool Game::OverLapTest(int movx, int movy)
{

	return (movx <= x0 + 8 && movx >= x0 - 8 && movy >= y0 - 8 && movy <= y0 + 8) ||
		   (movx <= x1 + 8 && movx >= x1 - 8 && movy >= y1 - 8 && movy <= y1 + 8) ||
		   (movx <= x2 + 8 && movx >= x2 - 8 && movy >= y2 - 8 && movy <= y2 + 8);

}

int Game::xborder(int x)
{

	const int left = x - 4;
	const int right = x + 4;

	if(left < 0) {
		return 5;
	}
	else if (right >= gfx.ScreenWidth) {
		return gfx.ScreenWidth - 5;
	}
	else return x;

}

int Game::yborder(int y)
{
	const int top = y - 4;
	const int bot = y + 4;

	if (top < 0) {
		return 5;
	}
	else if (bot >= gfx.ScreenHeight) {
		return gfx.ScreenHeight - 5;
	}
	else return y;
}


