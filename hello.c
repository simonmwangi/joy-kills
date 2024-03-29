#include <gtk/gtk.h> 
 
int main(int argc, char** argv) 
{ 
  gtk_init(&argc, &argv); 
  GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
  gtk_window_set_title(GTK_WINDOW (window), "Hello World!"); 
  gtk_window_set_default_size(GTK_WINDOW (window), 200, 200); 
  g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), NULL); 
  
  // Create a scrolled window
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);
  gtk_widget_show(window);
  gtk_main(); 
 
  return 0; 
} 