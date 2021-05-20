#include "ui.hpp"

int UI::splash(bool show){

    if(!show){
        return 1;
    }
    ImGui::SetNextWindowSize(ImVec2(675,75), ImGuiCond_Once);
    ImGui::SetNextWindowPos(ImVec2(350,200), ImGuiCond_Once);
    ImGui::Begin("Nebula");
        ImGui::Text("Welcome to Nebula. To start, either create a new machine or load a currently configured one");

        if (ImGui::Button("New Machine")){
            printf("Making a new Nebula Machine\n");
            //New Machine is to be made
        }
        ImGui::SameLine();
        if(ImGui::Button("Load Configured Machine")){
            printf("This will bring up a dialog box to select the file\n");
        }
    ImGui::End();
    show = 1;

    return 0;
}