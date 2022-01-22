#include <gb/gb.h>
#include <stdio.h>
#include "CharacterSprites.c"
#include "GameCharacter.c"

struct GameCharacter wizard;
UBYTE spritesize = 8;


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

void setupwizard(){
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
    set_sprite_data(0,4,CharacterSprites);
    setupwizard();
    
    SHOW_SPRITES;
    DISPLAY_ON;

    while(1){

        if(joypad() & J_LEFT){
           wizard.x -= 8;
           movegamecharacter(&wizard, wizard.x, wizard.y);
       }

       if(joypad() & J_RIGHT){
           wizard.x += 8;
           movegamecharacter(&wizard, wizard.x, wizard.y);
       }

       if(joypad() & J_UP){
           wizard.y -= 8;
           movegamecharacter(&wizard, wizard.x, wizard.y);
       }

       if(joypad() & J_DOWN){
           wizard.y += 8;
           movegamecharacter(&wizard, wizard.x, wizard.y);
       }


       performantdelay(10);
    }
}