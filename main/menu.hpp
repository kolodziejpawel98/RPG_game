#pragma once

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#undef max
#undef min
#include <utility>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

struct Option{
    Option(int x, int y, String text) : x(x), y(y), text(text) {};
    int x, y;
    String text;
};


class Menu{
    public:
        Menu() = default;
        
        void addMenuOption(int x, int y, String text){
            menuOptions.push_back(std::make_shared<Option>(x, y, text));
            currentOption = menuOptions.begin();
        };

        void display(){
            gb.display.println(menuOptions.size());
            for(auto &it : menuOptions){
                gb.display.setCursor(it->x, it->y);
                gb.display.println(it->text);
            }
            printCursor();
            buttonListener();
        }

        void printCursor(){
            gb.display.drawImage((*currentOption)->x - 10, (*currentOption)->y, startRightArrowDefault);
        }

        void buttonListener(){
            if(gb.buttons.pressed(BUTTON_DOWN) == true){
                if(currentOption == menuOptions.end() - 1){
                    currentOption = menuOptions.begin();
                }else{
                    currentOption++;
                }
                printCursor();
            }else if(gb.buttons.pressed(BUTTON_UP) == true){
                if(currentOption == menuOptions.begin()){
                    currentOption = menuOptions.end() - 1;
                }else{
                    currentOption--;
                }
                printCursor();
            }
        }

        std::vector<std::shared_ptr<Option>> menuOptions;
	    std::vector<std::shared_ptr<Option>>::iterator currentOption;
};