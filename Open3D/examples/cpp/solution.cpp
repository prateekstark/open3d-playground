#include <iostream>
#include <fstream>
#include <open3d/Open3D.h>
using namespace open3d;

int main(int argc, char *argv[]){
    utility::SetVerbosityLevel(utility::VerbosityLevel::Debug);
    const char* mesh_filename;
    if(argc == 1){
        mesh_filename = "test_mesh.ply";    
    }
    else if(argc == 2){
        mesh_filename = argv[1];
    }
    else{
        utility::LogWarning("Wrong arguments!");
        return 1;
    }
    
    std::cout << mesh_filename << std::endl;
    auto mesh = geometry::TriangleMesh();
    if (io::ReadTriangleMesh(mesh_filename, mesh)) {
        utility::LogInfo("Successfully read mesh_file: {}\n", mesh_filename);
    }
    else {
        utility::LogWarning("Failed to read mesh_file: {}\n", mesh_filename);
        return 1;
    }
    
    std::ofstream resultFile;
    resultFile.open("result.txt");
    auto connected_components = mesh.IdenticallyColoredConnectedComponents();
    for (size_t i=0; i<connected_components.size();i++) {
        for (auto const& v: connected_components[i]) {
            std::cout << v << " ";
            resultFile << v << " ";
        }
        std::cout << std::endl;
        resultFile << std::endl;
    }
    resultFile.close();
    std::cout << "Successfully written result file: result.txt" << std::endl;
    return 0;
}