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
        cur = cur->next;
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
    printf("1.\n");
    staff * heads = headp->sthead;
    if(heads == NULL){
        printf("6.\n");
        headp->sthead = tmp;
        heads = tmp;
    }
    else{
        printf("7.\n");
        char * p = gtk_entry_get_text(A->widget[2]);
        if(strcmp(heads->data.SNo,p)<0){
            tmp->next = heads;
            headp->sthead = tmp;
            printf("5.\n");
        }
        else{//gtk_entry_get_text(A->widget[2])<0)
            while(heads->next!=NULL){
                if(strcmp(heads->next->data.SNo,"U200847892"))  break;
                heads = heads->next;
                printf("4.\n");
            }
            tmp->next = heads->next;
            heads->next = tmp;
            printf("2.\n");
        }
    }
    printf("3.");
    headp->data.people++;
    SaveData();
   // ClearWindow(NULL,A);
}

void FindStaff(GtkWidget *wid,gpointer data){
    pipe * A = (pipe*)data;
    annual * heada = ahead;
    project * headp = NULL;
    staff * heads = NULL;
    //处理空操作
    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {Msg(1,"请输入年份！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {Msg(1,"请输入项目编号！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0) {Msg(1,"请输入学号！");return ;}

    int flag = 0;
    while(heada!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[0]),heada->data.CSNo)==0){
            flag = 1;break;
        }
        heada = heada->next;
    }
    if(flag == 0) {Msg(1,"没有查询到该年份信息");return ;}
    int flag2 = 0;
    headp = heada->pjhead;
    while(headp!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[1]),headp->data.CNo)==0){
            flag2 = 1;break;
        }
        headp = headp->next;
    }
    if(flag2 == 0) {Msg(1,"没有查询到该年份下的项目信息");return ;}
    int flag3 = 0;
    heads = headp->sthead;
    while(heads!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[2]),heads->data.SNo)==0){
            flag3 = 1;break;
        }
        heads = heads->next;
    }
    if(flag3==0) {Msg(1,"没有查询到该年份下隶属于该项目下的人员信息！");return ;}
    printf("Ready to putin\n");
    printf("heads is %d",heads);
    char old[10];char queue[10];
    gtk_entry_set_text(A->widget[3],heads->data.name);
    gtk_entry_set_text(A->widget[4],itoa(heads->data.old,old,10));
    gtk_entry_set_text(A->widget[5],heads->data.status);
    gtk_entry_set_text(A->widget[6],heads->data.profession);
    gtk_entry_set_text(A->widget[7],heads->data.classNo);
    gtk_entry_set_text(A->widget[8],heads->data.talent);
    gtk_entry_set_text(A->widget[9],heads->data.task);
    gtk_entry_set_text(A->widget[10],heads->data.tel);
    gtk_entry_set_text(A->widget[11],itoa(heads->data.que,queue,10));
    A->widget[12] = (GtkWidget*)heads;
}

void ChangeStaff(GtkWidget *wid,gpointer data){
    pipe* A = (pipe *)data;

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

    staff * ss = (staff *)A->widget[12];

    strcpy(ss->data.name,gtk_entry_get_text(A->widget[3]));
    ss->data.old = atoi(gtk_entry_get_text(A->widget[4]));
    strcpy(ss->data.status,gtk_entry_get_text(A->widget[5]));
    strcpy(ss->data.profession,gtk_entry_get_text(A->widget[6]));
    strcpy(ss->data.classNo,gtk_entry_get_text(A->widget[7]));
    strcpy(ss->data.talent,gtk_entry_get_text(A->widget[8]));
    strcpy(ss->data.task,gtk_entry_get_text(A->widget[9]));
    strcpy(ss->data.tel,gtk_entry_get_text(A->widget[10]));
    ss->data.que = atoi(gtk_entry_get_text(A->widget[11]));


    SaveData();
    A->widget[12] = NULL;
}
int Judges(staff * cur,pipe * A){
    int flagAnd = 1;int flagOr = 0;
    if(gtk_toggle_button_get_active(A->widget[4])){
        if(Correspond1(cur->data.SNo,gtk_entry_get_text(A->widget[0]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[5])){
        if(Correspond2(cur->data.name,gtk_entry_get_text(A->widget[1]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[6])){
        if(Correspond2(cur->data.profession,gtk_entry_get_text(A->widget[2]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[7])){
        if(Correspond2(cur->data.talent,gtk_entry_get_text(A->widget[3]))){
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
point *QueryForLists(pipe * A){
    annual * heada = ahead;
    point *head = NULL;
    point * cur = NULL;
    while(heada!=NULL){
        project * headp = heada->pjhead;
        while(headp!=NULL){
            staff * heads = headp->sthead;
            while(heads !=NULL){
                if(Judges(heads,A)!=0){
                    point * tmp = (point *)malloc(sizeof(point));
                    tmp->next = NULL;tmp->parent.addp = headp;
                    tmp->add.adds = heads;
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

                heads = heads->next;
            }
            headp = headp->next;
        }
        heada = heada->next;
    }
    return head;
}



void QueryStaff(GtkWidget * wid,gpointer data){
    pipe * A = (pipe *)data;
    point *head = QueryForLists(A);
    //输出head到clist；
    GtkWidget * clist = A->widget[9];

    while(head!=NULL){
        staff * heads = head->add.adds;
        char old[10];char que[10];
        itoa(heads->data.old,old,10);
        itoa(heads->data.que,que,10);
        char * text[] = {
            head->parent.addp->data.CNo,
            heads->data.SNo,
            heads->data.name,
            old,
            heads->data.status,
            heads->data.profession,
            heads->data.classNo,
            heads->data.talent,
            heads->data.task,
            heads->data.tel,
            que
        };
        gtk_clist_append(GTK_CLIST(clist),text);
        head = head->next;
    }
    FreeAllPoint(head);
}
void DeleteStaff(GtkWidget* wid, gpointer data){
    GtkWidget *clist = (GtkWidget *)data;
    int i = 0;char * ptext;
    while(gtk_clist_get_text (clist,i++,1,&ptext)){
        annual * heada = ahead;
        while(heada!=NULL){
            project * headp = heada->pjhead;
            while(headp!=NULL){
                staff * heads = headp->sthead;
                if(strcmp(heads->data.SNo,ptext)==0){
                    staff * tmp = heads;
                    headp->sthead = tmp->next;
                    free(tmp);
                    headp->data.people--;
                }
                else{
                    while(heads->next!=NULL){
                        if(strcmp(heads->next->data.SNo,ptext)==0){
                            staff * tmp = heads->next;
                            heads->next = tmp->next;
                            free(tmp);
                            headp->data.people--;
                        }

                        heads = heads->next;
                    }
                }
                headp = headp->next;
            }
            heada = heada->next;
        }
    }
    SaveData();

}

