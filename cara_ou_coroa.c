#include <gtk/gtk.h>
#include <stdlib.h>
#include <time.h>

// Função para jogar a moeda
int jogaMoeda() {
    return rand() % 2;
}

// Função para lidar com o clique do botão
void jogar(GtkWidget *widget, gpointer data) {
    int escolha = GPOINTER_TO_INT(data);
    int resultado = jogaMoeda();

    // Mostra o resultado em uma caixa de diálogo
    GtkWidget *dialog;
    dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                    GTK_DIALOG_MODAL,
                                    GTK_MESSAGE_INFO,
                                    GTK_BUTTONS_OK,
                                    (resultado == escolha) ? "Você ganhou!" : "Você perdeu!");
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
}

int main(int argc, char *argv[]) {
    // Inicializa GTK
    gtk_init(&argc, &argv);

    // Cria a janela principal
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Cara ou Coroa");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Cria um botão para Cara
    GtkWidget *button_cara = gtk_button_new_with_label("Cara");
    g_signal_connect(button_cara, "clicked", G_CALLBACK(jogar), GINT_TO_POINTER(0));

    // Cria um botão para Coroa
    GtkWidget *button_coroa = gtk_button_new_with_label("Coroa");
    g_signal_connect(button_coroa, "clicked", G_CALLBACK(jogar), GINT_TO_POINTER(1));

    // Cria uma caixa vertical para organizar os botões
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_box_pack_start(GTK_BOX(box), button_cara, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), button_coroa, TRUE, TRUE, 0);

    // Adiciona a caixa à janela principal
    gtk_container_add(GTK_CONTAINER(window), box);

    // Exibe a janela
    gtk_widget_show_all(window);

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    // Inicia o loop principal GTK
    gtk_main();

    return 0;
}
