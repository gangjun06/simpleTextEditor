#include <gtk/gtk.h>

#ifndef APP_WIDGET_H
#define APP_WIDGET_H

typedef struct {
    GtkWidget *w_txtvw_main;            // Pointer to text view object
    GtkWidget *w_dlg_file_choose;       // Pointer to file chooser dialog box
    GtkWidget *w_dlg_preferences;       // Pointer to file chooser dialog box
    GtkTextBuffer *textbuffer_main;     // Pointer to text buffer
    GtkWidget *w_dlg_about;             // Pointer to about dialog box
} app_widgets;

#endif
