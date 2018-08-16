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
	if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
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

	//Border Collision
	if (x + 4 >= gfx.ScreenWidth) {
		x = gfx.ScreenWidth - 5;
		vx = 0;
	}
	if (x - 4 < 0) {
		x = 4;
		vx = 0;
	}
	if (y + 4 >= gfx.ScreenHeight) {
		y = gfx.ScreenHeight - 5;
		vy = 0;
	}
	if (y - 4 < 0) {
		y = 4;
		vy = 0;
	}

	//Cursor color change collision
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

}

void Game::ComposeFrame()
{
	
	gfx.PutPixel(x + 1, y, red, green, blue);
	gfx.PutPixel(x + 2, y, red, green, blue);
	gfx.PutPixel(x + 3, y, red, green, blue);
	gfx.PutPixel(x + 4, y, red, green, blue);
	gfx.PutPixel(x, y + 1, red, green, blue);
	gfx.PutPixel(x, y + 2, red, green, blue);
	gfx.PutPixel(x, y + 3, red, green, blue);
	gfx.PutPixel(x, y + 4, red, green, blue);

	gfx.PutPixel(x - 1, y, red, green, blue);
	gfx.PutPixel(x - 2, y, red, green, blue);
	gfx.PutPixel(x - 3, y, red, green, blue);
	gfx.PutPixel(x - 4, y, red, green, blue);
	gfx.PutPixel(x, y - 1, red, green, blue);
	gfx.PutPixel(x, y - 2, red, green, blue);
	gfx.PutPixel(x, y - 3, red, green, blue);
	gfx.PutPixel(x, y - 4, red, green, blue);





}
