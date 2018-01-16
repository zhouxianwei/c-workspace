#include <gtk/gtk.h>

static gboolean on_delete_event(GtkWidget *widget, GdkEvent *event, gpointer data){
	return FALSE; //返回true阻止关闭window
}

static void printf_msg(GtkWidget *widget, gpointer data){
	gtk_button_set_label(GTK_BUTTON(widget), "连接成功");
}

int main(int argc, char *argv[])
{
	GtkWidget *window, *button;
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "连接测试");
	g_signal_connect (window, "delete-event", G_CALLBACK (on_delete_event), NULL);
	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_container_set_border_width(GTK_CONTAINER (window), 10);
	gtk_window_set_type_hint(GTK_WINDOW(window),GDK_WINDOW_TYPE_HINT_DOCK);
	button = gtk_button_new_with_label("连接");
	g_signal_connect(button, "clicked", G_CALLBACK(printf_msg), NULL);
	// g_signal_connect_swapped (button, "clicked", G_CALLBACK (gtk_widget_destroy), window);
	gtk_container_add(GTK_CONTAINER(window), button);
	// gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_MOUSE);
	gtk_widget_show(button);
	gtk_widget_show(window);
	gtk_main();
	return 0;
}