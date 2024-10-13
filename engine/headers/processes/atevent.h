#pragma once

#include "../atmath.h"
#include "../attypes.h"
#include "../athelpers.h"
#include "../../backend/headers/atGLAPI.h"

#define MAX_KEYS 1024
#define MAX_MOUSE_BUTTONS 32

typedef struct ATeventData {
    bool quit;
    GLFWwindow* windowPtr;
    struct inputState {
        unsigned char current_keys[MAX_KEYS];
        unsigned char previous_keys[MAX_KEYS];
        unsigned char current_mouse_buttons[MAX_MOUSE_BUTTONS];
        unsigned char previous_mouse_buttons[MAX_MOUSE_BUTTONS];
    } inputState;
} ATeventData;
ATeventData* _atGetEventData(void);
void _atInitEventData(ATeventData* event);

ATerrorType _atPrepEvent(void* d);
ATerrorType _atMainEvent(void* d);
ATerrorType _atPostEvent(void* d);

// External Event/Input API
unsigned char _atIsKeyPressed(ATeventData* event, ATkeyboardKey key);
unsigned char _atIsKeyTriggered(ATeventData* event, ATkeyboardKey key);
unsigned char _atIsKeyReleased(ATeventData* event, ATkeyboardKey key);
unsigned char _atIsMouseButtonPressed(ATeventData* event, ATmouseButton button);
unsigned char _atIsMouseButtonTriggered(ATeventData* event, ATmouseButton button);
unsigned char _atIsMouseButtonReleased(ATeventData* event, ATmouseButton button);
