#include "ui.hpp"

int UI::splash(bool* show, Mainboard mainboard){

    if(!*show){
        return 1;
    }
    ImGui::SetNextWindowSize(ImVec2(675,75), ImGuiCond_Once);
    ImGui::SetNextWindowPos(ImVec2(350,200), ImGuiCond_Once);
    ImGui::Begin("Nebula");
        ImGui::Text("Welcome to Nebula. To start, either create a new machine or load a currently configured one");

        if (ImGui::Button("New Machine")){
            printf("Making a new Nebula Machine\n");
            mainboard.addCPU();
            //New Machine is to be made
            *show = false;
        }
        ImGui::SameLine();
        if(ImGui::Button("Load Configured Machine")){
            //mainboard.loadConfiguration();
            printf("This will bring up a dialog box to select the file\n");
            *show = false;
        }

    ImGui::End();
    

    return 0;
}