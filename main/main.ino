#include <Gamebuino-Meta.h>
#include "declarations.h"
#include "graphics.h"

void setup() {
  gb.begin();
  gb.setFrameRate(30); 
  // gb.display.init(160, 128, ColorMode::index);
}    
 
void loop() {
  while(!gb.update());
  gb.display.clear();
  buttonListener();
  if(gameScreen == HERO_CHOOSING){
    gb.display.drawImage(0, 0, startBackground);
    // gb.display.init(160, 128, ColorMode::index);
    // gb.display.setCursor(13, 5);
    // gb.display.println("Choose Your\n    fighter!");
    // gb.display.setColor(WHITE);
    // gb.display.setCursor(13, 13);
    // gb.display.println((*currentHero)->name);
    // gb.display.setColor(WHITE);
    // gb.display.drawRect(23, 29, 33, 12);
    gb.display.setCursor(5, 38);
    gb.display.printf("Attack");
    // gb.display.setCursor(69, 38);
    // gb.display.printf("%d", (*currentHero)->attack);

    gb.display.setCursor(5, 47);
    gb.display.printf("Defence");
    drawHeroInfo();
    // gb.display.setCursor(69, 47);
    // gb.display.printf("%d", (*currentHero)->defence);

    // gb.display.drawImage(35, 38, startSkillBar);
    // gb.display.drawImage(35, 47, startSkillBar);
    // gb.display.drawImage(36, 39, startSkillCell);
    // gb.display.drawImage(36, 48, startSkillCell);
    // gb.display.drawImage(4, 12, startLeftArrowDefault);
    // gb.display.drawImage(44, 12, startRightArrowDefault);
    // gb.display.drawImage(54, 2, startAvatarGunner);
    // gb.display.setCursor(13, 80);
    // gb.display.printf("Defence: %d", (*currentHero)->defence);
    // gb.display.setCursor(13, 96);
    // gb.display.println("Special skill: " + (*currentHero)->specialSkill());
  }else if(gameScreen == MAP){
    gb.display.init(80, 64, ColorMode::index);
    // gb.display.drawRect(2, 2, 4, 4);
    // gb.display.drawRect(32, 32, 4, 4);
    gb.display.setCursor(13, 13);
    gb.display.printf("warrior:");
    gb.display.setCursor(13, 19);
    gb.display.printf("1 2 3 4 5 6 7 8 9 0 10:");
    gb.display.setCursor(13, 34);
    gb.display.printf("Special skill:");
    // gb.display.drawRect(heroMapCoordinates::x, heroMapCoordinates::y, heroMapCoordinates::width, heroMapCoordinates::height);
  }
}


