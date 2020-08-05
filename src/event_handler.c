#include <gtk/gtk.h>
#include <gmodule.h>
#include "event_handler.h"
#include "app_widget.h"
#include "file_manage.h"

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
        file_manage *manage = g_slice_new(file_manage); 
        manage->file_path = g_string_new(file_name);
        manage->scrolled_window = gtk_scrolled_window_new(NULL, NULL);
        manage->text_buffer = gtk_text_buffer_new(NULL);
        gtk_text_buffer_set_text(manage->text_buffer, file_contents, -1);
        manage->text_view = gtk_text_view_new_with_buffer(manage->text_buffer);
        gtk_container_add(GTK_CONTAINER(manage->scrolled_window), manage->text_view);
        gtk_notebook_append_page(widgets->w_notebook_main, manage->scrolled_window, NULL);

        widgets->text_list = g_list_append(widgets->text_list, manage);
        //gtk_notebook_set_current_page(widgets->w_notebook_main,  g_list_length(widgets->text_list)-1);

        gtk_widget_show_all(widgets->window);
      }
      g_free(file_name);
      g_free(file_contents);
    }
  }

  // Finished with the "Open Text File" dialog box, so hide it
  gtk_widget_hide(widgets->w_dlg_file_choose);
}

// File --> New
void on_menuitem_new_activate(GtkMenuItem *menuitem, app_widgets *widgets)
{
  file_manage *manage = g_slice_new(file_manage); 
  manage->file_path = NULL;
  manage->scrolled_window = gtk_scrolled_window_new(NULL, NULL);
  manage->text_buffer = gtk_text_buffer_new(NULL);
  manage->text_view = gtk_text_view_new_with_buffer(manage->text_buffer);
  gtk_container_add(GTK_CONTAINER(manage->scrolled_window), manage->text_view);
  gtk_notebook_append_page(widgets->w_notebook_main, manage->scrolled_window, NULL);

  widgets->text_list = g_list_append(widgets->text_list, manage);
  //gtk_notebook_set_current_page(widgets->w_notebook_main,  g_list_length(widgets->text_list)-1);

  gtk_widget_show_all(widgets->window);
}

// File --> Save
void on_menuitem_save_activate(GtkMenuItem *menuitem, app_widgets *widgets)
{
  gint current =  gtk_notebook_get_current_page(GTK_NOTEBOOK(widgets->w_notebook_main));
  file_manage *manage;
  gchar *text;
  gboolean file_success;
  GtkTextIter start, end;
  manage = g_list_nth_data(widgets->text_list, current);
  gtk_text_buffer_get_bounds(manage->text_buffer, &start, &end);
  text = gtk_text_buffer_get_text(manage->text_buffer, &start, &end, FALSE);
  if(manage->file_path==NULL){
    g_print("save_as\n");
    return;
  }
  file_success = g_file_set_contents(manage->file_path->str, text, -1, NULL);
  if(!file_success){
    g_print("Error");
  }
}

// File --> Close
void on_menuitem_close_activate(GtkMenuItem *menuitem, app_widgets *widgets)
{
  gint current =  gtk_notebook_get_current_page(GTK_NOTEBOOK(widgets->w_notebook_main));
  file_manage *manage;
  manage = g_list_nth_data(widgets->text_list, current);
  widgets->text_list = g_list_remove(widgets->text_list, manage);
  gtk_notebook_remove_page(GTK_NOTEBOOK(widgets->w_notebook_main), current);
  g_slice_free(file_manage, manage);
}

// File --> Quit
void on_menuitem_quit_activate(GtkMenuItem *menuitem, app_widgets *widgets)
{
  gtk_main_quit();
}

// Help --> About
void on_menuitem_about_activate(GtkMenuItem *menuitem, app_widgets *widgets)
{
  gtk_widget_show(widgets->w_dlg_about);
  gtk_dialog_run(GTK_DIALOG (widgets->w_dlg_about));
  gtk_widget_hide(widgets->w_dlg_about);
}

// Edit --> Preferences
void on_menuitem_preferences_activate(GtkMenuItem *menuitem, app_widgets *widgets)
{
  gtk_widget_show(widgets->w_dlg_preferences);
  if(gtk_dialog_run(GTK_DIALOG (widgets->w_dlg_preferences)) == GTK_RESPONSE_OK){
    g_print("OK!");
  }

  gtk_widget_hide(widgets->w_dlg_preferences);
}

