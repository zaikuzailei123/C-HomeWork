#include "InfoAndType.h"
#include"Util.h"

void Msg(int mode,char * msg){
    GtkWidget* dialog ;
    GtkMessageType type ;
    char *message = msg;
    switch(mode){
    case 1 :
        type = GTK_MESSAGE_ERROR ; break;
    case 2 :
        type = GTK_MESSAGE_INFO ; break;
    }
    dialog = gtk_message_dialog_new(NULL,GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                    type ,GTK_BUTTONS_OK,message);
    gtk_window_set_position(dialog,GTK_WIN_POS_CENTER);
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}


void ClearWindow(GtkWidget * wid,gpointer data){
    pipe * A = (pipe *)data;
    for(int i = 0;i<A->n;i++){
     gtk_entry_set_text(A->widget[i],"");

    }
}

void FreeAllPoint(point * head){
    while(head!=NULL){
        point * tmp = head;
        head = head->next;
        free(tmp);
    }
}
int Correspond(char * Main,char *beTest){

}



