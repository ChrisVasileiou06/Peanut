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


#ifndef PEANUT_UTILS_TIMER_H_
#define PEANUT_UTILS_TIMER_H_

#include "Pch/Pch.h"

#include "Utils/Math.h"
#include "Utils/Types.h"

namespace Peanut{
#ifdef PEANUT_DEBUG
    template <typename _Res>
    class Timer{

    };
#else
    template <typename _Res>
    class Timer{};
#endif // // PEANUT_DEBUG
}

#endif // PEANUT_UTILS_TIMER_H_