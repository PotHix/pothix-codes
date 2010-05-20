/*
 * Exemplo de um Botão Olá Mundo!!!
 *
 */

#include <gtk/gtk.h>

/*
 * Essa é uma função para chamada de retorno (callbacks), os argumentos de "data"
 * estão sendo ignorados e explicarei melhor "callbacks" depois.
 *
 */

static void hello(GtkWidget *widget, gpointer data)
{
   g_print("Ola Mundo!!\n");
}


/* GTK irá emitir um sinal "destroy". Retornando TRUE significa que
 * você não irá querer que a janela seja destruída. Isto é útil para
 * aqueles tipos de janelas popup que fazem confirmação de
 * fechamento de janelas - "Você realmente deseja sair?"
 */

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data)
{
   g_print("callback delete_event!!!\n");
   return TRUE;
}

/*
 * Outro callback tratando a saída do programa.
 */

static void destroy (GtkWidget *widget, gpointer data)
{
   g_print("Funcao destroy!!!\n");
   gtk_main_quit();
}



int main(int argc, char *argv[])
{

   // GtkWidget é o tipo de armazenamento para os widgets //
   GtkWidget *window;
   GtkWidget *button;

   // Esta função inicializa a biblioteca, seta os manipuladores de sinais padrões //
   gtk_init(&argc,&argv);

   // Cria uma nova janela
   window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

   /*
    * Quando é dada para janela um sinal "delete_event" (fornecido pelo gerenciador de
    * janela, geralmente por uma opção de "fechar", ou por uma opção do menu), nós
    * fazemos uma chamada para a função delete_event() como está definido acima. O
    * dado passado para a função neste caso é NULL e é ignorado dentro da função
    * callback delete_event();
    */
   g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event),NULL);

   /*
    * Aqui nós conectamos o evento "destroy" para o tratador de sinal. Este evento
    * acontece quando nós chamamos a função gtk_widget_destroy() pela janela (clique
    * para fechar a janela no canto direito superior) ou então se nós retornamos
    * FALSE na chamada "delete_event";
    *
    * Será explicado melhor sobre "Propagação de sinal" e TRUE e FALSE dentro de um
    * tratador de sinal. Tudo será esclarecido mais adiante.
    *
    */
   g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(destroy),NULL);

   // Seta a grossura da borda de uma janela
   gtk_container_set_border_width(GTK_CONTAINER(window),10);

   // Cria um botão novo escrito "helllllo!"
   button = gtk_button_new_with_label("helllllo");

   /*
    * Novamente um tratador de sinal! Desta vez é para o botão. Quando um botão
    * recebe este sinal "clicked", será chamado a função hello() definida acima.
    * Podemos ver que temos NULL, que é um argumento NULO enviado para a função
    * callback hello().
    *
    */
   g_signal_connect(G_OBJECT(button),"clicked", G_CALLBACK(hello), NULL);


   /*
    * Outro sinal.. este sinal causa a destruição da janela ao ser clicado. Esta chama a
    * função gtk_widget_destroy(window) para tal e novamente, o sinal de destruir pode
    * vir daqui(clique no botão) ou então do gerenciador de janelas (botões de fechar -
    * altF4, etc).
    *
    */
   g_signal_connect_swapped(G_OBJECT(button), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(window));

   // Esta função empacota o botão dentro de um container, neste caso o
   // container seria o "window" (janela principal criada).
   gtk_container_add(GTK_CONTAINER(window),button);

   // A última etapa é mostrar o botão na tela
   gtk_widget_show(button);

   // e também, lógico, devemos mostrar a janela
   gtk_widget_show(window);

   /*
    * Todas as aplicações GTK devem ter uma chamada gtk_main(). O controle do
    * programa termina aqui e esta função fica esperando algum evento acontecer
    * (clique de mouse, movimento do mouse, tecla pressionada, etc)
    *
    */

   gtk_main();

   return 0;
}
