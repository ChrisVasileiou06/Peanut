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

#include "Utils/Types.h"

#include "Core/Defines.h"

namespace Peanut{
    class Data{
    public:
        Data() = default;

        ~Data() = default;

        bool contains_id(const std::string& id) const noexcept;

        bool contains_value(const std::string& value) const;

        bool contains_value(const std::string& id, const std::string& value) const;


        std::vector<std::string>& get(const std::string& id);

        std::vector<std::string>& get(uint16_t pos);


        uint16_t push_id(const std::string& id) noexcept;

        uint16_t insert_id(const std::string& id, uint16_t pos);

        uint16_t insert_id(const std::string& id, const std::string& pos_id); 
        
        uint16_t remove_id(uint16_t pos);

        uint16_t remove_id(const std::string& id);

        
        uint16_t push_value(const std::string& id, const std::string& value) noexcept;

        uint16_t insert_value(const std::string& id, const std::string& value, uint16_t pos);

        uint16_t insert_value(const std::string& id, const std::string& value, const std::string& pos_value);

        uint16_t remove_value(const std::string& id, uint16_t value_pos);

        uint16_t remove_value(const std::string& id, const std::string& value);

        std::vector<std::string>& operator[](const std::string& id);

        std::vector<std::string>& operator[](uint16_t pos);

    private:
        std::vector<std::string> _ids;
        std::unordered_map<std::string, std::vector<std::string>> _map;

    private:
        bool _check_value(const std::string& value) noexcept;
    };
}

#endif // PEANUT_CORE_DATA_STRUCT_H_