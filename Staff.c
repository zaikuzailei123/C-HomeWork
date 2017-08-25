#include"InfoAndType.h"

void AddStaff(GtkWidget *wid,gpointer data){
    pipe* A = (pipe *)data;

    annual * heada = ahead;
    int flag = 0;
    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {Msg(1,"请输入年份！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {Msg(1,"请输入项目编号！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0) {Msg(1,"请输入学号！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0) {Msg(1,"请输入姓名！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[4]),"")==0) {Msg(1,"请输入年龄！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[5]),"")==0) {Msg(1,"请输入类别！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[6]),"")==0) {Msg(1,"请输入学院专业！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[7]),"")==0) {Msg(1,"请输入班级！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[8]),"")==0) {Msg(1,"请输入本人特长！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[9]),"")==0) {Msg(1,"请输入承担任务！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[10]),"")==0) {Msg(1,"请输入联系电话！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[11]),"")==0) {Msg(1,"请输入项目排名！");return ;}
    //检测年份信息存在
    while(heada!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[0]),heada->data.CSNo)==0){
            flag = 1;
            break;
        }
        heada = heada->next;
    }
    if(flag == 0 ){Msg(1,"没有查询到年份信息！");return ;}
    project * headp = heada->pjhead;int flag2 = 0;
    //检测项目信息存在
    while(headp!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[1]),headp->data.CNo)==0){
            flag2 = 1;
            break;
        }
        headp = headp->next;
    }
    if(flag2==0) {Msg(1,"没有查询到项目信息！");return ;}
    //检测信息重复
    staff * cur = headp->sthead;int flag_e = 0;
    while(cur!=NULL){
        if(strcmp(cur->data.SNo,gtk_entry_get_text(A->widget[2]))==0){
            flag_e = 1;break;
        }
    }
    if(flag_e == 1) {Msg(1,"该人员已有信息！");return ;}

    //创建节点
    staff * tmp = (staff * )malloc(sizeof(staff));
    tmp->next = NULL;
    strcpy(tmp->data.SNo,gtk_entry_get_text(A->widget[2]));
    strcpy(tmp->data.name,gtk_entry_get_text(A->widget[3]));
    tmp->data.old = atoi(gtk_entry_get_text(A->widget[4]));
    strcpy(tmp->data.status,gtk_entry_get_text(A->widget[5]));
    strcpy(tmp->data.profession,gtk_entry_get_text(A->widget[6]));
    strcpy(tmp->data.classNo,gtk_entry_get_text(A->widget[7]));
    strcpy(tmp->data.talent,gtk_entry_get_text(A->widget[8]));
    strcpy(tmp->data.task,gtk_entry_get_text(A->widget[9]));
    strcpy(tmp->data.tel,gtk_entry_get_text(A->widget[10]));
    tmp->data.que = atoi(gtk_entry_get_text(A->widget[11]));

    staff * heads = headp->sthead;
    if(heads == NULL){
        headp->sthead = tmp;
        heads = tmp;
    }
    else{
        if(strcmp(heads->data.SNo,gtk_entry_get_text(A->widget[2]))<0){
            tmp->next = heads;
            headp->sthead = tmp;
        }
        else{
            while(heads->next!=NULL){
                if(strcmp(heads->next->data.SNo,gtk_entry_get_text(A->widget[2])<0)) break;
                heads = heads->next;
            }
            tmp->next = heads->next;
            heads->next = tmp;
        }
    }
    headp->data.people++;
    SaveData();
}





