#include"InfoAndType.h"
#include"LoadAndExit.h"

void AddProject(GtkWidget *wid,gpointer data){
    pipe * A = (pipe *)data;

    annual * heada = ahead;
    int flag = 0;
    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {Msg(1,"请输入年份！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {Msg(1,"请输入项目编号！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0) {Msg(1,"请输入项目名称！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0) {Msg(1,"请输入经费数！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[4]),"")==0) {Msg(1,"请输入立项时间！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[5]),"")==0) {Msg(1,"请输入结题时间！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[6]),"")==0) {Msg(1,"请输入完成评价！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[7]),"")==0) {Msg(1,"请输入负责人！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[8]),"")==0) {Msg(1,"请输入负责人电话！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[9]),"")==0) {Msg(1,"请输入结果形式！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[10]),"")==0) {Msg(1,"请输入结果名称！");return ;}
    printf("before find\n");
    while(heada!=NULL){
        printf("ready to find! head point is %d\n",heada);
        if(strcmp(gtk_entry_get_text(A->widget[0]),heada->data.CSNo)==0){
            flag = 1;break;
        }
        heada = heada->next;
    }
    if(flag == 0){Msg(1,"没有查询到该年份信息！");return ;}

    project * cur = heada->pjhead;int flag_2 = 0;
    while(cur!=0){
        if(strcmp(gtk_entry_get_text(A->widget[1]),cur->data.CNo)==0){
            flag_2 = 1;break;
        }
        cur = cur->next;
    }
    if(flag_2==1) {Msg(1,"该项目已有信息！");return ;}

    project * tmp = (project *)malloc(sizeof(project));
    tmp->next = NULL;tmp->sthead = NULL;
    strcpy(tmp->data.CNo,gtk_entry_get_text(A->widget[1]));
    strcpy(tmp->data.pjName,gtk_entry_get_text(A->widget[2]));
    tmp->data.Money = atof(gtk_entry_get_text(A->widget[3]));
    tmp->data.people = 0;
    strcpy(tmp->data.timeBg,gtk_entry_get_text(A->widget[4]));
    strcpy(tmp->data.timeEnd,gtk_entry_get_text(A->widget[5]));
    strcpy(tmp->data.evaluate,gtk_entry_get_text(A->widget[6]));
    strcpy(tmp->data.resPeople,gtk_entry_get_text(A->widget[7]));
    strcpy(tmp->data.ResPeoTel,gtk_entry_get_text(A->widget[8]));
    strcpy(tmp->data.resultType,gtk_entry_get_text(A->widget[9]));
    strcpy(tmp->data.resultName,gtk_entry_get_text(A->widget[10]));

    project * headp = heada->pjhead;
    if(headp==NULL){
        heada->pjhead = tmp;
        headp = tmp;
    }
    else{
        if(strcmp(headp->data.CNo,tmp->data.CNo)<0){
            tmp->next = headp;
            heada->pjhead = tmp;
        }
        else{
            while(headp->next!=NULL){
                if(strcmp(headp->next->data.CNo,tmp->data.CNo)<0)  break;
                headp = headp->next;
            }
            tmp->next = headp->next;
            headp->next = tmp;
        }
    }
    heada->data.pjSupportNum++;
    SaveData();
    ClearWindow(NULL,A);
}

void FindProject(GtkWidget *wid,gpointer data){
    pipe * A = (pipe *)data;
    annual * heada = ahead;
    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {Msg(1,"请输入年份！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {Msg(1,"请输入项目编号！");return ;}
    int flag = 0;
    while(heada!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[0]),heada->data.CSNo)==0){
            flag = 1; break;
        }
        heada = heada->next;
    }
    if(flag == 0) {Msg(1,"没有找到年份信息！");return ;}
    project * headp = heada->pjhead;
    int flag2 = 0;
    while(headp!=NULL){
        if(strcmp(gtk_entry_get_text(A->widget[1]),headp->data.CNo)==0){
            flag2 = 1; break;
        }
        headp = headp->next;
    }
    if(flag2==0){Msg(1,"在该年份下没有找到项目信息，请检查是否是年份输入错误！");return ;}

    char money[10];
    gtk_entry_set_text(A->widget[2],headp->data.pjName);
    gtk_entry_set_text(A->widget[3],gcvt(headp->data.Money,6,money));
    gtk_entry_set_text(A->widget[4],headp->data.timeBg);
    gtk_entry_set_text(A->widget[5],headp->data.timeEnd);
    gtk_entry_set_text(A->widget[6],headp->data.evaluate);
    gtk_entry_set_text(A->widget[7],headp->data.resPeople);
    gtk_entry_set_text(A->widget[8],headp->data.ResPeoTel);
    gtk_entry_set_text(A->widget[9],headp->data.resultType);
    gtk_entry_set_text(A->widget[10],headp->data.resultName);
    A->widget[11] = (GtkWidget *)headp;

}


