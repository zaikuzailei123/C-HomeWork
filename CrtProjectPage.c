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
    GtkWidget * button_ensure;
    GtkWidget * button_clear;
    GtkWidget * button_query;

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
	if ( !gtk_builder_add_from_file(builder,"config/ChangeProjectPage.glade", NULL)) {
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
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(ChangeProject),pipes);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
    button_query = GTK_BUTTON(gtk_builder_get_object(builder, "button3"));
    g_signal_connect(G_OBJECT(button_query),"clicked",G_CALLBACK(FindProject),pipes);

	gtk_widget_show_all(addwindow);
}
void QueryProjectSwitch(GtkWidget *wid,gpointer data){
    pipe*A = (pipe *)data;
    gtk_clist_clear(A->widget[10]);
    gtk_clist_clear(A->widget[11]);

    int flag = 0;//判断是否选择了一项查询
    if(gtk_toggle_button_get_active(A->widget[5])){
       flag = 1;
       if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0){Msg(1,"请输入项目编号！");return ;}

    }
    if(gtk_toggle_button_get_active(A->widget[6])){
        flag = 1;
        if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0){Msg(1,"请输入经费下限！");return ;}
        if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0){Msg(1,"请输入经费上限！");return ;}
    }
    if(gtk_toggle_button_get_active(A->widget[7])){
        flag = 1;
        if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0){Msg(1,"请输入项目名称！");return ;}
    }
    if(gtk_toggle_button_get_active(A->widget[8])){
        flag = 1;
        if(strcmp(gtk_entry_get_text(A->widget[4]),"")==0){Msg(1,"请输入成果形式！");return ;}
    }

    if(flag==0){Msg(1,"请至少选择一种方式查询");return ;}
    QueryProject(wid,A);
}

