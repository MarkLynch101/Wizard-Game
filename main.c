#include <gb/gb.h>
#include <stdio.h>
#include "CaveEntrenceMap.c"
#include "CaveEntrenceSprites.c"
#include "CharacterSprites.c"
#include "GameCharacter.c"

struct GameCharacter wizard;
UBYTE spritesize = 8;
UBYTE animateCycle = 0;
UINT8 animationDelay = 6;
UINT8 steepsize = 4;

//moves characters
void movegamecharacter(struct GameCharacter* character, UINT8 x, UINT8 y){
    move_sprite(character->spritids[0], x, y);
    move_sprite(character->spritids[1], x + spritesize, y);
    move_sprite(character->spritids[2], x, y + spritesize);
    move_sprite(character->spritids[3], x + spritesize, y + spritesize);
}

void performantdelay(UINT8 numloops){
    UINT8 i;
    for(i = 0; i < numloops; i++){
        wait_vbl_done();
    }
}


//creates characters
void createwizard(){
    wizard.x = 80;
    wizard.y = 80;
    wizard.width = 16;
    wizard.height = 16;

    set_sprite_tile(0, 0);
    wizard.spritids[0] = 0;
    set_sprite_tile(1, 1);
    wizard.spritids[1] = 1;
    set_sprite_tile(2, 2);
    wizard.spritids[2] = 2;
    set_sprite_tile(3, 3);
    wizard.spritids[3] = 3;

    movegamecharacter(&wizard, wizard.x, wizard.y);
}

void main()
{
    set_bkg_data(0,61,CaveEntrenceSprites);
    set_bkg_tiles(0, 0, 100, 36, CaveEntrenceMap);
    scroll_bkg(80,72);

    set_sprite_data(0,48,CharacterSprites);
    createwizard();

    while(1){
        SHOW_BKG;
        SHOW_SPRITES;
        DISPLAY_ON;

        if(joypad() & J_LEFT){
           wizard.x -= steepsize;
           performantdelay(animationDelay);

           if (animateCycle == 0){
                set_sprite_tile(0, 24);
                set_sprite_tile(1, 25);
                set_sprite_tile(2, 26);
                set_sprite_tile(3, 27);
                animateCycle = 1;
            }
            else{
                set_sprite_tile(0, 28);
                set_sprite_tile(1, 29);
                set_sprite_tile(2, 30);
                set_sprite_tile(3, 31);
                animateCycle = 0;
            }

          // movegamecharacter(&wizard, wizard.x, wizard.y);
           scroll_bkg(-4,0);

            performantdelay(animationDelay);

           set_sprite_tile(0, 4);
           set_sprite_tile(1, 5);
           set_sprite_tile(2, 6);
           set_sprite_tile(3, 7);
       }

       if(joypad() & J_RIGHT){
           wizard.x += steepsize;
           performantdelay(animationDelay);

           if (animateCycle == 0){
                set_sprite_tile(0, 40);
                set_sprite_tile(1, 41);
                set_sprite_tile(2, 42);
                set_sprite_tile(3, 43);
                animateCycle = 1;
            }
            else{
                set_sprite_tile(0, 44);
                set_sprite_tile(1, 45);
                set_sprite_tile(2, 46);
                set_sprite_tile(3, 47);
                animateCycle = 0;
            }

          // movegamecharacter(&wizard, wizard.x, wizard.y);
           scroll_bkg(4,0);

            performantdelay(animationDelay);

           set_sprite_tile(0, 12);
           set_sprite_tile(1, 13);
           set_sprite_tile(2, 14);
           set_sprite_tile(3, 15);
       }

       if(joypad() & J_UP){
           wizard.y -= steepsize;
           performantdelay(animationDelay);

            if (animateCycle == 0){
                set_sprite_tile(0, 32);
                set_sprite_tile(1, 33);
                set_sprite_tile(2, 34);
                set_sprite_tile(3, 35);
                animateCycle = 1;
            }
            else{
                set_sprite_tile(0, 36);
                set_sprite_tile(1, 37);
                set_sprite_tile(2, 38);
                set_sprite_tile(3, 39);
                animateCycle = 0;
            }

           //movegamecharacter(&wizard, wizard.x, wizard.y);
           scroll_bkg(0,-4);

            performantdelay(animationDelay);

           set_sprite_tile(0, 8);
           set_sprite_tile(1, 9);
           set_sprite_tile(2, 10);
           set_sprite_tile(3, 11);
       }

       if(joypad() & J_DOWN){
           wizard.y += steepsize;
           performantdelay(animationDelay);

            if (animateCycle == 0){
                set_sprite_tile(0, 16);
                set_sprite_tile(1, 17);
                set_sprite_tile(2, 18);
                set_sprite_tile(3, 19);
                animateCycle = 1;
            }
            else{
                set_sprite_tile(0, 20);
                set_sprite_tile(1, 21);
                set_sprite_tile(2, 22);
                set_sprite_tile(3, 23);
                animateCycle = 0;
            }

           //movegamecharacter(&wizard, wizard.x, wizard.y);
           scroll_bkg(0,4);

            performantdelay(animationDelay);

           set_sprite_tile(0, 0);
           set_sprite_tile(1, 1);
           set_sprite_tile(2, 2);
           set_sprite_tile(3, 3);
       }


       performantdelay(5);
       HIDE_BKG;
    }
}