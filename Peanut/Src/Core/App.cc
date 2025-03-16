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


#include "Core/App.h"

namespace Peanut{
    uint16_t App::init(int16_t argc, char** argv) noexcept{
        Event<uint16_t>* ev = new Event<uint16_t>(EventType::INTERNAL);

        ev->set_repeat(false);
        ev->set_args("set twitter 'AFt2-5d' -safe");
        std::cout << ev->to_string() << std::endl;
        return PEANUT_NO_ERROR;
    }

    void App::start(bool& stop) noexcept{
        Updatable* current_task = nullptr;

        while(!stop){
            if(_update_queue.size() > 0){
                current_task = _update_queue.front();
                _update_queue.pop();
                current_task->update();
                _update_queue.push(current_task);
            }
        }
        return;
    }
}