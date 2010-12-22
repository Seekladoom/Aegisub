// Copyright (c) 2010, Amar Takhar <verm@aegisub.org>
//
// Permission to use, copy, modify, and distribute this software for any
// purpose with or without fee is hereby granted, provided that the above
// copyright notice and this permission notice appear in all copies.
//
// THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
// WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
// ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
// WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
// ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
// OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
//
// $Id$

/// @file hotkey.cpp
/// @brief Hotkey handler
/// @ingroup hotkey menu event window

#include "config.h"

#ifndef AGI_PRE
#include <math.h>

#include <memory>
#endif

#include <libaegisub/io.h>
#include <libaegisub/json.h>
#include <libaegisub/log.h>

#include "aegisub/hotkey.h"

#include "aegisub/toolbar.h"
#include "libresrc/libresrc.h"
#include "command/command.h"


namespace hotkey {

std::string Combo::Str() { return ""; }
std::string Combo::StrMenu() { return ""; }

Hotkey *hotkey;

Hotkey::~Hotkey() {}

Hotkey::Hotkey() {

	LOG_D("hotkey/init") << "Generating hotkeys.";

    std::istringstream *stream = new std::istringstream(GET_DEFAULT_CONFIG(default_hotkey));
    json::UnknownElement hotkey_root = agi::json::parse(stream);

	json::Object object = hotkey_root;

	for (json::Object::const_iterator index(object.Begin()); index != object.End(); index++) {
		const json::Object::Member& member = *index;
		const json::Array& array = member.element;
		BuildHotkey(member.name, array);

    }
}


void Hotkey::BuildHotkey(std::string context, const json::Array& array) {

	for (json::Array::const_iterator index(array.Begin()); index != array.End(); index++) {

		const json::Object& obj = *index;
	} // for index

}

} // namespace toolbar


