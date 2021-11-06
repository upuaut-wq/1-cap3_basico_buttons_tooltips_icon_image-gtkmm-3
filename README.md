# cap3_basico
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
        this->m_btn1.set_image_from_icon_name("gtk-home");
        this->m_btn1.set_image_position(Gtk::POS_RIGHT);
        this->m_btn1.set_always_show_image(true); 
    ~~~

    Lista de Icones.
    
    * Presente na pasta `/usr/share/icons`
    * Para aumentar de tamanho o icone, pode ser utilizado a opção `Gtk::IconSize`. Veja o exemplo;

        `this->m_btn1.set_image_from_icon_name("gtk-home",Gtk::ICON_SIZE_BUTTON);`

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

    Ao tentar colocar um tamanho e imagem personalizadas, a opção acima não funciona. Para resolver, utilizei as seguinte linhas de código.

    `