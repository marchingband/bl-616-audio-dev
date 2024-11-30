/* ------------------------------------------------------------
name: "flanger"
Code generated with Faust 2.68.6 (https://faust.grame.fr)
Compilation options: -lang c -ct 1 -es 1 -mcd 16 -single -ftz 0
------------------------------------------------------------ */

#ifndef  __mydsp_H__
#define  __mydsp_H__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif 


#ifdef __cplusplus
extern "C" {
#endif

#if defined(_WIN32)
#define RESTRICT __restrict
#else
#define RESTRICT __restrict__
#endif

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <dsp.h>


#ifndef FAUSTCLASS 
#define FAUSTCLASS mydsp
#endif

#ifdef __APPLE__ 
#define exp10f __exp10f
#define exp10 __exp10
#endif

typedef struct {
	FAUSTFLOAT fCheckbox0;
	FAUSTFLOAT fHslider0;
	int fSampleRate;
	float fConst0;
	float fConst1;
	FAUSTFLOAT fHslider1;
	int iVec0[2];
	float fRec0[2];
	float fRec1[2];
	FAUSTFLOAT fHbargraph0;
	FAUSTFLOAT fHslider2;
	int IOTA0;
	float fVec1[4096];
	FAUSTFLOAT fHslider3;
	FAUSTFLOAT fHslider4;
	float fRec2[2];
	FAUSTFLOAT fCheckbox1;
	FAUSTFLOAT fHslider5;
	float fVec2[4096];
	float fRec3[2];
} mydsp;

mydsp* newmydsp() { 
	mydsp* dsp = (mydsp*)calloc(1, sizeof(mydsp));
	return dsp;
}

void deletemydsp(mydsp* dsp) { 
	free(dsp);
}

void metadatamydsp(MetaGlue* m) { 
	m->declare(m->metaInterface, "basics.lib/bypass2:author", "Julius Smith");
	m->declare(m->metaInterface, "basics.lib/name", "Faust Basic Element Library");
	m->declare(m->metaInterface, "basics.lib/tabulateNd", "Copyright (C) 2023 Bart Brouns <bart@magnetophon.nl>");
	m->declare(m->metaInterface, "basics.lib/version", "1.11.1");
	m->declare(m->metaInterface, "compile_options", "-lang c -ct 1 -es 1 -mcd 16 -single -ftz 0");
	m->declare(m->metaInterface, "delays.lib/name", "Faust Delay Library");
	m->declare(m->metaInterface, "delays.lib/version", "1.1.0");
	m->declare(m->metaInterface, "demos.lib/flanger_demo:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "demos.lib/flanger_demo:licence", "MIT");
	m->declare(m->metaInterface, "demos.lib/name", "Faust Demos Library");
	m->declare(m->metaInterface, "demos.lib/version", "1.1.0");
	m->declare(m->metaInterface, "filename", "flanger.dsp");
	m->declare(m->metaInterface, "filters.lib/lowpass0_highpass1", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/name", "Faust Filters Library");
	m->declare(m->metaInterface, "filters.lib/nlf2:author", "Julius O. Smith III");
	m->declare(m->metaInterface, "filters.lib/nlf2:copyright", "Copyright (C) 2003-2019 by Julius O. Smith III <jos@ccrma.stanford.edu>");
	m->declare(m->metaInterface, "filters.lib/nlf2:license", "MIT-style STK-4.3 license");
	m->declare(m->metaInterface, "filters.lib/version", "1.3.0");
	m->declare(m->metaInterface, "maths.lib/author", "GRAME");
	m->declare(m->metaInterface, "maths.lib/copyright", "GRAME");
	m->declare(m->metaInterface, "maths.lib/license", "LGPL with exception");
	m->declare(m->metaInterface, "maths.lib/name", "Faust Math Library");
	m->declare(m->metaInterface, "maths.lib/version", "2.7.0");
	m->declare(m->metaInterface, "name", "flanger");
	m->declare(m->metaInterface, "oscillators.lib/name", "Faust Oscillator Library");
	m->declare(m->metaInterface, "oscillators.lib/version", "1.4.0");
	m->declare(m->metaInterface, "phaflangers.lib/name", "Faust Phaser and Flanger Library");
	m->declare(m->metaInterface, "phaflangers.lib/version", "1.1.0");
	m->declare(m->metaInterface, "platform.lib/name", "Generic Platform Library");
	m->declare(m->metaInterface, "platform.lib/version", "1.3.0");
	m->declare(m->metaInterface, "routes.lib/name", "Faust Signal Routing Library");
	m->declare(m->metaInterface, "routes.lib/version", "1.2.0");
}

int getSampleRatemydsp(mydsp* RESTRICT dsp) {
	return dsp->fSampleRate;
}

int getNumInputsmydsp(mydsp* RESTRICT dsp) {
	return 2;
}
int getNumOutputsmydsp(mydsp* RESTRICT dsp) {
	return 2;
}

void classInitmydsp(int sample_rate) {
}

void instanceResetUserInterfacemydsp(mydsp* dsp) {
	dsp->fCheckbox0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider0 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider1 = (FAUSTFLOAT)(0.5f);
	dsp->fHslider2 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider3 = (FAUSTFLOAT)(1.0f);
	dsp->fHslider4 = (FAUSTFLOAT)(1e+01f);
	dsp->fCheckbox1 = (FAUSTFLOAT)(0.0f);
	dsp->fHslider5 = (FAUSTFLOAT)(1.0f);
}

void instanceClearmydsp(mydsp* dsp) {
	/* C99 loop */
	{
		int l0;
		for (l0 = 0; l0 < 2; l0 = l0 + 1) {
			dsp->iVec0[l0] = 0;
		}
	}
	/* C99 loop */
	{
		int l1;
		for (l1 = 0; l1 < 2; l1 = l1 + 1) {
			dsp->fRec0[l1] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l2;
		for (l2 = 0; l2 < 2; l2 = l2 + 1) {
			dsp->fRec1[l2] = 0.0f;
		}
	}
	dsp->IOTA0 = 0;
	/* C99 loop */
	{
		int l3;
		for (l3 = 0; l3 < 4096; l3 = l3 + 1) {
			dsp->fVec1[l3] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l4;
		for (l4 = 0; l4 < 2; l4 = l4 + 1) {
			dsp->fRec2[l4] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l5;
		for (l5 = 0; l5 < 4096; l5 = l5 + 1) {
			dsp->fVec2[l5] = 0.0f;
		}
	}
	/* C99 loop */
	{
		int l6;
		for (l6 = 0; l6 < 2; l6 = l6 + 1) {
			dsp->fRec3[l6] = 0.0f;
		}
	}
}

void instanceConstantsmydsp(mydsp* dsp, int sample_rate) {
	dsp->fSampleRate = sample_rate;
	dsp->fConst0 = fminf(1.92e+05f, fmaxf(1.0f, (float)(dsp->fSampleRate)));
	dsp->fConst1 = 6.2831855f / dsp->fConst0;
}

void instanceInitmydsp(mydsp* dsp, int sample_rate) {
	instanceConstantsmydsp(dsp, sample_rate);
	instanceResetUserInterfacemydsp(dsp);
	instanceClearmydsp(dsp);
}

void initmydsp(mydsp* dsp, int sample_rate) {
	classInitmydsp(sample_rate);
	instanceInitmydsp(dsp, sample_rate);
}

void buildUserInterfacemydsp(mydsp* dsp, UIGlue* ui_interface) {
	ui_interface->declare(ui_interface->uiInterface, 0, "tooltip", "Reference: https://ccrma.stanford.edu/~jos/pasp/Flanging.html");
	ui_interface->openVerticalBox(ui_interface->uiInterface, "FLANGER");
	ui_interface->declare(ui_interface->uiInterface, 0, "0", "");
	ui_interface->openHorizontalBox(ui_interface->uiInterface, "0x00");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fCheckbox0, "0", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fCheckbox0, "tooltip", "When this is checked, the flanger         has no effect");
	ui_interface->addCheckButton(ui_interface->uiInterface, "Bypass", &dsp->fCheckbox0);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fCheckbox1, "1", "");
	ui_interface->addCheckButton(ui_interface->uiInterface, "Invert Flange Sum", &dsp->fCheckbox1);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHbargraph0, "2", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHbargraph0, "style", "led");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHbargraph0, "tooltip", "Display sum of flange delays");
	ui_interface->addHorizontalBargraph(ui_interface->uiInterface, "Flange LFO", &dsp->fHbargraph0, (FAUSTFLOAT)-1.5f, (FAUSTFLOAT)1.5f);
	ui_interface->closeBox(ui_interface->uiInterface);
	ui_interface->declare(ui_interface->uiInterface, 0, "1", "");
	ui_interface->openHorizontalBox(ui_interface->uiInterface, "0x00");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider1, "unit", "Hz");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Speed", &dsp->fHslider1, (FAUSTFLOAT)0.5f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1e+01f, (FAUSTFLOAT)0.01f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "2", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider5, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Depth", &dsp->fHslider5, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "3", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider2, "style", "knob");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Feedback", &dsp->fHslider2, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-0.999f, (FAUSTFLOAT)0.999f, (FAUSTFLOAT)0.001f);
	ui_interface->closeBox(ui_interface->uiInterface);
	ui_interface->declare(ui_interface->uiInterface, 0, "2", "");
	ui_interface->openHorizontalBox(ui_interface->uiInterface, "Delay Controls");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "1", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider4, "unit", "ms");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Flange Delay", &dsp->fHslider4, (FAUSTFLOAT)1e+01f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2e+01f, (FAUSTFLOAT)0.001f);
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "2", "");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "style", "knob");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider3, "unit", "ms");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Delay Offset", &dsp->fHslider3, (FAUSTFLOAT)1.0f, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)2e+01f, (FAUSTFLOAT)0.001f);
	ui_interface->closeBox(ui_interface->uiInterface);
	ui_interface->declare(ui_interface->uiInterface, 0, "3", "");
	ui_interface->openHorizontalBox(ui_interface->uiInterface, "0x00");
	ui_interface->declare(ui_interface->uiInterface, &dsp->fHslider0, "unit", "dB");
	ui_interface->addHorizontalSlider(ui_interface->uiInterface, "Flanger Output Level", &dsp->fHslider0, (FAUSTFLOAT)0.0f, (FAUSTFLOAT)-6e+01f, (FAUSTFLOAT)1e+01f, (FAUSTFLOAT)0.1f);
	ui_interface->closeBox(ui_interface->uiInterface);
	ui_interface->closeBox(ui_interface->uiInterface);
}

