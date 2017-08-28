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
int Correspond1(char * Main,char *beTest){
    if(strlen(Main)<strlen(beTest)) return 0;
    char c;int flag = 1;
    for(int i = 0;beTest[i]!='\0'&&Main[i]!='\0';i++){
        c = beTest[i];
        if(c=='*') continue;
        else if(c!=Main[i]){
            flag = 0;
            break;
        }
    }
    return flag;
}

int Correspond2(char * Main,char *beTest){
    char block[5];int i = 0;int count = 0;
    int suc = 0;int total = 0;
    while(beTest[i++]!='\0'){
        if(count <=2){
            block[count++] = beTest[i];
        }
        else{
            block[count] = '\0';
            count = 0;
            total ++;
            if(strstr(Main,block)!=NULL) suc ++;

        }
    }
    double a = (double)suc;
    double b= (double)total;
    if(a/b>=0.4) return 1;
    else return 0;
}

char * ftoRatio(char * src,float n){
    char * p = src;
    if(n>=1.0){
        src[0] = '1';src[1] = '0';src[2] = '0';
        src[3] = '%';src[4] = '\0';
        return src;
    }
    n = n*100;
    if(n>1.0){

        gcvt(n,6,src);printf("the char is %s",src);
        strcat(src,"%");
        return src;
    }
    src[0] = '0';src[1] = '.';
    p = &src[2];int count = 2;
    while(n<1&&count++<6){
        n = n*10;
        if(n = 0) break;
        switch((int)n){
            case 0:*p = '0';break;case 1:*p = '1';break;case 2:*p = '2';break;case 3:*p = '3';break;
            case 4:*p = '4';break;case 5:*p = '5';break;case 6:*p = '6';break;case 7:*p = '7';break;
            case 8:*p = '8';break;case 9:*p = '9';break;
        }
        n = n-(int)n;
        p++;
    }
    *p = '%';
    *(p+1) = '\0';
    return src;


}






