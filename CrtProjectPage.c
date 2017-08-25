#include"InfoAndType.h"
#include "Util.h"
#include"LoadAndExit.h"
#include"Project.h"


void CreateAddProjectPage(){
    GtkWidget * button_ensure;
    GtkWidget * button_clear;

    GtkWidget * addwindow;

    GtkWidget * CSNo;
    GtkWidget * CNo;
    GtkWidget * pjName;
    GtkWidget * Money;
    GtkWidget * timeBg;
    GtkWidget * timeEnd;
    GtkWidget * evaluate;
    GtkWidget * resPeople;
    GtkWidget * ResPeoTel;
    GtkWidget * resultType;
    GtkWidget * resultName;

    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/AddProjectPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    //获得输入域
    CSNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    CNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    pjName = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    Money = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    timeBg = GTK_ENTRY(gtk_builder_get_object(builder,"entry6"));
    timeEnd = GTK_ENTRY(gtk_builder_get_object(builder,"entry7"));
    evaluate = GTK_ENTRY(gtk_builder_get_object(builder,"entry8"));
    resPeople = GTK_ENTRY(gtk_builder_get_object(builder,"entry9"));
    ResPeoTel = GTK_ENTRY(gtk_builder_get_object(builder,"entry10"));
    resultType = GTK_ENTRY(gtk_builder_get_object(builder,"entry11"));
    resultName = GTK_ENTRY(gtk_builder_get_object(builder,"entry12"));

	pipes->widget[0]= CSNo;
	pipes->widget[1]= CNo;
	pipes->widget[2]= pjName;
	pipes->widget[3]= Money;
	pipes->widget[4]= timeBg;
	pipes->widget[5]= timeEnd;
	pipes->widget[6]= evaluate;
	pipes->widget[7]= resPeople;
	pipes->widget[8]= ResPeoTel;
	pipes->widget[9]= resultType;
	pipes->widget[10]= resultName;

    pipes->n = 11;
    //获得按钮
	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(AddProject),pipes);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));

    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
	gtk_widget_show_all(addwindow);

}

void CreateChangeProjectPage(){



}

void CreateQueryProjectPage(){



}

void CreateDeleteProjectPage(){



}
