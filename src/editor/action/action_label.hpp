/*
   Copyright (C) 2010 - 2014 by Fabian Mueller <fabianmueller5@gmx.de>
   Part of the Battle for Wesnoth Project http://www.wesnoth.org/

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY.

   See the COPYING file for more details.
*/

/**
 * @file
 * Editor action classes. Some important points:
 * - This is a polymorphic hierarchy of classes, so actions are usually passed around
 *   as editor_action pointers
 * - The pointers can, in general, be null. Always check for null before doing anything.
 *   The helper functions perform_ that take a pointer do that.
 * - The perform() functions can throw when an error occurs. Use smart pointers if you
 *   need to ensure the pointer is deleted.
 */

#ifndef EDITOR_ACTION_LABEL_HPP
#define EDITOR_ACTION_LABEL_HPP

#include "editor/action/action.hpp"

#include "../../map.hpp"
#include "../../map_label.hpp"


namespace editor {

/**
 * Set label action
 */
class editor_action_label : public editor_action_location
{
	public:
		editor_action_label(map_location loc, const std::string& text, const std::string& team_name,
				SDL_Color color, bool visible_fog, bool visible_shroud, bool immutable)
		: editor_action_location(loc), text_(text) , team_name_(team_name), color_(color)
		, visible_fog_(visible_fog), visible_shroud_(visible_shroud), immutable_(immutable)
		{
		}
		editor_action_label* clone() const;
		editor_action* perform(map_context& mc) const;
		void perform_without_undo(map_context& mc) const;
		const char* get_name() const { return "label"; }
	protected:
		const std::string text_;
		const std::string team_name_;
		SDL_Color color_;
		bool visible_fog_;
		bool visible_shroud_;
		bool immutable_;
};

class editor_action_label_delete : public editor_action_location
{
	public:
		editor_action_label_delete(map_location loc)
		: editor_action_location(loc)
		{
		}
		editor_action_label_delete* clone() const;
		editor_action* perform(map_context& mc) const;
		void perform_without_undo(map_context& mc) const;
		const char* get_name() const { return "label_delete"; }
};

} //end namespace editor

#endif
