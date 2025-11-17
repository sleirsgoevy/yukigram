/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#include "history/history_location_manager.h"

#include "mainwidget.h"
#include "core/file_utilities.h"
#include "lang/lang_keys.h"
#include "ui/image/image.h"
#include "data/data_file_origin.h"
#include "platform/platform_specific.h"

QString LocationClickHandler::copyToClipboardText() const {
	return _text;
}

QString LocationClickHandler::copyToClipboardContextItemText() const {
	return tr::lng_context_copy_link(tr::now);
}

void LocationClickHandler::onClick(ClickContext context) const {
	Platform::LaunchMaps(_point, [text = _text] {
		File::OpenUrl(text);
	});
}

void LocationClickHandler::setup() {
	_text = Url(_point);
}

QString LocationClickHandler::Url(const Data::LocationPoint &point) {
	return u"https://www.openstreetmap.org/?mlat="_q
		+ point.latAsString()
		+ u"&mlon="_q
		+ point.lonAsString()
		+ u"#map=16/"_q
		+ point.latAsString()
		+ u"/"_q
		+ point.lonAsString();
}