void DeleteProjectEnsure(GtkWidget* wid,gpointer data);
static GtkWidget *t;
void CreateQueryProjectPage(){
    //button
    GtkWidget * button_ensure;
    GtkWidget * button_clear;
    GtkWidget * button_delete;
    //check
    GtkWidget * CNoCk;
    GtkWidget * MoneyCk;
    GtkWidget * pjNameCk;
    GtkWidget * resultnmCk;
    GtkWidget * AndOrCk;

    //window
    GtkWidget * addwindow;
    //输入域
    GtkWidget * CNo;
    GtkWidget * MoneyF;
    GtkWidget * MoneyC;
    GtkWidget * pjName;
    GtkWidget * resultType;

    GtkWidget * Scroll1;
    GtkWidget * Scroll2;


    GtkWidget * clist1;
    GtkWidget * clist2;

    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/QueryProjectPage.glade", NULL)) {
		printf("connot load file!");return ;
	}
	printf("Load!\n");
	//获得窗体
	addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(SubExitEvent),addwindow);
    //获得输入域
    CNo = GTK_ENTRY(gtk_builder_get_object(builder,"entry1"));
    MoneyF = GTK_ENTRY(gtk_builder_get_object(builder,"entry2"));
    MoneyC = GTK_ENTRY(gtk_builder_get_object(builder,"entry3"));
    pjName = GTK_ENTRY(gtk_builder_get_object(builder,"entry4"));
    resultType = GTK_ENTRY(gtk_builder_get_object(builder,"entry5"));
    //获得check
    CNoCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton1"));
    MoneyCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton2"));
    pjNameCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton3"));
    resultnmCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton4"));
    AndOrCk = GTK_CHECK_BUTTON(gtk_builder_get_object(builder,"checkbutton5"));
    //
    printf("OK");
    //创建Clist
    clist1=gtk_clist_new(12);
    gtk_clist_set_column_title(GTK_CLIST(clist1),0,"年度编号");
    gtk_clist_set_column_title(GTK_CLIST(clist1),1,"项目编号");
    gtk_clist_set_column_title(GTK_CLIST(clist1),2,"项目名称");
    gtk_clist_set_column_title(GTK_CLIST(clist1),3,"经费数");
    gtk_clist_set_column_title(GTK_CLIST(clist1),4,"参与人员");
    gtk_clist_set_column_title(GTK_CLIST(clist1),5,"立项时间");
    gtk_clist_set_column_title(GTK_CLIST(clist1),6,"结题时间");
    gtk_clist_set_column_title(GTK_CLIST(clist1),7,"完成评价");
    gtk_clist_set_column_title(GTK_CLIST(clist1),8,"负责人");
    gtk_clist_set_column_title(GTK_CLIST(clist1),9,"联系电话");
    gtk_clist_set_column_title(GTK_CLIST(clist1),10,"成果形式");
    gtk_clist_set_column_title(GTK_CLIST(clist1),11,"成果名称");
    gtk_clist_column_titles_show(GTK_CLIST(clist1));
    gtk_clist_set_column_auto_resize(clist1,0,TRUE);gtk_clist_set_column_auto_resize(clist1,1,TRUE);
    gtk_clist_set_column_auto_resize(clist1,2,TRUE);gtk_clist_set_column_auto_resize(clist1,3,TRUE);
    gtk_clist_set_column_auto_resize(clist1,4,TRUE);gtk_clist_set_column_auto_resize(clist1,5,TRUE);
    gtk_clist_set_column_auto_resize(clist1,6,TRUE);gtk_clist_set_column_auto_resize(clist1,7,TRUE);
    gtk_clist_set_column_auto_resize(clist1,8,TRUE);gtk_clist_set_column_auto_resize(clist1,9,TRUE);
    gtk_clist_set_column_auto_resize(clist1,10,TRUE);gtk_clist_set_column_auto_resize(clist1,11,TRUE);
    Scroll1 = GTK_SCROLLED_WINDOW(gtk_builder_get_object(builder,"scrolledwindow1"));
    gtk_container_add(GTK_CONTAINER(Scroll1),clist1);


    clist2=gtk_clist_new(11);
    gtk_clist_set_column_title(GTK_CLIST(clist2),0,"项目编号");
    gtk_clist_set_column_title(GTK_CLIST(clist2),1,"学号");
    gtk_clist_set_column_title(GTK_CLIST(clist2),2,"姓名");
    gtk_clist_set_column_title(GTK_CLIST(clist2),3,"年龄");
    gtk_clist_set_column_title(GTK_CLIST(clist2),4,"类别");
    gtk_clist_set_column_title(GTK_CLIST(clist2),5,"学院专业");
    gtk_clist_set_column_title(GTK_CLIST(clist2),6,"班级");
    gtk_clist_set_column_title(GTK_CLIST(clist2),7,"本人特长");
    gtk_clist_set_column_title(GTK_CLIST(clist2),8,"承担任务");
    gtk_clist_set_column_title(GTK_CLIST(clist2),9,"联系电话");
    gtk_clist_set_column_title(GTK_CLIST(clist2),10,"贡献排名");
    gtk_clist_column_titles_show(GTK_CLIST(clist2));
    gtk_clist_set_column_auto_resize(clist2,0,TRUE);gtk_clist_set_column_auto_resize(clist2,1,TRUE);
    gtk_clist_set_column_auto_resize(clist2,2,TRUE);gtk_clist_set_column_auto_resize(clist2,3,TRUE);
    gtk_clist_set_column_auto_resize(clist2,4,TRUE);gtk_clist_set_column_auto_resize(clist2,5,TRUE);
    gtk_clist_set_column_auto_resize(clist2,6,TRUE);gtk_clist_set_column_auto_resize(clist2,7,TRUE);
    gtk_clist_set_column_auto_resize(clist2,8,TRUE);gtk_clist_set_column_auto_resize(clist2,9,TRUE);
    gtk_clist_set_column_auto_resize(clist2,10,TRUE);
    Scroll2 = GTK_SCROLLED_WINDOW(gtk_builder_get_object(builder,"scrolledwindow2"));
    gtk_container_add(GTK_CONTAINER(Scroll2),clist2);

	pipes->widget[0]= CNo;
	pipes->widget[1]= MoneyF;
	pipes->widget[2]= MoneyC;
	pipes->widget[3]= pjName;
	pipes->widget[4]= resultType;
    pipes->n = 5;
    pipes->widget[5]= CNoCk;
    pipes->widget[6]= MoneyCk;
    pipes->widget[7]= pjNameCk;
    pipes->widget[8]= resultnmCk;
    pipes->widget[9]= AndOrCk;
    pipes->widget[10] = clist1;
    pipes->widget[11] = clist2;
    t = addwindow;
    //获得按钮
	button_ensure = GTK_BUTTON(gtk_builder_get_object(builder, "button1"));
    g_signal_connect(G_OBJECT(button_ensure),"clicked",G_CALLBACK(QueryProjectSwitch),pipes);
	button_clear = GTK_BUTTON(gtk_builder_get_object(builder, "button2"));
    g_signal_connect(G_OBJECT(button_clear),"clicked",G_CALLBACK(ClearWindow),pipes);
	button_delete = GTK_BUTTON(gtk_builder_get_object(builder, "button3"));
    g_signal_connect(G_OBJECT(button_delete),"clicked",G_CALLBACK(DeleteProjectEnsure),clist1);
	gtk_widget_show_all(addwindow);
}
void DeleteProjectEnsure(GtkWidget* wid,gpointer data){
    GtkWidget*clist = (GtkWidget * )data;

    GtkWidget*dialog = gtk_dialog_new_with_buttons ("删除列表中的数据", t,GTK_DIALOG_MODAL,
                                          GTK_STOCK_DELETE, GTK_RESPONSE_OK,GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,NULL);
    GtkWidget * label = gtk_label_new ("          确定要删除列表中的所有数据吗？         \n                (子项也将会被删除！)    ");
    gtk_box_pack_start_defaults (GTK_BOX (GTK_DIALOG (dialog)->vbox), label);
    gtk_widget_show_all (dialog);
    if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_OK){
        DeleteProject(NULL,clist);
    }
    gtk_widget_destroy (dialog);
}








