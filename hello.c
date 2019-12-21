#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>

int main()
{
    al_init();
    al_install_keyboard();

    // vykresli obraz 30x za sekundu

    ALLEGRO_TIMER* timer = al_create_timer(1.0 /30.0);
    ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();

    al_init_font_addon(); // initialize the font addon
    al_init_ttf_addon();// initialize the ttf (True Type Font) addon

    // otevreme okno o velikosti delka:2880 x viska:2000

    ALLEGRO_DISPLAY* disp = al_create_display(2880, 2000);

    //ALLEGRO_FONT* font = al_create_builtin_font();
    ALLEGRO_FONT *font = al_load_ttf_font("pirulen.ttf",72,0 );

   if (!font){
      fprintf(stderr, "Could not load 'pirulen.ttf'.\n");
      return -1;
   }

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(disp));
    al_register_event_source(queue, al_get_timer_event_source(timer));

    bool redraw = true;
    ALLEGRO_EVENT event;

    float posuv_x = 0;
    float posuv_y = 0;
    float zmena_x = 0;
    float zmena_y = 0;

    al_start_timer(timer);
    while(1)
    {
        al_wait_for_event(queue, &event);

        if(event.type == ALLEGRO_EVENT_TIMER)
            redraw = true;
        else 
        {
            if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;

            bool konec = false;

            if(event.type == ALLEGRO_EVENT_KEY_UP)
            {
                zmena_x = 0;
                zmena_y = 0;
            }

            if(event.type == ALLEGRO_EVENT_KEY_DOWN)
            {
              switch(event.keyboard.keycode) {
                case ALLEGRO_KEY_Q:
                  konec = true;
                  break;
                
                case ALLEGRO_KEY_W:
                case ALLEGRO_KEY_PAD_5:
                  zmena_y = -4;
                  break;
                //-----------------

                case ALLEGRO_KEY_S:
                case ALLEGRO_KEY_PAD_2:

                  zmena_y = 4;
                  break;
                //-----------------

                case ALLEGRO_KEY_A:
                case ALLEGRO_KEY_PAD_1:

                  zmena_x = -4;
                  break;

                //-----------------

                case ALLEGRO_KEY_D:
                case ALLEGRO_KEY_PAD_3:
                
                  zmena_x = 4;                                                    
                  break;

                }
            }

            if (konec) break;
        }

        if(redraw && al_is_event_queue_empty(queue))
        {            
            // vypln pozadi tmave modrbou barvou

            al_clear_to_color(al_map_rgb(66,66,66));
            //al_clear_to_color(al_map_rgb(56,56,56));

            // nakresli obdelnik od 100,100 do 400,400, tmave cervenou barvou, 10 px tlusty
            
            //al_draw_filled_rectangle(10.0 + posuv_x, 20.0 + posuv_y, 40.0 + posuv_x, 50.0 + posuv_y, al_map_rgb(13, 0, 78));
            // nakresli obdelnik od 120,120 do 420,420, sedou barvou, 10 px tlusty

            al_draw_rectangle(5.0 +  posuv_x, 10.0 + posuv_y, 11.0 + posuv_x, 11.0 + posuv_y, al_map_rgb(255,  0, 0),30.0);
            al_draw_rectangle(10.0 + posuv_x, 15.0 + posuv_y, 21.0 + posuv_x, 21.0 + posuv_y, al_map_rgb(250, 0, 0),30.0);
            al_draw_rectangle(15.0 + posuv_x, 20.0 + posuv_y, 31.0 + posuv_x, 31.0 + posuv_y, al_map_rgb(200, 0, 0),30.0);
            al_draw_rectangle(20.0 + posuv_x, 25.0 + posuv_y, 41.0 + posuv_x, 41.0 + posuv_y, al_map_rgb(27, 33, 45),30.0);
            al_draw_rectangle(25.0 + posuv_x, 30.0 + posuv_y, 52.0 + posuv_x, 52.0 + posuv_y, al_map_rgb(27, 44, 45),30.0);
            al_draw_rectangle(30.0 + posuv_x, 35.0 + posuv_y, 83.0 + posuv_x, 63.0 + posuv_y, al_map_rgb(27, 55, 45),30.0);
            al_draw_rectangle(35.0 + posuv_x, 40.0 + posuv_y, 64.0 + posuv_x, 94.0 + posuv_y, al_map_rgb(27, 66, 45),30.0);
            al_draw_rectangle(40.0 + posuv_x, 45.0 + posuv_y, 75.0 + posuv_x, 75.0 + posuv_y, al_map_rgb(27, 77, 45),30.0);
            al_draw_rectangle(45.0 + posuv_x, 50.0 + posuv_y, 86.0 + posuv_x, 86.0 + posuv_y, al_map_rgb(27, 88, 45),30.0);
            al_draw_rectangle(50.0 + posuv_x, 55.0 + posuv_y, 97.0 + posuv_x, 97.0 + posuv_y, al_map_rgb(27, 99, 45),30.0); 

            al_draw_rectangle(5.0 +  posuv_x, 10.0 + posuv_y, 11.0 + posuv_x, 11.0 + posuv_y, al_map_rgb(255,  0, 0),10.0);
            al_draw_rectangle(10.0 + posuv_x, 15.0 + posuv_y, 21.0 + posuv_x, 21.0 + posuv_y, al_map_rgb(250, 0, 0),10.0);
                             (15.0 + posuv_x, 20.0 + posuv_y, 31.0 + posuv_x, 31.0 + posuv_y, al_map_rgb(230, 0, 0),10.0);
            al_draw_rectangle(20.0 + posuv_x, 25.0 + posuv_y, 41.0 + posuv_x, 41.0 + posuv_y, al_map_rgb(200, 0, 0),10.0);
            al_draw_rectangle(25.0 + posuv_x, 30.0 + posuv_y, 52.0 + posuv_x, 52.0 + posuv_y, al_map_rgb(180, 0, 0),10.0);
            al_draw_rectangle(30.0 + posuv_x, 35.0 + posuv_y, 83.0 + posuv_x, 63.0 + posuv_y, al_map_rgb(150, 0, 0),10.0);
            al_draw_rectangle(35.0 + posuv_x, 40.0 + posuv_y, 64.0 + posuv_x, 94.0 + posuv_y, al_map_rgb(130, 0, 0),10.0);
            al_draw_rectangle(40.0 + posuv_x, 45.0 + posuv_y, 75.0 + posuv_x, 75.0 + posuv_y, al_map_rgb(100, 0, 0),10.0);
            al_draw_rectangle(45.0 + posuv_x, 50.0 + posuv_y, 86.0 + posuv_x, 86.0 + posuv_y, al_map_rgb(80, 0, 0),10.0);
            al_draw_rectangle(50.0 + posuv_x, 55.0 + posuv_y, 97.0 + posuv_x, 97.0 + posuv_y, al_map_rgb(50, 0, 0),10.0);

            //al_draw_circle (255,255,255,al_map_rgb(120,0,0),80+posuv_x);
            //al_draw_circle (244,255,222,al_map_rgb(150,0,0),80+posuv_x);
            //al_draw_circle (233,255,211,al_map_rgb(55,55,55),80+posuv_x);
            //(222,255,200,al_map_rgb(33,33,33),80+posuv_x);
            //al_draw_circle (255,266,277,al_map_rgb(44,44,44),80+posuv_x);
            //(266,277,288,al_map_rgb(66,66,66),80+posuv_x);
            al_draw_text(font, al_map_rgb(0, 0, 0), 255, 155, 0, "Hello John this is G world and big game!");
            al_flip_display();

            posuv_x = posuv_x + zmena_x;
            posuv_y = posuv_y + zmena_y;
         
            //if (posuv_x>100 && zmena_x==2) zmena_y = -2;
            
            /*
            if (posuv_x>200 && zmena_x==2)
            {
                zmena_x =-2;
                zmena_y = 0;
            } 
            */

            redraw = false;
        }
    }

    al_destroy_font(font);
    al_destroy_display(disp);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);

    return 0;
    }
