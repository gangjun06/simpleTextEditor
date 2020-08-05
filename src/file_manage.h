#include <gtk/gtk.h>

#ifndef FILE_MANAGE_H
#define FILE_MANAGE_H

typedef struct {
  GString *file_name;
  GString *file_path;
  GtkWidget *scrolled_window;
  GtkWidget *label;
  GtkWidget *text_view;
  GtkTextBuffer *text_buffer;
} file_manage;

#endif