void computemydsp(mydsp* dsp, int count, FAUSTFLOAT** RESTRICT inputs, FAUSTFLOAT** RESTRICT outputs) {
	FAUSTFLOAT* input0 = inputs[0];
	FAUSTFLOAT* input1 = inputs[1];
	FAUSTFLOAT* output0 = outputs[0];
	FAUSTFLOAT* output1 = outputs[1];
	int iSlow0 = (int)((float)(dsp->fCheckbox0));
	float fSlow1 = powf(1e+01f, 0.05f * (float)(dsp->fHslider0));
	float fSlow2 = dsp->fConst1 * (float)(dsp->fHslider1);
	float fSlow3 = sinf(fSlow2);
	float fSlow4 = cosf(fSlow2);
	float fSlow5 = (float)(dsp->fHslider2);
	float fSlow6 = 0.001f * (float)(dsp->fHslider3);
	float fSlow7 = 0.0005f * (float)(dsp->fHslider4);
	float fSlow8 = (float)(dsp->fHslider5);
	float fSlow9 = (((int)((float)(dsp->fCheckbox1))) ? -fSlow8 : fSlow8);
	/* C99 loop */
	{
		int i0;
		for (i0 = 0; i0 < count; i0 = i0 + 1) {
			dsp->iVec0[0] = 1;
			dsp->fRec0[0] = fSlow3 * dsp->fRec1[1] + fSlow4 * dsp->fRec0[1];
			dsp->fRec1[0] = (float)(1 - dsp->iVec0[1]) + fSlow4 * dsp->fRec1[1] - fSlow3 * dsp->fRec0[1];
			dsp->fHbargraph0 = (FAUSTFLOAT)(dsp->fRec1[0] + dsp->fRec0[0]);
			float fTemp0 = (float)(input0[i0]);
			float fTemp1 = fSlow1 * ((iSlow0) ? 0.0f : fTemp0);
			float fTemp2 = fSlow5 * dsp->fRec2[1] - fTemp1;
			dsp->fVec1[dsp->IOTA0 & 4095] = fTemp2;
			float fTemp3 = dsp->fConst0 * (fSlow6 + fSlow7 * (dsp->fRec0[0] + 1.0f));
			int iTemp4 = (int)(fTemp3);
			float fTemp5 = floorf(fTemp3);
			dsp->fRec2[0] = dsp->fVec1[(dsp->IOTA0 - min(2049, max(0, iTemp4))) & 4095] * (fTemp5 + (1.0f - fTemp3)) + (fTemp3 - fTemp5) * dsp->fVec1[(dsp->IOTA0 - min(2049, max(0, iTemp4 + 1))) & 4095];
			output0[i0] = (FAUSTFLOAT)(((iSlow0) ? fTemp0 : 0.5f * (fTemp1 + dsp->fRec2[0] * fSlow9)));
			float fTemp6 = (float)(input1[i0]);
			float fTemp7 = fSlow1 * ((iSlow0) ? 0.0f : fTemp6);
			float fTemp8 = fSlow5 * dsp->fRec3[1] - fTemp7;
			dsp->fVec2[dsp->IOTA0 & 4095] = fTemp8;
			float fTemp9 = dsp->fConst0 * (fSlow6 + fSlow7 * (dsp->fRec1[0] + 1.0f));
			int iTemp10 = (int)(fTemp9);
			float fTemp11 = floorf(fTemp9);
			dsp->fRec3[0] = dsp->fVec2[(dsp->IOTA0 - min(2049, max(0, iTemp10))) & 4095] * (fTemp11 + (1.0f - fTemp9)) + (fTemp9 - fTemp11) * dsp->fVec2[(dsp->IOTA0 - min(2049, max(0, iTemp10 + 1))) & 4095];
			output1[i0] = (FAUSTFLOAT)(((iSlow0) ? fTemp6 : 0.5f * (fTemp7 + dsp->fRec3[0] * fSlow9)));
			dsp->iVec0[1] = dsp->iVec0[0];
			dsp->fRec0[1] = dsp->fRec0[0];
			dsp->fRec1[1] = dsp->fRec1[0];
			dsp->IOTA0 = dsp->IOTA0 + 1;
			dsp->fRec2[1] = dsp->fRec2[0];
			dsp->fRec3[1] = dsp->fRec3[0];
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif
