#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <iostream>
#include <fstream>
#include <string>
#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_memory_editor.h"
#include "imgui_logger.h"
#include "imgui_internal.h"
#include "imgui_impl_opengl3.h"
#include <GL/glew.h>

#include "uistatus.hpp"
#include "mainboard.hpp"


class UI{
    public:
        int run();


    private:
        Mainboard mainboard;

        
        int splash(bool*,Mainboard);
};
