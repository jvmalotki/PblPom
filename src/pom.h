#pragma once
#include "pebble_os.h"

#define POM_UUID { 0x42, 0xB2, 0x76, 0xD7, 0x8F, 0x6F, 0x44, 0x9B, 0x89, 0x03, 0xD1, 0x56, 0xC0, 0xD1, 0xE9, 0xBD }
#define POM_NAME "PblPom"

typedef enum {
    PomStateReady,
    PomStateWorking,
    PomStateResting,
} PomState;

typedef struct {
    uint16_t language;
    uint16_t workTicks;
    uint16_t restTicks;
    uint16_t longRestTicks;
    uint16_t pomsPerLongRest;
    bool takeLongRests;
    bool vibrateWhileWorking;
} PomSettings;


typedef struct {

    PomSettings settings;
    
    unsigned int completedPoms;
    int ticksRemaining;
    int totalTicks;
    PomState state;
    
    Window mainWindow;
    Window menuWindow;
    TextLayer workingTextLayer;
    TextLayer timeTextLayer;
    InverterLayer inverterLayer;

} PomApplication;


void pomSetState(PomState newState);

//the shared, global, application structure
extern PomApplication app;
