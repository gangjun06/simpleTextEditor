#include <gtk/gtk.h>

#ifndef FILE_MANAGE_H
#define FILE_MANAGE_H

typedef struct {
  gchar *file_name;
  gchar *file_path;
  GtkTextBuffer *textbuffer;
} file_manage;

#endif
