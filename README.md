# Open3D Playground

The repository contains some add-ons to the open-sourced Open3D library.

## Add-ons

### IdenticallyColoredConnectedComponents()
This feature returns a list of identically-connected components in a triangle mesh.

#### Algorithm Used
The algorithm used to achieve the above task is Breadth-First Search. The pseudo-code for the same is provided below:
```
def IdenticallyColoredConnectedComponents():
    connected_components = []
    num_vertices = vertices_.size()
    visited = [False] * num_vertices    # Mark all the nodes as unvisited in the beginning

    for i in num_vertices:
        connected_pool = []
        if not visited[i]:
            queue = []
            queue.append(i)
            connected_pool.append(i)
            visited[i] = True    # Mark this node as visited
            while(not queue.empty()):
                lastVertex = queue.back()
                for v in adjacency_list_[lastVertex]:
                    if(not visited[v] and (vertex_colors_[v] == vertex_colors_[lastVertex])):
                        queue.insert(0, v)
                        connected_pool.append(v)
                        visited[v] = True
                queue.pop()
            connected_pool.sort()
            connected_components.append(connected_pool)

    return connected_components
```
The time complexity for the above algorithm is O(|V| + |E|).

#### Examples:
##### Python Example:
```python
import open3d as o3d
# Read triangle mesh "test_mesh.ply"
mesh = o3d.io.read_triangle_mesh("test_mesh.ply")
# Then get connected components
connected_components = mesh.identically_colored_connected_components()
# Print connected_components in the specified format.
```
##### CPP Example:
```cpp
#include <open3d/Open3D.h>
using namespace open3d;

int main(int argc, char *argv[]){
    /* Block for reading the triangle mesh from .ply file */
    auto mesh = geometry::TriangleMesh();
    const char* mesh_filename = "test_mesh.ply"
    if (io::ReadTriangleMesh(mesh_filename, mesh)) {
        utility::LogInfo("Successfully read mesh_file: {}\n", mesh_filename);
    }
    else {
        utility::LogWarning("Failed to read mesh_file: {}\n", mesh_filename);
        return 1;
    }

    /* Invocation of IdenticallyColoredConnectedComponents | return type - vector<list<int> > */
    auto connected_components = mesh.IdenticallyColoredConnectedComponents();

    /* Block for saving/writing/printing the result in specified format. */
    return 0;
}
```

#### Unit Tests
Appropriately updated all the tests for correctness in Python as well as C++. To run the tests, make and build Open3D by
```bash
cmake -DBUILD_UNIT_TESTS=ON ..
make -j
```
and then run:
- C++
```bash
./bin/tests
```
- Python
```bash
pytest ../python/test/custon_test.py
```
#### Solution File:
There are two solution files present, one for C++ (Open3D/examples/Cpp/solution.cpp) and the other one for python (Open3D/examples/python/Basic/solution.py). Usage for running the solution files is:
- C++
```bash
#After building the system, from the main/root Open3D directory
./build/bin/examples/solution /path/to/custom/test.ply
# Example: ./build/bin/examples/solution examples/test_data/test_mesh.ply
```
- Python
```bash
#From the main directory
python examples/python/Basic/solution.py /path/to/custom/test.ply
#Example: python examples/python/Basic/solution.py examples/test_data/test_mesh.ply
```

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.