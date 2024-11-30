#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "dsp.h"
#include "flanger.h"

void buildUserInterfacemydsp(mydsp* dsp, UIGlue* ui_interface);

mydsp dsp;

float *buf_in[1];
float *buf_out[1];
size_t buf_len;

int min(int a, int b)
{
    return (a < b ? a : b);
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

void extract(const char *name, float *p, float init, float min, float max, float step){};
void *declare(UIGlue *uiInterface, float *p, const char* key, const char* val){};
void openVerticalBox(UIGlue *uiInterface, char* key){};
void openHorizontalBox(UIGlue *uiInterface, char* key){};
void *closeBox(UIGlue *uiInterface){};
void *addVerticalBargraph(UIGlue *uiInterface, const char *name, float *p, float f1, float f2){};
void *addHorizontalBargraph(UIGlue *uiInterface, const char *name, float *p, float f1, float f2){};
void *addButton(UIGlue *uiInterface, const char *name, float *p){extract(name, p, 0, 0, 0, 0);};
void *addCheckButton(UIGlue *uiInterface, const char *name, float *p){extract(name, p, 0, 0, 0, 0);};
void *addVerticalSlider(UIGlue *uiInterface, const char *name, float *p, float init, float min, float max, float step){extract(name, p, init, min, max, step);};
void *addHorizontalSlider(UIGlue *uiInterface, const char *name, float *p, float init, float min, float max, float step){extract(name, p, init, min, max, step);};
void *addNumEntry(UIGlue *uiInterface, const char *name, float *p, float init, float min, float max, float step){extract(name, p, init, min, max, step);};

UIGlue ui_glue = {
    .openVerticalBox = openVerticalBox,
    .openHorizontalBox = openHorizontalBox,
    .closeBox = closeBox,
    .declare = declare,
    .addVerticalSlider = addVerticalSlider,
    .addHorizontalSlider = addHorizontalSlider,
    .addNumEntry = addNumEntry,
    .addVerticalBargraph = addVerticalBargraph,
    .addHorizontalBargraph = addHorizontalBargraph,
    .addButton = addButton,
    .addCheckButton = addCheckButton
};

void dsp_init(size_t buf_size)
{
    initmydsp(&dsp, 48000);
    buildUserInterfacemydsp(&dsp, &ui_glue);
    buf_in[0] = (float *)malloc(buf_size * sizeof(float));
    buf_out[0] = (float *)malloc(buf_size * sizeof(float));
    buf_len = buf_size;
}

void dsp_run(int16_t *src, int16_t *dest)
{
    for (int i = 0; i < buf_len; i++)
    {
        buf_in[0][i] = (float)src[i] / 32767.0;
    }
    computemydsp(&dsp, buf_len, buf_in, buf_out);
    for (int i = 0; i < buf_len; i++)
    {
        float val = buf_out[0][i];
        int32_t raw = (int32_t)(val * 32767);
        dest[i] = (uint16_t)(raw < -32768 ? -32768 : raw > 32767 ? 32767 : raw);
    }
}
