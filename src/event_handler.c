#include <gtk/gtk.h>
#include "event_handler.h"
#include "app_widget.h"

// File --> Open
void on_menuitem_open_activate(GtkMenuItem *menuitem, app_widgets *widgets) {
  gchar *file_name = NULL;        // Name of file to open from dialog box
  gchar *file_contents = NULL;    // For reading contents of file
  gboolean file_success = FALSE;  // File read status

  // Show the "Open Text File" dialog box
  gtk_widget_show(widgets->w_dlg_file_choose);

  // Check return value from Open Text File dialog box to see if user clicked the Open button
  if (gtk_dialog_run(GTK_DIALOG (widgets->w_dlg_file_choose)) == GTK_RESPONSE_OK) {
    // Get the file name from the dialog box
    file_name = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widgets->w_dlg_file_choose));
    if (file_name != NULL) {
      // Copy the contents of the file to dynamically allocated memory
      file_success = g_file_get_contents(file_name, &file_contents, NULL, NULL);
      if (file_success) {
        GtkWidget *scrolledWidget = gtk_scrolled_window_new(NULL, NULL);
        GtkTextBuffer *buffer = gtk_text_buffer_new(NULL);
        gtk_text_buffer_set_text(buffer, file_contents, -1);
        GtkWidget *textWidget = gtk_text_view_new_with_buffer(buffer);
        gtk_container_add(GTK_CONTAINER(scrolledWidget), textWidget);
        gtk_notebook_append_page(widgets->w_notebook_main, scrolledWidget, NULL);

        gtk_widget_show_all(widgets->window);
      }
      g_free(file_contents);
    }
    g_free(file_name);
  }

  // Finished with the "Open Text File" dialog box, so hide it
  gtk_widget_hide(widgets->w_dlg_file_choose);
}

// File --> Close
void on_menuitem_close_activate(GtkMenuItem *menuitem, app_widgets *app_wdgts)
{
  // Clear the text from window "Close the file"
  //gtk_text_buffer_set_text(app_wdgts->textbuffer_main, "", -1);
  g_print("success_close");
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


