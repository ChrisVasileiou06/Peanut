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


#ifndef PEANUT_CORE_DATA_STRUCT_H_
#define PEANUT_CORE_DATA_STRUCT_H_

#include "Pch/Pch.h"

#include "Core/Defines.h"

namespace Peanut{
    class Data{
    public:
        Data() = default;

        ~Data() = default;

        uint16_t add(const std::string& id, const std::string& val) noexcept;

        uint16_t set(const std::string& id, const std::string& val) noexcept;

        uint16_t remove(const std::string& id) noexcept;

    private:
        std::map<std::string, std::string> _map;
    };
}

#endif // PEANUT_CORE_DATA_STRUCT_H_