#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtk/gtk.h>

typedef struct{
  GtkWidget *content_area;
  GtkWidget *window;
  GtkWidget *stack;
  GtkWidget *add_pass_area;
} Window;

int show_main_window(int argc, char** argv);

#endif
