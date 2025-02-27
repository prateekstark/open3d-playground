.. _getting_started:

Getting started
###############

.. _install_open3d_python:

Installing from PyPI or Conda
=============================

Open3D Python packages are distributed via
`PyPI <https://pypi.org/project/open3d/>`_ and
`Conda <https://anaconda.org/open3d-admin/open3d>`_.

Supported Python versions:

* 3.6
* 3.7
* 3.8

Supported operating systems:

* Ubuntu 18.04+
* macOS 10.14+
* Windows 10 (64-bit)

If you have other Python versions (e.g. Python 2) or operating systems, please
refer to :ref:`compilation` and compile Open3D from source.

Pip (PyPI)
----------

.. code-block:: bash

    pip install open3d

Note: In general, we recommend using a
`virtual environment <https://docs.python-guide.org/dev/virtualenvs/>`_ for
containerization. Otherwise, depending on the configurations, ``pip3`` may be
needed for Python 3, or the ``--user`` option may need to be used to avoid
permission issues. For example:

.. code-block:: bash

    pip3 install open3d
    # or
    pip install --user open3d
    # or
    python3 -m pip install --user open3d

Development version (pip)
-------------------------

To test the latest features in Open3D, download and install the development
version (``HEAD`` of ``master`` branch):

:Linux: `Python 3.6 <https://storage.googleapis.com/open3d-releases-master/python-wheels/open3d-0.11.2+4def7dd-cp36-cp36m-linux_x86_64.whl>`__
        `Python 3.7 <https://storage.googleapis.com/open3d-releases-master/python-wheels/open3d-0.11.2+4def7dd-cp37-cp37m-linux_x86_64.whl>`__
        `Python 3.8 <https://storage.googleapis.com/open3d-releases-master/python-wheels/open3d-0.11.2+4def7dd-cp38-cp38-linux_x86_64.whl>`__

:MacOS: `Python 3.6 <https://storage.googleapis.com/open3d-releases-master/python-wheels/open3d-0.11.2+4def7dd-cp36-cp36m-macosx_10_9_x86_64.whl>`__
        `Python 3.7 <https://storage.googleapis.com/open3d-releases-master/python-wheels/open3d-0.11.2+4def7dd-cp37-cp37m-macosx_10_9_x86_64.whl>`__
        `Python 3.8 <https://storage.googleapis.com/open3d-releases-master/python-wheels/open3d-0.11.2+4def7dd-cp38-cp38-macosx_10_9_x86_64.whl>`__

:Windows: `Python 3.6 <https://storage.googleapis.com/open3d-releases-master/python-wheels/open3d-0.11.2+4def7dd-cp36-cp36m-win_amd64.whl>`__
        `Python 3.7 <https://storage.googleapis.com/open3d-releases-master/python-wheels/open3d-0.11.2+4def7dd-cp37-cp37m-win_amd64.whl>`__
        `Python 3.8 <https://storage.googleapis.com/open3d-releases-master/python-wheels/open3d-0.11.2+4def7dd-cp38-cp38-win_amd64.whl>`__

Please use these links from the `latest version of this page <http://www.open3d.org/docs/latest/getting_started.html>`__ only. For example, to install the latest development version on Linux for Python 3.8:

.. code-block:: bash

    pip install --user --pre https://storage.googleapis.com/open3d-releases-master/python-wheels/open3d-0.11.2+4def7dd-cp38-cp38-linux_x86_64.whl


Conda
-----

.. code-block:: bash

    conda install -c open3d-admin open3d

Note: Open3D prebuilt binaries for Conda (Anaconda/Miniconda) can be found at
`open3d <https://anaconda.org/open3d-admin/open3d>`_. Currently, the ``open3d``
package is distributed under the ``open3d-admin`` channel. To setup Conda,
please see `the official documentations <https://conda.io/docs/user-guide/install/index.html>`_.


Try it
------

Now, try importing Open3D.

.. code-block:: bash

    python -c "import open3d as o3d"

If this works, congratulations, now Open3D has been successfully installed!


Running Open3D tutorials
========================

A complete set of Python tutorials and testing data will also be copied to
demonstrate the usage of Open3D Python interface. See ``examples/python`` for all Python examples.

.. note:: Open3D's Python tutorial utilizes some external packages: ``numpy``,
    ``matplotlib``, ``opencv-python``. OpenCV is only used for reconstruction
    system. Please read util/install-deps-python.sh for installing these
    packages.
