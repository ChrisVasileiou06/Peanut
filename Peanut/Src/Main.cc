/* 
 * Copyright (C) 2025 Christos Vasileiou
 * 
 * This file is part of Peanut.
 *
 * peanut is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Peanut is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Peanut.  If not, see <http://www.gnu.org/licenses/>.
 */


#include "Core/Defines.h"
#include "Core/App.h"

int main(int argc, char** argv) noexcept{
    Peanut::App* app = new Peanut::App();
    bool* glstop = new bool;
    *glstop = false;

    if(app->init(argc, argv) != PEANUT_NO_ERROR){
        exit(1);
    }

    app->start(*glstop);

    delete app;
    delete glstop;
    return 0;
}