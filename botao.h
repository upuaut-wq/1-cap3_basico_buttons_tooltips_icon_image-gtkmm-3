#ifndef GTKMM_BOTAO_H
#define GTKMM_BOTAO_H
#include <gtkmm/box.h>
#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include <gtkmm/image.h>
#include <gdkmm/pixbuf.h>
#include <gtkmm/scale.h>
#include <gtkmm/label.h>

class Botao : public Gtk::Window
{
public:
    Botao();
    virtual ~Botao();

protected:
    //Sinais
     bool on_button_query_tooltip(int x, int y, bool keyboard_tooltip, const Glib::RefPtr<Gtk::Tooltip>& tooltip);
     void on_btn4_alt_img();
    //Widgets 
    Gtk::Box m_box1; 
    Gtk::Button m_btn1;
    Gtk::Button m_btn2;
    Gtk::Button m_btn3;
    Gtk::Button m_btn4;

    //Tool Tip Personalizado
    Gtk::Window m_tooltip_p;
    Gtk::Scale m_scale;
    Gtk::Label m_label;
    Gtk::Image m_img_t;


    //Referencia e imagem para botão 3
    Glib::RefPtr<Gdk::Pixbuf> ref_icon_bt3;
    Gtk::Image m_img;


};

#endif //GTKMM_BOTAO_H