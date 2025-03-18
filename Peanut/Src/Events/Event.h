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


#ifndef PEANUT_EVENTS_EVENT_H_
#define PEANUT_EVENTS_EVENT_H_

#include "Pch/Pch.h"

#include "Utils/Math.h"
#include "Utils/Types.h"
#include "Utils/Timer.h"

#include "Core/Defines.h"

#include "Events/EventInterface.h"

namespace Peanut{
    template <typename _StructArgs>
    class Event : public EventInterface{
    public: 
        Event(const EventType& evtype)
            :EventInterface(evtype){
                return;
            }

        Event(const EventAttrs& attrs)
            :EventInterface(attrs){
                return;
            }

        ~Event() = default;

        void dispatch() override{
            if(_attrs.async){
                
            }
            else{
                _func(cast<_StructArgs, std::string>(_args));
            }
            return;
        }

        void set_args(const std::string& args) noexcept{
            _args = args;
            return;
        }

        std::string to_string() const noexcept{
            std::string res = "";

            res += "Event \n";
            res += "type: ";
            res += cast<std::string, EventType>(_attrs.type);
            res += "\n";
            res += "repeat: ";
            res += cast<std::string, bool>(_attrs.repeat);
            res += "\n";
            res += "async: ";
            res += cast<std::string, bool>(_attrs.async);
            res += "\n";
            res += "args: ";
            res += _args;
            return res;
        }

    private:    
        std::string _args;
        std::function<void(_StructArgs&)> _func;
    };
}

#endif // PEANUT_EVENTS_EVENT_H_