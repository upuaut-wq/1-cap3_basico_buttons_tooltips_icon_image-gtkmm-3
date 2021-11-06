#include "botao.h"
#include <iostream>

Botao::Botao(){
    //Configuração da Window
    this->set_border_width(10); //Borda entre o limite da window e o objeto.

    //Alinhamento da Box
    this->m_box1.set_property("orientation",Gtk::ORIENTATION_VERTICAL);

    this->m_box1.set_border_width(0); //Borda entre o limite da Box e o objeto dentro dela(mesmo da window).
    this->m_box1.set_spacing(10); //Expaçamento entre os objetos, não adiciona espaço extra entre entre a box e o obj.

    //Adiciona a Box na Window
    this->add(this->m_box1);

    //Adiciona os Botoes dentro da Box
    this->m_box1.pack_start(this->m_btn1);
    this->m_box1.pack_start(this->m_btn2);
    this->m_box1.pack_start(this->m_btn3);
    this->m_box1.pack_start(this->m_btn4);

    //Propriedades do Botão 1 ******************************************************************************************************
    this->m_btn1.set_focus_on_click(false); //Não permite foco quando utilizado CTRL+Click. 
    this->m_btn1.set_tooltip_markup("<span foreground=\"blue\" size=\"x-large\">Este texto é azul</span> isso é <i>LEGAL </i>!");
    //Veja mais https://docs.gtk.org/Pango/pango_markup.html
    
    //Adiciona icone e label ao botao
    this->m_btn1.set_label(" Botão1");
    this->m_btn1.set_image_from_icon_name("gtk-home"); //Vale somente para botoes padrao
    this->m_btn1.set_image_position(Gtk::POS_RIGHT);
    this->m_btn1.set_always_show_image(true);


    //Propriedades do Botão 2 ******************************************************************************************************
    this->m_btn2.set_can_focus(false); //Não permite o foco quando precionado o TAB;

    //Propriedades do Botão 3
    this->m_btn3.set_vexpand(true); //Ativa a expanção do objeto para ocupar espaço sobrando.
               //set_hexpand(true)  <- versão horizontal

    this->m_btn3.set_halign(Gtk::ALIGN_START); //Alinhamento do objeto.
                          //Gtk::ALIGN_BASELINE    
                          //Gtk::ALIGN_CENTER    
                          //Gtk::ALIGN_END    
                          //Gtk::ALIGN_FILL < - Preenche todo o espaço.
    //Existe a opção set_valign(Gtk::ALIGN_START); <- Alinhamento na vertical

    this->m_btn3.set_size_request(100,100); //So funciona se estiver fora do ALIGN_FILL.
    this->m_btn3.set_margin_start(10); //Adiciona uma margem no objeto.Possui para todos os lados.
    
    //Adiciona somente icone ao botão.
    //PAREI AQUI
                                        


    this->show_all_children();
}


Botao::~Botao(){

}