# cap3_basico gtkmm 3.0
## OBS : Este é um "caderno", as informações contidas neste arquivo são anotações pessoais e podem apresentar informações incorretas.

### App

![](https://github.com/upuaut-wq/cap3_basico/blob/master/DOC/Peek%2006-11-2021%2023-26.gif)

Exemplo básico de um programa gtkmm.

* ### Adicionar Imagem em um botão(Icone).

    Para inserir um icone em um botão, foi utilizado as seguintes linhas de código.

    Vale lembrar que, esse procedimento funcionou somente para lista de icones padrão do Linux.

    * O set_label() , adiciona a escrita no botão.
    * O set_image_from_icon_name(), insere o icone(Até onde eu entendi o nome do icone precisa estar na lista de icones padrão do linux).
    * O set_image_position(), indica a posição da imagem em relaçao ao label.
    * O set_always_show_image(true), necessário para mostrar a imagem e o label, **sem esta opção, é mostrado somente a imagem ou o label(o que for inserido por último)**.

     ~~~c++
        //Adiciona icone e label ao botao
        this->m_btn1.set_label(" Botão1");
        this->m_btn1.set_image_from_icon_name("gtk-home",Gtk::SIZE_ICON_BUTTON);
        this->m_btn1.set_image_position(Gtk::POS_RIGHT);
        this->m_btn1.set_always_show_image(true); 
    ~~~

    Lista de Icones.
    
    * Presente na pasta `/usr/share/icons`
    * Para aumentar de tamanho o icone, pode ser utilizado a opção `Gtk::IconSize`. Veja o exemplo;

        ~~~c++
        this->m_btn1.set_image_from_icon_name("gtk-home",Gtk::ICON_SIZE_BUTTON);
        ~~~


    * Os tamanhos possiveis são;

        Desc | Tamanho
        -----|--------
        ICON_SIZE_INVALID | Erro 
        ICON_SIZE_MENU  | (16px)
        ICON_SIZE_SMALL_TOOLBAR  | (16px)
        ICON_SIZE_LARGE_TOOLBAR  | (24px)
        ICON_SIZE_BUTTON  | (16px)
        ICON_SIZE_DND  |  (32px
        ICON_SIZE_DIALOG  | (48px)

* ### Adicionar Imagem, PARTE 2.

    * Arquivo .cpp
    
        Ao tentar colocar um tamanho e imagem personalizadas, a opção acima não funciona. Para resolver, utilizei as seguinte linhas de código.

        ~~~c++
        //Adiciona somente icone ao botão.
        this->ref_icon_bt3 = Gdk::Pixbuf::create_from_file("icon.png",100,100,false); 
        this->m_img.set(this->ref_icon_bt3);                         
        this->m_btn3.set_image(this->m_img);                         
        //this->m_btn3.set_label("Btn3");            < Adiciona um Label
        //this->m_btn3.set_always_show_image(true);  < Mostra tbm o label
        ~~~

    * A seguir o codigo no arquivo .h;

        O Gtk::Imagem recebe "uma referência" que define o tamanho da imagem. Em seguida a imagem é adicionada ao botão.

        ~~~c++
        //Referencia e imagem para botão 3
        Glib::RefPtr<Gdk::Pixbuf> ref_icon_bt3;
        Gtk::Image m_img;
        ~~~

* ### Método 3 para inserir imagem em um botão.

    * Neste método é obrigatório o uso de Label e o tamanho da imagem não pode ser alterado. 

        ~~~c
        //Botoes
        add_pixlabel(const std::string &pixfile, const Glib::ustring &label, Gtk::Align x_align, Gtk::Align y_align = Gtk::ALIGN_CENTER);
        ~~~

        &**pixfile** é o endereço de onde a imagem está localizada. As outras é para alinhamento da imagem em relação ao eixo X e Y.

* ### Sinais

    * Sinal para o botão4.

        

        ~~~c++
        this->m_btn4.signal_clicked().connect(sigc::mem_fun(*this,&Botao::on_btn4_alt_img));                 
        ~~~

        OBS : Os sinais devem começar com o prefixo `on_`.

    * Implementação do sinal.

        ~~~c++
         void  Botao::on_btn4_alt_img(){
            //Na documentação é recomendado utilizar o Ustring ao invés de string.
            // Relacionado a caracteres de algumas linguagens(Tradução)->rever...
            Glib::ustring n_icon[5] = {"gtk-media-forward","gtk-dialog-warning","gtk-page-setup","gtk-refresh","gtk-add"};
            std::srand(std::time(0));
            int x = rand() % 5;
            std::cout << x << std::endl;
            std::cout << n_icon[x] << std::endl;

            this->m_img_t.set_from_icon_name(n_icon[x],Gtk::ICON_SIZE_DIALOG);
            this->m_btn1.set_image_from_icon_name(n_icon[x]);

            //Achei estranho ter que refazer o código para redimencionar o tamanho da imagem.
            this->ref_icon_bt3 = Gdk::Pixbuf::create_from_file("icon.png",50,50,false); 
            this->m_img.set(this->ref_icon_bt3);                                       
            this->m_btn3.set_image(this->m_img);        
        }
    ~~~

* ### ToolTips

    * Identificado três tipos de tooltip.

        **1.** `set_tooltip_window` <- Cria uma `Gtk::Window`, permite adicionar widgets dentro dela, para exemplo foi testado com um `Gtk::Label`, `Gtk::Scale` e um `Gtk::Image`.

        Exemplo;

        ~~~c++
        this->m_btn2.set_label("Botão2");
        this->m_btn2.set_tooltip_window(this->m_tooltip_p); //Adiciona um tooltip do tipo window ao botao.
        

        //Button's custom tooltip window:
        this->m_tooltip_p.set_default_size(0, 0);  //Tamanho do tooltip.0 = se ajusta ao conteudo.
        
        //Para TEXTO
        Gtk::Label* label = Gtk::make_managed<Gtk::Label>("A label in a custom tooltip window");
        this->m_tooltip_p.add(*label); 
        label->show();

        //Para WIDGET(Aparenta funcionar para qualquer widget)
        this->m_scale.set_range(0,100);             
        this->m_tooltip_p.add(this->m_scale);   
        this->m_scale.show(); 

        //Para IMAGE
        this->m_tooltip_p.add(this->m_img_t);  
        this->m_img_t.set_from_icon_name("gtk-media-forward",Gtk::ICON_SIZE_DIALOG);
        this->m_img_t.show();  
        ~~~

        * Sinal de ativação.

            Diferente dos outros tooltips, o tooltip do tipo window precisa de um sinal para ser exibido. 
            
            **_Confesso que não entendi muito bem como funciona, mas creio que seja abordado em capítulos posteriores_**.

            Arquivo .h

            ~~~c++
            this->m_btn2.signal_query_tooltip().connect(sigc::mem_fun(*this, &Botao::on_button_query_tooltip));
            ~~~

            Implementação do sinal no arquivo .cpp.

            ~~~c++
            bool Botao::on_button_query_tooltip(int, int, bool, const Glib::RefPtr<Gtk::Tooltip>&)
            {
            return true;
            }
            ~~~


        **2.** `set_tooltip_text` <- Permite adicionar texto normal, sem formações com tags.

        Exemplo;

        ~~~c++
        this->m_btn3.set_tooltip_text("  -Texto normal sem tags de formatação.\n  -Imagem personalizada no icone.\n  -Margem esq,dir de 10px.\n  -Alinhamento no inicio com vspand.\n -Nome pode ser colocado tbm.");
        ~~~

        **3.** `set_tooltip_markup` <- Permite adicionar texto com tags de formatação. A formatação de textos "pelo que entendi, vem da lib Pango".

        Exemplo;

        ~~~c++
        this->m_btn1.set_focus_on_click(false);
        this->m_btn1.set_tooltip_markup("<span foreground="blue" size="x-large">Este texto é azul</span> isso é <i>LEGAL </i>!");
        ~~~

* ### Sinais e Widgets do arquivo .h

    ~~~c++
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
    ~~~
