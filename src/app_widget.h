#include <gtk/gtk.h>
#include <gmodule.h>


#ifndef APP_WIDGET_H
#define APP_WIDGET_H

typedef struct {
    GtkWidget *window;
    GtkWidget *w_dlg_file_choose;
    GtkWidget *w_dlg_preferences;
    GtkNotebook *w_notebook_main;
    GList *text_list;
    int current;
    GtkWidget *w_dlg_about;
} app_widgets;

#endif