void ChangeProject(GtkWidget *wid,gpointer data){
    pipe * A = (pipe *)data;
    annual * heada = ahead;
    //判断输入信息
    if(strcmp(gtk_entry_get_text(A->widget[0]),"")==0) {Msg(1,"请输入年份！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[1]),"")==0) {Msg(1,"请输入项目编号！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[2]),"")==0) {Msg(1,"请输入项目名称！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[3]),"")==0) {Msg(1,"请输入经费数！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[4]),"")==0) {Msg(1,"请输入立项时间！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[5]),"")==0) {Msg(1,"请输入结题时间！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[6]),"")==0) {Msg(1,"请输入完成评价！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[7]),"")==0) {Msg(1,"请输入负责人！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[8]),"")==0) {Msg(1,"请输入负责人电话！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[9]),"")==0) {Msg(1,"请输入结果形式！");return ;}
    if(strcmp(gtk_entry_get_text(A->widget[10]),"")==0) {Msg(1,"请输入结果名称！");return ;}

    project * p = (project *)A->widget[11];
    strcpy(p->data.pjName,gtk_entry_get_text(A->widget[2]));
    p->data.Money = atof(gtk_entry_get_text(A->widget[3]));
    strcpy(p->data.timeBg,gtk_entry_get_text(A->widget[4]));
    strcpy(p->data.timeEnd,gtk_entry_get_text(A->widget[5]));
    strcpy(p->data.evaluate,gtk_entry_get_text(A->widget[6]));
    strcpy(p->data.resPeople,gtk_entry_get_text(A->widget[7]));
    strcpy(p->data.ResPeoTel,gtk_entry_get_text(A->widget[8]));
    strcpy(p->data.resultType,gtk_entry_get_text(A->widget[9]));
    strcpy(p->data.resultName,gtk_entry_get_text(A->widget[10]));

    A->widget[11] = NULL;
    SaveData();
}




//判断条件
int Judgep(project * cur,pipe * A){
    int flagAnd = 1;int flagOr = 0;
    if(gtk_toggle_button_get_active(A->widget[5])){
        if(Correspond1(cur->data.CNo,gtk_entry_get_text(A->widget[0]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[6])){
        if(cur->data.Money>=atof(gtk_entry_get_text(A->widget[1]))&&
           cur->data.Money<=atof(gtk_entry_get_text(A->widget[2]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
        printf("***%d   %d**",flagAnd,flagOr);
    }
    if(gtk_toggle_button_get_active(A->widget[7])){
        if(Correspond2(cur->data.pjName,gtk_entry_get_text(A->widget[3]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[8])){
        if(Correspond2(cur->data.resultType,gtk_entry_get_text(A->widget[4]))){
            flagOr = 1;
        }
        else{
            flagAnd = 0;
        }
    }
    if(gtk_toggle_button_get_active(A->widget[9])){
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

point *QueryForListp(pipe * A){
    annual * heada = ahead;
    point *head = NULL;
    point * cur = NULL;
    while(heada!=NULL){
        project * headp =heada->pjhead;
        while(headp!=NULL){
            if(Judgep(headp,A)!=0){
                point * tmp = (point *)malloc(sizeof(point));
                tmp->next = NULL;tmp->parent.adda = heada;
                tmp->add.addp = headp;
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
            headp = headp->next;
        }
        heada = heada->next;
    }
    return head;
}

void QueryProject(GtkWidget* wid, gpointer data){
    pipe * A = (pipe *)data;
    point *head = QueryForListp(A);
    //输出head到clist；
    GtkWidget * clist1 = A->widget[10];
    GtkWidget * clist2 = A->widget[11];

    while(head!=NULL){
        project * prj = head->add.addp;
        annual * ann = head->parent.adda;
        printf("%d   %d",prj,ann);
        char money[12];char people[12];
        gcvt(prj->data.Money,6,money);
        itoa(prj->data.people,people,10);
        printf("\n\n%s\n\n",ann->data.CSNo);
        printf("%s\n\n",prj->data.pjName);
        char * text1[] = {
            ann->data.CSNo,
            prj->data.CNo,
            prj->data.pjName,
            money,people,
            prj->data.timeBg,
            prj->data.timeEnd,
            prj->data.evaluate,
            prj->data.resPeople,
            prj->data.ResPeoTel,
            prj->data.resultType,
            prj->data.resultName
        };
        gtk_clist_append(GTK_CLIST(clist1),text1);

        staff * heads = prj->sthead;
        for(int i = 1;i<=prj->data.people;i++){
            staff * cur = heads;
            while(cur!=NULL){
                if(cur->data.que==i){
                    char old[10];char que[10];
                    itoa(cur->data.old,old,10);
                    itoa(cur->data.que,que,10);
                    char * text2[] = {
                        prj->data.CNo,
                        cur->data.SNo,
                        cur->data.name,
                        old,cur->data.status,
                        cur->data.profession,
                        cur->data.classNo,
                        cur->data.talent,
                        cur->data.task,
                        cur->data.tel,
                        que
                    };
                    gtk_clist_append(GTK_CLIST(clist2),text2);
                }
                cur = cur->next;
            }
        }
        head = head->next;
    }
    FreeAllPoint(head);
}
void DeleteProject(GtkWidget * wid,gpointer data){
    GtkWidget * clist = (GtkWidget *)data;
    int i = 0;char * ptext;
    while(gtk_clist_get_text (clist,i++,1,&ptext)){
        annual * heada = ahead;
        while(heada!=NULL){
            project * headp = heada->pjhead;
            staff * heads = NULL;
            if(strcmp(heada->pjhead->data.CNo,ptext)==0){
                project * tmp = heada->pjhead;
                heads = tmp->sthead;
                heada->pjhead = tmp->next;
                free(tmp);
                heada->data.pjSupportNum--;
                break;
            }
            else{
                while(headp->next!=NULL){
                    if(strcmp(headp->next->data.CNo,ptext)==0){
                        project * tmp = headp->next;
                        heads = tmp->sthead;
                        headp->next = tmp->next;
                        free(tmp);
                        heada->data.pjSupportNum--;
                        break;
                    }
                    headp = headp->next;
                }
            }

            while(heads!=NULL){
                staff * tmp = heads;
                heads = heads->next;
                free(tmp);
            }
            heada = heada->next;
        }
    }
    SaveData();
}




