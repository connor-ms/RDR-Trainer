#pragma once

#define IsButtonPressed(btn) IS_BUTTON_PRESSED(1, btn, 4, 4)
#define IsButtonDown(btn)    IS_BUTTON_DOWN(1, btn, 4, 4)

void HandleInput();
void HandleMenuInput();
void HSVtoRGB(float *fR, float *fG, float *fB, float *fH, float *fS, float *fV);