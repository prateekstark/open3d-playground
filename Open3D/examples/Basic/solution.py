import sys
import open3d as o3d


if __name__ == "__main__":
    argc = len(sys.argv)
    if(argc == 1):
        mesh_filename = "test_mesh.ply"
    elif(argc == 2):
        mesh_filename = sys.argv[1]
    else:
        print("Wrong arguments!")
        exit(0)
    mesh = o3d.io.read_triangle_mesh(mesh_filename)
    connected_components = mesh.identically_colored_connected_components()
    result_file = open("result.txt", "w+")

    for components in connected_components:
        for vertex in components:
            print("{}".format(vertex), end=" ")
            result_file.write("{} ".format(vertex))
        print()
        result_file.write("\n")
    result_file.close()
