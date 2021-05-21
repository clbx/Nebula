#include "ui.hpp"
#include <fstream>


int UI::run(){
    UIStatus uiStatus;
    uiStatus.showSplash = true; //Show Splash on Startup


    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0){
        printf("Error: %s\n", SDL_GetError());
        return -1;
    }

    const char *glsl_version = "#version 150";
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG); // Always required on Mac
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);


    // Create window with graphics context
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
    SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Window *window = SDL_CreateWindow("Nebula", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); // Enable vsync

    bool err = glewInit() != 0;
    if (err){
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return 1;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;

    ImGui::StyleColorsDark();
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);



    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    glEnable(GL_DEBUG_OUTPUT);



    ImGuiContext* context = ImGui::GetCurrentContext();
    const char* focused = "";
    bool done = false;

    bool ctrlState = false;

    while (!done){
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            ImGui_ImplSDL2_ProcessEvent(&event);
            if (event.type == SDL_QUIT)
                done = true;
            if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
                done = true;
            if (event.type == SDL_KEYDOWN){
                //TODO: Add scope to this with only affecting the active window
                // debugLog.AddLog("Keys mods: %s%s%s%s\n", io.KeyCtrl ? "CTRL " : "", io.KeyShift ? "SHIFT " : "", io.KeyAlt ? "ALT " : "", io.KeySuper ? "SUPER " : "");
                switch (event.key.keysym.sym){
                    case SDLK_SPACE:
                        if (ctrlState)
                        break;
                    case SDLK_r:
                        if (ctrlState)
                        break;
                    case SDLK_m:
                        if (ctrlState)
                        break;
                    case SDLK_c:
                        if (ctrlState)
                        break;
                    case SDLK_RCTRL:
                        ctrlState = true;
                        break;
                    case SDLK_LCTRL:
                        ctrlState = true;
                        break;
                }
            }
            if (event.type == SDL_KEYUP){
                switch (event.key.keysym.sym){
                    case SDLK_RCTRL:
                        ctrlState = false;
                        break;
                    case SDLK_LCTRL:
                        ctrlState = false;
                        break;
                }
            }
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(window);
        ImGui::NewFrame();

        ImGui::ShowDemoWindow();


        splash(&uiStatus.showSplash,mainboard);
 

        // Rendering
        ImGui::Render();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        SDL_GL_SwapWindow(window);

        focused = context->WindowsFocusOrder.back()->Name; //Set at end to guarentee size > 0 on init
    }
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    SDL_GL_DeleteContext(gl_context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}





