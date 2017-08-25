#include"InfoAndType.h"
#include"Util.h"
#include"Annual.h"
#include"LoadAndExit.h"





void CreateAddAnnualPage(){
    GtkWidget * button_ensure;
    GtkWidget * button_clear;

    GtkWidget * addwindow;
    GtkWidget * CSNo;
    GtkWidget * MoneyInput;
    GtkWidget * Respeople;
    GtkWidget * pjApply;
    GtkWidget * pjEnd;
    GtkWidget * timebg;
    GtkWidget * timeed;

    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/AddAnnualPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    //获得输入域
    CSNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    MoneyInput = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    Respeople = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    pjApply = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    pjEnd = GTK_ENTRY(gtk_builder_get_object(builder,"entry5"));
    timebg = GTK_ENTRY(gtk_builder_get_object(builder,"entry6"));
    timeed = GTK_ENTRY(gtk_builder_get_object(builder,"entry7"));
	pipes->widget[0]= CSNo;
	pipes->widget[1]= MoneyInput;
	pipes->widget[2]= Respeople;
	pipes->widget[3]= pjApply;
	pipes->widget[4]= pjEnd;
	pipes->widget[5]= timebg;
	pipes->widget[6]= timeed;
    pipes->n = 7;
    //获得按钮
	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(AddAnnual),pipes);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));

    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
	gtk_widget_show_all(addwindow);
}

void CreateChangeAnnualPage(){



}

void CreateQueryAnnualPage(){



}

void CreateDeleteAnnualPage(){



}
