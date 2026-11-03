#include <SDL2/SDL.h>
#include <cctype>
#include <cstring>

static const int SCREEN_W = 1280;
static const int SCREEN_H = 720;

static const unsigned char* glyph(char c) {
    static const unsigned char blank[7] = {0,0,0,0,0,0,0};
    #define G(ch,a,b,c,d,e,f,g) case ch: { static const unsigned char v[7]={a,b,c,d,e,f,g}; return v; }
    switch (c) {
        G('A',14,17,17,31,17,17,17) G('B',30,17,17,30,17,17,30)
        G('C',14,17,16,16,16,17,14) G('D',30,17,17,17,17,17,30)
        G('E',31,16,16,30,16,16,31) G('F',31,16,16,30,16,16,16)
        G('G',14,17,16,23,17,17,15) G('H',17,17,17,31,17,17,17)
        G('I',14,4,4,4,4,4,14) G('J',7,2,2,2,18,18,12)
        G('K',17,18,20,24,20,18,17) G('L',16,16,16,16,16,16,31)
        G('M',17,27,21,21,17,17,17) G('N',17,25,21,19,17,17,17)
        G('O',14,17,17,17,17,17,14) G('P',30,17,17,30,16,16,16)
        G('Q',14,17,17,17,21,18,13) G('R',30,17,17,30,20,18,17)
        G('S',15,16,16,14,1,1,30) G('T',31,4,4,4,4,4,4)
        G('U',17,17,17,17,17,17,14) G('V',17,17,17,17,17,10,4)
        G('W',17,17,17,21,21,21,10) G('X',17,17,10,4,10,17,17)
        G('Y',17,17,10,4,4,4,4) G('Z',31,1,2,4,8,16,31)
        G('0',14,17,19,21,25,17,14) G('1',4,12,4,4,4,4,14)
        G('2',14,17,1,2,4,8,31) G('3',30,1,1,14,1,1,30)
        G('4',2,6,10,18,31,2,2) G('5',31,16,16,30,1,1,30)
        G('6',14,16,16,30,17,17,14) G('7',31,1,2,4,8,8,8)
        G('8',14,17,17,14,17,17,14) G('9',14,17,17,15,1,1,14)
        G('-',0,0,0,31,0,0,0) G(':',0,4,4,0,4,4,0)
        G('.',0,0,0,0,0,12,12) G('/',1,2,2,4,8,8,16)
        G('!',4,4,4,4,4,0,4)
        default: break;
    }
    #undef G
    return blank;
}

static void text(SDL_Renderer* r, int x, int y, const char* s, int scale, SDL_Color color) {
    SDL_SetRenderDrawColor(r, color.r, color.g, color.b, 255);
    for (; *s; ++s, x += 6 * scale) {
        const unsigned char* rows = glyph((char)toupper((unsigned char)*s));
        for (int yy=0; yy<7; ++yy) {
            for (int xx=0; xx<5; ++xx) {
                if (rows[yy] & (1u << (4-xx))) {
                    SDL_Rect p = {x + xx*scale, y + yy*scale, scale, scale};
                    SDL_RenderFillRect(r, &p);
                }
            }
        }
    }
}

static void fill(SDL_Renderer* r, int x, int y, int w, int h, SDL_Color c) {
    SDL_SetRenderDrawColor(r,c.r,c.g,c.b,255);
    SDL_Rect q={x,y,w,h}; SDL_RenderFillRect(r,&q);
}

int main(int, char**) {
    setvbuf(stdout, NULL, _IONBF, 0);
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0) return 1;

    SDL_Window* win = SDL_CreateWindow("FC27 Custom Creator", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, SCREEN_W, SCREEN_H, 0);
    if (!win) return 2;
    SDL_Surface* surface = SDL_GetWindowSurface(win);
    SDL_Renderer* renderer = SDL_CreateSoftwareRenderer(surface);
    if (!renderer) return 3;

    SDL_Joystick* pad = SDL_NumJoysticks() > 0 ? SDL_JoystickOpen(0) : NULL;
    const char* items[] = {"BAHASA INDONESIA", "VISUAL MODS", "USB FILE MANAGER", "PENGATURAN"};
    const int itemCount = 4;
    int selected = 0;
    int page = -1;
    bool running = true;

    while (running) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            if (ev.type == SDL_QUIT) running = false;
            if (ev.type == SDL_JOYBUTTONDOWN) {
                int b = ev.jbutton.button;
                if (b == 11 && page < 0) selected = (selected + itemCount - 1) % itemCount;
                if (b == 12 && page < 0) selected = (selected + 1) % itemCount;
                if (b == 0) { if (page < 0) page = selected; }
                if (b == 1 && page >= 0) page = -1;
                if ((b == 3 || b == 9) && page < 0) running = false;
                if (b == 3 && page >= 0) page = -1;
            }
        }

        fill(renderer,0,0,SCREEN_W,SCREEN_H,{10,16,30,255});
        fill(renderer,0,0,SCREEN_W,112,{18,34,58,255});
        text(renderer,48,35,"FC27 CUSTOM CREATOR",5,{235,245,255,255});
        text(renderer,50,135,"OFFLINE HOMEbrew TOOL",2,{105,205,225,255});

        if (page < 0) {
            for (int i=0;i<itemCount;i++) {
                int y=205+i*94;
                SDL_Color panel = i==selected ? SDL_Color{22,92,115,255} : SDL_Color{25,38,57,255};
                fill(renderer,48,y,780,70,panel);
                text(renderer,78,y+22,items[i],3,{245,248,252,255});
                if (i==selected) fill(renderer,850,y+12,8,46,{75,220,205,255});
            }
            text(renderer,50,625,"DPAD PILIH   X BUKA   O KEMBALI   TRIANGLE KELUAR",2,{175,190,210,255});
        } else {
            fill(renderer,48,205,1000,250,{25,38,57,255});
            text(renderer,80,240,items[page],4,{90,220,210,255});
            text(renderer,80,325,"PROTOTIPE AWAL",3,{245,248,252,255});
            text(renderer,80,385,"FITUR INI BELUM DIAKTIFKAN",2,{210,220,235,255});
            text(renderer,80,425,"MODUL AKAN DIBANGUN BERTAHAP",2,{210,220,235,255});
            text(renderer,50,625,"O KEMBALI KE MENU",2,{175,190,210,255});
        }

        SDL_UpdateWindowSurface(win);
        SDL_Delay(16);
    }

    if (pad) SDL_JoystickClose(pad);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
