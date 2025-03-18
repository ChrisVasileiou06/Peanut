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


#include "Core/Data.h"

namespace Peanut{
    uint16_t Data::add(const std::string& id, const std::string& val) noexcept{
        if(_map.count(id) > 0){
            return PEANUT_DATA_ID_ALREADY_EXISTS;
        }

        _map[id] = val;
        return PEANUT_NO_ERROR;
    }

    uint16_t Data::set(const std::string& id, const std::string& val) noexcept{
        if(_map.count(id) == 0){
            return PEANUT_DATA_INVALID_ID;
        }

        _map[id] = val;
        return PEANUT_NO_ERROR;
    }

    uint16_t Data::remove(const std::string& id) noexcept{
        if(_map.count(id) == 0){
            return PEANUT_DATA_INVALID_ID;
        }

        _map.erase(id);
        return PEANUT_NO_ERROR;
    }
}