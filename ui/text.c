#include <gtk/gtk.h>

void entry_callback(GtkWidget *widget, gpointer label){
        const gchar *entry_text;

        //获取文本内容
        entry_text = gtk_entry_get_text(GTK_ENTRY(widget));

        gtk_label_set_text(GTK_LABEL(label), (char *)entry_text);

        fflush(stdout);

}

int main(int argc, char *argv[]){
	GtkWidget *window;
	gtk_init(&argc, &argv);
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER); //设置窗体位置

	GtkWidget *entry = gtk_entry_new();
	GtkWidget *label = gtk_label_new("hello label");
	GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);

	gtk_container_add(GTK_CONTAINER(window), box);

	gtk_container_add(GTK_CONTAINER(box), label);

	gtk_container_add(GTK_CONTAINER(box), entry);

	gtk_entry_set_max_length(GTK_ENTRY(entry), 100);

	g_signal_connect(entry, "activate", G_CALLBACK(entry_callback), label);

	g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}