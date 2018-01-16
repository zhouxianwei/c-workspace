// gcc main.c -o ui `pkg-config --cflags --libs gtk+-3.0` -mwindows

#include <gtk/gtk.h>
#include <gio/gio.h>

GtkStyleProvider * useCss();

static void
apply_css (GtkWidget *widget, GtkStyleProvider *provider)
{
  gtk_style_context_add_provider (gtk_widget_get_style_context (widget), provider, G_MAXUINT);
  if (GTK_IS_CONTAINER (widget))
    gtk_container_forall (GTK_CONTAINER (widget), (GtkCallback) apply_css, provider);
}

int main (int argc, char *argv[]){
    gtk_init (&argc, &argv);

    GtkWidget *popup;
    popup = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    // gtk_window_set_decorated(GTK_WINDOW(popup), TRUE);  //显示或者隐藏标题栏

    // gtk_window_set_title (GTK_WINDOW (popup), "Window");
    gtk_window_set_default_size(GTK_WINDOW (popup), 374, 374); //设置窗体宽高
    gtk_window_set_resizable (GTK_WINDOW(popup), FALSE); // 设置不能改变大小
    gtk_window_set_position(GTK_WINDOW (popup),  GTK_WIN_POS_CENTER); //居中显示
    // gtk_container_set_border_width(GTK_CONTAINER(popup), 2);

    //box布局
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    //添加布局
    gtk_container_add(GTK_CONTAINER(popup), vbox);

    GtkWidget *top = gtk_button_new_with_label("Button1");
    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    GtkWidget *bottom = gtk_button_new_with_label("Button3");

    //设置组件的大小
    gtk_widget_set_size_request(top,80,44);
    gtk_widget_set_size_request(scroll,374,294);
    gtk_widget_set_size_request(bottom,80,36);
    //此函数为居中对齐 会影响到gtk_box_pack_start的效果
    //https://developer.gnome.org/gtk3/stable/GtkWidget.html#gtk-widget-set-valign
    gtk_widget_set_halign(top, GTK_ALIGN_CENTER);
    gtk_widget_set_halign(scroll, GTK_ALIGN_CENTER);
    gtk_widget_set_halign(bottom, GTK_ALIGN_CENTER);
    //gtk_box_pack_start(box, widget, expand, fill, padding)
    //https://developer.gnome.org/gtk3/stable/GtkBox.html#gtk-box-pack-start
    gtk_box_pack_start(GTK_BOX(vbox), top, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), scroll, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), bottom, FALSE, FALSE, 0);
    gtk_widget_show(scroll);

    GtkWidget *text = gtk_text_view_new();

    gtk_container_add(GTK_CONTAINER(scroll), text);

    gtk_widget_show(text);

    g_signal_connect (popup, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	// apply_css(popup, useCss());

    gtk_widget_show_all(popup);
    gtk_main ();
    return 0;
}


GtkStyleProvider * useCss(){
    //css获取的文档 https://developer.gnome.org/gtk3/stable/GtkStyleContext.html
    GtkStyleProvider *cssProvider = GTK_STYLE_PROVIDER (gtk_css_provider_new ()); //css样式的提供者
    GResource *gresources = g_resource_load("gtk.gresource", NULL); //读取gresource文件
    g_resources_register(gresources); //gresource内容全局化
    gtk_css_provider_load_from_resource (GTK_CSS_PROVIDER (cssProvider), "/ui.css"); //使用gresource内的路径
    return cssProvider;
}