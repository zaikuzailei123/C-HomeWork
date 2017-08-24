#include"InfoAndType.h"
#include"Util.h"
#include"Annual.h"


void ClearWindow(GtkWidget * wid,gpointer data){
    GtkWidget **p = (GtkWidget **)data;
    printf("ready to clear\n");
    printf("%d",p[1]);
    for(int i = 0;i<7;i++) gtk_entry_set_text(GTK_ENTRY(p[i]),"");
    printf("cleared\n");
}

void CreateAddAnnualPage(){
    GtkWidget * button_ensure;
    GtkWidget * button_clear;

    GtkWidget * window1;
    //输入域
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
	window1 = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(window1),"delete_event",G_CALLBACK(SubExitEvent),NULL);
    //获得输入域
    CSNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    MoneyInput = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    Respeople = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    pjApply = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    pjEnd = GTK_ENTRY(gtk_builder_get_object(builder,"entry5"));
    timebg = GTK_ENTRY(gtk_builder_get_object(builder,"entry6"));
    timeed = GTK_ENTRY(gtk_builder_get_object(builder,"entry7"));
    //获得按钮
	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    GtkWidget * entries[7] = {CSNo,MoneyInput,Respeople,pjApply,pjEnd,timebg,timeed};

    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(AddAnnual),entries);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),entries);
	gtk_widget_show_all(window1);
}



void CreateChangeAnnualPage(){



}

void CreateQueryAnnualPage(){



}

void CreateDeleteAnnualPage(){



}
