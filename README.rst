DTLE-2026
=========

Cloning The Repository
----------------------

.. code-block:: console

   $ git clone https://github.com/jfasch/DTLE-2026.git

This creates a directory ``DTLE-2026`` in the current working
directory.

Preparing The Clone
-------------------

We use the `googletest <https://github.com/google/googletest>`__
testing framework as a submodule of ours. You have to change into the
project, and pull that in.

.. code-block:: console

   $ cd DTLE-2026
   $ git submodule update --init --recursive

Building The Project
--------------------

In the remainder, ``<SRCDIR>`` denotes the project's source
directory - this is the directory that the ``git clone`` command
created.

``<BUILDDIR>`` is a directory which is distinct from the source
directory (CMake recommends to *not* build in the source directory, in
order to avoid side effects). We assume that you have created it
somewhere (and that it is empty).

Now that we have ``<SRCDIR>`` and ``<BUILDDIR>`` ready, we now use
CMake to fill the build directory with build files.

.. code-block:: console

   $ cd <BUILDDIR>
   $ cmake <SRCDIR>
   ... roedel ...

Next, we build the project, together with the accompanied tests.

.. code-block:: console

   $ cd <BUILDDIR>           # if you aren't there already
   $ make
   ... roedel ...
   
Testing The Project
-------------------

The project has a test suite (which is why we bothered to setup
``googletest`` before). Run that test suite to verify that everything
is ok,

.. code-block:: console

   $ cd <BUILDDIR>           # if you aren't there already
   $ ./tests/DTLE-2026-tests
   [==========] Running 3 tests from 3 test suites.
   [----------] Global test environment set-up.
   [----------] 1 test from led_tests
   [ RUN      ] led_tests.basic
   [       OK ] led_tests.basic (0 ms)
   [----------] 1 test from led_tests (0 ms total)
   
   [----------] 1 test from sensor_tests
   [ RUN      ] sensor_tests.basic
   [       OK ] sensor_tests.basic (0 ms)
   [----------] 1 test from sensor_tests (0 ms total)
   
   [----------] 1 test from controller_tests
   [ RUN      ] controller_tests.basic
   [       OK ] controller_tests.basic (0 ms)
   [----------] 1 test from controller_tests (0 ms total)
   
   [----------] Global test environment tear-down
   [==========] 3 tests from 3 test suites ran. (0 ms total)
   [  PASSED  ] 3 tests.
   
Running The Project
-------------------

When all is well the firmware should be fully functional. As a final
*integration test*, run it.

.. code-block:: console

   $ ./firmware/DTLE-2026-firmware 
   --*------
   -----*---
   --------*
   --*------
   -----*---
   --------*
   --*------
   ...
