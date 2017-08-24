#include"InfoAndType.h"
#include"ShowPage.h"
#include"LoadAndExit.h"

GtkWidget * button_add;
GtkWidget * button_change;
GtkWidget * button_query;
GtkWidget * button_delete;
GtkWidget * button_static;
GtkWidget * button_tuoguan;

GtkWidget * check[3];
GtkWidget *CreateMainPage(){

	GtkBuilder *builder = gtk_builder_new();

	if ( !gtk_builder_add_from_file(builder,"config/MainPage.glade", NULL)) {
		printf("connot load file!");return NULL;
	}
	//获得窗体
	GtkWidget *window = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(ExitEvent),NULL);
	//获得检查框
	check[0] = GTK_RADIO_BUTTON(gtk_builder_get_object(builder,"radiobutton1"));
	check[1] = GTK_RADIO_BUTTON(gtk_builder_get_object(builder,"radiobutton2"));
	check[2] = GTK_RADIO_BUTTON(gtk_builder_get_object(builder,"radiobutton3"));
    //获得按钮
	GtkButton *button_add = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_add),"clicked",G_CALLBACK(ShowAddPage),check);

	GtkButton *button_change = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(G_OBJECT(button_change),"clicked",G_CALLBACK(ShowChangePage),check);

	GtkButton *button_query = GTK_BUTTON(gtk_builder_get_object(builder, "button3"));
    g_signal_connect(G_OBJECT(button_query),"clicked",G_CALLBACK(ShowQueryPage),check);

	GtkButton *button_delete = GTK_BUTTON(gtk_builder_get_object(builder, "button4"));
    g_signal_connect(G_OBJECT(button_delete),"clicked",G_CALLBACK(ShowDeletePage),check);

	GtkButton *button_static = GTK_BUTTON(gtk_builder_get_object(builder, "button5"));
    g_signal_connect(G_OBJECT(button_static),"clicked",G_CALLBACK(ShowStaticPage),NULL);
	GtkButton *button_tuoguan = GTK_BUTTON(gtk_builder_get_object(builder, "button6"));
    g_signal_connect(G_OBJECT(button_tuoguan),"clicked",G_CALLBACK(ShowTuoguanPage),NULL);

	gtk_widget_show_all(window);
}
