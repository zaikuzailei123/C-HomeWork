#include"InfoAndType.h"
#include"ShowPage.h"
#include"LoadAndExit.h"
#include"Util.h"

static GtkWidget * button_add;
static GtkWidget * button_change;
static GtkWidget * button_query;
static GtkWidget * button_delete;
static GtkWidget * button_static;
static GtkWidget * button_tuoguan;

static GtkWidget * check[3];
GtkWidget *CreateMainPage(){

	GtkBuilder *builder = gtk_builder_new();

	if ( !gtk_builder_add_from_file(builder,"config/MainPage.glade", NULL)) {
		printf("connot load file!");return NULL;
	}
	//获得窗体
	window = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(window),"delete_event",G_CALLBACK(ExitEvent),NULL);
	//获得检查框
	check[0] = GTK_RADIO_BUTTON(gtk_builder_get_object(builder,"radiobutton1"));
	check[1] = GTK_RADIO_BUTTON(gtk_builder_get_object(builder,"radiobutton2"));
	check[2] = GTK_RADIO_BUTTON(gtk_builder_get_object(builder,"radiobutton3"));
    //获得按钮
	button_add = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_add),"clicked",G_CALLBACK(ShowAddPage),check);

	button_change = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(G_OBJECT(button_change),"clicked",G_CALLBACK(ShowChangePage),check);

	button_query = GTK_BUTTON(gtk_builder_get_object(builder, "button3"));
    g_signal_connect(G_OBJECT(button_query),"clicked",G_CALLBACK(ShowQueryPage),check);

	button_delete = GTK_BUTTON(gtk_builder_get_object(builder, "button4"));
    g_signal_connect(G_OBJECT(button_delete),"clicked",G_CALLBACK(ShowDeletePage),check);

	button_static = GTK_BUTTON(gtk_builder_get_object(builder, "button5"));
    g_signal_connect(G_OBJECT(button_static),"clicked",G_CALLBACK(ShowStaticPage),NULL);
	button_tuoguan = GTK_BUTTON(gtk_builder_get_object(builder, "button6"));
    g_signal_connect(G_OBJECT(button_tuoguan),"clicked",G_CALLBACK(ShowTuoguanPage),NULL);

	gtk_widget_show_all(window);
	return window;
}
