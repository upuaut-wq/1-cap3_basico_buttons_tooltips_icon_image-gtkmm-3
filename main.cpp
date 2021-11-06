#include <gtkmm/window.h>
#include <glibmm/ustring.h>
#include "botao.h"

int main(int argc, char *argv[]){
    auto app = Gtk::Application::create(argc, argv,"exemplo.botoes");
    Botao btn;
    return app->run(btn);
}