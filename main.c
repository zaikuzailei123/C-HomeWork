#include"InfoAndType.h"
#include "Util.h"
#include "MainPage.h"

annual * ahead = NULL;
GtkWidget * window;


 int main(int argc,char *argv[]){
	gtk_init(&argc,&argv);

    ahead = LoadData();
	window = CreateMainPage();



	gtk_main();

	return 0;
 }

