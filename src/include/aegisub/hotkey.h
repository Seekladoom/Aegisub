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

/// @file hotkey.h
/// @brief Hotkey handler
/// @ingroup hotkey menu event window

#include "config.h"

#ifndef AGI_PRE
#include <math.h>

#include <memory>
#endif

namespace hotkey {

class Hotkey;
extern Hotkey *hotkey;

typedef std::vector<std::string> ComboMap;

class Combo {
public:
	std::string Str();
	std::string StrMenu();
	ComboMap Get();
	std::string CmdName() { return cmd_name; }
	Combo() {}
	~Combo() {}
private:
	std::string cmd_name;
};

class Hotkey {
public:
	Hotkey();
	~Hotkey();

private:
	typedef std::multimap<std::string, Combo*> HotkeyMap;
	void BuildHotkey(std::string context, const json::Array& array);
};

} // namespace hotkey
