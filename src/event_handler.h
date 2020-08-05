#include <gtk/gtk.h>
#include "app_widget.h"

#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

void on_menuitem_open_activate(GtkMenuItem *menuitem, app_widgets *widgets);

void on_menuitem_close_activate(GtkMenuItem *menuitem, app_widgets *widgets);

void on_menuitem_quit_activate(GtkMenuItem *menuitem, app_widgets *widgets);

void on_menuitem_about_activate(GtkMenuItem *menuitem, app_widgets *widgets);

void on_menuitem_preferences_activate(GtkMenuItem *menuitem, app_widgets *widgets);

#endif
