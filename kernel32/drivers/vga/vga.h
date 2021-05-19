// -------------------------------------------------------------------------------------
//
#ifndef __VGA_H__
#define __VGA_H__

#include "kernel32.h"
#include "sysgfx.h"
#include "sysvga.h"

extern void vga_init(void);

// VGA register port addresses
#define ATTRCON_ADDR		0x03C0
#define MISC_ADDR		0x03C2
#define VGAENABLE_ADDR		0x03C3
#define SEQ_ADDR		0x03C4
#define GRACON_ADDR		0x03CE
#define CRTC_ADDR		0x03D4
#define STATUS_ADDR		0x03DA

// Video mode numbers
#define MODE00H					0x00
#define MODE01H					0x00
#define MODE02H					0x03
#define MODE03H					0x03
#define MODE04H					0x04
#define MODE05H					0x05
#define MODE06H					0x06
#define MODE07H					0x07
#define MODE0DH					0x0D
#define MODE0EH					0x0E
#define MODE0FH					0x0F
#define MODE10H					0x10
#define MODE11H					0x11
#define MODE12H					0x12
#define MODE13H					0x13
#define CHAIN4					0x14
#define MODE_X					0x15
#define MODE_A					0x16
#define MODE_B					0x17
#define MODE_C					0x18
#define MODE_D					0x19
#define MODE_E					0x1A
#define MODE_F					0x1B
#define MODE_G					0x1C
#define MODE_H					0x1D
#define MODE_I					0x1E
#define MODE_J					0x1F
#define MODE_K					0x20
#define MODE_L					0x21
#define MODE_M					0x22

// Keypresses
#define Escape			0x001b

// Videomode attributes
#define TVU_TEXT				0x0001
#define TVU_GRAPHICS				0x0002
#define TVU_MONOCHROME				0x0004
#define TVU_PLANAR				0x0008
#define TVU_UNCHAINED				0x0010

// Videomode Info Structure
typedef struct {
   int mode;                      // Videomode Number
   int width;                     // Width in pixels
   int height;                    // Height in pixels
   unsigned int width_bytes;      // Number of bytes per screen
   int colors;                    // Number of colors
   int attrib;                    // Videomode attributes
}Vmode;

extern Vmode Mode;

// MODES.CPP Function Prototypes
void SetVideoMode(int);
void ReadBIOSfont(int, int);
void SetMode(const unsigned char *);
void setpal(int, BYTE, BYTE, BYTE);

// CLEAR.CPP Function Prototypes
void TextClear(char);
void PlanarClear(char);
void UnchainedClear(char);
void Clear13H(char);
void Clear04H();
void Clear06H();
void Clear0DH(char);

// TESTS.CPP Function Prototypes
void ModeTest();
void TextTest();

// DUAL.CPP Function Prototypes
void DualTest();

//
void setvmode(int);
void setpalette4(void);
void setpalette16(void);
void setpalette256(void);

//
extern int vga_terminal;
extern int visible_before_switch;
extern int graphicModeActive;

#endif

