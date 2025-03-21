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


#ifndef PEANUT_CORE_APP_H_
#define PEANUT_CORE_APP_H_

#include "Pch/Pch.h"

#include "Utils/Math.h"
#include "Utils/Types.h"

#include "Core/Defines.h"
#include "Core/Updatable.h"

#include "Events/Event.h"

namespace Peanut{
    class App{
    public:
        uint16_t init(int16_t argc, char** argv) noexcept;

        void start(bool& stop) noexcept;

    private:
        std::queue<Updatable*> _update_queue;
    };
}

#endif // PEANUT_CORE_APP_H_