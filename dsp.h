#ifndef DSP_H
#define DSP_H

typedef struct c {
	struct UIGlue *uiInterface;
	void (*openVerticalBox)(struct UIGlue *uiInterface, char* key);
	void (*openHorizontalBox)(struct UIGlue *uiInterface, char* key);
	void (*closeBox)(struct UIGlue *uiInterface);
	void (*declare)(struct UIGlue *uiInterface, float *p, const char* key, const char* val);

	void (*addVerticalSlider)(struct UIGlue *uiInterface, const char *name, float *p, float init, float min, float max, float step);
	void (*addHorizontalSlider)(struct UIGlue *uiInterface, const char *name, float *p, float init, float min, float max, float step);
	void (*addNumEntry)(struct UIGlue *uiInterface, const char *name, float *p, float init, float min, float max, float step);

	void (*addVerticalBargraph)(struct UIGlue *uiInterface, const char *name, float *p, float f1, float f2);
	void (*addHorizontalBargraph)(struct UIGlue *uiInterface, const char *name, float *p, float f1, float f2);
	void (*addButton)(struct UIGlue *uiInterface, const char *name, float *p);
	void (*addCheckButton)(struct UIGlue *uiInterface, const char *name, float *p);
} UIGlue;

typedef void (* metaDeclareFun) (void* ui_interface, const char* key, const char* value);

typedef struct b{
	void* metaInterface;
    metaDeclareFun declare;
} MetaGlue;

#endif