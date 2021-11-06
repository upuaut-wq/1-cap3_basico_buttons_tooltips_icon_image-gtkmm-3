#include "botao.h"
#include <iostream>

Botao::Botao():m_tooltip_p(Gtk::WINDOW_POPUP){ //Necessario definir o tipo de janela no constructor.
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

    //BOTÃO1 ******************************************************************************************************
    this->m_btn1.set_focus_on_click(false); //Não permite foco quando utilizado CTRL+Click. 
    this->m_btn1.set_tooltip_markup("<span foreground=\"blue\" size=\"x-large\">Este texto é azul</span> isso é <i>LEGAL </i>!");
    //Veja mais https://docs.gtk.org/Pango/pango_markup.html
    
    //Adiciona icone e label ao botao
    this->m_btn1.set_label(" Botão1");
    this->m_btn1.set_image_from_icon_name("gtk-home",Gtk::ICON_SIZE_BUTTON); //Vale somente para botoes padrao
    this->m_btn1.set_image_position(Gtk::POS_RIGHT);
    this->m_btn1.set_always_show_image(true);


    //BOTÃO2 ******************************************************************************************************
    this->m_btn2.set_can_focus(false); //Não permite o foco quando precionado o TAB;
    this->m_btn2.set_label("Botão2");
    this->m_btn2.set_tooltip_window(this->m_tooltip_p); //Adiciona um tooltip do tipo window ao botao.

    //Button's custom tooltip window:
    this->m_tooltip_p.set_default_size(0, 0);  //Tamanho do tooltip.0 = se ajusta ao conteudo.
    this->m_scale.set_range(0,100);               //Intervalo do Scale.
    
    //Para TEXTO
    //Gtk::Label* label =
    //Gtk::make_managed<Gtk::Label>("A label in a custom tooltip window");
    //label->show();

    //Para WIDGET(Aparenta funcionar)
    //this->m_tooltip_p.add(this->m_scale);   //Adiciona a window o scale.
    //this->m_scale.show();  //Deve estar presente, aparentemente o show_all_children da view principal não alcança o scale.

    //Para IMAGE
    this->m_tooltip_p.add(this->m_img_t);   //Adiciona a window o scale.
    this->m_img_t.set_from_icon_name("gtk-media-forward",Gtk::ICON_SIZE_DIALOG);
    this->m_img_t.show();  //Deve estar presente, aparentemente o show_all_children da view principal não alcança o scale.

    //O tooltip aparece muito rapido,não é possivel alterar o valor do scale.
    this->m_btn2.signal_query_tooltip().connect(sigc::mem_fun(*this, &Botao::on_button_query_tooltip)); //Sinal gerado pelo tooltip.

    //BOTÃO3 ******************************************************************************************************
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
    this->m_btn3.set_margin_end(10); //Adiciona uma margem no objeto.Possui para todos os lados.
    
    //Adiciona somente icone ao botão.
    this->ref_icon_bt3 = Gdk::Pixbuf::create_from_file("icon.png",100,100,false); //Cria uma referencia.
    this->m_img.set(this->ref_icon_bt3);                                          //Adiciona a referencia em um widget do tipo image.
    this->m_btn3.set_image(this->m_img);                                          //Adiciona a imagem no botão.
    //this->m_btn3.set_label("Btn3");            < Adiciona um Label
    //this->m_btn3.set_always_show_image(true);  < Mostra tbm o label

    this->m_btn3.set_tooltip_text("  -Texto normal sem tags de formatação.\n  -Imagem personalizada no icone.\n  -Margem esq,dir de 10px.\n  -Alinhamento no inicio com vspand.\n -Nome pode ser colocado tbm.");

    //BOTÃO3 ******************************************************************************************************
    this->m_btn4.set_label("Altera");
    this->m_btn4.signal_clicked().connect(sigc::mem_fun(*this,&Botao::on_btn4_alt_img)); //Sinal, quando acionado altera imagem.                      
    this->m_btn4.set_tooltip_text("Altera a imagem do tooltipWindow e do botao1");


    this->show_all_children();
}


Botao::~Botao(){

}



bool Botao::on_button_query_tooltip(int, int, bool, const Glib::RefPtr<Gtk::Tooltip>&)
{
  //We already have a custom window ready, just return true to show it:
  
  return true;
}


    void  Botao::on_btn4_alt_img(){
        //Na documentação é recomendado utilizar o Ustring ao inves de string.
        // Relacionado a caracteres de algumas linguagens(Tradução)->rever...
        Glib::ustring n_icon[5] = {"gtk-media-forward","gtk-dialog-warning","gtk-page-setup","gtk-refresh","gtk-add"};
        std::srand(std::time(0));
        int x = rand() % 5;
        std::cout << x << std::endl;
        std::cout << n_icon[x] << std::endl;

        //Realiza a alteração
        this->m_img_t.set_from_icon_name(n_icon[x],Gtk::ICON_SIZE_DIALOG);
        this->m_btn1.set_image_from_icon_name(n_icon[x]);
    }