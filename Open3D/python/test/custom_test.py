import open3d as o3d
import numpy as np
import pytest

import sys
import os

# sys.path.append(os.path.dirname(os.path.realpath(__file__)) + "/..")
from open3d_test import list_devices


@pytest.mark.parametrize("device", list_devices())
def test_connected_components(device):
    mesh_file = os.path.join(sys.path[0], "sample_mesh.ply")
    mesh = o3d.io.read_triangle_mesh(mesh_file)
    connected_components = mesh.identically_colored_connected_components()
    print(connected_components)
    assert connected_components[0] == [0, 3, 5, 6]
    assert connected_components[1] == [1, 4]
    assert connected_components[2] == [2]
