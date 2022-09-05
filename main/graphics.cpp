#include "graphics.hpp"

Image startBackground(startBackgroundCode);
Image startSkillBar(startSkillBarCode);
Image startSkillCell(startSkillCellCode);
Image startAvatarStalker(startAvatarStalkerCode);
Image startAvatarSniper(startAvatarSniperCode);
Image startAvatarPope(startAvatarPopeCode);
Image startAvatarHacker(startAvatarHackerCode);
Image startAvatarGunner(startAvatarGunnerCode);
Image startRightArrowDefault(startRightArrowDefaultCode);
Image startRightArrowActivated(startRightArrowActivatedCode);
Image startLeftArrowDefault(startLeftArrowDefaultCode);
Image startLeftArrowActivated(startLeftArrowActivatedCode);
Image mapWorldPath(mapWorldPathCode);
Image mapWorldTown(mapWorldTownCode);
Image mapWorldCave(mapWorldCaveCode);
Image mapWorldQuestionMark(mapWorldQuestionMarkCode);
Image mapWorldForest(mapWorldForestCode);
Image mapWorldGunner(mapWorldGunner);
Image mapWorldSniper(mapWorldSniper);
Image mapWorldPope(mapWorldPope);
Image mapWorldHacker(mapWorldHacker);
Image mapWorldStalker(mapWorldStalker);
Image mapWorldBackground(mapWorldBackgroundCode);

namespace heroMapCoordinates{
    uint8_t x = 50;
    uint8_t y = 50;
    uint8_t width = 2;
    uint8_t height = 2;
}

namespace screenDimension{
    const uint8_t highResWidth = 160;
    const uint8_t highResHeight = 128;
    const uint8_t lowResWidth = 80;
    const uint8_t lowResHeight = 64;
    const uint8_t mapMovingPointLeft = 18;
    const uint8_t mapMovingPointRight = lowResWidth - 18;
    const uint8_t mapMovingPointUp = 18;
    const uint8_t mapMovingPointBottom = lowResHeight - 18;
    int mapPrzesuniecieX = -40;
    int mapPrzesuniecieY = -49;
}

namespace cursorPosition{
    uint8_t x = 16, y = 42;
}
