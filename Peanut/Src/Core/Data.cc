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
    bool Data::contains_id(const std::string& id) const noexcept{
        if(_map.find(id) != _map.end()){
            return true;
        }

        return false;
    }

    bool Data::contains_value(const std::string& id, const std::string& value) const{
        auto iter = _map.find(id);

        if(iter == _map.end()){
            return false;
        }

        uint16_t max = iter->second.size();

        for(uint16_t index = 0; index < max; ++index){
            if(iter->second.at(index) == value){
                return true;
            }
        }

        return false;
    }

    bool Data::contains_value(const std::string& value) const{
        for(uint16_t index = 0; index < _ids.size(); ++index){
            if(contains_value(_ids[index], value)){
                return true;
            }
        }

        return false;
    }

    std::vector<std::string>& Data::get(const std::string& id){
        if(!contains_id(id)){
            _map[id];
            _ids.push_back(id);
            return _map[id];
        }

        return _map[id];
    }

    std::vector<std::string>& Data::get(uint16_t pos){
        if(pos > _ids.size()){
            exit(1);
        }

        return _map.at(_ids[pos]);
    }

    uint16_t Data::push_id(const std::string& id) noexcept{
        if(!contains_id(id)){
            return PEANUT_DATA_ID_ALREADY_EXISTS;
        }

        _map[id];

        return PEANUT_NO_ERROR;
    }

    uint16_t Data::insert_id(const std::string& id, uint16_t pos){
        if(pos > _ids.size() || (!contains_id(id))){
            return PEANUT_DATA_INVALID_ID;
        }

        _ids.insert((_ids.begin() + pos), id);
        _map[id];
        
        return PEANUT_NO_ERROR;
    }

    uint16_t Data::insert_id(const std::string& id, const std::string& pos_id){
        if((_map.find(pos_id) == _map.end()) || (!contains_id(id))){
            return PEANUT_DATA_INVALID_ID;
        }

        uint16_t pos = 0;

        for(uint16_t index = 0; index < _ids.size(); ++index){
            if(_ids[index] == pos_id){
                pos = index;
                break;
            }
        }

        _ids.insert((_ids.begin() + pos), id);
        _map[id];

        return PEANUT_NO_ERROR;
    }

    uint16_t Data::remove_id(uint16_t pos){
        if(pos > _ids.size()){
            return PEANUT_DATA_INVALID_ID;
        }

        _map.erase(_ids[pos]);

        return PEANUT_NO_ERROR;
    }

    uint16_t Data::remove_id(const std::string& id){
        if(!contains_id(id)){
            return PEANUT_DATA_INVALID_ID;
        }

        _map.erase(id);

        return PEANUT_NO_ERROR;
    }

    uint16_t Data::push_value(const std::string& id, const std::string& value) noexcept{
        if(!contains_id(id)){
            return PEANUT_DATA_INVALID_ID;
        }

        if(!_check_value(value)){
            return PEANUT_DATA_BANNED_VALUE;
        }

        _map.at(id).push_back(value);

        return PEANUT_NO_ERROR;
    }

    uint16_t Data::insert_value(const std::string& id, const std::string& value, uint16_t pos){
        if((!contains_id(id)) || (pos > _map.at(id).size())){
            return PEANUT_DATA_INVALID_ID;
        }

        if(!_check_value(value)){
            return PEANUT_DATA_BANNED_VALUE;
        }

        _map.at(id).insert((_map.at(id).begin() + pos), value);

        return PEANUT_NO_ERROR;
    }

    uint16_t Data::insert_value(const std::string& id, const std::string& value, const std::string& pos_value){
        if(!contains_id(id)){
            return PEANUT_DATA_INVALID_ID;
        }

        if(!_check_value(value)){
            return PEANUT_DATA_BANNED_VALUE;
        }

        uint16_t pos = 0;

        for(uint16_t index = 0; index < _map.at(id).size(); ++index){
            if(_map[id][index] == pos_value){
                pos = index;
                break;
            }
        }

        _map[id].insert((_map[id].begin() + pos), value);

        return PEANUT_NO_ERROR;
    }

    uint16_t Data::remove_value(const std::string& id, uint16_t value_pos){
        if((!contains_id(id)) || (value_pos > _map[id].size())){
            return PEANUT_DATA_INVALID_ID;
        }

        _map[id].erase(_map[id].begin() + value_pos);

        return PEANUT_NO_ERROR;
    }

    uint16_t Data::remove_value(const std::string& id, const std::string& value){
        if(!contains_id(id)){
            return PEANUT_DATA_INVALID_ID;
        }

        uint16_t pos = 0;

        for(uint16_t index = 0; index < _map[id].size(); ++index){
            if(_map[id][index] == value){
                pos = index;
                break;
            }
        }

        _map[id].erase(_map[id].begin() + pos);

        return PEANUT_NO_ERROR;
    }

    std::vector<std::string>& Data::operator[](const std::string& id){
        return get(id);
    }

    std::vector<std::string>& Data::operator[](uint16_t pos){
        return get(pos);
    }
}