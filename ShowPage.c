#include"InfoAndType.h"
#include"CrtAnnualPage.h"
#include"CrtProjectPage.h"
#include"CrtStaffPage.h"
#include"LoadAndExit.h"


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
    gtk_widget_destroy(window);
}

void ShowStaticPage(GtkWidget *button, gpointer data){
    GtkWidget ** check = (GtkWidget **)data;
    gtk_widget_destroy(window);
    if(gtk_toggle_button_get_active(check[0])){
        CreateStaticAnnualPage();
    }
    if(gtk_toggle_button_get_active(check[1])){
        CreateStaticProjectPage();
    }
    if(gtk_toggle_button_get_active(check[2])){
        CreateStaticStaffPage();
    }
}
gboolean window_drag(GtkWidget *widget, GdkEventButton *event, GdkWindowEdge edge);
static int drag = 0;
void ShowTuoguanPage(GtkWidget *button, gpointer data){
    gtk_widget_destroy(window);
    //托管页面必须释放节点，然后调用gtk_main_quit
    //编写托管界面
    gtk_widget_destroy(window);
    GtkWidget * addwindow;
    GtkWidget * image;
    GtkBuilder *builder = gtk_builder_new();
	if ( !gtk_builder_add_from_file(builder,"config/Tuoguan.glade", NULL)) {
		printf("connot load file!");return ;
	}
    addwindow = GTK_WIDGET(gtk_builder_get_object(builder,"window1"));
    printf("  %d  ",addwindow);
    g_signal_connect(G_OBJECT(addwindow),"delete_event",G_CALLBACK(ExitEvent),NULL);

    //实现拖动小图标（棒呆了……）
    gtk_widget_add_events(addwindow, GDK_BUTTON_PRESS_MASK);
    g_signal_connect(G_OBJECT(addwindow), "button-press-event", G_CALLBACK(window_drag), NULL);

    image = GTK_IMAGE(gtk_builder_get_object(builder,"image1"));
    gtk_image_set_from_file (image,"image/Tuoguan.png");
    gtk_widget_show_all(addwindow);
}
gboolean window_drag(GtkWidget *widget, GdkEventButton *event, GdkWindowEdge edge){
    if (event->button == 1){
        gtk_window_begin_move_drag(GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                   event->button,event->x_root, event->y_root, event->time);
    }
    if(event->type==GDK_2BUTTON_PRESS){
        window = CreateMainPage();
        gtk_widget_destroy(widget);
    }
    return FALSE;
}





