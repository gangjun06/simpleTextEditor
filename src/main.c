#include <gtk/gtk.h>
#include "app_widget.h"
#include "event_handler.h"

int main(int argc, char *argv[])
{
  GtkBuilder      *builder; 
  //GtkWidget       *window;
  app_widgets     *widgets = g_slice_new(app_widgets);

  gtk_init(&argc, &argv);

  builder = gtk_builder_new_from_file("glade/main.glade");
  widgets->window = GTK_WIDGET(gtk_builder_get_object(builder, "window_main"));

  widgets->text_list = NULL;

  widgets->w_dlg_file_choose = GTK_WIDGET(gtk_builder_get_object(builder, "dlg_file_choose"));
  widgets->w_dlg_about = GTK_WIDGET(gtk_builder_get_object(builder, "dlg_about"));
  widgets->w_dlg_save = GTK_WIDGET(gtk_builder_get_object(builder, "dlg_save"));
  widgets->w_dlg_preferences = GTK_WIDGET(gtk_builder_get_object(builder, "dlg_preferences"));
  widgets->w_notebook_main = GTK_NOTEBOOK(gtk_notebook_new());
  gtk_box_pack_end(GTK_BOX(gtk_builder_get_object(builder, "main_gtkbox")), GTK_WIDGET(widgets->w_notebook_main), TRUE, TRUE, 0);

  gtk_builder_connect_signals(builder, widgets);
  g_object_unref(builder);

  gtk_widget_show(widgets->window);
  gtk_widget_show_all(widgets->window);
  gtk_main();
  g_slice_free(app_widgets, widgets);

  return 0;
}

void on_window_main_destroy()
{
  gtk_main_quit();
}
