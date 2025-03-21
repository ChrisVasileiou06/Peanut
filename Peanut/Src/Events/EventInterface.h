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


#ifndef PEANUT_EVENTS_EVENT_INTERFACE_H_
#define PEANUT_EVENTS_EVENT_INTERFACE_H_

#include "Pch/Pch.h"

#include "Utils/Math.h"
#include "Utils/Types.h"
#include "Utils/Timer.h"

#include "Core/Defines.h"

namespace Peanut{
    enum class EventType{
        NONE = 0,
        INTERNAL = 1,
        USER = 2
    };

    template <>
    inline std::string cast<std::string, EventType>(const EventType& x){
        switch(x){
            case EventType::NONE:
            return "None";
            break;
            case EventType::INTERNAL:
            return "Internal";
            break;
            case EventType::USER:
            return "User";
            break;
            default:
            return "-";
            break;
        }
    }

    struct EventAttrs{
        EventType type = EventType::NONE;
        bool repeat = false;
        bool async = false;
    };

    class EventInterface{
    public:
        EventInterface(const EventType& evtype);

        EventInterface(const EventAttrs& attrs);

        virtual ~EventInterface();

        virtual void dispatch();

        const bool& repeat() const noexcept;

        const bool& async() const noexcept;

        void set_repeat(bool x) noexcept;

        void set_async(bool x) noexcept;

    protected:
        EventAttrs _attrs;

    private:
        Timer<float> _timer;

        EventType _type = EventType::NONE;
    };
}

#endif // PEANUT_EVENTS_EVENT_INTERFACE_H_