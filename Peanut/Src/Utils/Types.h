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


#ifndef PEANUT_UTILS_TYPES_H_
#define PEANUT_UTILS_TYPES_H_

#include "Pch/Pch.h"

#include "Utils/Math.h"

namespace Peanut{
    template <typename _To, typename... _From>
    inline _To cast(const _From&... x){
        exit(1);
    }

    template <>
    inline uint16_t cast<uint16_t, std::string>(const std::string& x){
        uint16_t res = 0;

        for(uint16_t index = 0; index < x.size(); ++index){
            res = res + (x[index] - (int16_t)('0')) * unsigned_pow(10, (x.size() - index - 1));
        }
        return res;
    }

    template <>
    inline uint64_t cast<uint64_t, std::string>(const std::string& x){
        uint64_t res = 0;

        for(int16_t index = 0; index < x.size(); ++index){
            res = res + (x[index] - (int16_t)('0')) * unsigned_pow64(10, (x.size() - index - 1));
        }
        return res;
    }
}

#endif // PEANUT_UTILS_TYPES_H_