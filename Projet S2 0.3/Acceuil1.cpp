#include "Acceuil1.h"
#include <allegro.h>
#include <iostream>


/// attend qu'on appuie sur une touche et se termine
void Acceuil1()
{
     BITMAP* image_acc;
     BITMAP* veuillez;
        image_acc=load_bitmap("pics/acc.bmp",nullptr);
        if(!image_acc)
        {
            std::cout<<"image d acc pas trouvee";
            return;
        }
        veuillez=load_bitmap("pics/veuillez.bmp",nullptr);
        if(!veuillez)
        {
            std::cout<<"image veuillez pas trouvee";
            return;
        }
    BITMAP* buffer;
    buffer=create_bitmap(SCREEN_W,SCREEN_H);
    int i=0;
    int top=100;
    while(!keypressed()&&!mouse_b & 1)
    {

        stretch_blit(image_acc,buffer,0,0,image_acc->w,image_acc->h,0,0,SCREEN_W,SCREEN_H);
        i++;
        if(i>top)
        {
            draw_sprite(buffer,veuillez,SCREEN_W/2-veuillez->w/2+10,350);

            if(i>top*2)
                i=0;
        }
        blit(buffer,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        clear_bitmap(buffer);
    }
}

