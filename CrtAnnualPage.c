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
    GtkWidget * button_query;
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
	if ( !gtk_builder_add_from_file(builder,"config/ChangeAnnualPage.glade", NULL)) {
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
    for(int i = 0;i<=6;i++) printf("  %d  ",pipes->widget[i]);
    //获得按钮
	button_query = GTK_BUTTON(gtk_builder_get_object(builder, "button3"));
    g_signal_connect(G_OBJECT(button_query),"clicked",G_CALLBACK(FindAnnual),pipes);

	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(ChangeAnnual),pipes);

	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
	gtk_widget_show_all(addwindow);
}

void CreateQueryAnnualPage(){
    //button
    GtkWidget * button_ensure;
    GtkWidget * button_clear;
    GtkWidget * toggle;

    //check
    GtkWidget * CSNoCk;
    GtkWidget * MoneyCk;
    GtkWidget * pjSupportCk;
    GtkWidget * AndOrCk;

    //window
    GtkWidget * addwindow;
    //输入域
    GtkWidget * CSNo;
    GtkWidget * MoneyF;
    GtkWidget * MoneyC;
    GtkWidget * pjApplyF;
    GtkWidget * pjApplyC;

    GtkWidget * Scroll;















    GtkWidget * clist;


    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/QueryAnnualPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    //获得输入域
    CSNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    MoneyF = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    MoneyC = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    pjApplyF = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    pjApplyC = GTK_ENTRY(gtk_builder_get_object(builder,"entry5"));
    //获得check
    CSNoCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton1"));
    MoneyCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton2"));
    pjSupportCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton3"));
    AndOrCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton4"));
    //

    //创建Clist
    clist=gtk_clist_new(8);
    gtk_clist_set_column_title(GTK_CLIST(clist),0,"年度编号");
    gtk_clist_set_column_title(GTK_CLIST(clist),1,"投入资金");
    gtk_clist_set_column_title(GTK_CLIST(clist),2,"负责人");
    gtk_clist_set_column_title(GTK_CLIST(clist),3,"申报项目数");
    gtk_clist_set_column_title(GTK_CLIST(clist),4,"实际支持项目数");
    gtk_clist_set_column_title(GTK_CLIST(clist),5,"结题项目数");
    gtk_clist_set_column_title(GTK_CLIST(clist),6,"计划开始时间");
    gtk_clist_set_column_title(GTK_CLIST(clist),7,"计划结束时间");
    gtk_clist_column_titles_show(GTK_CLIST(clist));
    gtk_container_add(GTK_CONTAINER(Scroll),clist);

	pipes->widget[0]= CSNo;
	pipes->widget[1]= MoneyF;
	pipes->widget[2]= MoneyC;
	pipes->widget[3]= pjApplyF;
	pipes->widget[4]= pjApplyC;
    pipes->n = 5;
    pipes->widget[5]= CSNoCk;
    pipes->widget[6]= MoneyCk;
    pipes->widget[7]= pjSupportCk;
    pipes->widget[8]= AndOrCk;
    pipes->widget[9] = clist;

    //获得按钮
	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(QueryAnnual),pipes);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);

	gtk_widget_show_all(addwindow);
}

void CreateDeleteAnnualPage(){



}
