#include"InfoAndType.h"
#include"LoadAndExit.h"
#include"Staff.h"
#include "Util.h"

void CreateAddStaffPage(){
    GtkWidget * button_ensure;
    GtkWidget * button_clear;

    GtkWidget * addwindow;

    GtkWidget * CSNo;
    GtkWidget * CNo;
    GtkWidget * SNo;
    GtkWidget * name;
    GtkWidget * old;;
    GtkWidget * status;
    GtkWidget * profession;
    GtkWidget * classNo;
    GtkWidget * talent;
    GtkWidget * task;
    GtkWidget * tel;
    GtkWidget * que;

    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/AddStaffPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    //获得输入域
    CSNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    CNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    SNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    name = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    old = GTK_ENTRY(gtk_builder_get_object(builder,"entry5"));
    status = GTK_ENTRY(gtk_builder_get_object(builder,"entry6"));
    profession = GTK_ENTRY(gtk_builder_get_object(builder,"entry7"));
    classNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry8"));
    talent = GTK_ENTRY(gtk_builder_get_object(builder,"entry9"));
    task = GTK_ENTRY(gtk_builder_get_object(builder,"entry10"));
    tel = GTK_ENTRY(gtk_builder_get_object(builder,"entry11"));
    que = GTK_ENTRY(gtk_builder_get_object(builder,"entry12"));

	pipes->widget[0]= CSNo;
	pipes->widget[1]= CNo;
	pipes->widget[2]= SNo;
	pipes->widget[3]= name;
	pipes->widget[4]= old;
	pipes->widget[5]= status;
	pipes->widget[6]= profession;
	pipes->widget[7]= classNo;
	pipes->widget[8]= talent;
	pipes->widget[9]= task;
	pipes->widget[10]= tel;
	pipes->widget[11]= que;

    pipes->n = 12;
    //获得按钮
	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(AddStaff),pipes);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));

    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
	gtk_widget_show_all(addwindow);
}

void CreateChangeStaffPage(){



}

void CreateQueryStaffPage(){



}

void CreateDeleteStaffPage(){



}
