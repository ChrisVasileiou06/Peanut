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


#include "Events/EventInterface.h"

namespace Peanut{
    EventInterface::EventInterface(const EventType& evtype){
        _type = evtype;
        return;
    }

    EventInterface::EventInterface(const EventAttrs& attrs){
        _attrs.type = attrs.type;
        _attrs.repeat = attrs.repeat;
        _attrs.async = attrs.async;
        return;
    }

    EventInterface::~EventInterface(){
        return;
    }

    void EventInterface::dispatch(){
        exit(1);
        return;
    }

    const bool& EventInterface::repeat() const noexcept{
        return _attrs.repeat;
    }

    const bool& EventInterface::async() const noexcept{
        return _attrs.async;
    }

    void EventInterface::set_repeat(bool x) noexcept{
        _attrs.repeat = x;
        return;
    }

    void EventInterface::set_async(bool x) noexcept{
        _attrs.async = x;
        return;
    }
}