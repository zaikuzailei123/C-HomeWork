#include"InfoAndType.h"
#include"CrtAnnualPage.h"
#include"CrtProjectPage.h"
#include"CrtStaffPage.h"


GtkWidget * check;

void ShowAddPage(GtkWidget *button, gpointer data){
    GtkWidget * check[] = (GtkWidget *p[])data;
    gtk_widget_destroy(window);
    if(gtk_toggle_action_get_active(check[0])){
        CreateAddAnnualPage();
    }
    if(gtk_toggle_action_get_active(check[1])){
        CreateAddProjectPage();
    }
    if(gtk_toggle_action_get_active(check[2])){
        CreateAddStaffPage();
    }

}
void ShowChangePage(GtkWidget *button, gpointer data){
    GtkWidget * check[] = (GtkWidget *p[])data;
    gtk_widget_destroy(window);
    if(gtk_toggle_action_get_active(check[0])){
        CreateChangeAnnualPage();
    }
    if(gtk_toggle_action_get_active(check[1])){
        CreateChangeProjectPage();
    }
    if(gtk_toggle_action_get_active(check[2])){
        CreateChangeStaffPage();
    }
}
void ShowQueryPage(GtkWidget *button, gpointer data){
    GtkWidget * check[] = (GtkWidget *p[])data;
    gtk_widget_destroy(window);
    if(gtk_toggle_action_get_active(check[0])){
        CreateQueryAnnualPage();
    }
    if(gtk_toggle_action_get_active(check[1])){
        CreateQueryProjectPage();
    }
    if(gtk_toggle_action_get_active(check[2])){
        CreateQueryStaffPage();
    }
}
void ShowDeletePage(GtkWidget *button, gpointer data){
    GtkWidget * check[] = (GtkWidget *p[])data;
    gtk_widget_destroy(window);
    if(gtk_toggle_action_get_active(check[0])){
        CreateDeleteAnnualPage();
    }
    if(gtk_toggle_action_get_active(check[1])){
        CreateDeleteProjectPage();
    }
    if(gtk_toggle_action_get_active(check[2])){
        CreateDeleteStaffPage();
    }
}


void ShowStaticPage(GtkWidget *button, gpointer data){
    gtk_widget_destroy(window);
    //��д

}
void ShowTuoguanPage(GtkWidget *button, gpointer data){
    gtk_widget_destroy(window);
    //�й�ҳ������ͷŽڵ㣬Ȼ�����gtk_main_quit
    //��д�йܽ���


}







