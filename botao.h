#ifndef GTKMM_BOTAO_H
#define GTKMM_BOTAO_H
#include <gtkmm/box.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/image.h>
#include <gdkmm/pixbuf.h>

class Botao : public Gtk::Window
{
public:
    Botao();
    virtual ~Botao();

protected:
    //Sinais

    //Widgets 
    Gtk::Box m_box1; 
    Gtk::Button m_btn1;
    Gtk::Button m_btn2;
    Gtk::Button m_btn3;
    Gtk::Button m_btn4;
    Gtk::Image m_img;
};

#endif //GTKMM_BOTAO_H