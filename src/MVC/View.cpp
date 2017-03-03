/*
 * Created by David de Prez on 2-3-2017.
 *
 * 3D pong is a game console to play the game PONG in 3D.
 *  Copyright (C) 2017  David de Prez
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "MVC/View.h"

MVC::View::View(Model *model, Controller *controller)
		: model(model), controller(controller) {
}

MVC::View::~View() {

}

void MVC::View::update() {
	//standard view update will refresh screen
	display();
}

MVC::Controller *MVC::View::getController() {
	return controller;
}

MVC::Model *MVC::View::getModel() {
	return model;
}