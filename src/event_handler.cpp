#include <gtk/gtk.h>
#include "event_handler.h"

// File --> Open
void on_menuitem_open_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts) {
    gchar *file_name = NULL;        // Name of file to open from dialog box
    gchar *file_contents = NULL;    // For reading contents of file
    gboolean file_success = FALSE;  // File read status
    
    // Show the "Open Text File" dialog box
    gtk_widget_show(app_wdgts->w_dlg_file_choose);
    
    // Check return value from Open Text File dialog box to see if user clicked the Open button
    if (gtk_dialog_run(GTK_DIALOG (app_wdgts->w_dlg_file_choose)) == GTK_RESPONSE_OK) {
        // Get the file name from the dialog box
        file_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(app_wdgts->w_dlg_file_choose));
        if (file_name != NULL) {
            // Copy the contents of the file to dynamically allocated memory
            file_success = g_file_get_contents(file_name, &file_contents, NULL, NULL);
            if (file_success) {
                // Put the contents of the file into the GtkTextBuffer
                gtk_text_buffer_set_text(app_wdgts->textbuffer_main, file_contents, -1);
            }
            g_free(file_contents);
        }
        g_free(file_name);
    }

    // Finished with the "Open Text File" dialog box, so hide it
    gtk_widget_hide(app_wdgts->w_dlg_file_choose);
}

// File --> Close
void on_menuitem_close_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
    // Clear the text from window "Close the file"
    gtk_text_buffer_set_text(app_wdgts->textbuffer_main, "", -1);
}

// File --> Quit
void on_menuitem_quit_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
    gtk_main_quit();
}

// Help --> About
void on_menuitem_about_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
    gtk_widget_show(app_wdgts->w_dlg_about);
    gtk_dialog_run(GTK_DIALOG (app_wdgts->w_dlg_about));
    gtk_widget_hide(app_wdgts->w_dlg_about);
}

// Edit --> Preferences
void on_menuitem_preferences_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
    gtk_widget_show(app_wdgts->w_dlg_preferences);
    if(gtk_dialog_run(GTK_DIALOG (app_wdgts->w_dlg_preferences)) == GTK_RESPONSE_OK){
      g_print("OK!");
    }

    gtk_widget_hide(app_wdgts->w_dlg_preferences);
}


