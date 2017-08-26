#include"InfoAndType.h"
#include"LoadAndExit.h"

void AddAnnual(GtkWidget *wid,gpointer data) {
    pipe *A = (pipe *)data;

    annual * heada = ahead;
    int flag = 0;
    while(heada!=NULL) {
        if(strcmp(heada->data.CSNo,gtk_entry_get_text(A->widget[0]))==0) {
            flag = 1;
        }
        heada = heada->next;
    }
    printf("Ready to typein\n");
    printf("the typeinner is %d\n",A->widget[0]);
    if(flag ==1) {Msg(1,"该年份已经有信息！"); return ;}

    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {Msg(1,"请输入年份！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {Msg(1,"请输入投入资金！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0) {Msg(1,"请输入负责人！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0) {Msg(1,"请输入申请项目数！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[4]),"")==0) {Msg(1,"请输入结题项目数！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[5]),"")==0) {Msg(1,"请输入计划开始时间！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[6]),"")==0) {Msg(1,"请输入计划结束时间！");return ;}

    annual *tmp = (annual *)malloc(sizeof(annual));
    tmp->next = NULL;tmp->pjhead = NULL;
    strcpy(tmp->data.CSNo,gtk_entry_get_text(A->widget[0]));
    tmp->data.moneyInput = atof(gtk_entry_get_text(A->widget[1]));
    strcpy(tmp->data.resPeople,gtk_entry_get_text(A->widget[2]));
    tmp->data.pjApplyNum = atoi(gtk_entry_get_text(A->widget[3]));
    tmp->data.pjSupportNum = 0;
    tmp->data.pjEndNum=atoi(gtk_entry_get_text(A->widget[4]));
    strcpy(tmp->data.timgBg,gtk_entry_get_text(A->widget[5]));
    strcpy(tmp->data.timeEnd,gtk_entry_get_text(A->widget[6]));
    if(heada==NULL){
        ahead = tmp;
        heada = tmp;
    }
    else{
        if(strcmp(heada->data.CSNo,tmp->data.CSNo)<0){
            tmp->next = heada;
            ahead = tmp;
        }
        else{
            while(heada->next!=NULL){
                if(strcmp(heada->next->data.CSNo,tmp->data.CSNo)<0) break;
                heada = heada->next;
            }
            tmp->next = heada->next;
            heada->next = tmp;
        }
    }
    SaveData();
}

void FindAnnual(GtkWidget * wid , gpointer data){
    pipe *A = (pipe *)data;
    annual * heada = ahead;
    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {Msg(1,"请输入年份！");return ;}
    int flag = 0;
    while(heada!=NULL) {
        printf("2m%d",A->widget[0]);
        if(strcmp(heada->data.CSNo,gtk_entry_get_text(A->widget[0]))==0) {
            flag = 1;break;
        }
        heada = heada->next;
    }
    if(flag !=1) {Msg(1,"没有找到该年份信息！"); return ;}
    printf("Founded!the point is %s\n",heada->data.CSNo);
    char money[10];char apply[10];char end[10];
    printf("4m%d",A->widget[0]);
    gcvt(heada->data.moneyInput,6,money);
    printf("5m%d",A->widget[0]);
    gtk_entry_set_text(A->widget[1],money);
    gtk_entry_set_text(GTK_ENTRY(A->widget[2]),heada->data.resPeople);
    gtk_entry_set_text(GTK_ENTRY(A->widget[3]),itoa(heada->data.pjApplyNum,apply,10));
    gtk_entry_set_text(GTK_ENTRY(A->widget[4]),itoa(heada->data.pjEndNum,end,10));
    gtk_entry_set_text(GTK_ENTRY(A->widget[5]),heada->data.timgBg);
    gtk_entry_set_text(GTK_ENTRY(A->widget[6]),heada->data.timeEnd);
}

void ChangeAnnual(GtkWidget * wid , gpointer data){
    pipe *A = (pipe *)data;
    annual * heada = ahead;
    //提示错误
    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {Msg(1,"请输入年份！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {Msg(1,"请输入投入资金！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0) {Msg(1,"请输入负责人！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0) {Msg(1,"请输入申请项目数！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[4]),"")==0) {Msg(1,"请输入结题项目数！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[5]),"")==0) {Msg(1,"请输入计划开始时间！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[6]),"")==0) {Msg(1,"请输入计划结束时间！");return ;}

    int flag = 0;
    while(heada!=NULL) {
        if(strcmp(heada->data.CSNo,gtk_entry_get_text(A->widget[0]))==0) {
            flag = 1;break;
        }
        heada = heada->next;
    }
    if(flag !=1) {Msg(1,"没有找到该年份信息！"); return ;}
    heada->data.moneyInput=atof(gtk_entry_get_text(A->widget[1]));
    strcpy(heada->data.resPeople,gtk_entry_get_text(A->widget[2]));
    heada->data.pjApplyNum=atoi(gtk_entry_get_text(A->widget[3]));
    heada->data.pjEndNum=atoi(gtk_entry_get_text(A->widget[4]));
    strcpy(heada->data.timgBg,gtk_entry_get_text(A->widget[5]));
    strcpy(heada->data.timeEnd,gtk_entry_get_text(A->widget[6]));
    SaveData();

}
//判断条件
int Judge(annual * cur,pipe * A){
    int flagAnd = 1;int flagOr = 0;
    if(gtk_toggle_button_get_active(A->widget[5])){
        if(Correspond1(cur->data.CSNo,gtk_entry_get_text(A->widget[0]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[6])){
        if(cur->data.moneyInput>=atof(gtk_entry_get_text(A->widget[1]))&&
           cur->data.moneyInput<=atof(gtk_entry_get_text(A->widget[2]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[7])){
        if(cur->data.pjSupportNum>=atoi(gtk_entry_get_text(A->widget[3]))&&
           cur->data.pjSupportNum<=atoi(gtk_entry_get_text(A->widget[4]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[8])){
        return flagAnd;
    }
    else{
        return flagOr;
    }
}
//删除的时候直接调用这条函数
//注意：
/*1.项目删除pjsupport-1
2.pipe里面传参索引相对*/
point *QueryForList(pipe * A){
    annual * heada = ahead;
    point *head = NULL;
    point * cur = NULL;
    while(heada!=NULL){
        if(Judge(heada,A)!=0){
            point * tmp = (point *)malloc(sizeof(point));
            tmp->next = NULL;tmp->parent.adda = NULL;
            tmp->add.adda = heada;
            //处理头节点
            if(head==NULL){
                head = tmp;
                cur = head;
            }
            else{
                cur->next = tmp;
                cur = cur->next;
            }
        }
        heada = heada->next;
    }
    return head;
}

void QueryAnnual(GtkWidget * wid , gpointer data){
    pipe * A = (pipe *)data;
    point *head = QueryForList(A);
    //输出head到clist；
    GtkWidget * clist = A->widget[9];

    while(head!=NULL){
        annual * ann = head->add.adda;
        char money[10];char pja[10];char pjs[10];char pje[10];
        gcvt(ann->data.moneyInput,6,money);
        itoa(ann->data.pjApplyNum,pja,10);
        itoa(ann->data.pjSupportNum,pjs,10);
        itoa(ann->data.pjEndNum,pje,10);
        char * text[] = {
            ann->data.CSNo,
            money,
            ann->data.resPeople,
            pja,pjs,pje,
            ann->data.timgBg,
            ann->data.timeEnd
        };
        gtk_clist_append(GTK_CLIST(clist),text);
        head = head->next;
    }
    FreeAllPoint(head);
}





























