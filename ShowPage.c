#include"InfoAndType.h"
#include"CrtAnnualPage.h"
#include"CrtProjectPage.h"
#include"CrtStaffPage.h"


GtkWidget * check;

void ShowAddPage(GtkWidget *button, gpointer data){
    GtkWidget ** check = (GtkWidget **)data;
    printf("Ready to destroy Window");
    printf("window is %d\nqqq\n",window);
    gtk_widget_destroy(window);
    printf("Destroyed!\n");
    if(gtk_toggle_button_get_active(check[0])){
        printf("Ready to Create Annual Page!\n");
        CreateAddAnnualPage();
    }
    if(gtk_toggle_button_get_active(check[1])){
        CreateAddProjectPage();
    }
    if(gtk_toggle_button_get_active(check[2])){
        CreateAddStaffPage();
    }

}
void ShowChangePage(GtkWidget *button, gpointer data){
    GtkWidget ** check = (GtkWidget **)data;
    gtk_widget_destroy(window);
    if(gtk_toggle_button_get_active(check[0])){
        CreateChangeAnnualPage();
    }
    if(gtk_toggle_button_get_active(check[1])){
        CreateChangeProjectPage();
    }
    if(gtk_toggle_button_get_active(check[2])){
        CreateChangeStaffPage();
    }
}
void ShowQueryPage(GtkWidget *button, gpointer data){
    GtkWidget ** check = (GtkWidget **)data;
    gtk_widget_destroy(window);
    if(gtk_toggle_button_get_active(check[0])){
        CreateQueryAnnualPage();
    }
    if(gtk_toggle_button_get_active(check[1])){
        CreateQueryProjectPage();
    }
    if(gtk_toggle_button_get_active(check[2])){
        CreateQueryStaffPage();
    }
}

void ShowBeiFenPage(GtkWidget *button, gpointer data){

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







