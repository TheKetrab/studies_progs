#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>

// ***** ***** *****
// 300951
// Bartlomiej Grochowski
// ***** ***** *****


/*
typedef struct dane {
    int y;
    int n;
    int x;
    int g;
    char tekst[100];
} Dane;

Dane *inicjuj()
{
    Dane *wynik=malloc(sizeof(Dane));
    wynik->y=0;
    wynik->x=0;
    wynik->n=0;
    wynik->g=0;
    //sprintf(wynik->tekst,"tak: %d (%d \%), nie: %d (%d \%)",wynik->y,wynik->g,wynik->x,wynik->g);

    return wynik;
}*/

int y=0;
int n=0;
int x=0;
char tekst[100];
GtkWidget *box3;

void tak( GtkWidget *widget, gpointer *data )
{
    y++;
    printf("tak: %d, nie: %d, idk: %d\n",y,n,x);
    sprintf(tekst,"tak: %d (%.2f \%), nie: %d (%.2f \%)\n",y, (double)y / (double)(y+n+x) * 100 ,x, (double)n / (double)(y+n+x) * 100 );
    g_object_set( G_OBJECT( box3 ), "label", tekst, NULL );
}

void nie( GtkWidget *widget, gpointer *data )
{
    n++;
    printf("tak: %d, nie: %d, idk: %d\n",y,n,x);
    sprintf(tekst,"tak: %d (%.2f \%), nie: %d (%.2f \%)\n",y, (double)y / (double)(y+n+x) * 100 ,x, (double)n / (double)(y+n+x) * 100 );
    g_object_set( G_OBJECT( box3 ), "label", tekst, NULL );
}

void nwm( GtkWidget *widget, gpointer *data )
{
    x++;
    printf("tak: %d, nie: %d, idk: %d\n",y,n,x);
    sprintf(tekst,"tak: %d (%.2f \%), nie: %d (%.2f \%)\n",y, (double)y / (double)(y+n+x) * 100 ,x, (double)n / (double)(y+n+x) * 100 );
    g_object_set( G_OBJECT( box3 ), "label", tekst, NULL );
}


int main(int argc,char *argv[])
{
//    Dane *statystyka=inicjuj();
//    printf("%s",statystyka->tekst);


    //MAIN
    gtk_init (&argc, &argv);
    GtkWidget *window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window),"Glosowanie");
    gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
    gtk_container_set_border_width(GTK_CONTAINER(window), 30);
    g_signal_connect(G_OBJECT(window),"destroy",G_CALLBACK(gtk_main_quit),NULL);

    //BOXY
    GtkWidget *box_glowny = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(window), box_glowny);

    GtkWidget *box1 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_container_add(GTK_CONTAINER(box_glowny), box1);

    GtkWidget *pytanie=gtk_label_new("Czy lubisz ferie?");
    gtk_container_add(GTK_CONTAINER(box1), pytanie);

    GtkWidget *box2 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_container_add(GTK_CONTAINER(box_glowny), box2);

    //ODP
    GtkWidget *yep=gtk_button_new_with_label("TAK");
    gtk_box_pack_start(GTK_BOX(box2), yep, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(box2), yep);
    g_signal_connect (G_OBJECT (yep), "clicked", G_CALLBACK (tak), NULL);

    GtkWidget *no=gtk_button_new_with_label("NIE");
    gtk_box_pack_start(GTK_BOX(box2), no, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(box2), no);
    g_signal_connect (G_OBJECT (no), "clicked", G_CALLBACK (nie), NULL);

    GtkWidget *idk=gtk_button_new_with_label("NIE WIEM");
    gtk_box_pack_start(GTK_BOX(box2), idk, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(box2), idk);
    g_signal_connect (G_OBJECT (idk), "clicked", G_CALLBACK (nwm), NULL);

    box3 = gtk_label_new("tak: 0 (0 \%), nie: 0 (0 \%)");

    gtk_container_add(GTK_CONTAINER(box_glowny), box3);

    gtk_widget_show_all(window);
    gtk_main ();
    return 0;
}


