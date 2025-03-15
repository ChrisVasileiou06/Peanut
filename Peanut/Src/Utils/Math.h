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


#ifndef PEANUT_UTILS_MATH_H_
#define PEANUT_UTILS_MATH_H_

#include "Pch/Pch.h"

namespace Peanut{
    inline float unsigned_pow(uint16_t base, int16_t exponent){
        if(exponent == 0){
            return 1;
        }

        float res = base;

        for(uint16_t index = 1; index < exponent; ++index){
            res *= base;
        }

        if(exponent > 0){
            return res;
        }
        else{
            return ((float)(1 / res));
        }
    }

    inline double unsigned_pow64(uint64_t base, int16_t exponent){
        if(exponent == 0){
            return 1;
        }

        float res = base;

        for(uint16_t index = 1; index < exponent; ++index){
            res *= base;
        }

        if(exponent > 0){
            return res;
        }
        else{
            return ((float)(1 / res));
        }
    }

    inline float pow(int16_t base, int16_t exponent){
        if(base < 0){
            if(exponent % 2 == 0){
                return unsigned_pow((-1 * base), exponent);
            }
            else{
                return (-1 * unsigned_pow((-1 * base), exponent));
            }
        }
        else{
            return unsigned_pow(base, exponent);
        }
    }

    inline double pow64(int16_t base, int16_t exponent){
        if(base < 0){
            if(exponent % 2 == 0){
                return unsigned_pow64((-1 * base), exponent);
            }
            else{
                return (-1 * unsigned_pow64((-1 * base), exponent));
            }
        }
        else{
            return unsigned_pow64(base, exponent);
        }
    }
}

#endif // PEANUT_UTILS_MATH_H_